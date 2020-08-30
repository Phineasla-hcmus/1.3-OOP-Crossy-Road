#include "SaveLevel.h"
SaveInf::SaveInf(unsigned level, unsigned score, std::array<RoadInf, SAVE_LANE> roads)
	: m_level(level)
	, m_score(score)
	, m_road_arr(roads)
{}

unsigned SaveInf::get_level() const
{
	return m_level;
}

unsigned SaveInf::get_score() const
{
	return m_score;
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

void SaveInf::update_road(std::array<RoadInf, SAVE_LANE> new_roads)
{
	m_road_arr = new_roads;
}

bool saveGame(std::string& file_name, const SaveInf& save)
{
	std::ofstream fout(SAVE_DIR + file_name + FILE_EXT, std::ios::binary);
	if (!fout.is_open())
		return false;
	unsigned lv = save.get_level(), score = save.get_score();
	fout.write((char*)&lv, sizeof(save.get_level()));
	fout.write((char*)&score, sizeof(save.get_score()));
	fout.write((char*)&save.get_RoadInf(0), sizeof(SaveInf::RoadInf) * SAVE_LANE);
	fout.close();
	return true;
}

bool loadGame(std::string file_name, SaveInf& save)
{
	std::ifstream fin(SAVE_DIR + file_name + FILE_EXT, std::ios::binary);
	if (!fin.is_open())
		return false;
	std::array<SaveInf::RoadInf, SAVE_LANE> lanes;
	unsigned lv, score;
	fin.read((char*)&lv, sizeof(lv));
	fin.read((char*)&score, sizeof(score));
	fin.read((char*)&lanes[0], sizeof(SaveInf::RoadInf) * SAVE_LANE);
	save = SaveInf(lv, score, lanes);
	fin.close();
	return true;
}
