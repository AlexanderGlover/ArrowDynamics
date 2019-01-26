#include "World.h"
#include "../Katie/SpriteNode.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

World::World(sf::RenderWindow& window) :
	mWindow(window),
	mWorldView(window.getDefaultView()),
	mWorldBounds(0.f, 0.f, mWorldView.getSize().x, mWorldView.getSize().y),
	mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f),
	mPlayerAvatar(nullptr)
{
	TCHAR full_path[MAX_PATH];
	DWORD string_len = GetFullPathName(TEXT("Assets"),
		MAX_PATH,
		full_path,
		NULL);
	mAssetPath = full_path;

	LoadTextures();
	BuildScene();
	mWorldView.setCenter(mSpawnPosition);
}

void World::Update(sf::Time dt)
{
	//mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

	sf::Vector2f position = mPlayerAvatar->GetPosition();
	sf::Vector2f velocity = mPlayerAvatar->GetVelocity();

	if (position.x <= mWorldBounds.left + 150 || position.x >= mWorldBounds.left + mWorldBounds.width - 150)
	{
		velocity.x = -velocity.x;
		mPlayerAvatar->SetVelocity(velocity);
	}

	mSceneGraph.Update(dt);
}

void World::LoadTextures()
{
	mTextures.LoadResource(Textures::Mechanic, mAssetPath + "/Mechanic.jpg");
	mTextures.LoadResource(Textures::Manager, mAssetPath + "/Manager.jpg");
	mTextures.LoadResource(Textures::Background, mAssetPath + "/Thirdbackground.jpg");
}

void World::BuildScene()
{
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.AttachChild(std::move(layer));
	}

	sf::Texture& texture = mTextures.GetResource(Textures::Background);

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->AttachChild(std::move(backgroundSprite));

	sf::Texture& playerTexture = mTextures.GetResource(Textures::Mechanic);

	std::unique_ptr<SpriteNode> playerNode(new SpriteNode(playerTexture));
	playerNode->SetEntity(new Avatar(Avatar::Mechanic, mTextures));
	mPlayerAvatar = static_cast<Avatar*>(playerNode->GetEntity());
	mPlayerAvatar->SetPosition(mSpawnPosition);
	mSceneLayers[Forground]->AttachChild(std::move(playerNode));
	//mPlayerAvatar->SetVelocity(40.f, mScrollSpeed);
}

void World::Draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}