#include <iostream>
using namespace std;

// Template function
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // Using the template function with different data types
    cout << "Sum of integers: " << add(3, 4) << endl;          // Output: 7
    cout << "Sum of doubles: " << add(3.5, 4.5) << endl;      // Output: 8
    cout << "Sum of chars: " << add('A', 'B') << endl;          // Output: 'B' (ASCII value of 'A' is 65, 65 + 1 = 66 which is 'B')
    return 0;
}

// Output
// Sum of integers: 7
// Sum of doubles: 8
// Sum of chars: â