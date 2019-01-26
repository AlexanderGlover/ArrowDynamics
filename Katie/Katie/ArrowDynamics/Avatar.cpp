#include "Avatar.h"

Avatar::Avatar(Type type, const TextureHolder& textures) : mType(type), mSprite(textures.GetResource(ToTextureID(type)) )
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Avatar::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

Textures::ID Avatar::ToTextureID(int id)
{
	switch (id)
	{
	case Avatar::Mechanic:
		return(Textures::Mechanic);
	case Avatar::Manager:
		return(Textures::Manager);
	}
	return(Textures::Default);
}	