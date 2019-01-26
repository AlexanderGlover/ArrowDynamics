#pragma once
#include "SceneNode.h"
#include <algorithm>
#include "assert.h"
#include <AccCtrl.h>
#include "FOREACH.h"

SceneNode::SceneNode()
{
}

SceneNode::SceneNode(Entity* entity)
{
	mEntity = entity;
}

void SceneNode::SetEntity(Entity* entity)
{
	mEntity = entity;
}

Entity* SceneNode::GetEntity()
{
	return(mEntity);
}

void SceneNode::Update(sf::Time dt)
{
	UpdateCurrent(dt);
	UpdateChildren(dt);
}

void SceneNode::UpdateCurrent(sf::Time dt)
{
	
}

void SceneNode::UpdateChildren(sf::Time dt)
{
	FOREACH(Ptr& child, mChildren)
	{
		child->Update(dt);
	}
}

void SceneNode::AttachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::DetachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) -> bool { return p.get() == &node; });

	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	DrawCurrent(target, states);
	DrawChildren(target, states);
}
void SceneNode::DrawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	FOREACH(const Ptr& child, mChildren)
	{
		child->Draw(target, states);
	}
}

void SceneNode::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	
}

sf::Transform SceneNode::GetWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;
	for(const SceneNode* node = this; node != nullptr; node = node->mParent)
	{
		transform = node->getTransform() * transform;
	}
	return(transform);
}

sf::Vector2f SceneNode::GetWorldPosition() const
{
	return(GetWorldTransform() * sf::Vector2f());
}