#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For _kbhit() and _getch()
#include "snake.h"

#define INITIAL_LENGTH 3

typedef struct {
    int x;
    int y;
} Position;

static Position snake[100];
static int snake_length = INITIAL_LENGTH;
static char direction = 'R'; // R: Right, L: Left, U: Up, D: Down

void initialize_snake(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < snake_length; i++) {
        snake[i].x = HEIGHT / 2;
        snake[i].y = WIDTH / 2 - i;
        board[snake[i].x][snake[i].y] = '*';
    }
}

void draw_board(char board[HEIGHT][WIDTH]) {
    system("cls"); // Clear the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == '*') {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int update_game(char board[HEIGHT][WIDTH]) {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': direction = 'U'; break;
            case 's': direction = 'D'; break;
            case 'a': direction = 'L'; break;
            case 'd': direction = 'R'; break;
            case 'q': return 1; // Quit the game
        }
    }

    // Move the snake
    Position new_head = snake[0];
    switch (direction) {
        case 'U': new_head.x--; break;
        case 'D': new_head.x++; break;
        case 'L': new_head.y--; break;
        case 'R': new_head.y++; break;
    }

    // Check for collisions
    if (new_head.x < 0 || new_head.x >= HEIGHT || new_head.y < 0 || new_head.y >= WIDTH) {
        return 1; // Game over
    }

    // Move the snake
    for (int i = snake_length; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    snake[0] = new_head;

    // Update the board
    initialize_board(board);
    for (int i = 0; i < snake_length; i++) {
        board[snake[i].x][snake[i].y] = '*';
    }

    return 0; // Continue the game
}

