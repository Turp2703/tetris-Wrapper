#pragma once

#include "Grid.h"
#include "Blocks.cpp"

class Game
{
public:
	Game();
	~Game();
	void Draw();
	void HandleInput();
	void MoveBlockDown();


	bool m_GameOver;
	int m_Score;

private:
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	bool IsBlockOutside();
	void MoveBlockLeft();
	void MoveBlockRight();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesCleared, int movedDown);

	Grid m_Grid;
	std::vector<Block> blocks;
	Block m_CurrentBlock;
	Block m_NextBlock;
	//RSound m_RotateSound;
	//RSound m_ClearSound;
};