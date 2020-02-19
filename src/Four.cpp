#include "Four.h"
#include "Game.h"

Four::Four()
{
	TheTextureManager::Instance()->load("../Assets/textures/4.png",
		"four", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("four");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::FOUR);
}

Four::~Four()
{
}

void Four::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("four", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Four::update()
{
}

void Four::clean()
{
}
