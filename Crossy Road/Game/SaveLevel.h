#ifndef _save_level
#define _save_level
#include "../PCH.h"
constexpr auto SAVE_LANE = 4;
constexpr auto SAVE_DIR = "Save/";
constexpr auto HIGHSCORE_DIR = "Highscore/";
constexpr auto FILE_EXT = ".bin";
class SaveInf {
public:
	struct RoadInf {
		int		vehicleType;		//vehicle type
		int		vehicleNum;
		int		direction;			//direction
		float	speed;
		RoadInf() = default;
		RoadInf(int vehicleType, int vehicleNum, int dir, float speed);
	};
	SaveInf() = default;
	SaveInf(int,unsigned level, unsigned score, std::vector<RoadInf> roads,sf::Vector2f);
	unsigned	get_level() const;
	unsigned	get_score() const;
	unsigned	get_size()	const;
	int			getBestLane() const;
	sf::Vector2f get_position() const;
	const RoadInf& get_RoadInf(size_t)	const;
	void		update_score(unsigned);
	void		update_level(unsigned);
	void		update_road(std::vector<RoadInf> new_roads);
	void		update_position(sf::Vector2f);
	void		update_Y(int);
private:
	unsigned						m_level = 1;
	unsigned						m_score = 0;
	int								m_y=7;
	std::vector<RoadInf>			m_road_arr;
	sf::Vector2f                    m_position = {640,630};
};
bool saveGame(std::string& file_name, const SaveInf&);
bool loadGame(std::string file_name, SaveInf&);
bool loadHighScore(int& highscore);
bool saveHighScore(const int& highscore);
#endif 
