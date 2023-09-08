# HID-IO OpenRGB Plugin

[HID-IO](https://github.com/hid-io/hid-io-core) Plugin for OpenRGB.

## Notes

- Requires hid-io-core daemon to be running in the background (OpenRGB does not directly control HID-IO keyboards).
- This plugin uses capnproto to communicate with hid-io-core, hid-io-core usually uses the hid-io protocol to communicate with devices.
- Very early development stages (pre-alpha quality)

## What is this?

This is some boilerplate code that ease plugin writing for [OpenRGB](https://gitlab.com/CalcProgrammer1/OpenRGB).

## How to build

```bash
mkdir build
cmake ..
make -j
```

## Notes

- When you install an OpenRGB plugin it is usually cached (e.g. ~/.config/OpenRGB/plugins).
  * During development it makes more sense to symlink your build copy of the shared libray to the cached directory.
- To reload a plugin after building a new one you will likely need to restart OpenRGB
- `QT_DEBUG_PLUGINS=1 openrgb` is a useful command when debugging plugins
