#include <iostream>

// Abstraction (interface)
class IPrinter
{
public:
    virtual void print() = 0;
};

// Low-level module
class LaserPrinter : public IPrinter
{
public:
    void print() override
    {
        std::cout << "Printing with Laser Printer" << std::endl;
    }
};

// High-level module
class Document
{
private:
    IPrinter *printer;

public:
    Document(IPrinter *p) : printer(p) {}
    void print()
    {
        printer->print();
    }
};

int main()
{
    LaserPrinter laserPrinter;
    Document doc(&laserPrinter);
    doc.print(); // Printing with Laser Printer
    return 0;
}