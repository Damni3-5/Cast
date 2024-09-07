#pragma once

#include <random>

class Random
{
public:
    static int GenerateInt(int min, int max) {
        static std::random_device rd;
        static std::mt19937 generator{ rd() };
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(generator);
    }
};