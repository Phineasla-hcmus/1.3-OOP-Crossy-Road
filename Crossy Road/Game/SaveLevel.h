#ifndef _save_level
#define _save_level
#include "../PCH.h"
constexpr auto SAVE_LANE = 4;
constexpr auto SAVE_DIR = "Save/";
constexpr auto FILE_EXT = ".bin";
class SaveInf {
public:
	struct RoadInf {
		int		vehicleType;		//vehicle type
		int		vehicleNum;
		int		direction;			//direction
		float	speed;
	};
	SaveInf();
	SaveInf(unsigned level, unsigned score, std::array<RoadInf, SAVE_LANE> roads);
	unsigned	get_level() const;
	unsigned	get_score() const;
	const RoadInf& get_RoadInf(size_t)	const;
	void		update_score(unsigned);
	void		update_level(unsigned);
	void		update_road(std::array<RoadInf, SAVE_LANE> new_roads);
private:
	unsigned						m_level = 1;
	unsigned						m_score = 0;
	std::array<RoadInf, SAVE_LANE>	m_road_arr;
};
bool saveGame(std::string& file_name, const SaveInf&);
bool loadGame(std::string file_name, SaveInf&);
#endif // !_save_level
