# OcctCommon
> Work in progress

A Rhinocommon-like geometry library based on OpenCASCADE

## Requirements
- Windows
  - Add `CMakePresets.json` into project root directory to use `vcpkg`
    ``` json
    {
      "version": 3,
      "configurePresets": [
        {
            "name": "debug",
            "toolchainFile": "$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        }
      ]
    }
    ```
- Linux
  - Install `libocct` (on Debian) or `opencascade-devel` (on RedHat)
