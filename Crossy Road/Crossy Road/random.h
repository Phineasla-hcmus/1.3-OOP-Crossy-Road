#ifndef _random
#define _random
#include<ctime>
#include<random>
class random
{
private:
	std::mt19937 engine;
	template<typename Distribution, typename T>
	T get_number(T low, T high) {
		Distribution dist(low, high);
		return dist(engine);
	}
public:
	random(unsigned seed = std::time(nullptr));
	using uniform_int		= std::uniform_int_distribution<>;
	using uniform_double	= std::uniform_real_distribution<>;
	int		int_in_range	(int	low, int	high);
	double	double_in_range	(double low, double high);
};
#endif // !_random

