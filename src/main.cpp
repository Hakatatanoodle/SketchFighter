#include <SFML/Graphics.hpp>
#include <iostream>

//Constants
constexpr unsigned int kWindowWidth = 800;//using unsigned as videoMode() function takes unsigned int as parameters
constexpr unsigned int kWindowHeight = 600;
constexpr float kPlayerWidth = 50.f;
constexpr float kPlayerHeight = 100.f;
constexpr float kPlayerSpeed=200.f;
constexpr float kGravity =  1200.f;
constexpr float kJumpSpeed = 600.f;

class Player{
    public:
    
        //initialization function
        void initialize(sf::Vector2f startPosition)
        {
          m_shape = sf::RectangleShape(sf::Vector2f(kPlayerWidth,kPlayerHeight));
          m_shape.setFillColor(sf::Color::White);
          m_shape.setPosition(startPosition);
          m_speed = kPlayerSpeed;
          m_velocity = sf::Vector2f(0.f,0.f);
          m_position = startPosition;
        };
        void update(float delta)
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
        };
        void render(sf::RenderWindow& window)
        {
            window.draw(m_shape);
        };
    private:
        sf::RectangleShape m_shape;
        sf::Vector2f m_velocity;
        sf::Vector2f m_position;
        float m_speed;
};



//Event handling function
void handleEvents(sf::RenderWindow& window,Player& player)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            {
                std::cout<<"window closed!"<<std::endl;
                window.close(); 
            }
                                
            if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::Escape)
            {
                std::cout<<"Escape key pressed!"<<std::endl;
                window.close();
            }
    }
}



int main()
{
    std::cout<<"=====SketchFighter SFML Prototype=====" << std::endl;

    sf::RenderWindow window(
        sf::VideoMode(kWindowWidth, kWindowHeight),
        "SketchFighter Prototype");
    window.setFramerateLimit(60);

    Player player;
    player.initialize(sf::Vector2f(
        (kWindowWidth  - kPlayerWidth) /2.f,
        (kWindowHeight - kPlayerHeight)/2.f
    ));

    sf::Clock clock;
    while(window.isOpen())
    {
        float delta = clock.restart().asSeconds();

        handleEvents(window,player);
        player.update(delta);
        window.clear(sf::Color::Black);
        player.render(window);
        window.display();
    }
    std::cout<<"exiting main"<<std::endl;
    return 0;
}