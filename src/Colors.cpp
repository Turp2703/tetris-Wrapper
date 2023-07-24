#include "Colors.h"

const RColor darkGrey = { 26, 31, 40, 255 };
const RColor green = { 47, 230, 23, 255 };
const RColor red = { 232, 18, 18, 255 };
const RColor orange = { 226, 116, 17, 255 };
const RColor yellow = { 237, 234, 4, 255 };
const RColor purple = { 166, 0, 247, 255 };
const RColor cyan = { 21, 204, 209, 255 };
const RColor blue = { 13, 64, 216, 255 };
const RColor lightBlue = { 59, 85, 162, 255 };
const RColor darkBlue = { 44, 44, 127, 255 };

std::vector<RColor> GetCellColors() {
	return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}