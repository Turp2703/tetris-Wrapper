#include "Block.h"
#include "Position.h"

class LBlock : public Block {
public:
	LBlock() {
		m_id = 1;
		m_Cells[0] = { Position(0,2),Position(1,0),Position(1,1),Position(1,2) };
		m_Cells[1] = { Position(0,1),Position(1,1),Position(2,1),Position(2,2) };
		m_Cells[2] = { Position(1,0),Position(1,1),Position(1,2),Position(2,0) };
		m_Cells[3] = { Position(0,0),Position(0,1),Position(1,1),Position(2,1) };
		Move(0, 3);
	}
};
class JBlock : public Block {
public:
	JBlock() {
		m_id = 2;
		m_Cells[0] = { Position(0,0),Position(1,0),Position(1,1),Position(1,2) };
		m_Cells[1] = { Position(0,1),Position(0,2),Position(1,1),Position(2,1) };
		m_Cells[2] = { Position(1,0),Position(1,1),Position(1,2),Position(2,2) };
		m_Cells[3] = { Position(0,1),Position(1,1),Position(2,0),Position(2,1) };
		Move(0, 3);
	}
};
class IBlock : public Block {
public:
	IBlock() {
		m_id = 3;
		m_Cells[0] = { Position(1,0),Position(1,1),Position(1,2),Position(1,3) };
		m_Cells[1] = { Position(0,2),Position(1,2),Position(2,2),Position(3,2) };
		m_Cells[2] = { Position(2,0),Position(2,1),Position(2,2),Position(2,3) };
		m_Cells[3] = { Position(0,1),Position(1,1),Position(2,1),Position(3,1) };
		Move(-1, 3);
	}
};
class OBlock : public Block {
public:
	OBlock() {
		m_id = 4;
		m_Cells[0] = { Position(0,0),Position(0,1),Position(1,0),Position(1,1) };
		Move(0, 4);
	}
};
class SBlock : public Block {
public:
	SBlock() {
		m_id = 5;
		m_Cells[0] = { Position(0,1),Position(0,2),Position(1,0),Position(1,1) };
		m_Cells[1] = { Position(0,1),Position(1,1),Position(1,2),Position(2,2) };
		m_Cells[2] = { Position(1,1),Position(1,2),Position(2,0),Position(2,1) };
		m_Cells[3] = { Position(0,0),Position(1,0),Position(1,1),Position(2,1) };
		Move(0, 3);
	}
};
class TBlock : public Block {
public:
	TBlock() {
		m_id = 6;
		m_Cells[0] = { Position(0,1),Position(1,0),Position(1,1),Position(1,2) };
		m_Cells[1] = { Position(0,1),Position(1,1),Position(1,2),Position(2,1) };
		m_Cells[2] = { Position(1,0),Position(1,1),Position(1,2),Position(2,1) };
		m_Cells[3] = { Position(0,1),Position(1,0),Position(1,1),Position(2,1) };
		Move(0, 3);
	}
};
class ZBlock : public Block {
public:
	ZBlock() {
		m_id = 7;
		m_Cells[0] = { Position(0,0),Position(0,1),Position(1,1),Position(1,2) };
		m_Cells[1] = { Position(0,2),Position(1,1),Position(1,2),Position(2,1) };
		m_Cells[2] = { Position(1,0),Position(1,1),Position(2,1),Position(2,2) };
		m_Cells[3] = { Position(0,1),Position(1,0),Position(1,1),Position(2,0) };
		Move(0, 3);
	}
};