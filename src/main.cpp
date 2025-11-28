#define kInitialDummyHealth 50
#define kInitialPlayerPosition 0
#define kAttackDamage 5
#define kMoveRight 'd'
#define kMoveLeft 'a'
#define kAttack 'f'
#define kQuitLoop 'q'

#include <iostream>

//struct to hold the game state
struct GameState
{
    int dummyHealth;
    int playerPosition;
    bool isRunning;

};

//funtion to initialize the game state
void initializeGame(GameState& state)
{
    state.dummyHealth = kInitialDummyHealth;
    state.playerPosition = kInitialPlayerPosition;
    state.isRunning = true;
}

//function to print the state of the game
void printState(const GameState& state)
{
    std::cout<<"Dummy Health: "<<state.dummyHealth <<std::endl;
    std::cout<<"Player Position: "<<state.playerPosition<<std::endl;
    std::cout<<"\n";
}

//function to print instructions
void printInstructions(){
    std::cout<<"=====SketchFighter Console Prototype=====" << std::endl;
    std::cout<<"press a to move left!"<<std::endl;
    std::cout<<"press d to move right!"<<std::endl;
    std::cout<<"press f to attack!"<<std::endl;
    std::cout<<"press q to quit!"<<std::endl;
}

//function to process player input/command
void processInput(GameState& state,char input)
{
    std::cout << "Enter command (a=left, d=right, f=attack, q=quit): ";
     std::cin>>input;
    if(input==kMoveLeft)
    {
        state.playerPosition--;
        std::cout<<"player moved to left!"<<std::endl;
    }
    else if(input==kMoveRight)
    {
        state.playerPosition++;
        std::cout<<"player moved to right!"<<std::endl;
    }
    else if(input==kAttack)
    {
        state.dummyHealth-=kAttackDamage;
        if(state.dummyHealth<=0)
        {
            std::cout<<"You won!! Dummy got defeated!"<<std::endl;
            state.isRunning=false;
        }
        else 
        {
            std::cout<<"Dummy got hit!"<<std::endl;
        }
    }
    else if(input==kQuitLoop)
    {
        std::cout<<"player quit!"<<std::endl;
        state.isRunning=false;
    }
    else
    {
        std::cout<<"No such key!"<<std::endl;
    }
}

//function to run the game loop
void runGameLoop(GameState& state)
{
    char input;
    while(state.isRunning)
    {
        printState(state);
        processInput(state,input);
    }
}

int main() 
{
    //declare game state
    GameState state;
    //initialize game
    initializeGame(state);
    //print instructions
    printInstructions();
    //game loop
    runGameLoop(state);
    return 0;
}

