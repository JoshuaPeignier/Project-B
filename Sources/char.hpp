#ifndef CHAR_INCLUDE
#define CHAR_INCLUDE

#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp> 
#include <SFML/System/Time.hpp>
#include "AnimatedSprite.hpp"

class Character{

    private:
        sf::Vector2f pos;
        float speed;
        double size;
        std::string name;
        sf::Clock frameClock;
        sf::Time frameTime = frameClock.restart();
        
        sf::Texture texture;
        Animation walkingAnimationLeft;
        Animation walkingAnimationRight;
        Animation walkingAnimationUp;
        Animation walkingAnimationDown;
        Animation* currentAnimation;
        AnimatedSprite* animatedSprite;
    public:
        Character();
        Character(sf::Vector2i screenDimensions, std::string s);
        ~Character();
        
        void goTo(sf::Vector2f newPos);
        void move(sf::Vector2f& move, float coeffSpeed);
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void moveUpLeft();
        void moveUpRight();
        void moveDownLeft();
        void moveDownRight();
        void stopMoving();
        
        void loadTextureStr(std::string s);
        void loadTexture(sf::Texture& txtr);
        
        void draw(sf::RenderWindow& window);
};

#endif // CHAR_INCLUDE
