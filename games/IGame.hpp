/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <vector>
#include <memory>

typedef enum {
    NO_INPT = -1,
    LEFTKEY,
    RIGHTKEY,
    UPKEY,
    DOWNKEY,
    ENTRER,
    QUIT
} input;

namespace AllForOne {
    class IGame {
        public:
            virtual ~IGame() = default;
            virtual int getExit() const = 0;
            virtual int getScore() const = 0;
            virtual void initAll() = 0;
            virtual void gameLoop() = 0;
    };
}
#endif /* !IGAME_HPP_ */
