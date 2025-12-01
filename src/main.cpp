#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    const float playerSpeed = 200.f;
    std::cout<<"=====SketchFighter SFML Prototype====="<<std::endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SketchFighter Prototype");
    std::cout<<"Window created!"<<std::endl;
    window.setFramerateLimit(60);

    sf::Vector2f playerPosition;
    sf::Clock clock;
    while(window.isOpen())
    {
        sf::Event event;
        float delta =clock.restart().asSeconds();
        while(window.pollEvent(event))
        {
            
            if(event.type==sf::Event::Closed)
            {
                std::cout<<"window closed!"<<std::endl;
                window.close();
            }
                                
            if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Escape)
            {
                std::cout<<"Escape key pressed!"<<std::endl;
                window.close();
            }
            
            
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                playerPosition.x-=playerSpeed*delta;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                playerPosition.x+=playerSpeed*delta;

            }
        
        window.clear(sf::Color::Black);
        sf::RectangleShape player(sf::Vector2f(50.f,100.f));
        player.setFillColor(sf::Color::White);
        player.setPosition(playerPosition);
        window.draw(player);
        window.display();

    }
    std::cout<<"exiting main"<<std::endl;
    return 0;
}