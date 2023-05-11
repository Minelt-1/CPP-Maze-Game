#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random
{
private:
    std::mt19937 m_ran;
    std::uniform_int_distribution<int> m_dist;

public:
    Random(int start, int end)
        : m_ran{std::random_device{}()}, m_dist{start, end} {}

    int get_random_int()
    {
        return m_dist(m_ran);
    }
};

#endif
