#include<iostream>
#include<string>
#include "carengine.h"

using namespace std;

void Engine::setEngineType(string engT)
{
    engineType = engT;
}
string Engine::getEngineType()
{
    return engineType;
}
bool Engine::isHighPerfomance()
{
    return(engineType = "V8" || engineType = "Turbo");
}
void Car::setCarName(string cN)
{
    carName = cN;
}
string Car::getCarName()
{
    return carName;
}
void Car::setCarEngine(Engine &eng)
{
    engine = &eng;
}
Engine* Car::getCarEngine()
{
    return engine;
}
bool isSportsCar();
{
    return(engine->isHighPerfomance());
}