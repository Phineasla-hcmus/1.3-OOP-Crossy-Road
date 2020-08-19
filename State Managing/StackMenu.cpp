#include "StackMenu.h"
#include<iostream>

constexpr float BASE_Y = 95.0f;

    StackMenu::StackMenu(const sf::RenderWindow& window, float baseY)
        : m_basePosition((float)window.getSize().x / 2.0f, baseY)
        , m_baseSize(300, 20)
    {
        m_background.setOutlineThickness(2);
        m_background.setOutlineColor(sf::Color::Magenta);
        m_background.setFillColor({ 100, 10, 200, 150 });
        m_background.setSize(m_baseSize);
        m_background.setPosition(m_basePosition.x - m_baseSize.x/2.f , baseY - 100);

       
        m_titleText.setPosition(m_basePosition.x - m_baseSize.x / 2.f, baseY - 100);
        m_titleText.setOutlineColor(sf::Color::Yellow);
        m_titleText.setFillColor(sf::Color::Black);
        m_titleText.setOutlineThickness(2);
        m_titleText.setCharacterSize(20);
    }

    StackMenu::StackMenu(const sf::Vector2f& position)
        : m_basePosition(position)
        , m_baseSize(300, 20)
    {
        m_background.setFillColor({ 100, 100, 100, 128 });
        m_background.setSize(m_baseSize);
        m_background.setPosition(position);
    }

    /*StackMenu::StackMenu(StackMenu&& other)
        : m_widgets(std::move(other.m_widgets))
        , m_background(std::move(other.m_background))
        , m_basePosition(other.m_basePosition)
        , m_baseSize(other.m_baseSize)
    {};*/

    /*StackMenu& StackMenu::operator=(StackMenu&& other)
    {
        m_widgets = std::move(other.m_widgets);
        m_background = std::move(other.m_background);
        m_basePosition = other.m_basePosition;
        m_baseSize = other.m_baseSize;

        return *this;
    }*/

    void StackMenu::addWidget(std::unique_ptr<Widget> w)
    {
        initWidget(*w);
        m_widgets.push_back(std::move(w));
    }

    void StackMenu::initWidget(Widget& widget)
    {
        widget.setPosition({ m_basePosition.x - widget.getSize().x / 2.f,
                           m_basePosition.y-70 });


        m_basePosition.y += widget.getSize().y +40;
        m_baseSize.y += widget.getSize().y+40;
        m_background.setSize(m_baseSize);
    }

    void StackMenu::setTitle(const std::string& title, const sf::RenderTarget& target)
    {
        m_titleText.setString(title);
        m_titleText.setPosition(target.getSize().x-710,
        m_titleText.getPosition().y);
        
    }

    void StackMenu::handleEvent(sf::Event e, const sf::RenderWindow& window)
    {
        for (auto& widget : m_widgets) {
            widget->handleEvent(e, window);
        }
    }

    void StackMenu::render(sf::RenderTarget& renderer)
    {
        renderer.draw(m_background);
        renderer.draw(m_titleText);
        for (auto& widget : m_widgets) {
            widget->render(renderer);
        }
    }


