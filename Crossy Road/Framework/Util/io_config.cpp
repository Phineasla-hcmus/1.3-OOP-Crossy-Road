#include "io_config.h"

bool textureSet::loadFromFile(const std::string& dir)
{
	std::ifstream fin(dir);
	if (!fin)
		return false;
	std::string file_name, file_ext;
	sf::Vector2u size, file_dim;
	while (fin >> file_name >> file_ext 
		>> size.x >> size.y >> file_dim.x >> file_dim.y) 
	{
		m_set.emplace_back(textureInf(file_name, file_ext, size, file_dim));
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
	return m_set[idx].name;
}

const std::string& textureSet::getExt(size_t idx) const
{
	return m_set[idx].ext;
}

const textureInf& textureSet::getFullInf(size_t idx) const
{
	return m_set[idx];
}

textureInf::textureInf(const std::string& name, const std::string& ext, sf::Vector2u size, sf::Vector2u fileDimension)
	: name(name)
	, ext(ext)
	, size(size)
	, fileDim(fileDimension)
{}

sf::IntRect textureInf::getBounds(size_t idx) const
{
	int tu = idx % (fileDim.x / size.x);
	int tv = idx / (fileDim.x / size.x);
	return sf::IntRect(sf::Vector2i(tu * size.x, tv * size.y), sf::Vector2i(size));
}

size_t textureInf::numTexture()
{
	return (fileDim.x / size.x) * (fileDim.y / size.y);
}

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
