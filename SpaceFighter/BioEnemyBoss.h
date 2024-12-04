#pragma once
#include "BioEnemyShip.h"

class BioEnemyBoss : public BioEnemyShip {
public:
	void LoadContent(ResourceManager& resourceManager);
	BioEnemyBoss();
	virtual ~BioEnemyBoss(){}

	virtual void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }

	virtual void Update(const GameTime& gameTime);
	
	virtual void Draw(SpriteBatch& spriteBatch);
	

private:
	Texture* m_pTexture = nullptr;
};
