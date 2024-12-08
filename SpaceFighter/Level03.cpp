#include "Level03.h"
#include "BioEnemyBoss.h"

void Level03::LoadContent(ResourceManager& resourceManager)
{
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyBoss.png");

	double xPositions[] =
	{
		0.5
	};

	double delays[] =
	{
		0.0
	};

	SetEnemyShipCount(sizeof(xPositions) / sizeof(xPositions[0]));
	SetEnemyShipsRemaining( GetEnemyShipCount() );

	float delay = 1.0; // start delay
	Vector2 position;

	for (int i = 0; i < GetEnemyShipCount(); i++)
	{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), 100);
		BioEnemyBoss* pEnemy = new BioEnemyBoss();
		pEnemy->SetTexture(pTexture);
		pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position, (float)delay);
		AddGameObject(pEnemy);
	}
	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground01.png"));

	Level::LoadContent(resourceManager);
}