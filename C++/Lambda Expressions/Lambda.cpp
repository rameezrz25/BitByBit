#include <iostream>
using namespace std;
int main() {
    auto add = [](int a, int b) {
        return a + b;
    };

    int result = add(5, 3);
    cout << "The result of adding 5 and 3 is: " << result << endl;

    return 0;
}