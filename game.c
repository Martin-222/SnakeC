#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For _kbhit() and _getch()
#include <windows.h> // For Sleep()
#include "game.h"
#include "snake.h"

#define WIDTH 20
#define HEIGHT 10

void start_game() {
    char board[HEIGHT][WIDTH];
    int game_over = 0;

    initialize_board(board);
    initialize_snake(board);

    while (!game_over) {
        draw_board(board);
        game_over = update_game(board);
        Sleep(100); // Control the speed of the game
    }

    printf("Game Over!\n");
}

