#include "animation.h"

animation::frame::frame(const sf::IntRect& bounds, sf::Time delay)
	: bounds(bounds)
	, delay(delay)
{}

animation::animation(size_t frame_width, size_t frame_height)
	: FRAME_WIDTH(frame_width)
	, FRAME_HEIGHT(frame_height)
{}

void animation::add_frame(sf::Time delay, size_t row, size_t col)
{
	//sf::IntRect bounds;
	//bounds.top	= row * FRAME_HEIGHT;
	//bounds.height = FRAME_HEIGHT;
	//bounds.width	= FRAME_WIDTH;
	//bounds.left	= col * FRAME_WIDTH;
	m_frames.emplace_back(
		sf::IntRect(col * FRAME_WIDTH, row * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT)
		, delay);
}

const sf::IntRect& animation::getFrame()
{
	if (m_timer.getElapsedTime() >= m_frames[m_frame_idx].delay) {
		m_timer.restart();
		m_frame_idx++;//next frame idx
		if (m_frame_idx == m_frames.size())//loop back
			m_frame_idx = 0;
	}

	return m_frames[m_frame_idx].bounds;
}
