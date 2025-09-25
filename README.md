# About

Graphics demos I made for playing around and learning. The code is (hopefully) clean and self-documented,
most dependencies are included or downloaded automatically for easier building.

There are no complex abstractions aka "engine", however a small library of shared code is still used.
The goal is to keep things easy to understand while taking away some of the boilerplate.

The demos have been tested on Windows. On macOS the OpenGL demos might still work, but have not been
tested properly. Vulkan demos work only on Windows.

Check also https://github.com/0xc0dec/demo-rs - an alternative experiment in Rust.

# Building and running

## Windows

- Install Vulkan SDK. Make sure the VULKAN_SDK environment variable is set.
- `cd build`.
- `cmake -G "Visual Studio 16 2019" -A x64 ..` (or the alternative for the current MSVS at the time).
- Build using the generated IDE files.
- Run demos from the project root, e.g.: `./build/bin/<Debug|Release>/<Demo executable>`.

## macOS

- `cd build`.
- `cmake ..`.
- `make`
- Run demos from the project root, e.g.: `./build/bin/<Demo executable>`.

# Controls

Some demos use first person camera. Use `WASDQE` keys to move around and hold right mouse button to rotate.

# Demos

## [ImGui](/src/imgui) [VK/GL]

Basic [ImGui](https://github.com/ocornut/imgui) integration example.

![Image](/src/imgui/screenshot.png?raw=true)

## [Transform](/src/transform) [GL]

Object transform hierarchies and (first person) camera via reusable [`Transform`](src/common/transform.h) and [`Camera`](src/common/camera.h) classes and a helper [spectator function](src/common/spectator.h).

![Image](/src/transform/screenshot.png?raw=true)

## [Skybox](/src/skybox) [GL]

Skybox rendering on a single quad mesh using a bit of shader magic.

![Image](/src/skybox/screenshot.png?raw=true)

## [TrueType](/src/stb_truetype) [GL]

TrueType font rendering using [stb_truetype](https://github.com/nothings/stb) library.

![Image](/src/stb_truetype/screenshot.png?raw=true)

## To be continued?...

# Dependencies

- stb_truetype
- stb_image
- SDL
- GLEW
- glm
- ImGui
- Vulkan
- OpenGL
