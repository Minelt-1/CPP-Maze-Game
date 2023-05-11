#include "map.h"

const char Map::operator[](int index) const{
    return m_map[0][index];
}

const char Map::operator()(int x, int y) const{
    return m_map[x][y];
}

std::ostream &operator<<(std::ostream &out, const Map &map)
{
    for (int i = 0; i < mapX; i++){
        for (int j = 0; j < mapY; j++){
            out << map(i, j) << ' ';
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    return out;
}
