#pragma once
#include "../Katie/StateStack.h"
#include "../Katie/Context.h"
#include "World.h"

class GameState
{
public:
	GameState(StateStack& stack, Context::Context context);

	virtual void	Draw();
	virtual void	Update(sf::Time dt);
	virtual void	handleEvent(const sf::Event& event);
protected:
private:
	World	mWorld;
	Player&	mPlayer;
};