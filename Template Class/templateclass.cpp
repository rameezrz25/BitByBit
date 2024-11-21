#include <iostream>
using namespace std;

// Template class

template <class T>
class TemplateClass
{
    T data;
public:
    TemplateClass(T data)
    {
        this->data = data;
    }
    void display()
    {
        cout << "Data: " << data << endl;
    }
};

int main()
{
    TemplateClass<int> obj1(5);
    obj1.display();

    TemplateClass<float> obj2(5.5);
    obj2.display();

    TemplateClass<char> obj3('A');
    obj3.display();

    return 0;
}
 
 