#include "BioEnemyBoss.h"
#include "Level.h"
void BioEnemyBoss::LoadContent(ResourceManager& resourceManager)
{
	AudioSample* pAudio = resourceManager.Load<AudioSample>("Audio\\Effects\\Laser.wav");
	GetWeapon("blaster")->SetFireSound(pAudio);
	pAudio->SetVolume(0.5f);
	
	

		
}
BioEnemyBoss::BioEnemyBoss()
{
	SetSpeed(350);
	SetMaxHitPoints(1);
	SetCollisionRadius(140);
}

void BioEnemyBoss::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float x = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());
		x *= GetSpeed() * gameTime.GetElapsedTime() * 2.7f;
		TranslatePosition(x);
		FireWeapons();
		
	}
	EnemyShip::Update(gameTime);
}

void BioEnemyBoss::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float a = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * a, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
		// add this if i want to flip the ship back
		//spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * a, m_pTexture->GetCenter());

	}
}
