#include <iostream>
#include <numeric>
#include "random.h"
#include "map.h"
#include "Moves.h"

int main(){
    Map main_map;

    for (int i = 0; i < mapX; i++)
    {
        for(int j = 0; j < mapY; j++){
        Random rd{0, 15};
        switch (rd.get_random_int())
        {
            case 0:
            case 1:
            case 3:
                main_map.get()[i][j] = '$';
                break;
            case 2:
                main_map.get()[i][j] = '#';
                break;
            default:
                main_map.get()[i][j] = '.';
                break;
            }
        }
    }

    Random ranPlayer{0, mapY - 1};
    int playerY = ranPlayer.get_random_int();
    int playerX = 0;
    main_map.get()[playerX][playerY] = '@';

    std::cout << "\033[2J\033[1;1H"; // This is the escape sequence to clear the console screen
    bool loop = true;
    std::cout << "Well come to the maze game! Find you best way to go to the bottom levels and WIN! Watch out #, $ are walls!\n";
    while (loop)
    {
        if (won)
        {
            std::cout << "YOU WON!\n";
            return 1;
        }
        std::cout << '\n';
        std::cout << main_map;
        std::cout << "Your character is the @. use the (w), (a), (s), (d) to move: ";
        char input;
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();

        switch (input)
        {
        case 'w':
        case 'W':
            if (!Move(playerX, playerY, UP, main_map))
            {
                std::cout << "Connot move UP\n";
            }

            break;

        case 'a':
        case 'A':
            if (!Move(playerX, playerY, LEFT, main_map))
            {
                std::cout << "Cannot move LEFT\n";
            }
            break;

        case 's':
        case 'S':
            if (!Move(playerX, playerY, DOWN, main_map))
            {
                std::cout << "Cannot move DOWN\n";
            }

            break;

        case 'd':
        case 'D':
            if (!Move(playerX, playerY, RIGHT, main_map))
            {
                std::cout << "Cannot move RIGHT\n";
            }
            break;
        case 'Q':
            return 1;
        }
    }

    return 0;
}
