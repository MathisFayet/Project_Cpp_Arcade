/*
** EPITECH PROJECT, 2021
** saveScore.cpp
** File description:
** produce
*/

#include "../include/SFML.hpp"


LIB::SaveScore::SaveScore()
{
    this->score = 0;
    this->higthScore = 0;
}

LIB::SaveScore::~SaveScore()
{}

void LIB::SaveScore::createFilePacman(std::string name, int score)
{
    std::ofstream file;
    file.open("save/Pacman.txt", std::ios::out);
    if (file.bad())
        return;
    file << name << ":" << score;
    file.close();
}

void LIB::SaveScore::createFileSnake(std::string name, int score)
{
    std::ofstream file;
    file.open("save/Snake.txt", std::ios::out);
    if (file.bad())
        return;
    file << name << ":" << score;
    file.close();

}

void LIB::SaveScore::saveDataPacman(std::string name, int score)
{
    std::ofstream file;
    std::ifstream is("save/Pacman.txt");

    if (!is) {
        is.close();
        createFilePacman(name, score);
    } else {
        std::ofstream file;

        is.close();
        file.open("save/Pacman.txt", std::ios::app);
        file << std::endl;
        file << name << ":" << score;
        file.close();
    }
}

void LIB::SaveScore::saveDataSnake(std::string name, int score)
{
    std::ofstream file;
    std::ifstream is("save/Snake.txt");

    if (!is) {
        is.close();
        createFileSnake(name, score);
    } else {
        std::ofstream file;

        is.close();
        file.open("save/Snake.txt", std::ios::app);
        file << std::endl;
        file << name << ":" << score;
        file.close();
    }
}

std::vector<score_t> LIB::SaveScore::getHightScorePacman()
{
    std::vector<score_t> map;
    score_t score;
    std::ifstream file("save/Pacman.txt");
    std::string tmp;

    while (std::getline(file, tmp)) {
        score.name = tmp.substr(0, tmp.find(':'));
        score.score = std::atoi(tmp.substr(tmp.find(':') + 1, tmp.length()).c_str());
        std::cout << score.name << ": " << score.score << std::endl;
        map.push_back(score);
    }
    return (map);
}

std::vector<score_t> LIB::SaveScore::getHightScoreSnake()
{
    std::vector<score_t> map;
    score_t score;
    std::ifstream file("save/Snake.txt");
    std::string tmp;

    while (std::getline(file, tmp)) {
        score.name = tmp.substr(0, tmp.find(':'));
        score.score = std::atoi(tmp.substr(tmp.find(':') + 1, tmp.length()).c_str());
        map.push_back(score);
    }
    return (map);
}

void LIB::SaveScore::saveDataGame(std::string name, int score, LIB::SaveScore::Game game)
{
    if (game == LIB::SaveScore::Game::PACMAN) {
        saveDataPacman(name, score);
    }
    if (game == LIB::SaveScore::Game::SNAKE) {
        saveDataSnake(name, score);
    }
}