### **Template Method Pattern: Defining the Skeleton of an Algorithm** 🧑‍🍳✨

---

### **What is the Template Method Pattern?** 🤔

The **Template Method Pattern** is a **behavioral design pattern** that defines the **skeleton** of an algorithm in the  **superclass** , but lets **subclasses** override certain steps of the algorithm without changing its structure. In other words, it provides a **template** for an operation and allows subclasses to provide specific implementations for some parts of the algorithm.

Think of it like a **recipe** where you have a fixed process (steps) but can change some ingredients or methods to suit your needs!

---

### **Real-World Analogy: Cooking a Meal** 🍲

Imagine you are cooking a dish:

1. There’s a **basic recipe** with standard steps: wash ingredients, chop them, cook them, serve.
2. However, depending on the dish, you can change the **ingredients** (like vegetables or spices) or the **cooking technique** (grilling vs frying).
3. You don’t change the **overall process** — just specific parts of it.

In this analogy, the **basic recipe** is the  **template method** , and the **ingredients or cooking methods** that can change are the **steps** that subclasses (or different chefs) can customize.

---

### **Why Use the Template Method Pattern?** 🛠️

1. **Code Reuse** : You define common steps once and let subclasses reuse the shared code while customizing the specific steps.
2. **Consistency** : You enforce a consistent algorithm structure, ensuring that the order of operations remains the same.
3. **Control Over Algorithm** : The base class can control the overall flow of the algorithm while leaving flexibility for subclasses to fill in details.

---

### **How Does It Work?** 🛠️

1. **Abstract Class (Template Method)** : This defines the **template method** — the overall structure of the algorithm. Some of the steps can be implemented in the base class, while others are abstract and must be defined by subclasses.
2. **Concrete Class (Overrides Steps)** : The subclasses implement specific steps of the algorithm without changing the overall flow.

---

### **Template Method Pattern Structure** 🏗️

| **Role**                 | **Description**                                                             |
| ------------------------------ | --------------------------------------------------------------------------------- |
| **Abstract Class**       | Contains the template method and abstract steps to be overridden.                 |
| **Concrete Class**       | Implements the abstract steps and provides custom functionality.                  |
| **Template Method**      | The main method in the abstract class that defines the skeleton of the algorithm. |
| **Primitive Operations** | The customizable steps (methods) that are implemented by subclasses.              |

---

### **Example: Template Method Pattern in C++** 💻

#### **Scenario** : Making a Beverage (e.g., Tea or Coffee)

```cpp
#include <iostream>

// Abstract Class (Template)
class CaffeineBeverage {
public:
    // Template Method: Defines the algorithm structure
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

protected:
    virtual void brew() = 0;   // Abstract step (subclasses will implement)
    virtual void addCondiments() = 0;   // Abstract step (subclasses will implement)

    // Concrete steps
    void boilWater() {
        std::cout << "Boiling water\n";
    }

    void pourInCup() {
        std::cout << "Pouring into cup\n";
    }
};

// Concrete Class 1: Making Tea
class Tea : public CaffeineBeverage {
protected:
    void brew() override {
        std::cout << "Steeping the tea\n";
    }

    void addCondiments() override {
        std::cout << "Adding lemon\n";
    }
};

// Concrete Class 2: Making Coffee
class Coffee : public CaffeineBeverage {
protected:
    void brew() override {
        std::cout << "Dripping coffee through filter\n";
    }

    void addCondiments() override {
        std::cout << "Adding sugar and milk\n";
    }
};

// Client Code
int main() {
    CaffeineBeverage* tea = new Tea();
    tea->prepareRecipe();

    std::cout << "\n";

    CaffeineBeverage* coffee = new Coffee();
    coffee->prepareRecipe();

    delete tea;
    delete coffee;

    return 0;
}
```

 **Output** :

```
Boiling water
Steeping the tea
Pouring into cup
Adding lemon

Boiling water
Dripping coffee through filter
Pouring into cup
Adding sugar and milk
```

---

### **Example: Template Method Pattern in Python** 🐍

#### **Scenario** : Cooking a Dish (Tea or Coffee)

```python
from abc import ABC, abstractmethod

class CaffeineBeverage(ABC):
    # Template method: defines the skeleton of the algorithm
    def prepare_recipe(self):
        self.boil_water()
        self.brew()
        self.pour_in_cup()
        self.add_condiments()

    def boil_water(self):
        print("Boiling water")

    def pour_in_cup(self):
        print("Pouring into cup")

    # Abstract methods to be overridden by subclasses
    @abstractmethod
    def brew(self):
        pass

    @abstractmethod
    def add_condiments(self):
        pass

class Tea(CaffeineBeverage):
    def brew(self):
        print("Steeping the tea")

    def add_condiments(self):
        print("Adding lemon")

class Coffee(CaffeineBeverage):
    def brew(self):
        print("Dripping coffee through filter")

    def add_condiments(self):
        print("Adding sugar and milk")

# Client code
tea = Tea()
tea.prepare_recipe()

print("\n")

coffee = Coffee()
coffee.prepare_recipe()
```

 **Output** :

```
Boiling water
Steeping the tea
Pouring into cup
Adding lemon

Boiling water
Dripping coffee through filter
Pouring into cup
Adding sugar and milk
```

---

### **Advantages of Template Method Pattern** ✅

1. **Code Reusability** : Common steps of an algorithm are written once in the base class and reused by subclasses.
2. **Control Flow** : The base class controls the sequence of operations, while subclasses fill in the specific details.
3. **Extensibility** : You can add new variants of the algorithm by creating new subclasses that define new steps.

---

### **Disadvantages of Template Method Pattern** ❌

1. **Inheritance Overhead** : Since the template method pattern relies heavily on inheritance, it can lead to **tight coupling** between the base and subclasses.
2. **Limited Flexibility** : The algorithm structure is predefined in the base class, so if the algorithm needs significant changes, it could become harder to modify.
3. **Complexity** : If too many steps need customization, the pattern might end up being too rigid for more complex scenarios.

---

### **When to Use the Template Method Pattern?** 📌

* When you have an **algorithm** with  **several common steps** , but some parts need to be  **customized** .
* When you want to **reuse code** for common behavior while leaving some parts flexible.
* When you want to define the **structure** of an algorithm but **defer certain steps** to subclasses.

---

The **Template Method Pattern** is great for situations where you have a predefined structure but still need to allow **flexibility** in how specific parts of the algorithm are implemented. It helps to **standardize** the flow, while still allowing for **customization** where needed. It’s like following a **recipe** where the  **process is fixed** , but the **ingredients** can be adjusted! 🍲🎨
