#include "Three.h"
#include "Game.h"

Three::Three()
{
	TheTextureManager::Instance()->load("../Assets/textures/3.png",
		"three", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("three");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::THREE);
}

Three::~Three()
{
}

void Three::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("three", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Three::update()
{
}

void Three::clean()
{
}
