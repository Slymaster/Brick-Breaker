#include "Libs.hh"

#ifndef GAMEENTITY_HH
#define GAMEENTITY_HH

class GameEntity
{
    std::vector <class Observer *> observerList;//list of observer
    int score =  0;

public:
    void setScore(int S);
    int getScore();
    void subscribe (Observer *observer);//take an observer and add it in the list
    void notify();

};
#endif