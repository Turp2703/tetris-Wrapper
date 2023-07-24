#pragma once

#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"

class Block
{
public:
	Block();
	void Draw(int offsetX, int offsetY);
	void Move(int rows, int cols);
	void Rotate();
	void UndoRotation();
	std::vector<Position> GetCellPositions();

	int m_id;
	std::map<int, std::vector<Position>> m_Cells;

private:
	int m_CellSize;
	int m_RotationState;
	std::vector<RColor> m_Colors;
	int m_RowOffset;
	int m_ColOffset;
};