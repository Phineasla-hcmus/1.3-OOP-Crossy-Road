#ifndef _STACKMENU_H_
#define  _STACKMENU_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include"Widget.h"
class StackMenu
{
private:
    void initWidget(Widget&);
    std::vector<std::unique_ptr<Widget>>    _widgets;
    sf::RectangleShape                      _background;
    sf::Vector2f                            _base_pos;
    sf::Vector2f                            _base_size;
    Widget::Text                            _title_text;
public:
    StackMenu(const sf::RenderWindow& window, float baseY);
    StackMenu(const sf::Vector2f& position);
    StackMenu(StackMenu&& other);
    StackMenu& operator =(StackMenu&& other);
    ~StackMenu() = default;
    void addWidget(std::unique_ptr<Widget> w);
    //template<typename T, typename Args>
    //void addWidget(Args&& args) {
    //    auto w = std::make_unique<T>(std::forward<Args>(args));
    //    initWidget(*w);
    //    _widgets.push_back(std::move(w));
    //}
    void setTitle(const std::string& title, const sf::RenderTarget& target);
    void handleEvent(sf::Event e, const sf::RenderWindow& window);
    void render(sf::RenderTarget& renderer);
};
#endif // !_STACKMENU_H_
