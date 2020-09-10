#include"playlist.h"

sf::Music& playlist::cur_track()
{
	return m_track;
}

void playlist::add(const std::string& file_name)
{
	m_queue.push_back(file_name);
}

void playlist::set_repeat(bool repeat)
{
	m_repeat = repeat;
}

bool playlist::is_repeat() const
{
	return m_repeat;
}

std::string playlist::cur_track_name() const
{
	return m_queue[m_cur_track];
}

size_t playlist::size() const
{
	return m_queue.size();
}
