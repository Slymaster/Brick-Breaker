#include "GameEntity.hh"

int GameEntity::getScore()
{
    return score;
}

void  GameEntity::notify()
{
    for(int i = 0; i < observerList.size(); i++)
        observerList[i]->update();// error solve here with: https://stackoverflow.com/questions/12027656/pointer-to-incomplete-class-type-is-not-allowed/12027678
}

void GameEntity::setScore(int S)
{
    score = score + S;
}

void GameEntity::subscribe(Observer *observer)
{
    observerList.push_back(observer);
}