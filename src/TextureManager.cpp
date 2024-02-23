#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

unordered_map<string, sf::Texture> TextureManager::textures;

sf::Texture& TextureManager::getTexture(std::string textureName) {
    auto result = textures.find(textureName);
    if(result == textures.end()) {
        /// TEXTURE DOES NOT ALREADY EXIST IN THE MAP, GO GET IT ///
        sf::Texture newTexture;
        newTexture.loadFromFile("images/" + textureName + ".png");
        textures[textureName] = newTexture;
        return textures[textureName];
    }
    else {
        /// TEXTURE ALREADY EXIST ///
        return result->second;
    }
}
