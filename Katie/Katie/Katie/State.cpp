#pragma once
 
#include "State.h"

State::State(StateStack& stack, Context::Context context)
{
	mStack = &stack;
	mContext = context;
}