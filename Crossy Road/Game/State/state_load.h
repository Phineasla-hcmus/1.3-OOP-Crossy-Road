#ifndef _state_load_h
#define _state_load_h
#include<array>
#include"../../Framework/GUI/button.h"
#include"../../Framework/GUI/StackMenu.h"
#include"../../Framework/AssetManager/asset.h"
#include"../../Framework/State/state_base.h"
constexpr auto save_lane = 4;
class SaveInf {
	public:
	struct RoadInf {
		int		m_type;
		int		m_dir;
		float	m_speed;
	};
	SaveInf() = default;
	SaveInf(unsigned level, unsigned score, std::array<RoadInf, save_lane> roads);
	unsigned	get_level() const;
	unsigned	get_score() const;
	float		get_speed(size_t)		const;
	int			get_type(size_t)		const;
	int			get_dir(size_t)			const;
	const RoadInf& get_road_inf(size_t)	const;
	void		update_score(unsigned);
private:
	unsigned						m_level;
	unsigned						m_score;
	std::array<RoadInf, save_lane>	m_road_arr;
};
//case1
//menu->load(m_change=stateplaying)
//menu->load<->m_change
//menu->stateplaying
//case2
//menu->stateplaying->load
//menu->stateplaying->load(m_change=stateplaying)
//menu->stateplaying->(popped)
//menu->stateplaying<->m_change
//menu->NEW_stateplaying
class state_load :public state_base {
private:

public:
	state_load(Game&);

	void handleEvent(sf::Event e)			override;
	void update(sf::Time delta_time)		override;
	void draw(sf::RenderTarget& renderer)	override;
};
#endif // !_state_load_h