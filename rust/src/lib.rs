extern crate tokio;

use serde::{Deserialize, Serialize};
use tokio::runtime::Runtime;

use hid_io_client::capnp;
use hid_io_client::common_capnp::NodeType;
use hid_io_client::setup_logging_lite;
use rand::Rng;


// Represent the data within the QObject below with serde friendly types, so we can (de)serialize it
#[derive(Deserialize, Serialize)]
pub struct DataSerde {
    number: i32,
    string: String,
}

impl From<&MyObject> for DataSerde {
    fn from(value: &MyObject) -> DataSerde {
        DataSerde {
            number: value.number,
            string: value.string.to_string(),
        }
    }
}

const DEFAULT_STR: &str = r#"{"number": 1, "string": "Hello World!"}"#;

#[cxx_qt::bridge(cxx_file_stem = "my_object", namespace = "core")]
mod ffi {
    use super::*;
    //use super::{DataSerde, DEFAULT_STR};

    #[namespace = ""]
    unsafe extern "C++" {
        include!("cxx-qt-lib/qstring.h");
        type QString = cxx_qt_lib::QString;
    }

    #[cxx_qt::qobject]
    pub struct MyObject {
        #[qproperty]
        pub number: i32,
        #[qproperty]
        pub string: QString,
    }

    impl Default for MyObject {
        fn default() -> Self {
            let data_serde: DataSerde = serde_json::from_str(DEFAULT_STR).unwrap();
            data_serde.into()
        }
    }

    impl From<DataSerde> for MyObject {
        fn from(value: DataSerde) -> MyObject {
            MyObject {
                number: value.number,
                string: QString::from(&value.string),
            }
        }
    }

    impl qobject::MyObject {
        #[qinvokable]
        pub fn increment(self: Pin<&mut Self>) {
            let new_number = self.number() + 1;
            self.set_number(new_number);
        }

        #[qinvokable]
        pub fn reset(mut self: Pin<&mut Self>) {
            let data: DataSerde = serde_json::from_str(DEFAULT_STR).unwrap();
            self.as_mut().set_number(data.number);
            self.as_mut().set_string(QString::from(&data.string));
        }

        #[qinvokable]
        pub fn serialize(&self) -> QString {
            let data_serde = DataSerde::from(self.rust());
            let data_string = serde_json::to_string(&data_serde).unwrap();
            QString::from(&data_string)
        }

        #[qinvokable]
        pub fn grab_values(mut self: Pin<&mut Self>) {
            let string = r#"{"number": 2, "string": "Goodbye!"}"#;
            let data: DataSerde = serde_json::from_str(string).unwrap();
            self.as_mut().set_number(data.number);
            self.as_mut().set_string(QString::from(&data.string));
        }

        #[qinvokable]
        pub fn lsnodes(&self) -> QString {
            let rt = Runtime::new().unwrap();
            let val = rt.block_on(async {
                setup_logging_lite().ok();
                tokio::task::LocalSet::new().run_until(lsnodes()).await.unwrap()
            });
            let output = val.join("\n");
            QString::from(output.as_str())
        }
    }
}

async fn lsnodes() -> Result<Vec<String>, capnp::Error> {
    // Prepare hid-io-core connection
    let mut hidio_conn = hid_io_client::HidioConnection::new().unwrap();
    let mut rng = rand::thread_rng();

    // Connect and authenticate with hid-io-core
    let (hidio_auth, _hidio_server) = hidio_conn
        .connect(
            hid_io_client::AuthType::Priviledged,
            NodeType::HidioApi,
            "lsnodes".to_string(),
            format!("{:x} - pid:{}", rng.gen::<u64>(), std::process::id()),
            true,
            std::time::Duration::from_millis(1000),
        )
        .await?;
    let hidio_auth = hidio_auth.expect("Could not authenticate to hid-io-core");

    let nodes_resp = {
        let request = hidio_auth.nodes_request();
        request.send().promise.await?
    };
    let nodes = nodes_resp.get()?.get_nodes()?;

    let mut outval = Vec::new();
    for n in nodes {
        outval.push(format!(" * {} - {}", n.get_id(), hid_io_client::format_node(n)));
    }

    hidio_conn.disconnect().await?;
    Ok(outval)
}
