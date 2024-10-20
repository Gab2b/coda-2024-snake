#include "snake.h"

SDL_Texture* texturePomme;
SDL_Rect pomme;

void genererPomme(SDL_Rect* rect) {
    rect->x = (rand() % 9) * 32 + 32;
    rect->y = (rand() % 9) * 32 + 32;
    rect->w = 32;
    rect->h = 32;
}

int collision(SDL_Rect* a, SDL_Rect* b) {
    return (a->x == b->x && a->y == b->y);
}

int bordureCollision(SDL_Rect* rect) {
    return (rect->x < 32 || rect->x >= 288 || rect->y < 32 || rect->y >= 288);
}

void play() {
    SDL_Event e;
    image.x = 0;
    int direction = SDL_SCANCODE_D;
    int game = 1;

    int oldy = 0;
    int oldx = 0;

    // Initialiser la liste chaînée avec la tête du serpent
    Position* snake = NULL;
    ajouterCorps(&snake, display.x, display.y);

    // Initialiser la génération aléatoire
    srand(time(NULL));
    genererPomme(&pomme);

    // Dessiner la tête du serpent et la pomme à la position initiale
    SDL_RenderCopy(renderer, texturePomme, NULL, &pomme);
    SDL_RenderCopy(renderer, textureSnake, &image, &display);
    SDL_RenderPresent(renderer);

    while (game) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                game = 0;
            }

            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.scancode) {
                    case SDL_SCANCODE_W:
                        direction = SDL_SCANCODE_W;
                        break;
                    case SDL_SCANCODE_D:
                        direction = SDL_SCANCODE_D;
                        break;
                    case SDL_SCANCODE_S:
                        direction = SDL_SCANCODE_S;
                        break;
                    case SDL_SCANCODE_A:
                        direction = SDL_SCANCODE_A;
                        break;
                }
            }
        }

        SDL_Rect oldDisplay = display;

        // Mettre à jour la position de la tête du serpent en fonction de la direction actuelle
        switch (direction) {
            case SDL_SCANCODE_W:
                oldy = display.y;
                display.y -= 32;
                break;
            case SDL_SCANCODE_D:
                oldx = display.x;
                display.x += 32;
                break;
            case SDL_SCANCODE_S:
                oldy = display.y;
                display.y += 32;
                break;
            case SDL_SCANCODE_A:
                oldx = display.x;
                display.x -= 32;
                break;
        }

        // Vérifier la collision avec les bords
        if (bordureCollision(&display)) {
            game = 0; // Terminer le jeu si le serpent touche les bords
            continue;
        }

        // Vérifier la collision avec la pomme
        if (collision(&display, &pomme)) {
            // Ajouter un nouveau segment au corps du serpent
            ajouterCorps(&snake, oldx, oldy);
            // Générer une nouvelle position pour la pomme
            genererPomme(&pomme);
        } else {
            // Supprimer le dernier segment du serpent pour simuler le mouvement
            enleverCorps(&snake);
        }

        // Effacer l'ancienne position de la tête du serpent
        SDL_RenderCopy(renderer, textureHerbe, NULL, &oldDisplay);

        // Dessiner le corps du serpent
        Position* current = snake;
        while (current != NULL) {
            SDL_Rect segmentRect = {current->x, current->y, 32, 32};
            SDL_RenderCopy(renderer, textureSnake, &image, &segmentRect);
            current = current->next;
        }

        // Dessiner la pomme
        SDL_RenderCopy(renderer, texturePomme, NULL, &pomme);
        SDL_RenderCopy(renderer, textureSnake, &image, &display);
        SDL_RenderPresent(renderer);

        // Délai pour contrôler la vitesse du serpent
        SDL_Delay(300); // Ajuster le délai selon les besoins
    }

    // Libérer la mémoire du corps du serpent
    while (snake != NULL) {
        enleverCorps(&snake);
    }
}