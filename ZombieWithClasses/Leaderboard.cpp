#include "LeaderBoard.h"
#include <iostream>
#include <fstream>

LeaderBoard::LeaderBoard(Vector2F pos, Vector2F siz, unsigned int fSize) :
    mouseID(0), path("../saves/leaderboard.txt"), position(pos), size(siz), fontSize(fSize) {
    loadScores();
}

LeaderBoard::~LeaderBoard() {

}

void LeaderBoard::initialize(Managers::EventManager& em)
{
    EM = &em;
}



void LeaderBoard::addScore(const unsigned int score, const std::string name) {
    scores.emplace(score, name);
    std::ofstream file;
    file.open(path, std::fstream::in | std::fstream::ate);
    file << score << ' ' << name << std::endl;
    file.close();
}

void LeaderBoard::loadScores() {
    std::ifstream file;
    file.open(path);

    if (!file.is_open()) std::cout << "Leaderboard not found" << std::endl;
    else {
        unsigned int score;
        std::string name;
        while (file >> score >> name) {
            scores.emplace(score, name);
        }
    }
    file.close();
}

void LeaderBoard::removeListeners() {
    if (mouseID != 0) {
        EM->removeListenMouse(mouseID);
        mouseID = 0;
    }
}