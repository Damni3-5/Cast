#include "Field.h"

#include "Random.h"
#include "Sprite2D.h"

#define MINE 9

Field::Field(int _x, int _y)
{
	this->x = _x;
	this->y = _y;
	this->Restart();
	this->CalculateNumbers();
	this->Print();
}

void Field::Clear()
{
	grid.resize(x, std::vector<int>(y, 0));
}

void Field::Restart()
{
	this->Clear();

	for (int row = 0; row < grid.size(); row++)
		for (int column = 0; column < grid[row].size(); column++)
		{
			const int is_mine = Random::GenerateInt(1, grid.size() / 3);

			if (is_mine == 1) 
				grid[row][column] = MINE;
		}
}

void Field::Draw(int screenWidth, int screenHeight)
{
	//const int size1 = grid.size(), size2 = grid[0].size();
	//const int CellSize = std::max((screenHeight / size1), (screenWidth / size2));

	const Vector2 texture_size = ResourceManager::GetTextureSize("tiles");
	const float scaleX = (float)screenWidth / (texture_size.x * grid[0].size());
	const float scaleY = (float)screenHeight / (texture_size.y * grid.size());
	const float scale = fmax(scaleX, scaleY);

	for (int row = 0; row < grid.size(); row++)
	{
		for (int column = 0; column < grid[row].size(); column++)
		{
			Sprite2D sprite = { ResourceManager::GetTextureR("tiles"), (float)column * 32 * scale, (float)row * 32 * scale, scale };
			sprite.SetFrame(grid[row][column], 32, 32);
			sprite.Draw();

			//DrawRectangle(column * CellSize + 1 , row * CellSize + 1, CellSize - 1, CellSize - 1, cyan);
		}
	}
}

void Field::CalculateNumbers()
{
	int Mines = 0;
	for (int row = 0; row < grid.size(); row++)
	{
		for (int column = 0; column < grid[row].size(); column++)
		{
			if (grid[row][column] != MINE) continue;

			if (row + 1 < grid.size() && grid[row + 1][column] < 9)
				grid[row + 1][column] += 1;
			if (row - 1 >= 0 && grid[row - 1][column] < 9)
				grid[row - 1][column] += 1;
			if (column + 1 < grid[row].size() && grid[row][column + 1] < 9)
				grid[row][column + 1] += 1;
			if (column - 1 >= 0 && grid[row][column - 1] < 9)
				grid[row][column - 1] += 1;
			if (row - 1 >= 0 && column - 1 >= 0 && grid[row - 1][column - 1] < 9)
				grid[row - 1][column - 1] += 1;
			if (row + 1 < grid.size() && column + 1 < grid[row].size() && grid[row + 1][column + 1] < 9)
				grid[row + 1][column + 1] += 1;
			if (row - 1 >= 0 && column + 1 < grid[row].size() && grid[row - 1][column + 1] < 9)
				grid[row - 1][column + 1] += 1;
			if (row + 1 < grid.size() && column - 1 >= 0 && grid[row + 1][column - 1] < 9)
				grid[row + 1][column - 1] += 1;

			Mines++;
		}
	}
	std::cout << std::endl << "Mines = " << Mines << std::endl;
}

void Field::Print()
{
	for (const auto& row : grid) 
	{
		for (const auto& elem : row)
		{
			if(elem == MINE)
				std::cout << "X ";
			else
				std::cout << elem << " ";
		}
		std::cout << std::endl;
	}
}

