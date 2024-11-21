# Friend Function in C++

## Overview
A friend function in C++ is a function that is not a member of a class but has access to the class's private and protected members. This is useful for operations that require access to the internal state of the class, which cannot be achieved through public member functions alone.

## Syntax
To declare a friend function, use the `friend` keyword inside the class definition.

```cpp
class MyClass {
private:
    int privateVar;

public:
    MyClass(int val) : privateVar(val) {}

    // Declare friend function
    friend void displayPrivateVar(const MyClass& obj);
};

// Definition of friend function
void displayPrivateVar(const MyClass& obj) {
    std::cout << "Private Variable: " << obj.privateVar << std::endl;
}
```

## Example
Here is an example demonstrating the use of a friend function in C++:

```cpp
#include <iostream>

class MyClass {
private:
    int privateVar;

public:
    MyClass(int val) : privateVar(val) {}

    // Declare friend function
    friend void displayPrivateVar(const MyClass& obj);
};

// Definition of friend function
void displayPrivateVar(const MyClass& obj) {
    std::cout << "Private Variable: " << obj.privateVar << std::endl;
}

int main() {
    MyClass obj(42);
    displayPrivateVar(obj); // Accessing private member using friend function
    return 0;
}
```

## Explanation
In the example above:
- `MyClass` has a private member variable `privateVar`.
- The friend function `displayPrivateVar` is declared inside the class `MyClass` using the `friend` keyword.
- The friend function `displayPrivateVar` is defined outside the class and has access to the private member `privateVar`.
- In the `main` function, an object `obj` of `MyClass` is created, and the friend function `displayPrivateVar` is called to display the value of the private member `privateVar`.

