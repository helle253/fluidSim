#include "stdafx.h"
#include "Grid.h"
#include <math.h>

Grid::Grid()
{
}

Grid::Grid(Vec3 size) {
	int x = size.getX();
	int y = size.getY();
	int z = size.getZ();
	for (int i = 0; i < x; i++) {
		contents.push_back(std::vector<std::vector<Cell>>());
		tallCellHeights.push_back(std::vector<int>());
		terrainHeights.push_back(std::vector<int>());
		for (int j = 0; j < y; j++) {
			contents[j].push_back(std::vector<Cell>());
			for (int k = 0; k < z; k++) {
				contents[j][k].push_back(Cell());
			}
		}
	}
}

Grid::Grid(int x, int y, int z) {
	for (int i = 0; i < x; i++) {
		contents.push_back(std::vector<std::vector<Cell>>());
		tallCellHeights.push_back(std::vector<int>());
		terrainHeights.push_back(std::vector<int>());
		for (int j = 0; j < y; j++) {
			contents[j].push_back(std::vector<Cell>());
			for (int k = 0; k < z; k++) {
				contents[j][k].push_back(Cell());
				tallCellHeights[i].push_back(1);
				terrainHeights[i].push_back(1);
			}
		}
	}

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

int Grid::getTerrainHeight(int x, int z) const {
	return terrainHeights[x][z];
}
int Grid::getTerrainHeight(Vec3 v) const {
	return terrainHeights[v.getX()][v.getZ()];
}
void Grid::setTerrainHeight(int x, int z, int h) {
	terrainHeights[x][z] = h;
}
void Grid::setTerrainHeight(Vec3 v, int h) {
	terrainHeights[v.getX()][v.getZ()] = h;
}

/*
Can coarsen the grid. L is defined as logBASE2min(sizeX, sizeY, sizeZ) at the finest (starting) grid level. recursively call till you have reached the coarsest grid value.
Creates the next grid, and then calls the coarsen function on the newly created grid object.
*/
std::vector<Grid> Grid::coarsen(std::vector<Grid> grids, int L) {
	if (L < 1) return grids;
	int idx = grids.size() - 1;
	Vec3 size = grids[idx].gridSize();
}
//same function as above, but calculates for L and then call the above function
std::vector<Grid> Grid::coarsen() {
	int xSize = contents.size();
	int ySize = contents.size();
	int zSize = contents.size();
	int L = fmin(log2(xSize), fmin(log2(ySize), log2(zSize)));
	std::vector<Grid> coarsenedGrids = std::vector<Grid>();
	coarsenedGrids.push_back(*this);


	
	return coarsen(coarsenedGrids, L);
}
Vec3 Grid::gridSize() {
	return Vec3(contents.size(), contents[0].size(), contents[0][0].size());
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