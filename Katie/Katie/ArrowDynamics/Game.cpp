#include "Game.h"

Game::Game()
{
	RegisterStates();
}

void Game::RegisterStates()
{
	mStateStack.RegisterState<TitleState>(States::Title);
}

bool Game::Update(sf::Time dt)
{
	return(true);
}