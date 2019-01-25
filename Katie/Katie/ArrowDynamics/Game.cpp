#include "Game.h"

Game::Game()
{
	mStateStack = new StateStack();
	//RegisterStates();
}

void Game::RegisterStates()
{
	//mStateStack.RegisterState<TitleState>(States::Title);
}

bool Game::Update(sf::Time dt)
{
	return(true);
}