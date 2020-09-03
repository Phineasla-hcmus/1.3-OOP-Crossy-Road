#ifndef _animation_h
#define _animation_h
#include<SFML/Graphics.hpp>
#include<vector>
class animation {
private:
	struct frame {
        sf::IntRect bounds; //The area in a m_texture of the frame
        sf::Time    delay;  //Time delay to next frame
		frame(const sf::IntRect& bounds, sf::Time delay);
	};
	sf::Clock			m_timer;		//For progressing the animation
	std::vector<frame>	m_frames;		//List of animation frames
	size_t				m_frame_idx = 0;//The index of the current active frame
	const size_t		FRAME_WIDTH;
	const size_t		FRAME_HEIGHT;
public:
	//frame_width(file_width), frame_height(file_height)
	animation(size_t frame_width, size_t frame_height);
	void add_frame(sf::Time delay, size_t row, size_t col = 0);
	const sf::IntRect& getFrame();
};
#endif // !_animation_h
