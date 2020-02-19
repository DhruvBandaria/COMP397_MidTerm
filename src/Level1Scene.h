#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "RollButton.h"
#include "Label.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
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

	RollButton* m_pRollButton;

	DisplayObject* m_pDiceOne;
	DisplayObject* m_pDiceTwo;

	Label* m_pDiceOneLabel;
	Label* m_pDiceTwoLabel;

	// private data member
	glm::vec2 m_mousePosition;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
