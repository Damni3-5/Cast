#pragma once

#include <vector>
#include "colors.h"
#include <iostream>

// ���� 0-8		9-����
class Field 
{
public:
	Field(int _x, int _y);
	void Clear();
	void Restart();
	void Draw(int screenWidth, int screenHeight);
	void CalculateNumbers();
	void Print();

private:
	std::vector<std::vector<int>> grid;
	int x, y;
};