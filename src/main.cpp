#include <iostream>

//function to print the state of the game
void printState(int dummyHealth,int playerPosition)
{
    std::cout<<"Health: "<<dummyHealth <<std::endl;
    std::cout<<"Position: "<<playerPosition<<std::endl;
    std::cout<<"\n";
}


int main() 
{
    int dummyHealth=50,playerPosition=0;
    char input;

    std::cout << "=====SketchFighter Console Prototype=====" << std::endl;
    std::cout<<"press a to left!"<<std::endl;
    std::cout<<"press d to go right!"<<std::endl;
    std::cout<<"press f  to attack!"<<std::endl;
    std::cout<<"press q to quit!"<<std::endl;
    
    
    for(int i=0;i<=dummyHealth;i++)
    {
        printState(dummyHealth,playerPosition);
        printf("Enter any key: ");
        std::cin>>input;
       if(input=='a')
       {
        playerPosition--;
        std::cout<<"player moved to left!"<<std::endl;
       }
       else if(input=='d')
       {
        playerPosition++;
        std::cout<<"player moved to right!"<<std::endl;
       }
       else if(input=='f')
       {
        dummyHealth-=5;
        std::cout<<"player got hit!"<<std::endl;
       }
       else if(input=='q')
       {
        std::cout<<"player quit!"<<std::endl;
        break;
       }
       else
       {
        std::cout<<"No such key!"<<std::endl;
       }
    }
    return 0;
}

