#include "io_config.h"

bool textureSet::loadFromFile(const std::string& dir)
{
	std::ifstream fin(dir);
	if (!fin)
		return false;
	std::string file_name, file_ext;
	unsigned	width, height;
	while (fin >> file_name >> file_ext >> width >> height) {
		m_set.emplace_back(texture_inf(file_name, file_ext, width, height));
	}
	fin.close();
	return true;
}

size_t textureSet::size() const
{
	return m_set.size();
}

const std::string& textureSet::getName(size_t idx) const
{
	return m_set[idx].file_name;
}

const std::string& textureSet::getExt(size_t idx) const
{
	return m_set[idx].file_ext;
}

unsigned textureSet::getWidth(size_t idx) const
{
	return m_set[idx].texture_width;
}

std::pair<const std::string&, unsigned> textureSet::getAttribute(size_t idx) const
{
	return std::make_pair<const std::string&, unsigned>(getName(idx), getWidth(idx));
}
textureSet::texture_inf::texture_inf(const std::string& name, const std::string& ext, unsigned width, unsigned height)
	: file_name(name)
	, file_ext(ext)
	, texture_height(height)
	, texture_width(width)
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

bool textureLookup::loadNewSet(const std::string& file_dir)
{
	textureSet lookup;
	if (!lookup.loadFromFile(file_dir))
		return false;
	m_set.emplace_back(lookup);
	return true;
}

size_t textureLookup::size() const
{
	return m_set.size();
}

const textureSet& textureLookup::getSet(size_t idx) const
{
	return m_set[idx];
}
