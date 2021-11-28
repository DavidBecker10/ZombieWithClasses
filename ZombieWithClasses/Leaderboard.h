#ifndef ZOMBIEWITHCLASSES_LEADERBOARD_H
#define ZOMBIEWITHCLASSES_LEADERBOARD_H

#include<map>
#include"GraphicManager.h"
#include "EventManager.h"
#include "Ent.h"

class LeaderBoard : 
    public Ent
{
private:
    std::multimap<unsigned int, std::string> scores;
    //Managers::GraphicManager* GM;
    Managers::EventManager* EM;
    Vector2F position;
    Vector2F size;
    int offset;
    unsigned int mouseID;
    unsigned int fontSize;
    const char* path;

public:
    LeaderBoard(Vector2F pos = { 0.0f }, Vector2F siz = { 0.0f }, unsigned int fSize = 16);
    ~LeaderBoard();

    void initialize(Managers::EventManager& em);
    void subscribe();
    void update(float t);
    void addScore(const unsigned int score, const std::string name);
    void loadScores();
    void removeListeners();
    void setPosition(const Vector2F pos) { position = pos; }
    void setSize(const Vector2F siz) { size = siz; };
    void setFontSize(const unsigned int fSize) { fontSize = fSize; };
    std::multimap<unsigned int, std::string> getRanking() { return scores; };
};


#endif //ZOMBIEWITHCLASSES_LEADERBOARD_H
