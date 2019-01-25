#pragma once
#include <SFML/Window.hpp>
#include "../Katie/StateStack.h"

class Game : private sf::NonCopyable 
{
public:
	Game();
	bool Update(sf::Time dt);
	void ProcessInput();
protected:
private:
	void RegisterStates();
	StateStack mStateStack;
};