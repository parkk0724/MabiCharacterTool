#pragma once

class Pyramid;
class Grid
{
public:
	Grid();
	~Grid();

private:
	vector<ST_PC_VERTEX> vertex_;
	vector<Pyramid*> pyramid_;
public:
	void Setup(int nNumHalfTile = 15, float fInterval = 1.0f);
	void Render();
};

