#pragma once

template <typename TBase>
class IAffectable {
public:
	virtual void affect(TBase*& base) = 0;
};