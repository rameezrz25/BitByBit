# Polymorphism in C++

Polymorphism is a core concept in object-oriented programming that allows objects to be treated as instances of their parent class rather than their actual class. There are two types of polymorphism in C++:

## Compile-Time Polymorphism

Compile-time polymorphism is achieved through function overloading and operator overloading. It is also known as static polymorphism.

### Function Overloading

Function overloading allows multiple functions with the same name but different parameters to be defined.

### Operator Overloading

Operator overloading allows custom implementation for operators.

## Run-Time Polymorphism

Run-time polymorphism is achieved through inheritance and virtual functions. It is also known as dynamic polymorphism.

### Virtual Functions

Virtual functions allow derived classes to override methods in the base class.

### Pure Virtual Functions

- A pure virtual function is a virtual function that is declared by assigning 0 in its declaration.
- It is used to create an abstract class, which cannot be instantiated and is intended to be a base class for other classes.
- Derived classes must override pure virtual functions, otherwise, they will also become abstract classes.
- Pure virtual functions enforce a contract for derived classes to implement specific behavior.

Example:
```cpp
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    virtual void show() {
        cout << "Base class show function called" << endl;
    }
    virtual void pureVirtualFunction() = 0; // Pure virtual function
};

// Derived class
class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show function called" << endl;
    }
    void pureVirtualFunction() override {
        cout << "Derived class pure virtual function implementation" << endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;

    // Run-time polymorphism
    basePtr->show(); // Calls Derived class show function
    basePtr->pureVirtualFunction(); // Calls Derived class pure virtual function implementation

    return 0;
}
```

### Explanation

1. **Base Class**: The `Base` class contains a virtual function `show()` and a pure virtual function `pureVirtualFunction()`. The pure virtual function makes `Base` an abstract class.
2. **Derived Class**: The `Derived` class inherits from `Base` and overrides both the `show()` and `pureVirtualFunction()` methods.
3. **Main Function**: In the `main()` function, a pointer of type `Base` is used to point to an object of `Derived`. This demonstrates run-time polymorphism where the overridden methods in the `Derived` class are called using the base class pointer.

This example illustrates how virtual functions and pure virtual functions enable run-time polymorphism in C++. The `show()` function demonstrates overriding, while the `pureVirtualFunction()` enforces a contract for derived classes to implement specific behavior.