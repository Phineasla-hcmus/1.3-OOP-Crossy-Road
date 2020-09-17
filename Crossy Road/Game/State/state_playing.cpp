#include "state_playing.h"
constexpr auto AMBIENT_DIR = "Assets/audio/ambient.ogg";
constexpr auto AMBIENT_VOL = 60;
constexpr auto MUSIC_DIR = "Assets/audio/background.ogg";
constexpr auto MUSIC_VOL = 40;
state_playing::state_playing(Game& game)
	: state_base(game)
	, m_save()
	, m_world(game.get_txr_set())
	, m_pause_menu(game)
	, m_score_display(20, "SCORE")
	, m_level_display(50, "LEVEL")
	, m_gameover(game)
{   
	m_save.update_road(randomSaveInf(1));//level 1
	m_world.initLane(m_save);

	initAmbient();
}

state_playing::state_playing(Game& game, const SaveInf& save)
	: state_base(game)
	, m_save(save)
	, m_world(game.get_txr_set(), save.getBestLane())
	, m_pause_menu(game)
	, m_score_display(20, "SCORE")
	, m_level_display(50, "LEVEL")
	, m_gameover(game)
{
	m_score = m_save.get_score();
	m_level = m_save.get_level();
	m_world.initLane(m_save);

	initAmbient();
}

void state_playing::handleEvent(sf::Event ev)
{
	if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape) {
		if (m_ambient.getStatus() == sf::Music::Playing) pauseAllSound();
		else resumeAllSound();
		m_pause_menu.changeState();
	}
	if (m_pause_menu.isPaused())
		m_pause_menu.handleEvent(ev,this->game());
	if (m_is_gameover) {
		pauseAllSound();
		m_gameover.handleEvent(ev);
		if (m_gameover.GetState() == true)
			game().popState();
	}
}

void state_playing::handleInput()
{
	if (m_pause_menu.isPaused() == false)
		m_world.input();
}

void state_playing::draw(sf::RenderTarget& renderer)
{
	m_world.draw(renderer);
	
	if (m_pause_menu.isPaused() && !m_is_gameover) m_pause_menu.draw(renderer);
	m_score_display.draw(renderer);
	m_level_display.draw(renderer);
	//m_highestScoreDisplay.draw(renderer);

	if (m_is_gameover) {
		m_gameover.draw(renderer);
	}
}

void state_playing::initAmbient()
{
	initMusic(m_ambient, AMBIENT_DIR, AMBIENT_VOL);
	initMusic(m_music, MUSIC_DIR, MUSIC_VOL);
	//add some randomness to ambient sound
	sf::Time duration = m_ambient.getDuration();
	m_ambient.setPlayingOffset(sf::seconds(mtrand::getFloat(0, duration.asSeconds())));
	duration = m_music.getDuration();
	m_music.setPlayingOffset(sf::seconds(mtrand::getFloat(0, duration.asSeconds())));
}

void state_playing::pauseAllSound()
{
	m_ambient.pause();
	m_music.pause();
}

void state_playing::resumeAllSound()
{
	m_ambient.play();
	m_music.play();
}

std::vector<SaveInf::LaneInf> state_playing::randomSaveInf(unsigned lv)
{
	//int obstacleType, obstacleNum, direction, maxObstacleType = game().get_txr_set().size() - 1;
	//float speed;
	//std::vector<SaveInf::LaneInf> lane;    
	//for (size_t i = 0; i < 4; ++i) {
	//	direction		= -1 + mtrand::getInt(0, 1) * 2;//left or right
	//	obstacleType	= mtrand::getInt(0, maxObstacleType);//random base on how many type read from Config/
	//	obstacleNum		= lv < 5 ? (mtrand::getInt(1, lv)) : (lv < 10 ? mtrand::getInt(2, 4) : mtrand::getInt(3, 4));
	//	speed = lv > 2 ? (mtrand::getFloat(-10.f, 10.f) + 10u * lv) : mtrand::getFloat(40.f, 60.f);
	//	lane.emplace_back(1, 1, obstacleType, obstacleNum, direction, speed);
	//}
	//return lane;

	int		laneType, lanePos;
	int		obstacleType, obstacleNum, maxOstacle;
	int		direction;
	float	speed;
	std::vector<SaveInf::LaneInf> lane;
	const unsigned bias_type[] = { 0,1,1,1,2,2,2 };
	size_t bias_size = sizeof(bias_type) / sizeof(bias_type[0]);
	const std::string typeName[] = { "vehicle" , "animal" };
	for (size_t i = 1; i < Y_TILES - 1; ++i) {//lane 0 and lane 7 is resting lane
		/*
			0 = resting lane
			1 = vehicle lane
			2 = animal lane
		*/
		if ((laneType = bias_type[mtrand::getInt(0, bias_size - 1)]) != 0) {
			//get size of current txr_set
			maxOstacle = game().get_txr_set().operator[](typeName[laneType - 1]).size() - 1;
			lanePos = i;
			obstacleType = mtrand::getInt(0, maxOstacle);
			obstacleNum = lv < 5 ? (mtrand::getInt(1, lv)) : (lv < 10 ? mtrand::getInt(2, 4) : mtrand::getInt(3, 4));
			direction = -1 + mtrand::getInt(0, 1) * 2;//left or right
			speed = lv > 2 ? (mtrand::getFloat(-10.f, 10.f) + 10u * lv) : mtrand::getFloat(40.f, 60.f);
			lane.emplace_back(laneType, lanePos, obstacleType, obstacleNum, direction, speed);
		}
	}
	return lane;
}

void state_playing::update(sf::Time delta_time)
{    
	m_save.update_level(m_level);
	m_save.update_score(m_score);
	
	m_level_display.update(m_level);
	m_score_display.update(m_score);
	m_gameover.updateScore(m_score);

	if (!m_is_gameover && !m_pause_menu.isPaused())
	{
		m_world.update(delta_time.asSeconds());
		m_score += m_world.updateScore();
		unsigned step_level = m_world.updateLevel();
		if (step_level) {
			m_level += step_level;
			m_save.update_road(randomSaveInf(m_level));
			m_world.resetWorld(m_save);
		}
	}
	m_save.update_best_player_y(m_world.get_max_lane());
	m_pause_menu.updateSaveInfo(m_save);
	m_is_gameover = m_world.is_game_over();
}

state_playing::display::display(float centreY, const std::string& _text)
	:text(_text), centrepoint(centreY)
{
	updateDisplay();
	label.setOutlineThickness(2);
	label.setFillColor(sf::Color::White);
	label.setOutlineColor(sf::Color::Black);
}

void state_playing::display::update(int newData) {
	currentdata = newData;
	updateDisplay();
}

void state_playing::display::draw(sf::RenderTarget& target) {
	target.draw(label);
}

void state_playing::display::updateDisplay()
{
	label.setString(text + "   " + std::to_string(currentdata));
	label.setPosition(15, centrepoint - label.getGlobalBounds().height / 2);
}
