#include "SaveLevel.h"
SaveInf::SaveInf(unsigned level, unsigned score, std::array<RoadInf, save_lane> roads)
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

float SaveInf::get_speed(size_t idx) const
{
	return m_road_arr.at(idx).m_speed;
}

int SaveInf::get_type(size_t idx) const
{
	return m_road_arr.at(idx).m_type;
}

int SaveInf::get_dir(size_t idx) const
{
	return m_road_arr.at(idx).m_dir;
}

const SaveInf::RoadInf& SaveInf::get_road_inf(size_t idx) const
{
	return m_road_arr.at(idx);
}

void SaveInf::update_score(unsigned new_score)
{
	m_score = new_score;
}