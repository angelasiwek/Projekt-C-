#include<SFML/Graphics.hpp>

class Menu
{
    public:
        Menu(float width, float height);
        ~Menu();
        void draw(sf::RenderWindow &window);
        void UP();
        void DOWN();
        int GetPressedItem() { return chosenitem; }
         

    private:
    
        int chosenitem;
        sf::Font font;
        sf::Text items[3];
       
};