#include "state_playing.h"
#include <iostream>
#include "../../Crossy Road/Framework/game.h"
//#include "../../Framework/ResourceManager/ResourceHolder.h"
#include "../../Framework/ResourceManager/ResourceHolder.h"
#include "../../Framework/ResourceManager/resource.h"

#include "../../Framework/GUI/Button.h"

//#include "StateHighscores.h"
#include "state_main_menu.h"


    state_playing::state_playing(game& _game)
        : state_base(_game)
        , m_gameOverMenu(_game.get_window(), 720 / 3)
        , m_scoreDisplay(1280 / 8, "Score")
        , m_highestScoreDisplay(1280 / 2, "HighScore")
    {
        
        auto mmButton = std::make_unique<Button>();
        mmButton->setText("Main Menu\n");
        mmButton->setFunction([&]() {
           // m_pGame->popState();
            });

        auto submitBtn = std::make_unique<Button>();
        submitBtn->setText("Submit Score");
        submitBtn->setFunction([&]() {
           // m_pGame->changeState<StateHighscores>(*m_pGame, m_score);
            });

        auto exitButton = std::make_unique<Button>();
        exitButton->setText("Exit game\n");
        exitButton->setFunction([&]() {
          //  m_pGame->exitGame();
            });

        m_gameOverMenu.setTitle("GAME  OVER", _game.get_window());
        m_gameOverMenu.addWidget(std::move(mmButton));
        m_gameOverMenu.addWidget(std::move(submitBtn));
        m_gameOverMenu.addWidget(std::move(exitButton));

        //m_highestScoreDisplay.update(StateHighscores::getHighestScore());
    }

    void state_playing::handleEvent(sf::Event e)
    {
        if (m_isGameover) {
           // m_gameOverMenu.handleEvent(e, m_pGame->getWindow());
        }
    }

    void state_playing::handleInput()
    {
        m_world.input();
    }

    void state_playing::update(sf::Time deltaTime)
    {
        if (!m_isGameover) {
            m_score += m_world.update(deltaTime.asSeconds());
            m_scoreDisplay.update(m_score);

            if (m_score > m_highestScoreDisplay.getCurrentScoreDisplayed()) {
                m_highestScoreDisplay.update(m_score);
            }
        }

        m_isGameover = m_world.isGameOver();
    }


    void state_playing::render(sf::RenderTarget& renderer)
    {
        m_world.draw(renderer);

        //m_lifeDisplay.draw(renderer, m_world.getPlayer().getLives());
        m_scoreDisplay.draw(renderer);
        m_highestScoreDisplay.draw(renderer);

        if (m_isGameover) {
            m_gameOverMenu.render(renderer);
        }
    }

    ///////////////////////////////////////////////
    //     display member functions       ///
    state_playing::LifeDisplay::LifeDisplay()
    {
        m_lifeStamp.setSize({ Player::WIDTH / 2, Player::WIDTH / 2 });
        //m_lifeStamp.setTexture(&ResourceHolder::get().textures.get("si/player"));
        m_lifeStamp.setTextureRect({ 0, 0, 11, 8 });
        m_label.setPosition(1280 - (Player::WIDTH * 5), 10);
        m_label.setString("LIVES");
        m_label.setOutlineThickness(0);
    }

    void state_playing::LifeDisplay::draw(sf::RenderTarget& window, int lives)
    {
        float xOrigin = m_label.getPosition().x +
            m_label.getGlobalBounds().width + 10;
        float yOrigin = m_label.getPosition().y +
            m_label.getGlobalBounds().height / 2;

        window.draw(m_label);
        for (int i = 0; i < lives; i++) {
            m_lifeStamp.setPosition(xOrigin + i * Player::WIDTH / 2 + i * 10, yOrigin);
            window.draw(m_lifeStamp);
        }
    }

    state_playing::ScoreDisplay::ScoreDisplay(float x, const std::string& text)
        : m_text(text)
        , m_centerPosition(x)
    {
        updateDisplay();
        m_label.setOutlineThickness(0);
    }

    void state_playing::ScoreDisplay::update(int newScore)
    {
        m_currentScore = newScore;
        updateDisplay();
    }

    void state_playing::ScoreDisplay::draw(sf::RenderTarget& target)
    {
        target.draw(m_label);
    }

    int state_playing::ScoreDisplay::getCurrentScoreDisplayed() const
    {
        return m_currentScore;
    }

    void state_playing::ScoreDisplay::updateDisplay()
    {
        m_label.setString(m_text + "   " + std::to_string(m_currentScore));
        m_label.setPosition(m_centerPosition - m_label.getGlobalBounds().width / 2, 15);
    }
