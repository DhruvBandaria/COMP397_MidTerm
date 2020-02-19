#include "Six.h"
#include "Game.h"

Six::Six()
{
	TheTextureManager::Instance()->load("../Assets/textures/6.png",
		"six", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("six");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::ONE);
}

Six::~Six()
{
}

void Six::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("six", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Six::update()
{
}

void Six::clean()
{
}
