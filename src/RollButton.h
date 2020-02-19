#pragma once
#ifndef __ROLL_BUTTON__
#define __ROLL_BUTTON__

#include "Button.h"

class Level1Scene;

class RollButton : public Button
{
public:
	RollButton();
	~RollButton();


	bool ButtonClick() override;
	bool ButtonClick(Level1Scene* sender);
private:
	bool m_isClicked;
};

#endif /* defined (__START_BUTTON__) */