#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "menu.h"
#include<iostream>

int main()
{
    sf::RenderWindow window(sf:: VideoMode(800,600), "Nazwa okna");
    window.setFramerateLimit(60);
    sf::Event event;
    sf::Color color(184 ,3 ,205, 200);
    Menu items(window.getSize().x, window.getSize().y);
    
    while(1)
    {
        
        
        
        
        while (window.pollEvent(event))
        {
            
            switch(event.type)
            {   case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {   
                        case sf::Keyboard::Up:
                            items.UP();
                            break;
                        case sf::Keyboard::Down:
                            items.DOWN();
                            break;
                        
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        
        }

    
        window.clear(color);
        items.draw(window);

        window.display();

        
    }
    return 0;
}