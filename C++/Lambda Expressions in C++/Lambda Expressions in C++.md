# Lambda Expressions in C++

## Overview
C++11 introduced **lambda expressions**, which provide a way to define inline anonymous functions within your code. These functions are particularly useful for short code snippets that don't need to be reused elsewhere. Lambda expressions make your code more concise and improve readability by allowing you to define functions directly within other algorithms or expressions.

## Syntax

The basic syntax of a lambda expression is as follows:

```cpp
[ capture_clause ] ( parameters ) -> return_type { body }
```

### Explanation:
- **Capture Clause (`[]`)**: Specifies how variables from the surrounding scope are captured (either by reference or by value).
- **Parameters (`(parameters)`)**: Defines the input parameters for the lambda function.
- **Return Type (`-> return_type`)**: Specifies the return type of the lambda function (optional, often inferred by the compiler).
- **Body (`{ body }`)**: The body of the lambda function, where the logic is defined.

In many cases, the compiler can infer the return type, so you don't always need to specify it explicitly.

## Examples

### Example 1: Basic Lambda Expression with Standard Functions

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to print a vector using lambda
void printVector(vector<int> v) {
    // Lambda expression to print each element of the vector
    for_each(v.begin(), v.end(), [](int i) {
        std::cout << i << " ";
    });
    cout << endl;
}

int main() {
    vector<int> v {4, 1, 3, 5, 2, 3, 1, 7};

    // Print the vector
    printVector(v);

    // Find first element greater than 4
    auto p = find_if(v.begin(), v.end(), [](int i) {
        return i > 4;
    });
    cout << "First number greater than 4 is: " << *p << endl;

    // Sort the vector in non-increasing order using a lambda expression
    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool {
        return a > b;
    });

    // Print the sorted vector
    printVector(v);

    // Count elements greater than or equal to 5
    int count_5 = count_if(v.begin(), v.end(), [](int a) {
        return a >= 5;
    });
    cout << "The number of elements greater than or equal to 5 is: " << count_5 << endl;

    // Remove duplicates using a lambda expression
    p = unique(v.begin(), v.end(), [](int a, int b) {
        return a == b;
    });
    v.resize(distance(v.begin(), p)); // Resize vector to remove duplicates
    printVector(v);

    // Accumulate the factorial of 10 using lambda expression
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int f = accumulate(arr, arr + 10, 1, [](int i, int j) {
        return i * j;
    });
    cout << "Factorial of 10 is: " << f << endl;

    // Lambda expression to compute square of a number
    auto square = [](int i) {
        return i * i;
    };
    cout << "Square of 5 is: " << square(5) << endl;
}
```

### Output:

```
4 1 3 5 2 3 1 7
First number greater than 4 is: 5
7 5 4 3 3 2 1 1
The number of elements greater than or equal to 5 is: 2
7 5 4 3 2 1
Factorial of 10 is: 3628800
Square of 5 is: 25
```

### Example 2: Capturing Variables in Lambda Expressions

Lambda expressions can capture variables from the enclosing scope either by value or by reference.

#### Syntax for Capturing Variables:
- `[&]`: Capture all external variables by reference.
- `[=]`: Capture all external variables by value.
- `[a, &b]`: Capture specific variables by value or reference.

### Example 2: Using Different Capture Methods

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1 = {3, 1, 7, 9};
    vector<int> v2 = {10, 2, 7, 16, 9};

    // Capture both v1 and v2 by reference
    auto pushinto = [&] (int m) {
        v1.push_back(m);
        v2.push_back(m);
    };

    // Push 20 into both v1 and v2
    pushinto(20);

    // Access v1 by value (without modifying it)
    [v1]() {
        for (auto p = v1.begin(); p != v1.end(); p++) {
            cout << *p << " ";
        }
    }();

    int N = 5;

    // Find the first number greater than N using capture by value
    vector<int>::iterator p = find_if(v1.begin(), v1.end(), [N](int i) {
        return i > N;
    });
    cout << "First number greater than 5 is: " << *p << endl;

    // Count elements greater than or equal to N using capture by value
    int count_N = count_if(v1.begin(), v1.end(), [=](int a) {
        return (a >= N);
    });
    cout << "The number of elements greater than or equal to 5 is: " << count_N << endl;
}
```

### Output:

```
First number greater than 5 is: 7
The number of elements greater than or equal to 5 is: 3
```

## Key Points to Remember:
- Lambda expressions allow you to define anonymous functions within your code for short-lived tasks.
- Capturing variables by reference (`&`) or by value (`=`) is an essential feature to make lambda functions work with variables outside their scope.
- The return type can often be inferred by the compiler, but it can be explicitly specified if necessary.
- Lambda expressions are available in **C++11** and later versions.

### Important Notes:
- Lambda expressions are powerful tools but can be overused, so make sure to use them where appropriate, especially for small, concise operations.
- In more complex scenarios, such as recursive lambdas, explicit return type declaration is often necessary to guide the compiler.

