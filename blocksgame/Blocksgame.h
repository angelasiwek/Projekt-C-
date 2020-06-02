
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<iostream>
#include<vector>
#include<ctime>
#include<iomanip>
#include<sstream>

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
        void initFont();
        void initText();
        //game objects
        sf::RectangleShape enemy;
        std::vector<sf::RectangleShape> enemies;
        sf::CircleShape _friend;
        std::vector<sf::CircleShape> friends;
        sf::CircleShape hero;
        sf::Vector2f HeroPosition; 
        std::vector<sf::CircleShape> hearts;
        sf::Font font;
        sf::Text text;
        //game logic
        float enemySpawnTime;
        float enemySpawnTimeMAX;
        float friendSpawnTime;
        float friendSpawnTimeMAX;
        int friendsMAX;
        int enemiesMAX;
        float points;
        int health;
        bool gameover;
   

    public: 
    //Konstruktory i destruktory
        BlocksGame();
        virtual ~BlocksGame();

        const bool isrunning() const; 

    //Funkcje
        void updategame();
        void render();
        void updateEvents();
        int updateHeroPosition(int key);
        void updateEnemies();
        void renderEnemies();
        void updateFriends();
        void renderFriends();
        void renderHero();
        void spawnFriends();
        void spawnEnemies();
        void renderText();
        void updateText();
        int isGameOver();
    //void updateHero();

};