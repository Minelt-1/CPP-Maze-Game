#include <algorithm>
#include "map.h"
#include "Moves.h"

bool Move(int &indexX ,int &indexY, const directions& direction, Map& map){
    //direction UP
    if(direction == UP){
       if(indexX <= 0)
          return false;

       if (map.get()[indexX - 1][indexY] == '#' || map.get()[indexX - 1][indexY] == '$')
          return false;

       std::swap(map.get()[indexX - 1][indexY], map.get()[indexX][indexY]);
       indexX--;
    }
    //direction LEFT
    if(direction == LEFT){

       int index = 0;
       for (int i = 0; i < mapY; i++)
       {
          if(indexY == index)
             return false;

          index += mapY;
       }

          if (map.get()[indexX][indexY - 1] == '#' || map.get()[indexX][indexY - 1] == '$')
                  return false;

       std::swap(map.get()[indexX][indexY - 1], map.get()[indexX][indexY]);
       indexY--;
    }
    //direction RIGHT
    if(direction == RIGHT){
       int index = mapY - 1;
       for (int i = 0; i < mapY; i++)
       {
            if (indexY == index)
               return false;

            index += mapY;
       }

       if (map.get()[indexX][indexY + 1] == '#' || map.get()[indexX][indexY + 1] == '$')
          return false;

       std::swap(map.get()[indexX][indexY + 1], map.get()[indexX][indexY]);
       indexY++;
    }
    //direction DOWN
    if(direction == DOWN){

       if (map.get()[indexX + 1][indexY] == '#' || map.get()[indexX + 1][indexY] == '$')
          return false;

       if (indexX == mapX - 1){
          won = true;
          return true;
       }

       std::swap(map.get()[indexX + 1][indexY], map.get()[indexX][indexY]);
       indexX++;
    }

    return true;
}
