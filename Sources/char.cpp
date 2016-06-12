#include "char.hpp"

using namespace std;
using namespace sf;

// Default constructor
Character::Character(){}

// Constructor which sets the character to an initial position, with its name
Character::Character(Vector2i initial, string s): name(s){

    // Initializing all defaut values
    pos.x = (float) initial.x;
    pos.y = (float) initial.y;
    speed = 80.f;
    
    //Initializing texture and animations
    texture.loadFromFile("Sprites/Character/Link.png");
    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(32, 8, 13, 16));
    walkingAnimationDown.addFrame(sf::IntRect(32, 38, 13, 16));
    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationLeft.addFrame(sf::IntRect(62, 8, 14, 16));
    walkingAnimationLeft.addFrame(sf::IntRect(62, 38, 13, 15));
    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationUp.addFrame(sf::IntRect(93, 8, 12, 16));
    walkingAnimationUp.addFrame(sf::IntRect(93, 38, 12, 16));
    walkingAnimationRight.setSpriteSheet(texture);
    walkingAnimationRight.addFrame(sf::IntRect(122, 8, 14, 16));
    walkingAnimationRight.addFrame(sf::IntRect(122, 38, 13, 15));
    currentAnimation = &walkingAnimationDown;
    
    // Drawing the default sprite
    animatedSprite = new AnimatedSprite(seconds(0.15f), true, false);
    animatedSprite->setPosition(sf::Vector2f(initial/ 2));
}

Character::~Character(){
    free(animatedSprite);
}

void Character::move(Vector2f& movement, float coeffSpeed = 1.){
    frameTime = frameClock.restart();
    movement = movement*speed*coeffSpeed;
    pos = pos+movement;
    animatedSprite->play(*currentAnimation);
    animatedSprite->move(movement * frameTime.asSeconds());
    animatedSprite->update(frameTime);
}

void Character::moveLeft(){
    currentAnimation = &walkingAnimationLeft;
    Vector2f movement(-1.f, 0.f);
    move(movement);
}

void Character::moveRight(){
    currentAnimation = &walkingAnimationRight;
    Vector2f movement(1.f, 0.f);
    move(movement);
}

void Character::moveDown(){
    currentAnimation = &walkingAnimationDown;
    Vector2f movement(0.f, 1.f);
    move(movement);
}

void Character::moveUp(){
    currentAnimation = &walkingAnimationUp;
    Vector2f movement(0.f, -1.f);
    move(movement);
}

void Character::moveUpLeft(){
    currentAnimation = &walkingAnimationLeft;
    Vector2f movement(-1.f, -1.f);
    move(movement,1./1.414);
}

void Character::moveUpRight(){
    currentAnimation = &walkingAnimationRight;
    Vector2f movement(1.f, -1.f);
    move(movement,1./1.414);
}

void Character::moveDownLeft(){
    currentAnimation = &walkingAnimationLeft;
    Vector2f movement(-1.f, 1.f);
    move(movement,1./1.414);
}

void Character::moveDownRight(){
    currentAnimation = &walkingAnimationRight;
    Vector2f movement(1.f, 1.f);
    move(movement,1./1.414);
}

void Character::stopMoving(){
    frameTime = frameClock.restart();
    animatedSprite->stop();
    animatedSprite->play(*currentAnimation);
    animatedSprite->update(frameTime);
}

void Character::goTo(Vector2f newPos){
    pos = newPos;
    animatedSprite->setPosition(pos);
}

void Character::loadTextureStr(string s){
    texture.loadFromFile(s);
}

void Character::loadTexture(Texture& txtr){
    texture = txtr;
}

void Character::draw(sf::RenderWindow& window){
    window.draw(*animatedSprite);
}
