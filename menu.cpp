#include "menu.h"
#include<SFML/Graphics.hpp>
#include<iostream>

Menu::Menu(float width, float height)
{
    sf::Color color1(0,0,0,255);
    sf::Color color2(255,255,255,255);
    
    if(!font.loadFromFile("arial.ttf"))
    {
    }
    items[0].setFont(font);
    items[0].setColor(color2);
    items[0].setString("PLAY");
    items[0].setPosition(sf::Vector2f(width / 3, height / 4 *1));


    items[1].setFont(font);
    items[1].setColor(color1);
    items[1].setString("OPTIONS");
    items[1].setPosition(sf::Vector2f(width / 3, height / 4 *2));
    
    items[2].setFont(font);
    items[2].setColor(color1);
    items[2].setString("EXIT");
    items[2].setPosition(sf::Vector2f(width /3, height / 4 *3));

    chosenitem = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
    int i;
    for(i = 0; i < 3; i++)
    {
        window.draw(items[i]);
    }
}

void Menu::UP()
{
    sf::Color color1(0,0,0,255);
    sf::Color color2(255,255,255,255);
    if(chosenitem >= 1)
    {
        items[chosenitem].setColor(color1);
        chosenitem--;
        items[chosenitem].setColor(color2);

    }
}

void Menu::DOWN()
{   sf::Color color1(0,0,0,255);
    sf::Color color2(255,255,255,255);
    if(chosenitem < 2)
    {
        items[chosenitem].setColor(color1);
        chosenitem++;
        items[chosenitem].setColor(color2);
    }
}