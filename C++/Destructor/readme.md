# Destructors in C++

A destructor is a special member function that is executed when an object of a class is destroyed. Destructors are used to release resources that the object may have acquired during its lifetime.

## Types of Destructors

### 1. Default Destructor

If no destructor is defined in a class, the compiler provides a default destructor. This destructor does nothing but ensures that the object is destroyed properly.

```cpp
class MyClass {
public:
    // Default destructor provided by the compiler
    ~MyClass() = default;
};
```

### 2. User-Defined Destructor

A user-defined destructor is explicitly defined by the programmer to perform specific cleanup tasks.

```cpp
class MyClass {
public:
    ~MyClass() {
        // Custom cleanup code
        std::cout << "Destructor called!" << std::endl;
    }
};
```

### 3. Virtual Destructor

A virtual destructor ensures that the destructor of the derived class is called when an object is deleted through a base class pointer.

```cpp
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor called!" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor called!" << std::endl;
    }
};
```

### 4. Pure Virtual Destructor

A pure virtual destructor is used in abstract classes. Even though it is pure, it must be defined.

```cpp
class AbstractBase {
public:
    virtual ~AbstractBase() = 0; // Pure virtual destructor
};

AbstractBase::~AbstractBase() {
    // Definition of pure virtual destructor
    std::cout << "Pure virtual destructor called!" << std::endl;
}
```

## Example Usage

```cpp
#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor called!" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor called!" << std::endl;
    }
};

int main() {
    Base* obj = new Derived();
    delete obj; // Both Base and Derived destructors will be called
    return 0;
}
```

In this example, when `delete obj` is called, the destructor of `Derived` is called first, followed by the destructor of `Base`.
