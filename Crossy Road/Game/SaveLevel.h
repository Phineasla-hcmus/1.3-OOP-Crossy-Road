#ifndef _save_level
#define _save_level
#include "../PCH.h"
constexpr auto save_lane = 4;
class SaveInf {
public:
	struct RoadInf {
		int		vehicleType;		//vehicle type
		int		vehicleNum;
		int		direction;			//direction
		float	speed;
	};
	SaveInf() = default;
	SaveInf(unsigned level, unsigned score, std::array<RoadInf, save_lane> roads);
	unsigned	get_level() const;
	unsigned	get_score() const;
	const RoadInf& get_RoadInf(size_t)	const;
	void		update_score(unsigned);
private:
	unsigned						m_level = 1;
	unsigned						m_score = 0;
	std::array<RoadInf, save_lane>	m_road_arr;
};
#endif // !_save_level
