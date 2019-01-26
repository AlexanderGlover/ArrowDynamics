#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Entity.h"

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	SceneNode();
	SceneNode(Entity* entity);

	typedef std::unique_ptr<SceneNode> Ptr;
		
	void Update(sf::Time dt);
	void SetEntity(Entity* entity);
	Entity* GetEntity();
	void AttachChild(Ptr child);
	SceneNode::Ptr DetachChild(const SceneNode& node);

	sf::Transform GetWorldTransform() const;
	sf::Vector2f GetWorldPosition() const;
protected:
private:
	virtual void	UpdateCurrent(sf::Time dt);
	void			UpdateChildren(sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const { Draw(target, states); }
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void DrawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<Ptr>	mChildren;
	SceneNode*			mParent;

	Entity* mEntity;
};