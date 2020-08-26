#include "iofile.h"

bool texture_lookup::loadFromFile(const std::string& dir)
{
	std::ifstream fin(dir);
	if (!fin)
		return false;
	std::string file_name;
	unsigned	width;
	while (fin >> file_name >> width) {
		m_bucket.emplace_back(texture_attribute(file_name, width));
	}
	fin.close();
	return true;
}

size_t texture_lookup::size() const
{
	return m_bucket.size();
}

const std::string& texture_lookup::getFileName(size_t idx) const
{
	return m_bucket[idx].file_name;
}

unsigned texture_lookup::getWidth(size_t idx) const
{
	return m_bucket[idx].texture_width;
}

std::pair<const std::string&, unsigned> texture_lookup::getAttribute(size_t idx) const
{
	return std::make_pair<const std::string&, unsigned>(getFileName(idx), getWidth(idx));
}

texture_lookup::texture_attribute::texture_attribute(std::string name, unsigned width)
	:file_name(name)
	,texture_width(width)
{}

lane_inf::lane_inf(float minSpeed, float maxSpeed, unsigned minObst, unsigned maxObst)
	: m_speed({minSpeed,maxSpeed})
	, m_obstacle({minObst,maxObst})
{}

limit<float> lane_inf::speed()
{
	return m_speed;
}

limit<unsigned> lane_inf::obstacle()
{
	return m_obstacle;
}

const lane_inf& config_file::level(size_t idx)
{
	return m_level[idx];
}

bool config_file::loadFromFile(const std::string& dir)
{
	std::ifstream fin(dir);
	if (!fin)
		return false;
	float minSpeed, maxSpeed;
	int level, minObst, maxObst;
	while (fin >> level >> minSpeed >> maxSpeed >> minObst >> maxObst) {
		m_level.emplace_back(lane_inf(minSpeed, maxSpeed, minObst, maxObst));
	}
	fin.close();
	return true;
}

bool texture_set::loadNewSet(const std::string& file_dir)
{
	texture_lookup lookup;
	if (!lookup.loadFromFile(file_dir))
		return false;
	m_set.emplace_back(lookup);
	return true;
}

size_t texture_set::size() const
{
	return m_set.size();
}

const texture_lookup& texture_set::getSet(size_t idx) const
{
	return m_set[idx];
}
