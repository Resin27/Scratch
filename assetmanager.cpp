#include "assetmanager.h"

sf::Texture& AssetManager::getTexture(std::string textureFile)
{
    std::map<std::string, sf::Texture>::iterator it = texture.find(textureFile);
    if(it == texture.end())
    {
        if(!texture[textureFile].loadFromFile(textureFile))
        {
            std::cout << "Unable to load texture from " << textureFile << std::endl;
        }
    }

    return texture[textureFile];
}

sf::Font& AssetManager::getFont(std::string fontFile)
{
    std::map<std::string, sf::Font>::iterator it = font.find(fontFile);
    if(it == font.end())
    {
        if(!font[fontFile].loadFromFile(fontFile))
        {
            std::cout << "Unable to load font from " << fontFile << std::endl;
        }
    }

    return font[fontFile];
}

bool AssetManager::loadTexture(std::string textureFile)
{
    return texture[textureFile].loadFromFile(textureFile);
}

bool AssetManager::loadFont(std::string fontFile)
{
    return font[fontFile].loadFromFile(fontFile);
}

