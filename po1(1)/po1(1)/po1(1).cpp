#include <iostream>
#include <ctime>
#include <conio.h>
#include "WorldGenerator.h"
#include "Description.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACEBAR 32
#define KEY_S 115
#define KEY_R 114
#define KEY_X 120

int main()
{
    srand(time(NULL));
    auto generator = new WorldGenerator;
    auto world = generator->Generate();
    bool endFlag = true;
    int playerMove;
    int c;
    Description description;
    while (endFlag) {
        system("cls");
        std::cout << description;
        world->DrawMap();
        c = _getch();
        if (c && c != 224)
        {
            if (c == KEY_SPACEBAR)world->CalculateTurn(4);
            else if (c == KEY_S) {
                generator->Save();
            }
            else if (c == KEY_R) {
                generator->Read();
            }
            else if (c == KEY_X) {
                endFlag = false;
            }
        }
        else
        {
            switch (playerMove = _getch())
            {
            case KEY_UP     /* H */:
                world->CalculateTurn(0);
                break;
            case KEY_RIGHT   /* K */:
                world->CalculateTurn(1);
                break;
            case KEY_DOWN   /* M */:
                world->CalculateTurn(2);
                break;
            case KEY_LEFT: /* P */
                world->CalculateTurn(3);
                break;
            default:
                world->CalculateTurn();
                break;
            }
        }
    }
    delete generator;
}