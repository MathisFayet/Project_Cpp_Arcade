/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "../../IGame.hpp"

typedef struct s_snakePos {
    int posX;
    int posY;
} snakePos_t;

typedef enum {
    SNAKE,
    WALL,
    EAT
} ElemMap;

typedef struct s_map {
   int x;
   int y;
   ElemMap elemMap;
} map_t;

namespace AllForOne {
    class Nibbler : public IGame {
        public:
            Nibbler();
            ~Nibbler();
            void initAll();
            void gameLoop();

            void LeftKey();
            void RightKey();
            void UpKey();
            void DownKey();

            void readMap();

            int getExit() const;
            int getScore() const;

        private:
            int exit;
            int score;
            int sizeSnake;
            std::vector<map_t> map;
    };
}

#endif /* !NIBBLER_HPP_ */
