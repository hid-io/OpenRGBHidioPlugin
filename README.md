# Sample Rust Plugin 

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
