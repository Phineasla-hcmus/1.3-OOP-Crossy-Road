#ifndef _main_world
#define _main_world
#include<SFML/Graphics.hpp>
#include"../Framework/Util/random.h"
constexpr auto x_tile = 16;
constexpr auto y_tile = 9;
class world {
private:
public:
	world();
	void draw(sf::RenderTarget&);
};
#endif // !_main_world
