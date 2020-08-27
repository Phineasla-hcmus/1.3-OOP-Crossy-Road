#ifndef _iofile
#define _iofile
#include<string>
#include<vector>
#include<fstream>
#include"no_copy.h"
//Contain file texture name and it size, load from file
class textureSet {
private:
	struct texture_inf {
		const std::string&	file_name;
		const std::string&	file_ext;
		unsigned			texture_height;
		unsigned			texture_width;
		texture_inf(const std::string& name, const std::string& ext, unsigned width, unsigned height);
	};
	std::vector<texture_inf> m_set;
public:
	bool				loadFromFile(const std::string&);
	size_t				size() const;
	const std::string&	getName(size_t) const;
	const std::string&	getExt(size_t)	const;
	unsigned			getWidth(size_t) const;
	std::pair<const std::string&, unsigned> getAttribute(size_t) const;
};
//Contain multiple file names of multiple texture objects
class textureLookup : public no_copy {
private:
	std::vector<textureSet> m_set;
public:
	bool					loadNewSet(const std::string& file_dir);
	size_t					size() const;
	const textureSet&	getSet(size_t idx) const;
};
template<typename T>
struct limit {
	T min = 0, max = 0;
};
class lane_inf {
private:
	limit<float> m_speed;
	limit<unsigned> m_obstacle;
public:
	lane_inf(float minSpeed, float maxSpeed, unsigned minObst, unsigned maxObst);
	limit<float> speed();
	limit<unsigned> obstacle();
};
class config_file : public no_copy {
private:
	std::vector<lane_inf> m_level;
public: 
	const lane_inf& level(size_t);
	bool loadFromFile(const std::string&);
};
#endif // !_iofile
