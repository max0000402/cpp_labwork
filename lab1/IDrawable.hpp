#pragma once

#include <windows.h>

class IDrawable {
protected:
	~IDrawable() = default;
public:
	virtual void draw(HDC& hdc) = 0;

	virtual bool is_visible() = 0;
	virtual void hide() = 0;
	virtual void show() = 0;

	virtual int get_width() = 0;
	virtual int get_height() = 0;

	virtual COLORREF get_color() = 0;
};