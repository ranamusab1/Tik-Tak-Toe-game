#include "raylib.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define GRID_SIZE 3
#define CELL_SIZE (SCREEN_WIDTH / GRID_SIZE)

enum Player { NONE = 0, PLAYER_X, PLAYER_O };

Player grid[GRID_SIZE][GRID_SIZE];
Player currentPlayer = PLAYER_X;
bool gameOver = false;

void ResetGame() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = NONE;
        }
    }
    currentPlayer = PLAYER_X;
    gameOver = false;
}

bool CheckWin(Player player) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) return true;
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) return true;
    }
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) return true;
    if (grid[2][0] == player && grid[1][1] == player && grid[0][2] == player) return true;
    return false;
}

bool IsGridFull() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == NONE) return false;
        }
    }
    return true;
}

void DrawGrid() {
    for (int i = 0; i <= GRID_SIZE; i++) {
        DrawLine(i * CELL_SIZE, 0, i * CELL_SIZE, SCREEN_HEIGHT, BLACK);
        DrawLine(0, i * CELL_SIZE, SCREEN_WIDTH, i * CELL_SIZE, BLACK);
    }
}

void DrawMarks() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int x = j * CELL_SIZE + CELL_SIZE / 2;
            int y = i * CELL_SIZE + CELL_SIZE / 2;
            if (grid[i][j] == PLAYER_X) {
                DrawText("X", x - 20, y - 40, 80, RED);
            } else if (grid[i][j] == PLAYER_O) {
                DrawText("O", x - 20, y - 40, 80, BLUE);
            }
        }
    }
}

void UpdateGame() {
    if (gameOver) return;

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mouse = GetMousePosition();
        int row = mouse.y / CELL_SIZE;
        int col = mouse.x / CELL_SIZE;
        
        if (grid[row][col] == NONE) {
            grid[row][col] = currentPlayer;
            if (CheckWin(currentPlayer)) {
                gameOver = true;
            } else if (IsGridFull()) {
                gameOver = true;
                currentPlayer = NONE; // Draw
            } else {
                currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        }
    }
}

void DrawGame() {
    DrawGrid();
    DrawMarks();

    if (gameOver) {
        const char* message = "It's a Draw!";
        if (currentPlayer != NONE) {
            message = (currentPlayer == PLAYER_X) ? "Player X Wins!" : "Player O Wins!";
        }
        DrawText(message, SCREEN_WIDTH / 2 - MeasureText(message, 60) / 2, SCREEN_HEIGHT / 2 - 30, 60, BLACK);
        DrawText("Press R to Restart", SCREEN_WIDTH / 2 - MeasureText("Press R to Restart", 20) / 2, SCREEN_HEIGHT / 2 + 40, 20, GRAY);
    }
}

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tic Tac Toe");
    SetTargetFPS(60);

    ResetGame();

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_R)) {
            ResetGame();
        }

        UpdateGame();

        BeginDrawing();
        ClearBackground(GREEN);
        DrawGame();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
