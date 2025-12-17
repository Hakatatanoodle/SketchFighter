#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"
#include "constants.hpp"

//Event handling function
void handleEvents(sf::RenderWindow& window)
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

void handleAttack(Player& player,Enemy& enemy)
{
    if(player.getBounds().intersects(enemy.getBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        enemy.takeDamage(kAttackDamage);
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
    Enemy enemy;
    enemy.initialize(sf::Vector2f(100.f,400.f));
    player.initialize(sf::Vector2f(
        (kWindowWidth  - kPlayerWidth) /2.f,
        (kWindowHeight - kPlayerHeight)/2.f
    ));

    sf::Clock clock;
    while(window.isOpen())
    {
        float delta = clock.restart().asSeconds();

        handleEvents(window);
        player.update(delta);

        handleAttack(player,enemy);
        window.clear(sf::Color::Black);
        player.render(window);
        enemy.render(window);
        window.display();
    }
    std::cout<<"exiting main"<<std::endl;
    return 0;
}