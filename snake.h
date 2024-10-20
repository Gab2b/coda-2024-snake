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
extern SDL_Rect image;
extern SDL_Rect image2;

typedef struct corps {
    SDL_Rect rect;
    SDL_Texture* texture;
    struct corps* next; 
} Position;

int play();
int initSDL();
void cleanupSDL();
void ajouterCorps(Position **tete, int x, int y, SDL_Renderer* renderer, const char* texturePath);
void enleverCorps(Position **tete);
void genererPomme(SDL_Rect* rect, Position* snake, int game);
int collision(SDL_Rect* a, SDL_Rect* b);
int bordureCollision(SDL_Rect* rect);
void defaite();
void victoire();

#endif