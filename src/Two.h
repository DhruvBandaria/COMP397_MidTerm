#pragma once
#ifndef __TWO__
#define __TWO__
#include "DisplayObject.h"

class Two : public DisplayObject
{
public:
	Two();
	~Two();

	void draw() override;
	void update() override;
	void clean() override;
};

#endif /* defined (__ISLAND__) */