#include "raylib.h"
#include "ajedrez.h"
#include <stdlib.h>

//https://github.com/austin0209/just-chess

// peon 1, alfil 2, caballo 3, torre 5, Dama 9, rey 100, nada 0, negativo si es negro;
//que piezas estan en que lugar
int board_pieces[8][8] = {
    {-5,-3,-2,-9,-100,-2,-3,-5},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1},
    {5,3,2,9,100,2,3,5},
};

// identificar los lugares en el tablero
int board_values[8][8] = {
    {11, 12, 13, 14, 15, 16, 17, 18},
    {21, 22, 23, 24, 25, 26, 27, 28},
    {31, 32, 33, 34, 35, 36, 37, 38},
    {41, 42, 43, 44, 45, 46, 47, 48},
    {51, 52, 53, 54, 55, 56, 57, 58},
    {61, 62, 63, 64, 65, 66, 67, 68},
    {71, 72, 73, 74, 75, 76, 77, 78},
    {81, 82, 83, 84, 85, 86, 87, 88}
};


int main()
{
    InitWindow(SCREAN_WIDTH, SCREAN_HEIGHT, "Chess");

    SetTargetFPS(60);

    Player* p1 = newPlayer();
    int band = 0;

    while (!WindowShouldClose())
    {
        char pr[10];
        itoa(p1->whereToMoveX, pr, 10);
        BeginDrawing();
        drawBoard(board_pieces);
        if (band == 0)
            band = whatMove(p1, board_pieces);
        else if (band == 1)
            band = whereMove(p1);
        else if (band == 2)
            band = makeMove(board_pieces, p1);
        if ((IsMouseButtonDown(MOUSE_RIGHT_BUTTON)))
        {
            DrawText(pr, 10, 10, 20, BLUE);
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;


}