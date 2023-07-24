#include "Block.h"

Block::Block()
{
	m_CellSize = 30;
	m_RotationState = 0;
	m_Colors = GetCellColors();
	m_RowOffset = 0;
	m_ColOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
	std::vector<Position> tiles = GetCellPositions();
	for (auto& tile : tiles) {
		RRectangle(tile.col * (float)m_CellSize + offsetX, tile.row * (float)m_CellSize + offsetY, (float)m_CellSize - 1, (float)m_CellSize - 1)
			.Draw(m_Colors[m_id]);
	}
}

void Block::Move(int rows, int cols) {
	m_RowOffset += rows;
	m_ColOffset += cols;
}

void Block::Rotate()
{
	m_RotationState++;
	if (m_RotationState == (int)m_Cells.size()) {
		m_RotationState = 0;
	}
}

void Block::UndoRotation()
{
	m_RotationState--;
	if (m_RotationState == -1) {
		m_RotationState = (int)m_Cells.size() - 1;
	}
}

std::vector<Position> Block::GetCellPositions()
{
	std::vector<Position> tiles = m_Cells[m_RotationState];
	std::vector<Position> movedTiles;
	for (Position& tile : tiles) {
		movedTiles.push_back(Position(tile.row + m_RowOffset, tile.col + m_ColOffset));
	}
	return movedTiles;
}

