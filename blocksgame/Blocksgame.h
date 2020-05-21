
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<iostream>
#include<vector>
#include<ctime>

class BlocksGame
{
    private:

        //window
        sf::RenderWindow *window;
        sf::Event event; 
        sf::VideoMode videomode; 
        //funkcje 
        void initWindow();
        void initVariables();
        void initBlocks();
        void initHero();
        void initFriends();
        //game objects
        sf::RectangleShape enemy;
        std::vector<sf::RectangleShape> enemies;
        sf::CircleShape _friend;
        std::vector<sf::CircleShape> friends;
        sf::CircleShape hero;
        sf::Vector2f HeroPosition; 
        


    public: 
    //Konstruktory i destruktory
        BlocksGame();
        virtual ~BlocksGame();

        const bool isrunning() const; 

    //Funkcje
        void updategame();
        void render();
        void updateEvents();
        void updateHeroPosition(int key);
        void updateEnemies();
        void renderEnemies();
        void updateFriends();
        void renderFriends();
        void renderHero();
    //void updateHero();

};