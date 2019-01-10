#include "application.h"

#include "constants.h"

#include <iostream>

Application::Application() :
    m_iniFile("config.ini")
{

}

bool Application::initialize()
{
   if (m_iniFile.ParseError() < 0)
   {
       std::cout << "'config.ini' can not be loaded!" << std::endl;
       return false;
   }

   int windowWidth = m_iniFile.GetInteger("resolution", "width", DEFAULT_WINDOW_WIDTH);
   int windowHeight = m_iniFile.GetInteger("resolution", "height", DEFAULT_WINDOW_HEIGHT);

   m_window.create(sf::VideoMode(windowWidth, windowHeight), "MultiSnake");

   return true;
}

void Application::run()
{
    if (!initialize())
    {
        return;
    }

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }
    }
}

