#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp> 

using namespace sf;
using namespace std;

int main()
{
    /*
     * Generating main window
     */
    RenderWindow app(VideoMode(800, 600, 32), "Project B", Style::Resize | Style::Close | Style::Titlebar );

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
         * Tests
         */
         
         
        // Filling the screen with black
        app.clear();

        // Displaying the window
        app.display();
    }
    
    /*
     * The end
     */
    return EXIT_SUCCESS;
}
