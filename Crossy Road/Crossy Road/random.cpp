#include"framework/util/random.h"

random::random(unsigned seed)
	: engine(seed)
{}

int random::int_in_range(int low, int high)
{
	return get_number<uniform_int>(low, high);
}

double random::double_in_range(double low, double high)
{
	return get_number<uniform_double>(low, high);
}
