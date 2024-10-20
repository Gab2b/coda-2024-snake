#include "snake.h"

SDL_Texture* texturePomme;
SDL_Rect pomme;

void genererPomme(SDL_Rect* rect, Position* snake, int game)
{
    int collision;
    do {
        collision = 0;
        rect->x = (rand() % 8) * 32 + 32;
        rect->y = (rand() % 8) * 32 + 32;
        rect->w = 32;
        rect->h = 32;

        Position* current = snake;
        int i = 1;
        while (current != NULL) {
            if (current->rect.x == rect->x && current->rect.y == rect->y)
            {
                collision = 1;
                break;
            }
            current = current->next;
            i++;
        }

        if (i == 63)
        {
            collision = 1;
            game = -1;
        }
    } while (collision);
}

int collision(SDL_Rect* a, SDL_Rect* b) {
    return (a->x == b->x && a->y == b->y);
}

int bordureCollision(SDL_Rect* rect) {
    return (rect->x < 32 || rect->x >= 288 || rect->y < 32 || rect->y >= 288);
}

int corpsCollision(Position* snake) {
    SDL_Rect* headRect = &snake->rect;
    Position* current = snake->next; 
    while (current != NULL) {
        if (collision(headRect, &current->rect)) {
            return 1; 
        }
        current = current->next;
    }
    return 0; 
}

int play() {
    SDL_Event e;
    image.x = 0;
    int direction = SDL_SCANCODE_D;
    int game = 1;
    int delay = 450;

    Position* snake = NULL;
    ajouterCorps(&snake, 128, 128, renderer, "snake.png");

    srand(time(NULL));
    genererPomme(&pomme, snake, game);

    SDL_RenderCopy(renderer, snake->texture, &image, &snake->rect);
    SDL_RenderCopy(renderer, texturePomme, NULL, &pomme);
    SDL_RenderPresent(renderer);

    while (game == 1)
    {
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

        SDL_Rect oldHeadRect = snake->rect;

        Position* current = snake;
        while (current != NULL) {
            SDL_RenderCopy(renderer, textureHerbe, NULL, &current->rect);
            current = current->next;
        }

        current = snake;
        SDL_Rect prevRect = current->rect;
        while (current->next != NULL) {
            SDL_Rect tempRect = current->next->rect;
            current->next->rect = prevRect;
            prevRect = tempRect;
            current = current->next;
        }

        switch (direction) {
            case SDL_SCANCODE_W:
                snake->rect.y -= 32;
                break;
            case SDL_SCANCODE_D:
                snake->rect.x += 32;
                break;
            case SDL_SCANCODE_S:
                snake->rect.y += 32;
                break;
            case SDL_SCANCODE_A:
                snake->rect.x -= 32;
                break;
        }

        if (bordureCollision(&snake->rect))
        {
            game = 0; 
            continue;
        }
        if (corpsCollision(snake)) {
            game = 0; 
            continue;
        }
        if (collision(&snake->rect, &pomme))
        {
            Position* last = snake;
            while (last->next != NULL) {
                last = last->next;
            }
            ajouterCorps(&last, prevRect.x, prevRect.y, renderer, "snake.png");
            genererPomme(&pomme, snake, game);
            delay -= 7;
        }

        SDL_RenderCopy(renderer, textureHerbe, NULL, &oldHeadRect);

        current = snake;
        while (current != NULL)
        {
            if (current == snake)
            {
                SDL_RenderCopy(renderer, current->texture, &image, &current->rect);
            }
            else
            {
                SDL_RenderCopy(renderer, current->texture, &image2, &current->rect);
            }
            current = current->next;
        }


        SDL_RenderCopy(renderer, texturePomme, NULL, &pomme);
        SDL_RenderPresent(renderer);

        SDL_Delay(delay); 
    }

    while (snake != NULL)
    {
        enleverCorps(&snake);
    }

    return game;
}