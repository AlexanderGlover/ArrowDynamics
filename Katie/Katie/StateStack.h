#pragma once
#include "pch.h"

#include <SFML/Window.hpp>
#include "StateStack.h"
#include "StateIdentifiers.h"
#include "Context.h"

class StateStack : private sf::NonCopyable
{
public:
	enum Action
	{
		Push,
		Pop,
		Clear
	};
	explicit	StateStack(Context::Context context);

	template <typename T>
	void		registerState(States::ID stateID);
	void		update(sf::Time dt);
	void handleEvent(const sf::Event& event);

protected:

private:
};