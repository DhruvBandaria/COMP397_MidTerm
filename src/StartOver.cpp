#include "StartOver.h"
#include "Game.h"

StartOver::StartOver()
	:Button(
		"../Assets/textures/startOverButton.png",
		"startOverButton",
		START_BUTTON, glm::vec2(400.0f, 400.0f)), m_isClicked(false)
{
	
}

StartOver::~StartOver()
{
}

bool StartOver::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			Game::Instance()->changeSceneState(SECOND_SCENE);
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
