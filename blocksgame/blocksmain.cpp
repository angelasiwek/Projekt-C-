#include<iostream> 
#include "Blocksgame.h"

int main()
{
    std::srand(static_cast<unsigned>(time(NULL)));
    BlocksGame game;

    sf::Event event;
    
    
    
    

    while(game.isrunning() && game.isGameOver() == 0)
    {
        game.updategame();
        
        game.render();
        

    }
    
    
    return 0;
}