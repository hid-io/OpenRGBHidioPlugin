cmake_minimum_required(VERSION 3.24)

project(openrgb-hidio-plugin)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 5.15 COMPONENTS Core Gui Widgets Qml QuickControls2 QmlImportScanner QuickWidgets REQUIRED)
get_target_property(QMAKE Qt::qmake IMPORTED_LOCATION)

# Rust module
find_package(Corrosion QUIET)
if(NOT Corrosion_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        Corrosion
        GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
        GIT_TAG v0.3.1
    )
    FetchContent_MakeAvailable(Corrosion)
endif()

# Additional includes needed by OpenRGB plugins
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenRGB
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenRGB/RGBController
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenRGB/dependencies/hidapi
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenRGB/dependencies/json
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenRGB/hidapi_wrapper
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenRGB/i2c_smbus
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenRGB/net_port
)

# Setup qml files
set(QML_IMPORT_DIR ${CMAKE_CURRENT_BINARY_DIR}/qml)
set(PLUGIN_OUTPUT_DIR ${QML_IMPORT_DIR}/com/hidio/openrgb/plugin)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${PLUGIN_OUTPUT_DIR}/qmldir COPYONLY)

# Build Rust library
set(CRATE openrgb-hidio-plugin-rust)
corrosion_import_crate(MANIFEST_PATH rust/Cargo.toml CRATES ${CRATE})
set(CXXQT_EXPORT_DIR "${CMAKE_CURRENT_BINARY_DIR}/cxxqt")
corrosion_set_env_vars(${CRATE}
    "CXXQT_EXPORT_DIR=${CXXQT_EXPORT_DIR}"
    "QMAKE=${QMAKE}"
)
target_include_directories(${CRATE} INTERFACE "${CXXQT_EXPORT_DIR}/${CRATE}")

# Define the OpenRGB plugin library
add_library(${PROJECT_NAME} SHARED OpenRGBHIDIOPlugin.cpp resources.qrc)

# Link to Rust library and Qt
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CRATE}
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::QuickControls2
    Qt::Widgets
    Qt::QuickWidgets
)
qt_import_qml_plugins(${PROJECT_NAME})
