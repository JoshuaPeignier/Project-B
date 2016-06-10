#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp> 

class Character{
    private:
        int x;
        int y;
        int size;
        std::string name;
        sf::Texture texture;
        sf::Sprite sprite;
    public:
        Character();
        Character(int x0, int y0, std::string s);
        ~Character();
        
        void goTo(int x0, int y0);
        void move(int dx, int dy);
        
        void loadTextureStr(std::string s);
        void loadTexture(sf::Texture& txtr);
        
        void draw(sf::RenderWindow& window);
};
