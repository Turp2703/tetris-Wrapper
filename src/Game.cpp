#include <random>
#include "Game.h"

Game::Game()
{
	m_Grid = Grid();
	blocks = GetAllBlocks();
	m_CurrentBlock = GetRandomBlock();
	m_NextBlock = GetRandomBlock();
	m_GameOver = false;
	m_Score = 0;
	//InitAudioDevice();
	//m_RotateSound.Load("assets/rotate.mp3");
	//m_ClearSound.Load("assets/clear.mp3");
}

Game::~Game()
{
	CloseAudioDevice();
}

void Game::Draw()
{
	m_Grid.Draw();
	m_CurrentBlock.Draw(11,11);
	switch (m_NextBlock.m_id) {
		case 3: m_NextBlock.Draw(255, 290); break;
		case 4: m_NextBlock.Draw(255, 280); break;
		default: m_NextBlock.Draw(270, 270); break;
	}
}

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();
	if (m_GameOver && keyPressed != 0) {
		m_GameOver = false;
		Reset();
	}
	switch (keyPressed) {
		case KEY_LEFT: MoveBlockLeft(); break;
		case KEY_RIGHT: MoveBlockRight(); break;
		case KEY_DOWN: MoveBlockDown(); UpdateScore(0, 1); break;
		case KEY_UP: RotateBlock(); break;
	}
}

void Game::MoveBlockLeft()
{
	if (!m_GameOver)
	{
		m_CurrentBlock.Move(0, -1);
		if (IsBlockOutside() || !BlockFits()) {
			m_CurrentBlock.Move(0, 1);
		}
	}
}

void Game::MoveBlockRight()
{
	if (!m_GameOver)
	{
		m_CurrentBlock.Move(0, 1);
		if (IsBlockOutside() || !BlockFits()) {
			m_CurrentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown()
{
	if (!m_GameOver)
	{
		m_CurrentBlock.Move(1, 0);
		if (IsBlockOutside() || !BlockFits()) {
			m_CurrentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

void Game::RotateBlock()
{
	m_CurrentBlock.Rotate();
	if (IsBlockOutside() || !BlockFits()) {
		m_CurrentBlock.UndoRotation();
	}
	//else {
	//	m_RotateSound.Play();
	//}
}

void Game::LockBlock()
{
	for (Position& tile : m_CurrentBlock.GetCellPositions()) {
		m_Grid.grid[tile.row][tile.col] = m_CurrentBlock.m_id;
	}
	m_CurrentBlock = m_NextBlock;
	if (!BlockFits()) { m_GameOver = true; }
	m_NextBlock = GetRandomBlock();
	int rowsCleared = m_Grid.ClearFullRows();
	if (rowsCleared > 0) {
		//m_ClearSound.Play(); 
		UpdateScore(rowsCleared, 0);
	}
}

bool Game::BlockFits()
{
	for (Position& tile : m_CurrentBlock.GetCellPositions()) {
		if (!m_Grid.IsCellEmpty(tile.row, tile.col)) { return false; }
	}
	return true;
	//std::any_of(tiles.begin(), tiles.end(), m_Grid.IsCellEmpty());
}

void Game::Reset()
{
	m_Grid.Initialize();
	blocks = GetAllBlocks();
	m_CurrentBlock = GetRandomBlock();
	m_NextBlock = GetRandomBlock();
	m_Score = 0;
}

void Game::UpdateScore(int linesCleared, int movedDownPoints)
{
	switch (linesCleared) {
		case 1: m_Score += 100; break;
		case 2: m_Score += 300; break;
		case 3: m_Score += 500; break;
		case 4: m_Score += 1000; break;
	}
	m_Score += movedDownPoints;
}

Block Game::GetRandomBlock() {
	if (blocks.empty()) { blocks = GetAllBlocks(); }
	int rndIndex = rand() % blocks.size();
	Block block = blocks[rndIndex];
	blocks.erase(blocks.begin() + rndIndex);
	return block;
}

std::vector<Block> Game::GetAllBlocks() {
	return { IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock() };
}

bool Game::IsBlockOutside()
{
	for (Position& tile : m_CurrentBlock.GetCellPositions()) {
		if (m_Grid.IsCellOutside(tile.row, tile.col)) { return true; }
	}
	return false;
}
