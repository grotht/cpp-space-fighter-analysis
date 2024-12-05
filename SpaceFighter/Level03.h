#pragma once
#include "Level.h"
class Level03 : public Level
{

public:

	
	Level03() { }
	virtual ~Level03() { }
	

	virtual void LoadContent(ResourceManager& resourceManager);
private:
	std::vector<Projectile*> m_projectiles;
};
