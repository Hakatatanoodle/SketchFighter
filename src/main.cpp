#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    std::cout<<"=====SketchFighter Console Prototype====="<<std::endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SketchFighter Prototype");
    std::cout<<"Window created!"<<std::endl;
    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        sf::Event event;
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
        window.clear(sf::Color::Black);

        sf::RectangleShape player(sf::Vector2f(50.f,100.f));
        player.setFillColor(sf::Color::White);
        player.setPosition(375.f,250.f);

        window.draw(player);
        window.display();

    }
    std::cout<<"exiting main"<<std::endl;
    return 0;
}