#ifdef CARENGINE_H
#define CARENGINE_H

#include<iostream>
#include<string>

class Engine:
{
    private:
    string engineType;
    public:
    Engine();
    void setEngineType(string engT);
    string getEngineType();
    bool isHighPerfomance();
}

class Car:
{
    private:
    string carName;
    Engine* engine;
    public:
    void setCarName(string cN);
    string getCarName();
    void setCarEngine(Engine &eng);
    Engine* getCarEngine();
    bool isSportsCar();
}

#endif
