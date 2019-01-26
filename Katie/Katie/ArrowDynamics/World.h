#pragma once
#include "../Katie/Entity.h"
#include "../Katie/SceneNode.h"
#include "Avatar.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>

class World : private sf::NonCopyable
{
public:
	explicit	World(sf::RenderWindow& window);

	void		Update(sf::Time dt);
	void		Draw();

protected:

private:
	enum Layer
	{
		Background,
		Forground,
		LayerCount
	};

	void LoadTextures();
	void BuildScene();

	sf::RenderWindow&					mWindow;
	sf::View							mWorldView;
	TextureHolder						mTextures;
	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;

	sf::FloatRect	mWorldBounds;
	sf::Vector2f	mSpawnPosition;
	float			mScrollSpeed;

	Avatar*		mPlayerAvatar;

	sf::String mAssetPath;
};