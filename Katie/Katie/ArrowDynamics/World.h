#pragma once
#include <SFML/Graphics.hpp>

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

	sf::RenderWindow&					mWindow;
	sf::View							mWorldView;
	TextureHolder						mTextures;
	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayer;

	sf::FloatRect	mWorldBounds;
	sf::Vector2f	mSpawnPosition;
	float			mScrollSpeed;
};