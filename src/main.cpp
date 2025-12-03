#include <SFML/Graphics.hpp>
#include <iostream>

//Constants
constexpr unsigned int kWindowWidth = 800;//using unsigned as videoMode() function takes unsigned int as parameters
constexpr unsigned int kWindowHeight = 600;
constexpr float kPlayerWidth = 50.f;
constexpr float kPlayerHeight = 100.f;
constexpr float kPlayerSpeed=200.f;

struct GameState
{
    sf::Vector2f playerPosition;
    float playerSpeed;
    sf::RectangleShape player;
};

//initialization function
void init(GameState& state)
{
    state.playerPosition =  sf::Vector2f(
        (kWindowWidth-kPlayerWidth)/2.f,
        (kWindowHeight-kPlayerHeight)/2.f 
    );
    state.playerSpeed = kPlayerSpeed;
    state.player = sf::RectangleShape(sf::Vector2f(kPlayerWidth,kPlayerHeight));
    state.player.setFillColor(sf::Color::White);
    state.player.setPosition(state.playerPosition);
}

//Event handling function
void handleEvents(sf::RenderWindow& window,GameState& state)
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

void update(GameState& state,float delta)
{
    //Input handling
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                state.playerPosition.x -= state.playerSpeed * delta;
            }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                state.playerPosition.x+=state.playerSpeed*delta;
            }

        //Clamping
        if(state.playerPosition.x<0)
        {
            state.playerPosition.x=0;
        }

        float maxX=kWindowWidth-kPlayerWidth;
        if(state.playerPosition.x>maxX)
        {
            state.playerPosition.x=maxX;
        }
        //Apply to player
        state.player.setPosition(state.playerPosition);
}

void render(sf::RenderWindow& window,const GameState& state)
{
    window.clear(sf::Color::Black);
    window.draw(state.player);
    window.display();
}
int main()
{
    std::cout<<"=====SketchFighter SFML Prototype=====" << std::endl;

    sf::RenderWindow window(
        sf::VideoMode(kWindowWidth, kWindowHeight),
        "SketchFighter Prototype");
    window.setFramerateLimit(60);

    GameState state;
    init(state);


    sf::Clock clock;
    while(window.isOpen())
    {
        float delta = clock.restart().asSeconds();

        handleEvents(window,state);
        update(state,delta);
        render(window,state);
    }
    std::cout<<"exiting main"<<std::endl;
    return 0;
}