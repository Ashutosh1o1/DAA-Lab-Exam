#include <iostream>  
  
// Base class  
class Bird {  
public:  
    virtual void fly() {  
        std::cout << "Flying" << std::endl;  
    }  
};  
  
// Derived class  
class Sparrow : public Bird {  
public:  
    void fly() override {  
        std::cout << "Sparrow flying" << std::endl;  
    }  
};  
  
// Derived class  
class Penguin : public Bird {  
public:  
    void fly() override {  
        // Penguins can't fly, so we might break LSP  
        std::cout << "Penguin can't fly" << std::endl;  
    }  
};  
  
int main() {  
    Bird* b1 = new Sparrow();  
    b1->fly();  // Sparrow flying  
      
    Bird* b2 = new Penguin();  
    b2->fly();  // Penguin can't fly  
      
    delete b1;  
    delete b2;  
      
    return 0;  
} 