# Template Functions in C++

Template functions allow you to write generic and reusable code. They enable functions to operate with generic types, which makes them more flexible and reduces code duplication.

## Syntax

```cpp
template <typename T>
T functionName(T parameter) {
    // Function implementation
}
```

- `template <typename T>`: This is the template declaration. `T` is a placeholder for a data type.
- `T functionName(T parameter)`: This is the function declaration using the template type `T`.

## Example

```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add<int>(2, 3) << endl;       // Output: 5
    cout << add<double>(2.5, 3.5) << endl; // Output: 6.0
    return 0;
}
```

In this example, the `add` function can add two integers or two doubles using the same function definition.

## Benefits

- **Code Reusability**: Write once, use for any data type.
- **Type Safety**: Ensures that the operations are type-safe.
- **Maintainability**: Easier to maintain and update code.

## Common Use Cases

- Sorting algorithms
- Mathematical operations
- Data structures (e.g., linked lists, stacks, queues)

## Conclusion

Template functions are a powerful feature in C++ that help in writing generic, reusable, and maintainable code. They are essential for creating libraries and frameworks that work with any data type.

## Another Example

```cpp
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T concatenate(T a, T b) {
    return a + b;
}

int main() {
    cout << concatenate<string>("Hello, ", "World!") << endl; // Output: Hello, World!
    return 0;
}
```

In this example, the `concatenate` function can concatenate two strings using the same function definition.

## Example with Multiple Types

```cpp
#include <iostream>
using namespace std;

template <typename T, typename U>
auto multiply(T a, U b) -> decltype(a * b) {
    return a * b;
}

int main() {
    cout << multiply<int, double>(3, 4.5) << endl; // Output: 13.5
    cout << multiply<float, int>(2.5f, 4) << endl; // Output: 10
    return 0;
}
```

In this example, the `multiply` function can multiply two values of different types using the same function definition.