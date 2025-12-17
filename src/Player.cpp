#include "Player.hpp"
#include "constants.hpp"

void Player::initialize(const sf::Vector2f& startPosition)
{
    m_health = kPlayerHealth;
    m_speed = kPlayerSpeed;
    m_position = startPosition;
    m_shape.setSize(sf::Vector2f(kPlayerWidth,kPlayerHeight));
    m_shape.setFillColor(sf::Color::White);
    m_shape.setPosition(m_position);
    m_velocity = sf::Vector2f(0.f,0.f);
}
sf::FloatRect Player::getBounds() const
{
    return m_shape.getGlobalBounds();
}
void Player::update(float delta)
{
        //Horizontal Input handling
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                m_position.x -= m_speed * delta;
            }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                m_position.x+=m_speed*delta;
            }

        
        //Compute ground
        const float groundY = kWindowHeight - kPlayerHeight;
        bool onGround = m_position.y >= groundY;

        //Jump
        if(onGround && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            m_velocity.y = -kJumpSpeed;
        }

        //Applying Gravity
        if(m_position.y < groundY)
        {
            m_velocity.y += kGravity * delta;
        }
        //Velocity integration
        m_position.y += m_velocity.y * delta;

        //Clamping
        if(m_position.x<0)
        {
            m_position.x=0;
        }

        float maxX=kWindowWidth-kPlayerWidth;
        if(m_position.x>maxX)
        {
            m_position.x=maxX;
        }
        if(m_position.y<0.f)
        {
            m_position.y=0.f;
            if(m_velocity.y<0.f)
            {
                m_velocity.y=0.f;
            }
        }
        if(m_position.y> groundY)
        {
            m_position.y = groundY;
            if(m_velocity.y>0.f)
            {
                m_velocity.y=0.f;
            }
        }
        //Apply to player
        m_shape.setPosition(m_position);
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(m_shape);
}