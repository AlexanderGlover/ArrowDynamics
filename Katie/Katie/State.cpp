#pragma once
#include "pch.h"
#include "State.h"

State::State(StateStack& stack, Context::Context context)
{
	mStack = &stack;
	mContext = context;
}