#pragma once
 
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

	virtual void Draw() = 0;
	virtual bool Update(sf::Time dt) = 0;
	virtual bool HandleEvent(const sf::Event& event) = 0;
protected:
	void	RequestStackPush(States::ID stateID);
	void	RequestStackPop();
	void	RequestStateClear();

	Context::Context GetContext() const;
private:
	StateStack*	mStack;
	Context::Context		mContext;
};