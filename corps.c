#include "snake.h"

void ajouterCorps(Position **tete, int x, int y, SDL_Renderer* renderer, const char* texturePath)
{
    Position *nouveau = (Position*)malloc(sizeof(Position));
    nouveau->rect.x = x;
    nouveau->rect.y = y;
    nouveau->rect.w = 32;
    nouveau->rect.h = 32;
    nouveau->next = NULL;

    SDL_Surface* surface = IMG_Load(texturePath);
    if (surface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", texturePath, IMG_GetError());
        free(nouveau);
        return;
    }
    nouveau->texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (*tete == NULL) {
        *tete = nouveau;
    } else {
        Position *current = *tete;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nouveau;
    }
}

void enleverCorps(Position **tete)
{
    if (*tete == NULL) {
        return;
    }

    Position *temp = *tete;
    *tete = (*tete)->next;
    SDL_DestroyTexture(temp->texture);
    free(temp);
}