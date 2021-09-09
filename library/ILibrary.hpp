/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** Ilibrari
*/

#ifndef ILibrari_HPP_
#define ILibrari_HPP_

#include <iostream>
#include <memory>

typedef enum {
    NO_INPUT = -1,
    UP_ARROW,
    DOWN_ARROW,
    LEFT_ARROW,
    RIGHT_ARROW,
    TAB,
    ENTER,
    SPACE,
    N_TOUCH,
    Q_TOUCH,
    Z_TOUCH,
    D_TOUCH,
    S_TOUCH,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7
} Input;

namespace LIB
{
    class ILibrari {
        public:
            virtual ~ILibrari() = default;
            virtual void drawMainMenu() = 0;
            virtual void windowWin() = 0;
            virtual void windowLoose() = 0;
            virtual Input getInput() = 0;
            virtual void initStart() = 0;
            virtual void playSound() = 0;
            virtual void stopSound() = 0;
            virtual void drawTextNameScore() = 0;
            virtual int getExit() const = 0;
            virtual int getGame() const = 0;
            virtual int getLib() const = 0;
            virtual void destroyWindow() = 0;
    };
};

#endif /* !ILibrari_HPP_ */
