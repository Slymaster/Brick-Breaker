#!/bin/sh -x

g++ -c main.cpp Observer.cpp GameEntity.cpp;
g++ main.o Observer.o GameEntity.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system;
./sfml-app
