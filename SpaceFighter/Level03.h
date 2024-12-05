#pragma once
#include "Level.h"
class Level03 : public Level
{

public:

	
	Level03() { }
	virtual ~Level03() { }

	virtual void LoadContent(ResourceManager& resourceManager);

	virtual bool IsOver() const;

private:
	// How many enemy ships to spawn for this level
	static const int m_enemyShipCount = 1;
};
