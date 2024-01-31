#pragma once

#include <SFML/Graphics.hpp>

class Particle: public sf::CircleShape {
public:
    Particle(const float radius);
    ~Particle();

    void project(const double velocity, const double angle);
    void updatePosition(sf::Int64 deltaTime);

private:
    double verticalVelocity = 0;
    double horizontalVelocity = 0;
    double initialVerticalPosition;
};
