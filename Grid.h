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

protected:
	std::vector<std::vector<std::vector<Cell>>> contents;
	int tallCellHeight;
};

