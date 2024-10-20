#include "snake.h"

void ajouterCorps(Position **tete, int x, int y)
{
    Position *nouveau = (Position*)malloc(sizeof(Position));
    nouveau->x = x;
    nouveau->y = y;
    nouveau->next = *tete;
    *tete = nouveau;
}

void enleverCorps(Position **tete)
{
    if (*tete == NULL) return;

    Position *temp = *tete;
    *tete = (*tete)->next;
    free(temp);
}