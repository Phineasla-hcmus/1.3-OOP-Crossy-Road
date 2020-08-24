#include "state_load.h"

SaveInf::SaveInf(unsigned level, unsigned score, const std::array<int, save_lane>& lane_type, const std::array<float, save_lane>& lane_speed)
	: m_level(level)
	, m_score(score)
	, m_speed(lane_speed)
	, m_type(lane_type)
{}

unsigned SaveInf::get_level() const
{
	return m_level;
}

unsigned SaveInf::get_score() const
{
	return m_score;
}

float SaveInf::get_speed(size_t idx)
{
	return m_speed.at(idx);
}

int SaveInf::get_type(size_t idx)
{
	return m_type.at(idx);
}
