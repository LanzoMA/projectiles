#include <SFML/Graphics.hpp>
#include "particle.hpp"
#include "simulation.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char** argv) {
    // std::cout << "Number of arguments provided: " << argc << '\n';

    const double velocity =  argc == 3 ? atof(argv[1]) : 95;
    const double angle = argc == 3 ? atof(argv[2]) : 45;

    // std::cout << "Velocity: " << velocity << '\n';
    // std::cout << "Angle: " << angle << '\n';

    const size_t SCREEN_WIDTH = 1280;
    const size_t SCREEN_HEIGHT = 720;
    const char* WINDOW_NAME = "2D Projectile Motion Simulation";

    const float particleRadius = 12.5f;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_NAME);

    Particle particle(particleRadius);
    particle.project(velocity, angle);

    startSimulation(window, particle);

    return 0;
}

