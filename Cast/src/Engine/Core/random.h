#pragma once

#include <random>

class random
{
public:
    static int GenerateInt(int min, int max) {
        static std::random_device rd;
        static std::mt19937 generator{ rd() };
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(generator);
    }
};