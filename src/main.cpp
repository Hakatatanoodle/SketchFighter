#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    const float playerSpeed = 200.f;
    const float windowWidth = 800.f;
    const float windowHeight = 600.f;
    const float playerWidth = 50.f;
    const float playerHeight = 100.f;

    std::cout<<"=====SketchFighter SFML Prototype=====" << std::endl;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SketchFighter Prototype");
    std::cout<<"Window created!" << std::endl;
    window.setFramerateLimit(60);

    
    sf::Vector2f playerPosition(
        (windowWidth-playerWidth)/2.f,
        (windowHeight-playerHeight)/2.f 
    );
    sf::RectangleShape player(sf::Vector2f(playerWidth,playerHeight));
    player.setFillColor(sf::Color::White);
    player.setPosition(playerPosition);

    sf::Clock clock;
    while(window.isOpen())
    {
        float delta = clock.restart().asSeconds();

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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                playerPosition.x -= playerSpeed * delta;
                //Applying clamping to the left side of the window
                if(playerPosition.x < 0)
                {
                    playerPosition.x = 0;
                }
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                playerPosition.x+=playerSpeed*delta;
                //Applying clamping to the right side of the window
                float maxX=windowWidth-playerWidth;
                if(playerPosition.x>maxX)
                {
                    playerPosition.x=maxX;
                }

            }
        
        window.clear(sf::Color::Black);
        player.setPosition(playerPosition);
        window.draw(player);
        window.display();

    }
    std::cout<<"exiting main"<<std::endl;
    return 0;
}