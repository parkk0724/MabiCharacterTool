#pragma once
class Pyramid
{
public:
	Pyramid();
	~Pyramid();
private:
	std::vector<ST_PC_VERTEX> vertex_;
	D3DXMATRIXA16 matR_;
public:
	void Setup(D3DCOLOR c, D3DXMATRIXA16 & mat);
	void Render();
};