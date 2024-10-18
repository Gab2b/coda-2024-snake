#include "snake.h"

void ajouterCorps(Position *tete, int x, int y)
{
    Position *nouveau;
    nouveau->x = x;
    nouveau->y = y;
    nouveau->next = tete;
    tete = nouveau;
}

void enleverCorps(Position *tete)
{
    Position *temp = tete;
    tete = tete->next;
    free(temp);
}