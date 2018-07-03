#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
}


Grid::~Grid()
{
}

int Grid::getTallCellHeight(int x, int z) const {
	return tallCellHeights[x][z];
}
int Grid::getTallCellHeight(Vec3 v) const {
	return tallCellHeights[v.getX()][v.getZ()];
}
void Grid::setTallCellHeight(int x, int z, int h) {
	tallCellHeights[x][z] = h;
}
void Grid::setTallCellHeight(Vec3 v, int h) {
	tallCellHeights[v.getX()][v.getZ()] = h;
}

Cell Grid::getCellValue(Vec3 subCell) {
	int x = subCell.getX();
	int y = subCell.getY();
	int z = subCell.getZ();
	if (x > 0 && x < xMax &&
		z > 0 && y < zMax){
		//y value is above the tall cell but within the grid
		if (y > tallCellHeights[x][z] && y < yMax) {
			return contents[x][y][z];
		}
		//y value is within the tall cell
		else if (y < tallCellHeights[x][z] && y > 0) {
			Cell top = contents[x][yMax - 2][z];
			Cell bottom = contents[x][yMax - 1][z];
			float weight = y / tallCellHeights[x][z];
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

void Grid::extrapolateVelocity(float deltaTime) {

}