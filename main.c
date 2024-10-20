#include "snake.h"

void defaite()
{
    printf("\n\033[0;31mVous avez perdu !\033[0m\n\n");
    exit(1);
}

void victoire()
{
    printf("\n\033[0;31mVous avez perdu !\033[0m\n\n");
    exit(1);
}

int main(int argc, char const *argv[])
{
    initSDL();
    int sortie = play();

    if (sortie == -1)
    {
        victoire();
    }
    else
    {
        defaite();
    }

    cleanupSDL();
    return 0;
}
