#include "snake.h"

void play()
{
    SDL_Event e;
    image.x=0;
    SDL_RenderCopy(renderer, textureSnake, &image, &display);
    SDL_RenderPresent(renderer);
    

    int direction = SDL_SCANCODE_D;

    int game = 1;
    while (game)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                game = 0;
            }
            
            if (e.type == SDL_KEYDOWN)
            {
                SDL_Rect oldDisplay = display;
                switch (e.key.keysym.scancode) 
                {
                    case SDL_SCANCODE_W:
                        if (display.y >= 64)
                        {
                            display.y -= 32;
                        }
                        break;
                    case SDL_SCANCODE_D:
                        if (display.x <= 224)
                        {
                            display.x += 32;
                        }
                        break;
                    case SDL_SCANCODE_S:
                        if (display.y <= 224)
                        {
                            display.y += 32;
                        }
                        break;
                    case SDL_SCANCODE_A:
                        if (display.x >= 64)
                        {
                            display.x -= 32;
                        }
                        break;
                }
            
                SDL_RenderCopy(renderer, textureHerbe, NULL, &oldDisplay);
                
                SDL_RenderCopy(renderer, textureSnake, &image, &display);
                SDL_RenderPresent(renderer);
            }
        }
    }
}