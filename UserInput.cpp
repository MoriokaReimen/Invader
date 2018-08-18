/*!
 * \file UserInput.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief UserInputクラスの実装
 */
#include<UserInput.hpp>

#include<GameSystem.hpp>
#include<InputKeep.hpp>

#include<ncurses.h>

UserInput::UserInput()
{
    return;
}

UserInput::~UserInput()
{
    /*NO OP*/
}

char UserInput::store()
{
    InputKeep* keep = GameSystem::getInputKeep();
    SDL_Event event;
    char ch;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                keep->store(GAME_END);
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                case SDLK_k:
                    ch = 'k';
                    keep->store(UP);
                    break;
                case SDLK_j:
                    ch = 'j';
                    keep->store(DOWN);
                    break;
                case SDLK_h:
                    ch = 'h';
                    keep->store(RIGHT);
                    break;
                case SDLK_l:
                    ch = 'l';
                    keep->store(LEFT);
                    break;
                case SDLK_s:
                    ch = 's';
                    keep->store(SHOOT);
                    break;
                case SDLK_b:
                    ch = 'b';
                    keep->store(BOMB);
                    break;
                case SDLK_q:
                    ch = 'q';
                    keep->store(GAME_END);
                    break;
                default:
                    break;
                }
        default:
            break;
        }

    }

    return ch;
}

