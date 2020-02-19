#include "RollButton1.h"
#include "SecondScene.h"

RollButton1::RollButton1()
	:Button(
		"../Assets/textures/rollButton.png",
		"rollButton",
		START_BUTTON, glm::vec2(500.0f, 450.0f)), m_isClicked(false)
{
}

RollButton1::~RollButton1()
{
}

bool RollButton1::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			//Game::Instance()->changeSceneState(LEVEL1_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}

bool RollButton1::ButtonClick(SecondScene* sender)
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			sender->rollDice();
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
