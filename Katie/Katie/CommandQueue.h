#pragma once
#include <queue>
#include <functional>

struct Command
{
//	std::function<void(SceneNode&, sf::Time)>	action;
	unsigned int								category;
};

class CommandQueue
{
public:
	void	push(const Command& command);
	Command pop();
	bool	isEmpty() const;

private:
	std::queue<Command> mQueue;
};