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

   if (!m_resourceManager.loadResources())
   {
       std::cout << "Program can not be launched because some resources can not be loaded!" << std::endl;
       return false;
   }

   auto windowWidth = m_iniFile.GetInteger("display", "width", DEFAULT_WINDOW_WIDTH);
   auto windowHeight = m_iniFile.GetInteger("display", "height", DEFAULT_WINDOW_HEIGHT);
   bool isFullscreen = m_iniFile.GetBoolean("display", "fullscreen", false);
   auto windowStyle = (isFullscreen) ? sf::Style::Fullscreen : sf::Style::Titlebar | sf::Style::Close;

   m_window.create(sf::VideoMode(windowWidth, windowHeight), "MultiSnake", windowStyle);

   return true;
}

void Application::run()
{
    if (!initialize())
    {
        return;
    }

    runGameLoop();
}

void Application::runGameLoop()
{
    sf::Text text;
    text.setFont(*m_resourceManager.getFont(ResourceManager::FontType::Header).get());
    text.setString("Hullo");
    text.setPosition(200, 200);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(60);

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        m_window.clear(sf::Color::Black);
        m_window.draw(text);

        m_window.display();
    }
}



