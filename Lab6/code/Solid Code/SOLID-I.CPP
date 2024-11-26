#include <iostream>

// Interface for flying animals
class IFlyable
{
public:
    virtual void fly() = 0;
};

// Interface for swimming animals
class ISwimmable
{
public:
    virtual void swim() = 0;
};

// Bird class implementing IFlyable
class Bird : public IFlyable
{
public:
    void fly() override
    {
        std::cout << "Bird is flying" << std::endl;
    }
};

// Fish class implementing ISwimmable
class Fish : public ISwimmable
{
public:
    void swim() override
    {
        std::cout << "Fish is swimming" << std::endl;
    }
};

int main()
{
    Bird bird;
    Fish fish;

    bird.fly();  // Bird is flying
    fish.swim(); // Fish is swimming

    return 0;
}