#include "BioEnemyBoss.h"
#include "Level.h"
void BioEnemyBoss::LoadContent(ResourceManager& resourceManager)
{
	m_pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyBoss.png");
	AudioSample* pAudio = resourceManager.Load<AudioSample>("Audio\\Effects\\Laser.wav");
	GetWeapon("blaster")->SetFireSound(pAudio);
	SetPosition(Game::GetScreenCenter() + Vector2::UNIT_Y * 900);	
}
BioEnemyBoss::BioEnemyBoss()
{
	SetSpeed(50);
	SetMaxHitPoints(20);
	SetCollisionRadius(40);
}

void BioEnemyBoss::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float x = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());
		x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;
		TranslatePosition(x);
		
	}
	BioEnemyShip::Update(gameTime);
}

void BioEnemyBoss::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float a = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * a, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}