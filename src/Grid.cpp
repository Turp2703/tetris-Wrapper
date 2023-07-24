#include "Grid.h"
#include <iostream>
#include "Colors.h"
#include "Position.h"

Grid::Grid()
{
	m_Rows = 20;
	m_Cols = 10;
	m_CellSize = 30;
	Initialize();
	m_Colors = GetCellColors();
}

void Grid::Initialize()
{
	for (int row = 0; row < m_Rows; row++) {
		for (int col = 0; col < m_Cols; col++) {
			grid[row][col] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < m_Rows; row++) {
		for (int col = 0; col < m_Cols; col++) {
			std::cout << grid[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

void Grid::Draw()
{
	for (int row = 0; row < m_Rows; row++) {
		for (int col = 0; col < m_Cols; col++) {
			RRectangle(col * (float)m_CellSize + 11, row * (float)m_CellSize + 11, (float)m_CellSize - 1, (float)m_CellSize - 1)
				.Draw(m_Colors[grid[row][col]]);
		}
	}
}

bool Grid::IsCellOutside(int row, int col)
{
	if (row < 0) { return true; }
	if (row >= m_Rows) { return true; }
	if (col < 0) { return true; }
	if (col >= m_Cols) { return true; }
	return false;
}

bool Grid::IsCellEmpty(int row, int col)
{
	return grid[row][col] == 0;
}

int Grid::ClearFullRows()
{
	int completed = 0;
	for (int row = m_Rows - 1; row >= 0; row--) {
		if (IsRowFull(row)) {
			ClearRow(row);
			completed++;
		}
		else if (completed > 0) {
			MoveRowDown(row, completed);
		}
	}
	return completed;
}

bool Grid::IsRowFull(int row)
{
	for (int col = 0; col < m_Cols; col++) {
		if (grid[row][col] == 0) { return false; }
	}
	return true;
}

void Grid::ClearRow(int row)
{
	for (int col = 0; col < m_Cols; col++) {
		grid[row][col] = 0;
	}
}

void Grid::MoveRowDown(int row, int numRows)
{
	for (int col = 0; col < m_Cols; col++) {
		grid[row+numRows][col] = grid[row][col];
		grid[row][col] = 0;
	}
}
