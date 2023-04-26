#pragma once

#include "ABCFigure.hpp"
#include "ITreeVisitor.hpp"

class BareTree : public ABCFigure {
private:
	HBRUSH m_brush;
	HPEN m_pen;
public:
	BareTree(int x, int y, COLORREF color);
	void draw(HDC& hdc) override;
	virtual void accept(ITreeVisitor& visitor);
	~BareTree() override;
};