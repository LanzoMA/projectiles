#pragma once

#include <SFML/Graphics.hpp>
#include "particle.hpp"

void handleEvents(sf::RenderWindow& window);
void startSimulation(sf::RenderWindow& window, Particle& particle);
