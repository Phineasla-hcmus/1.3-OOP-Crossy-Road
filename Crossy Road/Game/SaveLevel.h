#ifndef _save_level
#define _save_level
#include "../PCH.h"
constexpr auto save_lane = 4;
class SaveInf {
public:
	struct RoadInf {
		int		m_type;		//vehicle type
		int		m_dir;		//direction
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
	unsigned						m_level = 1;
	unsigned						m_score = 0;
	std::array<RoadInf, save_lane>	m_road_arr;
};
#endif // !_save_level
