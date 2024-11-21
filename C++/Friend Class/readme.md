# Friend Class in C++

## Overview
A friend class in C++ is a class that has access to the private and protected members of another class. This is useful for closely related classes that need to share data and functions that are not meant to be exposed to the outside world.

## Syntax
To declare a friend class, use the `friend` keyword inside the class definition.

```cpp
class ClassA {
private:
    int privateVar;

public:
    ClassA(int val) : privateVar(val) {}

    // Declare friend class
    friend class ClassB;
};

class ClassB {
public:
    void displayPrivateVar(const ClassA& obj) {
        std::cout << "Private Variable: " << obj.privateVar << std::endl;
    }
};
```

## Example
Here is an example demonstrating the use of a friend class in C++:

```cpp
#include <iostream>

class ClassA {
private:
    int privateVar;

public:
    ClassA(int val) : privateVar(val) {}

    // Declare friend class
    friend class ClassB;
};

class ClassB {
public:
    void displayPrivateVar(const ClassA& obj) {
        std::cout << "Private Variable: " << obj.privateVar << std::endl;
    }
};

int main() {
    ClassA objA(42);
    ClassB objB;
    objB.displayPrivateVar(objA); // Accessing private member using friend class
    return 0;
}
```

## Explanation
In the example above:
- `ClassA` has a private member variable `privateVar`.
- The friend class `ClassB` is declared inside the class `ClassA` using the `friend` keyword.
- The member function `displayPrivateVar` of `ClassB` has access to the private member `privateVar` of `ClassA`.
- In the `main` function, an object `objA` of `ClassA` and an object `objB` of `ClassB` are created. The member function `displayPrivateVar` of `ClassB` is called to display the value of the private member `privateVar` of `ClassA`.
