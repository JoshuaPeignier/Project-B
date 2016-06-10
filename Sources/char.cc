#include "char.hh"

using namespace std;
using namespace sf;

Character::Character(){}

Character::Character(int x0, int y0, string s): x(x0), y(y0), name(s){
    loadTextureStr("Sprites/Character/Red.png");
    sprite.setPosition((float) x0, (float) y0);
}

Character::~Character(){}

void Character::move(int dx, int dy){
    if(dx > 0){loadTextureStr("Sprites/Character/Yellow.png");}
    else if(dx < 0){loadTextureStr("Sprites/Character/Green.png");}
    else if(dy > 0){loadTextureStr("Sprites/Character/Blue.png");}
    else if(dy < 0){loadTextureStr("Sprites/Character/Red.png");}
    x += dx;
    y += dy;
    sprite.move((float) dx, (float) dy);
}

void Character::goTo(int x0, int y0){
    x = x0;
    y = y0;
    sprite.setPosition((float) x0, (float) y0);
}

void Character::loadTextureStr(string s){
    texture.loadFromFile(s);
    sprite.setTexture(texture);
}

void Character::loadTexture(Texture& txtr){
    texture = txtr;
    sprite.setTexture(texture);
}

void Character::draw(sf::RenderWindow& window){
    window.draw(sprite);
}
