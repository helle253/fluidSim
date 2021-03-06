#pragma once
#include "Cell.h"
#include "Vec3.h"
#include <vector>
class Grid
{
public:
	Grid();
	Grid(int x, int y, int z);
	Grid(Vec3 size);
	~Grid();

	int getTallCellHeight(int x, int z) const;
	int getTallCellHeight(Vec3 v) const;
	int getTerrainHeight(int x, int z) const;
	int getTerrainHeight(Vec3 v) const;

	void setTallCellHeight(int x, int z, int h);
	void setTallCellHeight(Vec3 v, int h);
	void setTerrainHeight(int x, int z, int h);
	void setTerrainHeight(Vec3 v, int h);

	Cell getCellValue(Vec3 subCell);
	void extrapolateVelocity(float deltaTime);

	//returns the # size of the contents array in subcell units.
	Vec3 gridSize();

	std::vector<Grid> coarsen(std::vector<Grid> grids, int L);
	std::vector<Grid> coarsen();

protected:
	std::vector<std::vector<std::vector<Cell>>> contents;
	std::vector<std::vector<int>> tallCellHeights;
	std::vector<std::vector<int>> terrainHeights;
	int xMax;
	int yMax;
	int zMax;
};

