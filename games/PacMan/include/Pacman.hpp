/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../../../librari/ILibrari.hpp"
#include "../../IGame.hpp"

namespace AllForOne {
    class Pacman {
        public:
            Pacman();
            ~Pacman();
            void MoveWithInput(Input input);
            std::string GameName();
            std::string GetBackground();
            void GameReset();


        protected:
        private:
            std::vector<Input> _OkInput;
            std::vector<Input> _RIGHT;
            std::vector<Input> _UP;
            std::vector<Input> _LEFT;
            std::vector<Input> _DOWN;
            std::vector<Input> _DIR;
            bool _Miam;
            unsigned int _Score;
            bool _Animation;
            bool _GameOver;
            std::vector<AllForOne::Pacman> _Background;
    };
}
#endif /* !PACMAN_HPP_ */
