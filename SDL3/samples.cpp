/**
 * SyntaX v2.0 - SDL3 Integration Sample
 * Demonstrates the Allman style coding and the SyntaX modular architecture.
 */

#include "bettersdl.hpp"

int main(int argc, char* argv[])
{
    // Create an instance of the SyntaX SDL Engine
    // Parameters: Title, Width, Height
    bettersyntax::sdl::Engine app("SyntaX Engine v2.0 - SDL3 Sample", 1280, 720);

    // Standard Application Loop
    while (app.isRunning())
    {
        // Handle input and window events
        app.update();

        // Clear the screen with the default SyntaX Neon Purple
        app.clear();

        // Swap buffers to display the rendered frame
        app.render();
    }

    return 0;
}
