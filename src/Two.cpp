#include "Two.h"
#include "Game.h"

Two::Two()
{
	TheTextureManager::Instance()->load("../Assets/textures/2.png",
		"two", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("two");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::TWO);
}

Two::~Two()
{
}

void Two::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("two", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Two::update()
{
}

void Two::clean()
{
}
