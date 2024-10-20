#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <time.h>

#define RESIMG 16

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* textureBuissons;
extern SDL_Texture* textureHerbe;
extern SDL_Texture* textureSnake;
extern SDL_Texture* texturePomme;
extern SDL_Rect display;
extern SDL_Rect image;

typedef struct corps {
    int x;
    int y;
    struct corps* next; 
} Position;

void play();
int initSDL();
void cleanupSDL();
void ajouterCorps(Position **tete, int x, int y);
void enleverCorps(Position **tete);
void genererPomme(SDL_Rect* rect);
int collision(SDL_Rect* a, SDL_Rect* b);
int bordureCollision(SDL_Rect* rect);

#endif 