#include "game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::gameRun()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SYWAR THE QUEST OF JAAJ");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        render(window);
        window.display();
    }
}

void Game::render(sf::RenderWindow& window)
{

}
