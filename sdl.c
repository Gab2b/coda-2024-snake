#include "snake.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* textureBuissons = NULL;
SDL_Texture* textureHerbe = NULL;
SDL_Texture* textureSnake = NULL;
SDL_Rect image = {0, 0, 16, 16};
SDL_Rect image2 = {16, 0, 16, 16};

void cleanupSDL()
{
    SDL_DestroyTexture(textureBuissons);
    SDL_DestroyTexture(textureHerbe);
    SDL_DestroyTexture(textureSnake);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("Error SDL2 Init : %s\n", SDL_GetError());
        return 1;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) 
    {
        printf("Erreur d'initialisation de la SDL_Image\n");
        return 1;
    }

    window = SDL_CreateWindow("Turbo Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 320, SDL_WINDOW_OPENGL);
    if (window == NULL)
    {
        printf("Error Window Creation\n");
        return 3;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) 
    {
        printf("Erreur à la création du renderer\n");
        return 1;
    }

    SDL_Surface* buissons = IMG_Load("buisson.png");
    if (buissons == NULL) 
    {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }

    textureBuissons = SDL_CreateTextureFromSurface(renderer, buissons);
    if (textureBuissons == NULL) 
    {
        printf("Error creating texture\n");
        return 1;
    }

    SDL_Surface* herbe = IMG_Load("herbe.png");
    if (herbe == NULL) 
    {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }

    textureHerbe = SDL_CreateTextureFromSurface(renderer, herbe);
    if (textureHerbe == NULL) 
    {
        printf("Error creating texture\n");
        return 1;
    }

    SDL_Surface* snake = IMG_Load("snake.png");
    if (snake == NULL) 
    {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }

    textureSnake = SDL_CreateTextureFromSurface(renderer, snake);
    if (textureSnake == NULL) 
    {
        printf("Error creating texture\n");
        return 1;
    }

    SDL_Surface* pomme = IMG_Load("pomme.png");
    if (pomme == NULL) 
    {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }

    texturePomme = SDL_CreateTextureFromSurface(renderer, pomme);
    if (texturePomme == NULL) 
    {
        printf("Error creating texture\n");
        return 1;
    }
    SDL_FreeSurface(pomme);


    SDL_Rect rect;
    for (int i = 0; i < 320; i += 32) {
        rect = (SDL_Rect){i, 0, 32, 32};
        SDL_RenderCopy(renderer, textureBuissons, NULL, &rect);
        rect = (SDL_Rect){i, 288, 32, 32};
        SDL_RenderCopy(renderer, textureBuissons, NULL, &rect);
        rect = (SDL_Rect){0, i, 32, 32};
        SDL_RenderCopy(renderer, textureBuissons, NULL, &rect);
        rect = (SDL_Rect){288, i, 32, 32};
        SDL_RenderCopy(renderer, textureBuissons, NULL, &rect);
    }

    for (int y = 32; y < 288; y += 32) {
        for (int x = 32; x < 288; x += 32) {
            rect = (SDL_Rect){x, y, 32, 32};
            SDL_RenderCopy(renderer, textureHerbe, NULL, &rect);
        }
    }

    SDL_RenderPresent(renderer);
}