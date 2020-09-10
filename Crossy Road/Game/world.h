#ifndef _World_h
#define _World_h
#include"../PCH.h"
#include"Entity/Player.h"
#include"Entity/Road.h"
#include "SaveLevel.h"
constexpr auto AMBIENT_DIR	= "Assets/audio/ambient.ogg";
constexpr auto AMBIENT_VOL	= 100;
constexpr auto MUSIC_DIR	= "Assets/audio/background.ogg";
constexpr auto MUSIC_VOL	= 20;
class World {
private:
	sf::Music				m_ambient;
	sf::Music				m_music;
	Player					m_player;
	std::vector<Lane>		m_lanes;
	TileMap					m_background;
	const textureLookup&	m_vehicle_set;//collection of texture use for vehicle
	bool					m_game_over = false;
	int						m_best_lane = Y_TILES - 1;//the highest lane player walked on in a level (the lowest y pos)
public:
	World(const textureLookup&);
	void initLane(const SaveInf&);
	void resetWorld(const SaveInf&);
	void draw(sf::RenderTarget& target);
	void input();
	void update(float dt);
	bool tryPlayerCollideWith();
	bool updateScore();
	unsigned updateLevel();
	bool is_game_over();
	void pause();
};
bool initMusic(sf::Music&, const std::string& dir, float volume = 100, bool loop = true);
#endif // !_World_h
