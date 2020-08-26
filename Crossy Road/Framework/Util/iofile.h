#ifndef _iofile
#define _iofile
#include<string>
#include<vector>
#include<fstream>
#include"no_copy.h"
//Contain file texture name and it size, load from file
class texture_lookup : public no_copy {
private:
	struct texture_attribute {
		std::string file_name;
		unsigned	texture_width;
		texture_attribute(std::string name, unsigned width);
	};
	std::vector<texture_attribute> m_bucket;
public:
	bool				loadFromFile(const std::string&);
	const std::string&	getFileName(size_t) const;
	unsigned			getWidth(size_t) const;
	std::pair<const std::string&, unsigned> getAttribute(size_t) const;
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
