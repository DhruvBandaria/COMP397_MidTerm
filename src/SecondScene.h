#pragma once
#ifndef __SECOND_SCENE__
#define __SECOND_SCENE__

#include "Scene.h"
#include "Label.h"
#include "RollButton1.h"
#include "Background.h"

class SecondScene : public Scene
{
public:
	SecondScene();
	~SecondScene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	void rollDice();
	// getters
	glm::vec2 getMousePosition();

private:
	// game objects

	RollButton1* m_pRollButton;

	DisplayObject* m_pDiceOne;
	DisplayObject* m_pDiceTwo;
	DisplayObject* m_pDiceThree;
	DisplayObject* m_pDiceFour;

	Label* m_pDiceOneLabel;
	Label* m_pDiceTwoLabel;
	Label* m_pDiceThreeLabel;
	Label* m_pDiceFourLabel;
	Label* m_pHeadingLabel;

	Label* m_pResult;

	Background* m_pBack;

	// private data member
	glm::vec2 m_mousePosition;


};

#endif /* defined (__LEVEL_1_SCENE__) */
