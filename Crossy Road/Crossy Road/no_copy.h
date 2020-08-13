#ifndef _no_copy
#define _no_copy
class no_copy {
public:
	no_copy()							= default;
	no_copy(const no_copy&)				= delete;
	no_copy& operator=(const no_copy&)	= delete;
};
#endif // !_no_copy

