#include "state_load.h"
#include"../../Framework/game.h"
SaveInf::SaveInf(unsigned level, unsigned score, const std::array<int, save_lane>& lane_type, const std::array<float, save_lane>& lane_speed)
	: m_level(level)
	, m_score(score)
	, m_speed(lane_speed)
	, m_type(lane_type)
{}
SaveInf::SaveInf(const SaveInf& b) {
	m_level = b.m_level;
	m_score = b.m_score;
	m_speed = b.m_speed;
	m_type = b.m_type;
}
unsigned SaveInf::get_level() const
{
	return m_level;
}

unsigned SaveInf::get_score() const
{
	return m_score;
}

float SaveInf::get_speed(size_t idx) const
{
	return m_speed.at(idx);
}

int SaveInf::get_type(size_t idx) const
{
	return m_type.at(idx);
}

state_load::state_load(Game& game)
	: state_base(game),
	load_menu(game.get_window(),300)
{

}

void state_load::handleEvent(sf::Event e)
{
	load_menu.handleEvent(e, this->game().get_window());
}

void state_load::update(sf::Time delta_time)
{
}

void state_load::draw(sf::RenderTarget& renderer)
{
}

