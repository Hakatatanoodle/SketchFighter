#pragma once

#include<SFML/Graphics.hpp>
class Enemy 
{
    public:
    void initialize(const sf::Vector2f& enemyStartPosition);
    void render(sf::RenderWindow& window);
    void takeDamage(int damageAmount);
    sf::FloatRect getBounds() const;

    private: 
    sf::RectangleShape m_shape;
    sf::Vector2f m_position;
    int m_health;
    bool m_isAlive;
};