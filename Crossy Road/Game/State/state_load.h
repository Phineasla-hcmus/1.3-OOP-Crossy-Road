#ifndef _state_load_h
#define _state_load_h
#include<array>
#include"../../Framework/State/state_base.h"
#include"../../Framework/GUI/button.h"
#include"../../Framework/GUI/StackMenu.h"
#include"../../Framework/AssetManager/asset.h"
constexpr auto save_lane = 4;
class SaveInf {
private:
	unsigned						m_level;
	unsigned						m_score;
	std::array<float, save_lane>	m_speed;
	std::array<int, save_lane>		m_type;
public:
	SaveInf() = default;
	SaveInf(unsigned level, unsigned score, 
		const std::array<int, save_lane>& lane_type, const std::array<float, save_lane>& lane_speed);
	unsigned	get_level() const;
	unsigned	get_score() const;
	float		get_speed(size_t);
	int			get_type(size_t);
};
////menu->load(m_change=stateplaying)
////menu->load<->m_change
////menu->stateplaying
//
////menu->stateplaying->load
////menu->stateplaying->load(m_change=stateplaying)
////menu->stateplaying->(popped)
////menu->stateplaying<->m_change
////menu->NEW_stateplaying
//class state_load :public state_base {
//public:
//	bool isLoadFromMainMenu() {
//		return (game().m_states.size() == 2);
//	}
//	void loadFile() {
//		if (isLoadFromMainMenu())
//			game().swapState(std::make_unique<state_playing>(game, SaveInf));
//		else {
//			game().PopState();
//			game().swapState(std::make_unique<state_playing>(game, SaveInf));
//		}
//	}
//};
#endif // !_state_load_h