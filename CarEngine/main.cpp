#include<iostream>
#include<string>
#include "carengine.h"

using namespace std;

int main ()
{
    Engine* e;
    Car c1, c2;
    e.setEngineType("V8");
    c1.setCarName("Toyota");
    c2.setCarName("Honda");
    c1.setCarEngine(&e);
    c2.setCarEngine(&e);
    if(c1.isSportsCar())
    {
        cout<<c1.getCarName<<" is a sports car."<<endl;
    }
    if(c2.isSportsCar())
    {
        cout<<c2.getCarName<<" is a sports car."<<endl;
    }
}