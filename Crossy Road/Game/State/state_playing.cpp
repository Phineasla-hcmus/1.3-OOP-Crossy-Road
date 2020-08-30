#include "state_playing.h"
state_playing::state_playing(Game& game)
    : state_base(game)
    , m_save()
    , m_world(game.get_texture_set())
    , m_pause_menu(game)
    , m_score_display(20, "SCORE")
    , m_level_display(50, "LEVEL")
    , m_gameover(game)
{
    random r;
    std::array<SaveInf::RoadInf, SAVE_LANE> m_road_arr;
    for (int i = 0; i < SAVE_LANE; ++i) {
        m_road_arr[i].vehicleType = r.int_in_range(0, 1);
        m_road_arr[i].vehicleNum = 2;
        m_road_arr[i].direction = -1 + r.int_in_range(0, 1) * 2;
        m_road_arr[i].speed = r.double_in_range(50, 150);
    }
    m_save.update_road(m_road_arr);

    m_world.initLane(m_save);
}

state_playing::state_playing(Game& game, const SaveInf& save):
    state_base(game)
    , m_save(save)
    , m_world(game.get_texture_set())
    , m_pause_menu(game)
    , m_score_display(20, "SCORE")
    , m_level_display(50, "LEVEL")
    , m_gameover(game)
{
    m_world.initLane(m_save);

}

void state_playing::handleEvent(sf::Event ev)
{
    if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
    {
        m_pause_menu.changeState();
        m_is_paused = !m_is_paused;
    }
    if (m_is_paused) m_pause_menu.handleEvent(ev);
    if (m_is_gameover) {
        m_gameover.handleEvent(ev);
        if (m_gameover.GetState() == true)
            game().popState();
    }
}

void state_playing::handleInput()
{
     if(!m_is_paused)m_world.input();
}

void state_playing::draw(sf::RenderTarget& renderer)
{
    m_world.draw(renderer);
    
    if (m_is_paused&&!m_is_gameover) m_pause_menu.draw(renderer);
    m_score_display.draw(renderer);
    m_level_display.draw(renderer);
    //m_highestScoreDisplay.draw(renderer);

    if (m_is_gameover) {
        m_gameover.draw(renderer);
    }

}

void state_playing::update(sf::Time delta_time)
{
    //if (!m_is_gameover && !m_is_paused) {
    //    m_score += m_world.update(delta_time.asSeconds());
    //   //_score_display.update(m_score);

    //   // if (m_score > m_highestScoreDisplay.getCurrentScoreDisplayed()) {
    //    //    m_highestScoreDisplay.update(m_score);
    //   // }
    //}
    //if (m_level != m_world.getLevel()) {
    //    m_world.resetRoad();
    //    m_level = m_world.getLevel();
    //    std::cout << m_world.getLevel() << "\n";
    //}
    
   m_pause_menu.updateSaveInfo(m_save);
    //m_score = m_world.getScore();
    m_score_display.update(m_score);
    m_gameover.updateScore(m_score);
    m_level_display.update(m_level);
    m_is_paused = m_pause_menu.isPaused();


    uint new_level = m_level , new_score = m_score;
    m_world.update(new_level, new_score,delta_time.asSeconds());

    if (new_level>m_level) {
        m_save.update_level(m_level);
        m_save.update_score(m_score);
        m_world.resetWorld(m_save);
        m_level = new_level;//get level
    }
    m_score = new_score;//get score

    m_save.update_level(m_level);
    m_save.update_score(m_score);
    //m_is_gameover = m_world.isGameOver();
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
int state_playing::display::getCurrentDataDisplayed() const
{
    return currentdata;
}
void state_playing::display::updateDisplay()
{
    label.setString(text + "   " + std::to_string(currentdata));
    label.setPosition(15, centrepoint - label.getGlobalBounds().height / 2);

}
