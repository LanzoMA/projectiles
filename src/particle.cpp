#include <SFML/Graphics.hpp>
#include "constants.h"
#include "particle.hpp"
#include <cmath>
#include <iostream>

Particle::Particle(const float radius) : sf::CircleShape(radius) { 
    this->setOrigin(radius/2, radius/2);
    this->setFillColor(sf::Color(45, 40, 45));
    this->setPosition(150.f, 550.f);
    this->initialVerticalPosition = 550.f;
}

Particle::~Particle() { }

void Particle::project(const double velocity, const double degrees) {
    const double radians = degrees * (PI / 180);

    // std::cout << "Radians: " << radians << '\n';

    this->verticalVelocity = velocity * sin(radians);
    this->horizontalVelocity = velocity * cos(radians);
}

void Particle::updatePosition(sf::Int64 deltaTime) {
    const float uncertainty = 0.01;
    const float groundLevel = this->initialVerticalPosition;
    const double deltaTimeInSeconds = deltaTime * microSecondsToSeconds;

    sf::Vector2f position = this->getPosition();

    // std::cout << "X: " << position.x << " Y: " << position.y << "\n";
    // std::cout << "Horizonal Velocity: " << this->horizontalVelocity << " Vertical Velocity: " << this->verticalVelocity << "\n";
    
    const double horizontalDistanceTravelled = this->horizontalVelocity * deltaTimeInSeconds;
    const double verticalDistanceTravelled = this->verticalVelocity * deltaTimeInSeconds;

    const double distanceFromGround = this->initialVerticalPosition - position.y;

    this->move(horizontalDistanceTravelled, -(verticalDistanceTravelled));

    if (this->verticalVelocity >= -uncertainty && this->verticalVelocity <= uncertainty && distanceFromGround > 0) {
        std::cout << "Maximum Height Reached: " << distanceFromGround << "m\n";
    }
    
    if (distanceFromGround > -uncertainty) {
        this->verticalVelocity -= GRAVITY * deltaTimeInSeconds;
        return;
    }

    this->verticalVelocity = 0;
}
