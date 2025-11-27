#include <iostream>

//function to print the state of the game
void printState(int dummyHealth,int playerPosition)
{
    std::cout<<"Dummy Health: "<<dummyHealth <<std::endl;
    std::cout<<"Player Position: "<<playerPosition<<std::endl;
    std::cout<<"\n";
}


int main() 
{
    //constant declarations
    const int  kInitialDummyHealth=50;
    const int kInitialPlayerPosition=0;
    const int kAttackDamage=5;
    const char kMoveRight='d';
    const char kMoveLeft='a';
    const char kAttack='f';
    const char kQuitLoop='q';

    int dummyHealth=kInitialDummyHealth,playerPosition=kInitialPlayerPosition;
    char input;
    std::cout << "=====SketchFighter Console Prototype=====" << std::endl;
    std::cout<<"press a to move left!"<<std::endl;
    std::cout<<"press d to move right!"<<std::endl;
    std::cout<<"press f to attack!"<<std::endl;
    std::cout<<"press q to quit!"<<std::endl;
    bool isRunning =true;

    //game loop
    while(isRunning && dummyHealth>0)
    {
        printState(dummyHealth,playerPosition);
        std::cout << "Enter command (a=left, d=right, f=attack, q=quit): ";
        std::cin>>input;
       if(input==kMoveLeft)
       {
        playerPosition--;
        std::cout<<"player moved to left!"<<std::endl;
       }
       else if(input==kMoveRight)
       {
        playerPosition++;
        std::cout<<"player moved to right!"<<std::endl;
       }
       else if(input==kAttack)
       {
        dummyHealth-=kAttackDamage;
        std::cout<<"You won!! Dummy got defeated!"<<std::endl;
       }
       else if(input==kQuitLoop)
       {
        std::cout<<"player quit!"<<std::endl;
        isRunning=false;
       }
       else
       {
        std::cout<<"No such key!"<<std::endl;
       }
    }
    return 0;
}

