#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "inih/INIReader.h"

class Application
{
public:
    Application();

    void run();

private:
    bool initialize();
    sf::RenderWindow m_window;

    INIReader m_iniFile;
};

#endif // APPLICATION_H
