#include "Enemy.hpp"
#include "constants.hpp"

void Enemy::initialize(const sf::Vector2f& enemyStartPosition)
{
    m_shape = sf::RectangleShape(sf::Vector2f(kEnemyWidth,kEnemyHeight));
    m_shape.setFillColor(sf::Color::Red);
    m_position = enemyStartPosition;
    m_shape.setPosition(m_position);   
    m_health = kEnemyHealth;
    m_isAlive = true;
}

sf::FloatRect Enemy::getBounds() const 
{
    return m_shape.getGlobalBounds();
}

void Enemy::takeDamage(int damageAmount)
{
    m_health -= damageAmount;
    if(m_health<=0)
    {
        m_isAlive = false;
    }
}

void Enemy::render(sf::RenderWindow& window)
{
    if(!m_isAlive)
    {
        return ;
    }
    else{
        window.draw(m_shape);
    }
}