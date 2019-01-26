#include "../Katie/Entity.h"

#include "../Katie/SceneNode.h"

class Avatar : public Entity
{
public:
	enum Type
	{
		Mechanic,
		Manager,
	};

	explicit	Avatar(Type type, const TextureHolder& textures);
	virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	Type	mType;
	sf::Sprite mSprite;

	virtual Textures::ID ToTextureID(int id);
};