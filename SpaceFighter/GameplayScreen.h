
#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

class Level;

/** @brief The gameplay screen for the Space Fighter Game.
	It is responsible for creating and loading levels.
	@see Level
	@see Screen
*/
class GameplayScreen : public Screen
{

public:

	/** @brief Instantiate a gameplay screen object.
		@param levelIndex The index of the level to load. */
	GameplayScreen(const int levelIndex = 0);
	virtual ~GameplayScreen() { }

	/** @brief Load the content for the screen.
		@param resourceManager A reference to the game's resource manager. */
	virtual void LoadContent(ResourceManager& resourceManager);

	/** @brief Handle input for the screen.
		@param input The current state of all player input devices. */
	virtual void HandleInput(const InputState& input);

	/** @brief Update the screen.
		@param gameTime A reference to the game time object. */
	virtual void Update(const GameTime& gameTime);

	/** @brief Render the screen.
		@param spriteBatch A reference to the game's sprite batch, used for rendering. */
	virtual void Draw(SpriteBatch& spriteBatch);

	/** @brief Load a specific level.
		@param levelIndex The index of the level to load. */
	virtual void LoadLevel(const int levelIndex);

	/** @brief Load the next level. If the next level doesn't exist it exits. */
	virtual void NextLevel();


private:
	// Sets the starting level
	int m_levelIndex = 0;
	// Sets the max level that the game will auto transition too (eg. if the last level is 2, then a value of 1 is expected)
	int m_maxLevelIndex = 2;

	Level *m_pLevel = nullptr;

	ResourceManager *m_pResourceManager = nullptr;

};
