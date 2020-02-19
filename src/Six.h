#pragma once
#ifndef __SIX__
#define __SIX__
#include "DisplayObject.h"

class Six : public DisplayObject
{
public:
	Six();
	~Six();

	void draw() override;
	void update() override;
	void clean() override;
};

#endif /* defined (__ISLAND__) */