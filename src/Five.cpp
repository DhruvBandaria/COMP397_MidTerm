#include "Five.h"
#include "Game.h"

Five::Five()
{
	TheTextureManager::Instance()->load("../Assets/textures/5.png",
		"five", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("five");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::FIVE);
}

Five::~Five()
{
}

void Five::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("five", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Five::update()
{
}

void Five::clean()
{
}
