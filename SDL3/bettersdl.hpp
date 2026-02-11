#ifndef BETTERSDL_HPP
#define BETTERSDL_HPP

#include <SDL3/SDL.h>
#include <iostream>
#include <string>

namespace bettersyntax
{
    namespace sdl
    {
        class Engine
        {
        private:
            SDL_Window* window = nullptr;
            SDL_Renderer* renderer = nullptr;
            bool running = true;

        public:
            /**
             * Initializes the SDL3 video subsystem, creates a window and a renderer.
             */
            Engine(const char* title, int w, int h)
            {
                if (!SDL_Init(SDL_INIT_VIDEO))
                {
                    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
                    running = false;
                    return;
                }

                window = SDL_CreateWindow(title, w, h, 0);
                if (!window)
                {
                    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
                    running = false;
                    return;
                }

                renderer = SDL_CreateRenderer(window, NULL);
                if (!renderer)
                {
                    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
                    running = false;
                    return;
                }
            }

            /**
             * Handles core application events such as quitting.
             */
            void update()
            {
                SDL_Event event;
                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_EVENT_QUIT)
                    {
                        running = false;
                    }
                }
            }

            /**
             * Clears the current rendering target with the SyntaX brand color.
             * Default: Neon Purple (#BC13FE)
             */
            void clear(uint8_t r = 188, uint8_t g = 19, uint8_t b = 254)
            {
                SDL_SetRenderDrawColor(renderer, r, g, b, 255);
                SDL_RenderClear(renderer);
            }

            /**
             * Presents the finalized frame to the window.
             */
            void render()
            {
                SDL_RenderPresent(renderer);
            }

            /**
             * Returns the current state of the engine loop.
             */
            bool isRunning() const
            {
                return running;
            }

            /**
             * Ensures proper cleanup of SDL3 resources.
             */
            ~Engine()
            {
                if (renderer)
                {
                    SDL_DestroyRenderer(renderer);
                }

                if (window)
                {
                    SDL_DestroyWindow(window);
                }

                SDL_Quit();
            }
        };
    }
}

#endif
