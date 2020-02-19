#include "RollButton.h"
#include "Game.h"
#include "Level1Scene.h"

RollButton::RollButton()
	:Button(
	"../Assets/textures/rollButton.png",
	"rollButton",
	START_BUTTON, glm::vec2(500.0f, 400.0f)), m_isClicked(false)
{
}

RollButton::~RollButton()
{
	
}

bool RollButton::ButtonClick()
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

bool RollButton::ButtonClick(Level1Scene* sender)
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
