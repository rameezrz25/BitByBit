# Template Class in C++

Template classes allow you to create generic and reusable class definitions. They enable classes to operate with generic types, making them more flexible and reducing code duplication.

## Syntax

```cpp
template <typename T>
class ClassName {
public:
    T memberFunction(T parameter);
    // Other members
};
```

- `template <typename T>`: This is the template declaration. `T` is a placeholder for a data type.
- `class ClassName`: This is the class declaration using the template type `T`.

## Example: Stack

```cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(T const& element) {
        elements.push_back(element);
    }

    void pop() {
        if (elements.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        elements.pop_back();
    }

    T top() const {
        if (elements.empty()) {
            throw out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    cout << "Top element: " << intStack.top() << endl; // Output: Top element: 2
    intStack.pop();
    cout << "Top element after pop: " << intStack.top() << endl; // Output: Top element after pop: 1

    Stack<string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    cout << "Top element: " << stringStack.top() << endl; // Output: Top element: World
    stringStack.pop();
    cout << "Top element after pop: " << stringStack.top() << endl; // Output: Top element after pop: Hello

    return 0;
}
```

In this example, the `Stack` class can store and manage a stack of integers or strings using the same class definition.

## Benefits

- **Code Reusability**: Write once, use for any data type.
- **Type Safety**: Ensures that the operations are type-safe.
- **Maintainability**: Easier to maintain and update code.

## Common Use Cases

- Data structures (e.g., stacks, queues, linked lists)
- Containers (e.g., vectors, maps)
- Algorithms (e.g., sorting, searching)

## Conclusion

Template classes are a powerful feature in C++ that help in writing generic, reusable, and maintainable code. They are essential for creating libraries and frameworks that work with any data type.
