#pragma once
#include "Cell.h"
#include "Vec3.h"
#include <vector>
class Grid
{
public:
	Grid();
	~Grid();

	int getTallCellHeight() const;

	void setTallCellHeight(int h);

	Cell getCellValue(Vec3 subCell);

protected:
	std::vector<std::vector<std::vector<Cell>>> contents;
	int tallCellHeight;
	int xMax;
	int yMax;
	int zMax;
};

