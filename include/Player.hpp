#pragma once

#include<SFML/Graphics.hpp>

class Player
{
    public:
        void initialize(const sf::Vector2f& startPosition);
        sf::FloatRect getBounds() const;
        void update(float delta);
        void render(sf::RenderWindow& window);
    private:
        sf::RectangleShape m_shape;
        sf::Vector2f m_velocity;
        sf::Vector2f m_position;
        float m_speed;
        int m_health;
};