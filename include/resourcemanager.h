#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>

#include <map>
#include <memory>

using FontSharedPtr = std::shared_ptr<sf::Font>;

class ResourceManager
{
public:

    enum class FontType
    {
        Header,
        Text,
        Count
    };

    ResourceManager();

    bool loadResources();

    FontSharedPtr getFont(ResourceManager::FontType type);

private:
    bool loadFonts();

    std::map<ResourceManager::FontType, FontSharedPtr> m_fonts;
};

#endif // RESOURCEMANAGER_H
