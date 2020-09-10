#ifndef _music_manager
#define _music_manager
#include<string>
#include<vector>
#include<SFML/Audio.hpp>
constexpr auto MUSIC_DIR = "Assets/audio/";

class playlist {
private:
	sf::Music m_track;
	std::vector<std::string> m_queue;
	size_t m_cur_track = 0;
	bool m_repeat = true;
public:
	sf::Music& cur_track();
	void add(const std::string& file_name);
	void set_repeat(bool);
	bool is_repeat() const;
	std::string cur_track_name() const;
	size_t size() const;
};
#endif // !_music_manager
