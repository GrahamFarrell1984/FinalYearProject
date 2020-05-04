#include "App.h"

// Main method - entry point to the game
int main()
{
    App app; // Create an instance of the App class

    // Check if the game has been set up correctly
    if (app.setup()) {
        // If it has been set up correctly then call the run() method
        app.run();
    }
    return 0;
}
