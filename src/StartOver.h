#pragma once
#ifndef __START_OVER__
#define __START_OVER__

#include "Button.h"


class StartOver : public Button
{
public:
	StartOver();
	~StartOver();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__START_BUTTON__) */