#pragma once

#include <windows.h>

class IControlable {
protected:
	~IControlable() = default;
public:
	virtual void process_key_down(WPARAM key) = 0;
	virtual void process_left_mouse_down(POINT& p) = 0;
};