#ifndef MAP_H
#define MAP_H

#include<array>
#include<iostream>

inline constexpr int mapX{30};
inline constexpr int mapY{30};

class Map{
    private:
        char m_map[mapX][mapY];

    public:
        const char operator[](int index) const;

        const char operator()(int x, int y) const;

        friend std::ostream &operator<<(std::ostream &out, const Map &map);

        auto& get()
        {
            return m_map;
        }
};

#endif
