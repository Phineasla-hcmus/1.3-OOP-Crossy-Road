#include "StackMenu.h"
#include<iostream>

constexpr float BASE_Y = 95.0f;

    StackMenu::StackMenu(const sf::RenderWindow& window, float baseY)
        : _base_pos((float)window.getSize().x / 2.0f, baseY)
        , _base_size(300, 20)
    {
        _background.setOutlineThickness(2);
        _background.setOutlineColor(sf::Color::Cyan);
        _background.setFillColor({ 100, 100, 100, 230 });
        _background.setSize(_base_size);
        _background.setPosition(_base_pos.x - _base_size.x/2.f , baseY - 100);

       
       //m_titleText.setPosition( m_baseSize.x /20000000000.f, baseY - 100);
       // m_titleText.setOutlineColor(sf::Color::Yellow);
        //m_titleText.setOutlineThickness(10);
        //m_titleText.setCharacterSize(10);
    }

    StackMenu::StackMenu(const sf::Vector2f& position)
        : _base_pos(position)
        , _base_size(300, 20)
    {
        _background.setFillColor({ 100, 100, 100, 128 });
        _background.setSize(_base_size);
        _background.setPosition(position);
    }

    StackMenu::StackMenu(StackMenu&& other)
        : _widgets(std::move(other._widgets))
        , _background(std::move(other._background))
        , _base_pos(other._base_pos)
        , _base_size(other._base_size)
    {};

    StackMenu& StackMenu::operator=(StackMenu&& other)
    {
        _widgets = std::move(other._widgets);
        _background = std::move(other._background);
        _base_pos = other._base_pos;
        _base_size = other._base_size;

        return *this;
    }

    void StackMenu::addWidget(std::unique_ptr<Widget> w)
    {
        initWidget(*w);
        _widgets.push_back(std::move(w));
    }

    void StackMenu::initWidget(Widget& widget)
    {
        widget.setPosition({ _base_pos.x - widget.getSize().x / 2.f,
                           _base_pos.y-70 });
        _base_pos.y += widget.getSize().y +40;
        _base_size.y += widget.getSize().y+40;
        _background.setSize(_base_size);
    }

    void StackMenu::setTitle(const std::string& title, const sf::RenderTarget& target)
    {
        _title_text.setString(title);
        _title_text.setPosition(target.getSize().x -_title_text.getGlobalBounds().width / 2.f,
        _title_text.getPosition().y-70);
        
    }

    void StackMenu::handleEvent(sf::Event e, const sf::RenderWindow& window)
    {
        for (auto& widget : _widgets) {
            widget->handleEvent(e, window);
        }
    }

    void StackMenu::render(sf::RenderTarget& renderer)
    {
        renderer.draw(_background);
        renderer.draw(_title_text);
        for (auto& widget : _widgets) {
            widget->render(renderer);
        }
    }


