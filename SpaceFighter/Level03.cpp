#include "Level03.h"
#include "BioEnemyBoss.h"

bool Level03::IsOver() const {
	return (GetEnemyShipsRemaining() <= 0);
}

void Level03::LoadContent(ResourceManager& resourceManager)
{
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyBoss.png");
	const int COUNT = Level03::m_enemyShipCount;;

	double xPositions[COUNT] =
	{
		0.5
	};

	double delays[COUNT] =
	{
		0.0
	};

	float delay = 1.0; // start delay
	Vector2 position;

	for (int i = 0; i < COUNT; i++)
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