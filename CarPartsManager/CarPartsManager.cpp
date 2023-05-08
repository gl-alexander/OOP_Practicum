#include <iostream>
#include "Tyre.h"

class Engine : public CarPart
{
    unsigned _hp;
public :
    Engine(unsigned id, const MyString& manufacturer, const MyString& desc, unsigned hp) : CarPart(id, manufacturer, desc)
    {
        _hp = hp;
    }
    friend std::ostream& operator<<(std::ostream& os, const Engine& engine);
};

std::ostream& operator<<(std::ostream& os, const Engine& engine)
{
    os << (const CarPart&)engine;
    os << " - " << engine._hp << " horsepower.";
    return os;
}

class Battery : public CarPart
{
    unsigned _capacity;
    MyString _batteryId;

public:
    Battery(unsigned id, const MyString& manufacturer, const MyString& desc, unsigned capacity, const MyString& batteryId) : CarPart(id, manufacturer, desc)
    {
        _capacity = capacity;
        _batteryId = batteryId;
    }
    friend std::ostream& operator<<(std::ostream& os, const Battery& battery);
};

std::ostream& operator<<(std::ostream& os, const Battery& battery)
{
    os << (const CarPart&)battery;
    os << " - " << battery._capacity << " Ah";
    return os;
}

int main()
{
    Engine eng(1, "BMW", "Engine component", 120);
    std::cout << eng;
}
