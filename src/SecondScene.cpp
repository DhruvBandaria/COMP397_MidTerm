#include "SecondScene.h"
#include "Game.h"
#include "Two.h"
#include "One.h"
#include "Three.h"
#include "Four.h"
#include "RollButton1.h"
#include "Five.h"
#include "Six.h"

SecondScene::SecondScene()
{
	start();
}

SecondScene::~SecondScene()
{
}

void SecondScene::draw()
{
	m_pBack->draw();
	
	m_pRollButton->draw();
	m_pDiceOne->draw();
	m_pDiceTwo->draw();
	m_pDiceThree->draw();
	m_pDiceFour->draw();

	m_pDiceOneLabel->draw();
	m_pDiceTwoLabel->draw();
	m_pDiceThreeLabel->draw();
	m_pDiceFourLabel->draw();

	m_pHeadingLabel->draw();
	m_pResult->draw();
}

void SecondScene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	m_pRollButton->ButtonClick(this);

	m_pDiceOne->setPosition(glm::vec2(120, 200));
	m_pDiceTwo->setPosition(glm::vec2(370, 200));
	m_pDiceThree->setPosition(glm::vec2(620, 200));
	m_pDiceFour->setPosition(glm::vec2(870, 200));
}

void SecondScene::clean()
{
}

void SecondScene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while (SDL_PollEvent(&event))
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
			switch (event.button.button)
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

void SecondScene::start()
{
	m_pRollButton = new RollButton1();

	m_pDiceOne = new One();
	m_pDiceTwo = new Two();
	m_pDiceThree = new Three();
	m_pDiceFour = new Four();

	SDL_Color black = { 0,0,0,255 };

	m_pDiceOneLabel = new Label("1", "Consolas", 20, black,
		glm::vec2(120, 320), 0, true);

	m_pDiceTwoLabel = new Label("2", "Consolas", 20, black,
		glm::vec2(370, 320), 0, true);

	m_pDiceThreeLabel = new Label("3", "Consolas", 20, black,
		glm::vec2(620, 320), 0, true);
	
	m_pDiceFourLabel = new Label("4", "Consolas", 20, black,
		glm::vec2(870, 320), 0, true);

	m_pHeadingLabel = new Label("Roll 4d6", "Consolas", 20, black,
		glm::vec2(500, 50), 0, true);

	m_pResult = new Label("Result: 0", "Consolas", 20, black,
		glm::vec2(500, 400), 0, true);

	m_pBack = new Background();

	TheSoundManager::Instance()->load("../Assets/audio/dice-1.wav", "dice", SOUND_SFX);
}

void SecondScene::rollDice()
{
	TheSoundManager::Instance()->playSound("dice", 0);
	int temp1 = floor((rand() % 6) + 1);
	if (temp1 == 1)
	{
		m_pDiceOne = new One();
		m_pDiceOneLabel->setText("1");
	}
	else if (temp1 == 2)
	{
		m_pDiceOne = new Two();
		m_pDiceOneLabel->setText("2");
	}
	else if (temp1 == 3)
	{
		m_pDiceOne = new Three();
		m_pDiceOneLabel->setText("3");
	}
	else if (temp1 == 4)
	{
		m_pDiceOne = new Four();
		m_pDiceOneLabel->setText("4");
	}
	else if (temp1 == 5)
	{
		m_pDiceOne = new Five();
		m_pDiceOneLabel->setText("5");
	}
	else if (temp1 == 6)
	{
		m_pDiceOne = new Six();
		m_pDiceOneLabel->setText("6");
	}

	int temp2 = floor((rand() % 6) + 1);
	if (temp2 == 1)
	{
		m_pDiceTwo = new One();
		m_pDiceTwoLabel->setText("1");
	}
	else if (temp2 == 2)
	{
		m_pDiceTwo = new Two();
		m_pDiceTwoLabel->setText("2");
	}
	else if (temp2 == 3)
	{
		m_pDiceTwo = new Three();
		m_pDiceTwoLabel->setText("3");
	}
	else if (temp2 == 4)
	{
		m_pDiceTwo = new Four();
		m_pDiceTwoLabel->setText("4");
	}
	else if (temp2 == 5)
	{
		m_pDiceTwo = new Five();
		m_pDiceTwoLabel->setText("5");
	}
	else if (temp2 == 6)
	{
		m_pDiceTwo = new Six();
		m_pDiceTwoLabel->setText("6");
	}

	int temp3= floor((rand() % 6) + 1);
	if (temp3 == 1)
	{
		m_pDiceThree = new One();
		m_pDiceThreeLabel->setText("1");
	}
	else if (temp3 == 2)
	{
		m_pDiceThree = new Two();
		m_pDiceThreeLabel->setText("2");
	}
	else if (temp3 == 3)
	{
		m_pDiceThree = new Three();
		m_pDiceThreeLabel->setText("3");
	}
	else if (temp3 == 4)
	{
		m_pDiceThree = new Four();
		m_pDiceThreeLabel->setText("4");
	}
	else if (temp3 == 5)
	{
		m_pDiceThree = new Five();
		m_pDiceThreeLabel->setText("5");
	}
	else if (temp3 == 6)
	{
		m_pDiceThree = new Six();
		m_pDiceThreeLabel->setText("6");
	}
	int temp4 = floor((rand() % 6) + 1);
	if (temp4 == 1)
	{
		m_pDiceFour = new One();
		m_pDiceFourLabel->setText("1");
	}
	else if (temp4 == 2)
	{
		m_pDiceFour = new Two();
		m_pDiceFourLabel->setText("2");
	}
	else if (temp4 == 3)
	{
		m_pDiceFour = new Three();
		m_pDiceFourLabel->setText("3");
	}
	else if (temp4 == 4)
	{
		m_pDiceFour = new Four();
		m_pDiceFourLabel->setText("4");
	}
	else if (temp4 == 5)
	{
		m_pDiceFour = new Five();
		m_pDiceFourLabel->setText("5");
	}
	else if (temp4 == 6)
	{
		m_pDiceFour = new Six();
		m_pDiceFourLabel->setText("6");
	}

	if (temp1 < temp2 && temp1 < temp3 && temp1 < temp4){
		m_pResult->setText(std::to_string(temp2 + temp3 + temp4));
	}
	else if(temp2<temp3 && temp2<temp4)
	{
		m_pResult->setText(std::to_string(temp1 + temp3 + temp4));
	}
	else if(temp3<temp4)
	{
		m_pResult->setText(std::to_string(temp1 + temp2 + temp4));
	}
	else
	{
		m_pResult->setText(std::to_string(temp1 + temp2 + temp3));
	}
}

glm::vec2 SecondScene::getMousePosition()
{
	return m_mousePosition;
}
