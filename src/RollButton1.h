#pragma once
#ifndef __ROLL_BUTTON_1__
#define __ROLL_BUTTON_1__

#include "Button.h"

class SecondScene;

class RollButton1 : public Button
{
public:
	RollButton1();
	~RollButton1();


	bool ButtonClick() override;
	bool ButtonClick(SecondScene* sender);
private:
	bool m_isClicked;
};

#endif /* defined (__START_BUTTON__) */