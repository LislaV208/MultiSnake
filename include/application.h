#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "simpleini/SimpleIni.h"
#include "resourcemanager.h"

class Application
{
public:
    Application();

    void run();

private:    
    bool initialize();
    void runGameLoop();

    sf::RenderWindow m_window;

    CSimpleIniA m_iniFile;
    ResourceManager m_resourceManager;

};

#endif // APPLICATION_H
