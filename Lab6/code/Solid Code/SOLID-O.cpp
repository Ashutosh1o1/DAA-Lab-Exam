#include <iostream>

// Base class with a virtual method
class Shape
{
public:
    virtual double area() const = 0; // pure virtual function
    virtual ~Shape() = default;
};

// Circle class extending Shape
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() const override
    {
        return 3.14 * radius * radius;
    }
};

// Rectangle class extending Shape
class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override
    {
        return width * height;
    }
};

int main()
{
    Circle c(5);
    Rectangle r(3, 4);

    std::cout << "Area of Circle: " << c.area() << std::endl;
    std::cout << "Area of Rectangle: " << r.area() << std::endl;

    return 0;
}