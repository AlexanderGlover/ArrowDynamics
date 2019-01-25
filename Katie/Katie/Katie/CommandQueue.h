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
	void	Push(const Command& command);
	Command Pop();
	bool	IsEmpty() const;

private:
	std::queue<Command> mQueue;
};