#pragma once
#include "pch.h"
#include <memory>
#include "Player.h"
#include "StateStack.h"
#include "ResourceHolder.h"
#include "StateIdentifiers.h"
#include "Context.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class State
{
public:	
public:

	//typedef std::unique_ptr<State> Ptr;
	//struct Context { ... };

	State(StateStack& stack, Context::Context context);

	virtual void draw() = 0;
	virtual bool update(sf::Time dt) = 0;
	virtual bool handleEvent(const sf::Event& event) = 0;
protected:
	void	requestStackPush(States::ID stateID);
	void	requestStackPop();
	void	requestStateClear();

	Context::Context getContext() const;
private:
	StateStack*	mStack;
	Context::Context		mContext;
};