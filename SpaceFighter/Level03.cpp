#include "Level03.h"
#include "BioEnemyBoss.h"
#include "Blaster.h"

void Level03::LoadContent(ResourceManager& resourceManager)
{
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyBoss.png");
	

	
	Vector2 position;
	position.Set(.5 * Game::GetScreenWidth(),100);
	
		
		BioEnemyBoss* pEnemy = new BioEnemyBoss();
		Blaster* pEnemyBlaster = new Blaster("Enemy Blaster",false);
		pEnemyBlaster->SetProjectilePool(&m_projectiles);
		pEnemy->AttachItem(pEnemyBlaster, Vector2::UNIT_Y * 20);
		for (int i = 0; i < 100; i++) 
		{
			Projectile* pProjectile = new Projectile();
			pProjectile->SetWasShotByEnemy();
			pProjectile->SetDirection(Vector2::UNIT_Y);     
			m_projectiles.push_back(pProjectile);
			AddGameObject(pProjectile);
		}
		pEnemy->SetTexture(pTexture);
		pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position,1);
		AddGameObject(pEnemy);
	
	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground02.png"));

	Level::LoadContent(resourceManager);
}