#ifndef _resource_manager
#define _resource_manager
#include<string>
#include<unordered_map>
#include<SFML/Graphics.hpp>
#define DEFAULT_FOLDER_DIR "resourse/"
#define FAILED_FILE_NAME "FAILED"
template<typename Resource_t>
class res_manager
{
private:
	const std::string							_folder_dir;
	std::unordered_map<std::string, Resource_t> res_storage;
	std::string	file_dir	(const std::string& full_name);
	std::string full_name	(const std::string& name, const std::string& ext);
	void load_file			(const std::string& name, const std::string& ext);
public:
	res_manager				(const std::string& folder_name);
	const Resource_t& get	(const std::string& name, const std::string& ext);
};

template<typename Resource_t>
std::string res_manager<Resource_t>::file_dir(const std::string& full_name) {
	return _folder_dir + full_name;
}
template<typename Resource_t>
std::string res_manager<Resource_t>::full_name(const std::string& name, const std::string& ext) {
	return name + "." + ext;
}
template<typename Resource_t>
void res_manager<Resource_t>::load_file(const std::string& name, const std::string& ext) {
	Resource_t res;
	const std::string name_with_ext = full_name(name, ext);
	if (res.loadFromFile(file_dir(name_with_ext)) == 0) {
		//load placeholder if file not found
		res.loadFromFile(file_dir(full_name(FAILED_FILE_NAME, ext)));
	}
	res_storage.insert(std::make_pair(name_with_ext, res));
}

template<typename Resource_t>
res_manager<Resource_t>::res_manager(const std::string& folder_name)
	: _folder_dir(DEFAULT_FOLDER_DIR + folder_name + "/")
{}
template<typename Resource_t>
const Resource_t& res_manager<Resource_t>::get(const std::string& name, const std::string& ext) {
	std::string fullName = full_name(name, ext);
	//find resource
	auto found = res_storage.find(fullName);
	if (found != res_storage.end())
		return found->second;
	//not found, load from file
	else {
		load_file(name, ext);
		return res_storage.at(fullName);
	}
}
#endif // !_resource_manager