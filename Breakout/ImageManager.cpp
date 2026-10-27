#include "ImageManager.h"
#include <random>
#include <stdexcept>


bool ImageManager::loadTexture(const std::string& filename)
{
	sf::Texture displayTexture;
	if (!displayTexture.loadFromFile(filename))
	{
		std::cerr << "Failed to load texture: " << filename << "\n";
		return false;
	}

	displayTexture.setSmooth(true);
	displayImages.push_back(std::move(displayTexture));
	return true;
}

const sf::Texture& ImageManager::getRandomTexture() const
{
	if (displayImages.size() == 1)
	{
		lastIndex = 0;
		return displayImages[0];
	}
}
