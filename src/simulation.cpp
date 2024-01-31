#include <SFML/Graphics.hpp>
#include "particle.hpp"
#include "simulation.hpp"
#include <iostream>

void handleEvents(sf::RenderWindow& window) {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) { 
            window.close(); 
        }
    }
}

void startSimulation(sf::RenderWindow& window, Particle& particle) {
    window.clear(sf::Color(219, 39, 99));
    window.draw(particle);
    window.display();

    sf::Clock clock;

    while (clock.getElapsedTime().asSeconds() < 1.f) {
        handleEvents(window);
    }
    
    clock.restart();
    
    while (window.isOpen()) {
        handleEvents(window);

        sf::Int64 deltaTime = clock.getElapsedTime().asMicroseconds();
        // std::cout << "deltaTime (seconds): " << deltaTime << '\n';
        particle.updatePosition(deltaTime);
        clock.restart();

        window.clear(sf::Color(176, 219, 67));
        window.draw(particle);
        window.display();
    }
}

