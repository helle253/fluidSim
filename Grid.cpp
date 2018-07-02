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

Cell Grid::getCellValue(Vec3 subCell) {
	int x = subCell.getX();
	int y = subCell.getY();
	int z = subCell.getZ();
	if (x > 0 && x < xMax &&
		z > 0 && y < zMax){
		//y value is above the tall cell but within the grid
		if (y > tallCellHeight && y < yMax) {
			return contents[x][y][z];
		}
		//y value is within the tall cell
		else if (y < tallCellHeight && y > 0) {
			Cell top = contents[x][yMax - 2][z];
			Cell bottom = contents[x][yMax - 1][z];
			float weight = y / tallCellHeight;
			return bottom.interpolate(top, weight);
		}
		//y value is above the grid. Return identity Cell that functions as air
		else if (y > yMax) {
			return Cell();
		}
		//y value is below the grid. return a terrain cell???? TODO
		else {
			return Cell();
		}
	}
	else {
		return Cell();
	}

}