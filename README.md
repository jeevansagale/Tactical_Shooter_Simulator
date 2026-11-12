# Tactical Shooter Simulator

A first-person shooter prototype built in C++ with Raylib. The project explores player movement, camera control, shooting mechanics, weapon foundations, and the structure of a small real-time game.

This is a collaborative project with [Vedant Hire](https://github.com/HireVedant).

## Development Preview

<p align="center">
  <img src="Images/Screenshot%202026-07-03%20080749.png" width="48%" alt="Gameplay preview 1" />
  <img src="Images/Screenshot%202026-07-03%20080811.png" width="48%" alt="Gameplay preview 2" />
</p>
<p align="center">
  <img src="Images/Screenshot%202026-07-03%20080848.png" width="48%" alt="Gameplay preview 3" />
  <img src="Images/Screenshot%202026-07-03%20080930.png" width="48%" alt="Gameplay preview 4" />
</p>

## Implemented Features

- First-person player controller.
- Mouse-driven camera movement.
- Shooting mechanics and weapon-system foundation.
- HUD and UI elements.
- Audio and visual feedback.
- Separated source and header files for major gameplay systems.

## Planned Work

- Enemy behavior and AI.
- Additional weapons and customization.
- More maps and environments.
- Animation and audio improvements.
- Multiplayer exploration.
- Performance and gameplay refinement.

These are planned items, not currently completed features.

## Technology

- C++
- Raylib
- OpenGL (through Raylib)

## Source Layout

The repository currently keeps the C++ source and header files at the root, with an `Images/` folder for screenshots and an `Assets/` folder for runtime resources.

```text
Tactical_Shooter_Simulator/
├── Assets/
├── Images/
├── MainGame.cpp
├── MainGame.h
├── Player.cpp
├── Player.h
├── ShootSystem.cpp
├── ShootSystem.h
├── UI.cpp
├── UI.h
└── Tactical_Shooter_Simulator.cpp
```

## Build and Run

The repository currently includes Windows runtime binaries and DLLs, but does not include a Visual Studio solution, project file, CMake configuration, or Makefile.

To build from source, configure a C++ compiler and Raylib for your platform, then compile the tracked `.cpp` files and link against the matching Raylib dependencies. A reproducible build configuration is a useful future addition.

## Controls

| Action | Input |
|---|---|
| Move | W, A, S, D |
| Look around | Mouse |
| Shoot | Left mouse button |

## Contributors

- **Jeevan Sagale** — [GitHub](https://github.com/jeevansagale)
- **Vedant Hire** — [GitHub](https://github.com/HireVedant)

## License

No license file is currently included. Unless a license is added, the repository should be treated as source available for viewing, not as granting general permission to reuse or redistribute the code.
