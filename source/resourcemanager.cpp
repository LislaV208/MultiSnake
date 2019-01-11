#include "resourcemanager.h"

#include <vector>
#include <iostream>

const std::map<ResourceManager::FontType, const std::string> fontTypeToFilename = {
    { ResourceManager::FontType::Header, "Gameplay.ttf" },
    { ResourceManager::FontType::Text, "game_over.ttf" }
};

ResourceManager::ResourceManager()
{

}

bool ResourceManager::loadResources()
{
    if (!loadFonts())
        return false;

    return true;
}

FontSharedPtr ResourceManager::getFont(ResourceManager::FontType type)
{
    return m_fonts.at(type);
}

bool ResourceManager::loadFonts()
{
    int fontsCount = static_cast<int>(ResourceManager::FontType::Count);

    for (int i = 0; i < fontsCount; ++i)
    {
        auto fontPtr = std::make_shared<sf::Font>();
        auto type = static_cast<ResourceManager::FontType>(i);
        auto filename = fontTypeToFilename.at(type);

        if (!fontPtr->loadFromFile("fonts/" + filename))
        {
            std::cout << "Font " + filename + "can not be loaded!" << std::endl;
            return false;
        }

        m_fonts[type] = fontPtr;
    }

    return true;
}
