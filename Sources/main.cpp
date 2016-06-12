#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp> 
#include "char.hpp"

using namespace sf;
using namespace std;

int main()
{
    /*
     * Generating main window
     */
    Vector2i screenDimensions(800,600);
    RenderWindow app(VideoMode(screenDimensions.x, screenDimensions.y), "Project B", Style::Resize | Style::Close | Style::Titlebar );
    app.setFramerateLimit(60);

    /*
     * All Initialisations
     */
    Character player(screenDimensions,"Onyx");
     
    /*
     * Main loop
     */
    while (app.isOpen())
    {
        // Dealing with events
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            
        }

        /*
         * Pressing keys
         */
        bool noKeyWasPressed = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                player.moveUpLeft();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                player.moveUpRight();
            }
            else{
                player.moveUp();
            }
            noKeyWasPressed = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                player.moveDownLeft();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                player.moveDownRight();
            }
            else{
                player.moveDown();
            }
            noKeyWasPressed = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            player.moveLeft();
            noKeyWasPressed = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            player.moveRight();
            noKeyWasPressed = false;
        }
        else if (noKeyWasPressed){
            player.stopMoving();
        }

        /*
         * Tests
         */
         
         
        // Filling the screen with black
        app.clear();
        
        // Drawing the object
        player.draw(app);

        // Displaying the window
        app.display();
    }
    
    /*
     * The end
     */
    return EXIT_SUCCESS;
}
