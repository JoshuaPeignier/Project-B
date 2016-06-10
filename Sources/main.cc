#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp> 
#include "char.hh"

using namespace sf;
using namespace std;

int main()
{
    /*
     * Generating main window
     */
    RenderWindow app(VideoMode(800, 600, 32), "Project B", Style::Resize | Style::Close | Style::Titlebar );



    /*
     * All Initialisations
     */
    Character player(400,300,"Onyx");
     
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            player.move(0,-1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            player.move(0,1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            player.move(-1,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            player.move(1,0);
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
