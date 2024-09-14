#pragma once

#include <raylib.h>

#include <string>
#include <sstream>

std::string Vector2ToString(const Vector2& vec) 
{
    std::ostringstream oss;
    oss << "(" << vec.x << ", " << vec.y << ")";
    return oss.str();
}