#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
}


Grid::~Grid()
{
}

int Grid::getTallCellHeight() const {
	return tallCellHeight;
}

void Grid::setTallCellHeight(int h) {
	tallCellHeight = h;
}