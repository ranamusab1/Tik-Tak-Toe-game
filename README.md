## Below is a `README.md` file for the given Tic Tac Toe game using Raylib in C++. This file provides an overview of the project, instructions on how to set it up, build it, and run it.

```markdown
# Tic Tac Toe Game

This is a simple Tic Tac Toe game implemented in C++ using the Raylib library for graphics. The game allows two players to play Tic Tac Toe on a 3x3 grid.

## Features

- Two-player gameplay (Player X and Player O)
- Checks for wins and draws
- Restart the game by pressing 'R'
- Light green background for the game window

## Prerequisites

To build and run this game, you need the following:

- C++ Compiler (e.g., GCC)
- Raylib library
- CMake (optional, for easier building)

## Getting Started

### Installing Raylib

Follow the instructions on the [Raylib GitHub page](https://www.raylib.com/) to install Raylib for your system.

### Clone the Repository

```bash
git clone https://github.com/yourusername/tic-tac-toe-raylib.git
cd tic-tac-toe-raylib
```

### Build the Game

#### Using CMake (Recommended)

1. Create a `CMakeLists.txt` file with the following content:

    ```cmake
    cmake_minimum_required(VERSION 3.0)
    project(TicTacToe)

    set(CMAKE_CXX_STANDARD 11)

    # Add the raylib directory to the list of directories to be searched
    set(RAYLIB_DIR "path/to/raylib")  # Adjust this path to where Raylib is installed

    find_package(raylib REQUIRED)

    add_executable(TicTacToe main.cpp)
    target_link_libraries(TicTacToe raylib)
    ```

2. Create a `build` directory and navigate into it:

    ```bash
    mkdir build
    cd build
    ```

3. Run CMake to configure the project and generate a build system:

    ```bash
    cmake ..
    ```

4. Build the project:

    ```bash
    cmake --build .
    ```

#### Manual Build (Without CMake)

1. Compile the program using g++ (adjust the paths as needed):

    ```bash
    g++ main.cpp -o TicTacToe -I path/to/raylib/include -L path/to/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
    ```

### Run the Game

After building the game, you can run it from the command line:

```bash
./TicTacToe
```

## Game Instructions

- Player X starts the game.
- Players take turns clicking on the grid to place their mark (X or O).
- The game checks for wins after each move.
- If a player wins or the game is a draw, a message is displayed.
- Press 'R' to restart the game.

## Code Overview

- `Tik-Tak-Toe.cpp`: The main source file containing the game logic and rendering code.
- `raylib.h`: Header file for the Raylib library (make sure it's in your include path).

## License

This project is licensed under the EPL-2.0 License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [Raylib](https://www.raylib.com/) - A simple and easy-to-use library to enjoy videogames programming.
```

Replace `path/to/raylib` with the actual path where Raylib is installed on your system. This README provides comprehensive instructions for setting up, building, and running the Tic Tac Toe game, along with an overview of the game's features and gameplay instructions.
