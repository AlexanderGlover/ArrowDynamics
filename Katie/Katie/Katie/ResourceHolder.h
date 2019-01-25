#pragma once
#include <string>
#include <map>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void LoadResource(Identifier id, const std::string& filename);
	Resource& GetResource(Identifier id);
	const Resource& GetResource(Identifier id) const;

	template <typename Parameter>
	void LoadResource(Identifier id, const std::string& filename, const Parameter& secondParameter);
private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::LoadResource(Identifier id, const std::string& filename)
{
	std::unique_ptr<sf::Resource> resource(new Resource());
	if (!resource->loadFromFile(filename))
	{
		throw std::runtime_error("ResourceHolder::LoadResource - Failed to load " + filename);
	}

	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
	std::move(resource);
	assert(inserted.second);
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::LoadResource(Identifier id, const std::string& filename, const Parameter& secondParam)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename, secondParam))
	{
		throw std::runtime_error("ResourceHolder::LoadResource - Failed to load " + filename);
	}

	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
	std::move(resource);
	assert(inserted.second);
}


template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::GetResource(Identifier id)
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end);
	return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::GetResource(Identifier id) const
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end);
	return *found->second;
}