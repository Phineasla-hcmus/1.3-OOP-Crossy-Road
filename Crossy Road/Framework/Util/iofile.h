#ifndef _iofile
#define _iofile
#include<string>
#include<vector>
#include<fstream>
#include"no_copy.h"
//Contain file texture name and it size, load from file
class texture_lookup : public no_copy {
private:
	class texture_attribute {
		std::string file_name;
		unsigned	texture_width;
	};
	std::vector<texture_attribute> bucket;
public:
	bool loadFromFile(const std::string&);
};
#endif // !_iofile
