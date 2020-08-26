#include "iofile.h"

bool texture_lookup::loadFromFile(const std::string& dir)
{
	std::ifstream fin(dir);
	if (!fin)
		return false;

}
