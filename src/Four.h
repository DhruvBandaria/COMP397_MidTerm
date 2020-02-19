#pragma once
#ifndef __FOUR__
#define __FOUR__
#include "DisplayObject.h"

class Four : public DisplayObject
{
public:
	Four();
	~Four();

	void draw() override;
	void update() override;
	void clean() override;
};

#endif /* defined (__ISLAND__) */