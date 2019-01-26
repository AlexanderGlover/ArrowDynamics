#pragma once

#include <SFML/Window.hpp>
#include "StateIdentifiers.h"
#include "Context.h"

class StateStack : private sf::NonCopyable
{
public:
	StateStack();
	enum Action
	{
		Push,
		Pop,
		Clear
	};
	explicit	StateStack(Context::Context context);

	template <typename T>
	void	RegisterState(States::ID stateID);
	void	Update(sf::Time dt);
	void	HandleEvent(const sf::Event& event);

protected:

private:
};