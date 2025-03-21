# 🧊 Cub3D

## ↕️ Table of Contents
1.[Introduction](#-introduction)

2.[Features](#-features)

3.[Project Structure](#-project-structure)

4.[Setup](#-setup)

5.[Usage](#-usage)

6.[Built-in Mechanisms](#-built-in-mechanisms)

7.[Bonus Part](#-bonus-part)

8.[Conclusion](#-conclusion)

9.[Contributors](#-contributors)

10.[License](#-license)

## 📖 Introduction
Cub3D is a 3D game engine built as part of a C project. The project implements a 3D world with a camera and a player moving through it, based on the raycasting technique. It features a simple level design, and provides an interactive environment with wall collisions and player movement.

The goal of this project is to understand 3D game development fundamentals and graphics rendering, using MinilibX for rendering and libft for utilities.

## ✨ Features
- Raycasting: Implements a basic 3D environment using the raycasting algorithm.

- Player Movement: Allows for moving a player through a map.

- Texture Mapping: Textures are mapped onto walls based on the player's viewpoint.

- Wall Collisions: Basic wall collision detection is implemented, which prevents the player from moving through walls.

- Map Parsing: Reads and loads .cub files to generate game maps.

## 📂 Project Structure
```sh
Cub3D/
│
├── Makefile           # Compilation instructions
├── src/               # Source code files
│
├── inc                # Header files and textures for the project
├── maps               # Map variety for testing in .cub format
│
└── dirs/
    ├── libft          # Custom library
    └── mlx.zip        # Minilibx (graphics library) required for rendering the game
```
- mlx.zip/:
This is a zipped version of the MiniLibX library, which is required for graphical rendering. The library includes basic functions to create windows, handle user input (keyboard and mouse), and work with images. To use it, the zip file must be extracted and compiled before linking it with the main project.

## 🛠️ Setup
To install and compile Cub3D, follow these steps:
```sh
# Clone the repository
git clone https://github.com/Tudor-Ursescu/Cub3D.git
# Navigate into the project directory
cd Cub3D
# Unzip the mlx.zip int dirs
unzip dirs/mlx.zip -d dirs/
# Compile the project
make
```
This will generate an executable named `cub3d`.

## 🚀 Usage
Run the program with the following command:
```sh
./cub3d path/to/your/map.cub`
```
Example: `./cub3d maps/example.cub`

## 🔧 Built-in Mechanisms

| Functionality              | Description                                                                   |
|----------------------------|-------------------------------------------------------------------------------|
| **Raycasting**             | Uses raycasting to render a 3D perspective of the game environment.           |
| **Wall Rendering**         | Draws the walls of the map, based on textures and raycasting results.         |
| **Texture Mapping**        | Maps textures onto the walls to give the environment a realistic appearance.   |
| **Player Movement**        | Allows the player to move and rotate within the environment using keyboard inputs. |
| **Wall Collisions (Bonus)**| Prevents the player from walking through walls by checking for intersections with walls. |
| **Map Parsing**            | Reads and parses the `.cub` map file to create the game environment.          |

## 🎮 Bonus Part
In the bonus part, we tackled the implementation of wall collisions. While we have planned for other bonus features, such as a minimap, doors, animated sprites, and mouse-controlled rotation, only wall collisions were fully implemented in the project.

`Wall Collisions`
The player cannot move through walls. This is achieved by checking the position and direction of movement before updating the player's coordinates. If the player would collide with a wall, the movement is blocked.

## 💡 Conclusion

Cub3D is a fun and challenging project that brings the fundamentals of raycasting, game development, and 3D rendering into practice. By implementing core mechanics such as player movement, texture mapping, and collision detection, we’ve created an immersive first-person experience.  

While we tackled essential features, there’s always room for improvement—whether through additional bonuses like animated sprites or interactive doors. This project serves as a stepping stone toward more advanced game development, pushing our understanding of graphics programming and low-level optimizations.  

We hope you enjoy exploring our world as much as we enjoyed building it! 🚀  


## 👥 Contributors
[**Tudor Ursescu**](https://github.com/Tudor-Ursescu)

[**Tudor-Ioan Lupu**](https://github.com/DRACULATudor)
## 📜 License
This is an open-source project. Feel free to use, modify, and distribute it as needed!
