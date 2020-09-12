#include "SaveLevel.h"
SaveInf::SaveInf(int max_y, unsigned level, unsigned score, std::vector<RoadInf> roads, sf::Vector2f position)
	: m_level(level)
	, m_score(score)
	, m_road_arr(roads)
	, m_position(position)
	, m_y(max_y)
{}
sf::Vector2f  SaveInf::get_position() const 
{
	return m_position;
}
unsigned SaveInf::get_level() const
{
	return m_level;
}
int SaveInf::getBestLane() const
{
	return m_y;
}
unsigned SaveInf::get_score() const
{
	return m_score;
}

unsigned SaveInf::get_size() const
{
	return m_road_arr.size();
}

const SaveInf::RoadInf& SaveInf::get_RoadInf(size_t idx) const
{
	return m_road_arr.at(idx);
}

void SaveInf::update_score(unsigned new_score)
{
	m_score = new_score;
}

void SaveInf::update_level(unsigned level)
{
	m_level = level;
}

void SaveInf::update_road(std::vector<RoadInf> new_roads)
{
	m_road_arr = new_roads;
}

void SaveInf::update_position(sf::Vector2f position)
{
	m_position = position;
}
void SaveInf::update_Y(int maxY)
{
	m_y = maxY;
}
bool saveGame(std::string& file_name, const SaveInf& save)
{
	std::ofstream fout(SAVE_DIR + file_name + FILE_EXT, std::ios::binary);
	if (!fout.is_open())
		return false;
	unsigned lv = save.get_level(), score = save.get_score(), size = save.get_size();
	int maxY = save.getBestLane();
	sf::Vector2f posittion = save.get_position();
	fout.write((char*)&lv, sizeof(lv));
	fout.write((char*)&score, sizeof(score));
	fout.write((char*)&size, sizeof(size));
	//fout.write((char*)&posittion, sizeof(posittion));
	fout.write((char*)&maxY, sizeof(maxY));
	fout.write((char*)&save.get_RoadInf(0), (long long)size * sizeof(SaveInf::RoadInf));
	fout.close();
	return true;
}

bool loadGame(std::string file_name, SaveInf& save)
{
	std::ifstream fin(SAVE_DIR + file_name + FILE_EXT, std::ios::binary);
	if (!fin.is_open())
		return false;
	unsigned lv, score, size;
	int maxY;
	sf::Vector2f position;
	fin.read((char*)&lv, sizeof(lv));
	fin.read((char*)&score, sizeof(score));
	fin.read((char*)&size, sizeof(size));
	//fin.read((char*)&position, sizeof(position));
	fin.read((char*)&maxY, sizeof(maxY));
	std::vector<SaveInf::RoadInf> lanes(size);
	fin.read((char*)&lanes[0], (long long)size * sizeof(SaveInf::RoadInf));
	save = SaveInf(maxY,lv, score, lanes,position);
	fin.close();
	return true;
}
bool loadHighScore(int& highscore) {
	std::string filename = "highscore";
	std::ifstream fin(HIGHSCORE_DIR + filename + FILE_EXT, std::ios::binary);
	if (!fin.is_open())return false;
	fin.read((char*)&highscore, sizeof(int));
	fin.close();
	return true;
}
bool saveHighScore(const int& highscore) {
	std::string filename = "highscore";
	std::ofstream fout(HIGHSCORE_DIR + filename + FILE_EXT, std::ios::binary);
	if (!fout.is_open())return false;
	fout.write((char*)&highscore, sizeof(int));
	fout.close();
	return true;
}

SaveInf::RoadInf::RoadInf(int vehicleType, int vehicleNum, int dir, float speed)
	: vehicleType(vehicleType)
	, vehicleNum(vehicleNum)
	, direction(dir)
	, speed(speed)
{}
