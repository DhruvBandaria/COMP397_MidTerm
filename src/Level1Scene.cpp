#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include "One.h"
#include "Two.h"
#include "Three.h"
#include "Four.h"
#include "Five.h"
#include "Six.h"

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pBack->draw();
	m_pRollButton->draw();
	m_pDiceOne->draw();
	m_pDiceTwo->draw();

	m_pDiceOneLabel->draw();
	m_pDiceTwoLabel->draw();

	
}

void Level1Scene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	m_pRollButton->ButtonClick(this);

	m_pDiceOne->setPosition(glm::vec2(400, 200));
	m_pDiceTwo->setPosition(glm::vec2(700, 200));
}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	m_pRollButton = new RollButton();

	m_pDiceOne = new One();
	m_pDiceTwo = new Two();

	SDL_Color black = { 0,0,0,255 };
	
	m_pDiceOneLabel = new Label("1", "Consolas", 20, black, 
		glm::vec2(400, 320), 0, true);
	
	m_pDiceTwoLabel = new Label("2", "Consolas", 20, black,
		glm::vec2(700, 320), 0, true);

	m_pBack = new Background();

	TheSoundManager::Instance()->load("../Assets/audio/dice-1.wav", "dice", SOUND_SFX);
}

void Level1Scene::rollDice()
{
	TheSoundManager::Instance()->playSound("dice", 0);
	int temp= floor((rand() % 6) + 1);
	if(temp == 1)
	{
		m_pDiceOne = new One();
		m_pDiceOneLabel->setText("1");
	}
	else if(temp ==2)
	{
		m_pDiceOne = new Two();
		m_pDiceOneLabel->setText("2");
	}
	else if (temp == 3)
	{
		m_pDiceOne = new Three();
		m_pDiceOneLabel->setText("3");
	}
	else if (temp == 4)
	{
		m_pDiceOne = new Four();
		m_pDiceOneLabel->setText("4");
	}
	else if (temp == 5)
	{
		m_pDiceOne = new Five();
		m_pDiceOneLabel->setText("5");
	}
	else if (temp == 6)
	{
		m_pDiceOne = new Six();
		m_pDiceOneLabel->setText("6");
	}

	temp = floor((rand() % 6) + 1);
	if (temp == 1)
	{
		m_pDiceTwo = new One();
		m_pDiceTwoLabel->setText("1");
	}
	else if (temp == 2)
	{
		m_pDiceTwo = new Two();
		m_pDiceTwoLabel->setText("2");
	}
	else if (temp == 3)
	{
		m_pDiceTwo = new Three();
		m_pDiceTwoLabel->setText("3");
	}
	else if (temp == 4)
	{
		m_pDiceTwo = new Four();
		m_pDiceTwoLabel->setText("4");
	}
	else if (temp == 5)
	{
		m_pDiceTwo = new Five();
		m_pDiceTwoLabel->setText("5");
	}
	else if (temp == 6)
	{
		m_pDiceTwo = new Six();
		m_pDiceTwoLabel->setText("6");
	}
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

