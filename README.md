> *This project has been created as part of the 42 curriculum by darismen.*

# so_long

## Description

**so_long** is a 2D game developed as part of the 42 curriculum using the MLX42 graphics library.

The player must collect every item on the map and reach the exit while avoiding walls.

## Features

- 2D graphical rendering with MiniLibX
- Player movement
- Collectible items
- Exit validation
- Wall collision detection
- Map parsing and validation
- Movement counter displayed in the terminal

## Requirements

- Linux
- `gcc` or `clang`
- `make`
- MLX42
- X11 development libraries

## Installation

Clone the repository and compile the project:

```bash
git clone git@github.com:KeyOfCode/so_long_42.git so_long
cd so_long
make
```

## Usage

Run the game with a valid map file:

```bash
./so_long maps/example.ber
```

## Map Format

Maps use the following characters:

| Character | Description |
|---|---|
| `1` | Wall |
| `0` | Empty space |
| `P` | Player starting position |
| `C` | Collectible |
| `E` | Exit |

Example:

```text
111111
1000C1
10P001
1000E1
111111
```

A valid map must:

- Be rectangular
- Be surrounded by walls
- Contain exactly one player
- Contain exactly one exit
- Contain at least one collectible
- Have a valid path from the player to all collectibles and the exit

## Controls

| Key | Action |
|---|---|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` | Exit the game |

The game can also be closed using the window close button.

## Makefile Commands

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and the executable
make re     # Recompile the project
```

## Resources
No AI was used in the creatin of this project.

* [MLX42] (https://github.com/codam-coding-college/MLX42)
* [Libft] (https://github.com/KeyOfCode/Libft42)