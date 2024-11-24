### **Decorator Pattern: Adding Features Dynamically!** 🎨✨

---

### **What is the Decorator Pattern?** 🤔

The **Decorator Pattern** is a **structural design pattern** that allows you to **add new functionality** to an existing object **dynamically** without altering its structure. This pattern enables you to **extend** the behavior of an object in a flexible and reusable way, making it **better than subclassing** for adding responsibilities.

---

### **Real-World Analogy: A Christmas Tree** 🎄

Imagine a  **Christmas tree** :

* You have a basic tree (the object).
* You can decorate it with  **lights** ,  **ornaments** , and a **star** on top, all without changing the tree itself.
* You add these **decorations** (new features) dynamically, and each decoration adds new functionality or appearance, but you never alter the basic tree structure.

---

### **Why Use the Decorator Pattern?** 🛠️

1. **Dynamic Behavior** : Add or remove features on objects at runtime.
2. **Flexibility** : You can combine different decorators for varied behavior.
3. **Avoid Inheritance** : Avoid deep inheritance hierarchies for each combination of features.
4. **Single Responsibility** : Keeps class functionality separate and manageable.

---

### **How Does It Work?** 🛠️

1. **Component** : The interface that defines the methods we want to decorate.
2. **Concrete Component** : The base object to which we want to add functionality.
3. **Decorator** : The base class that wraps the component and adds extra functionality.
4. **Concrete Decorators** : Specific classes that extend the decorator and add specific behavior.

---

### **Decorator Pattern Structure** 🏗️

| **Component**         | **Role**                                                                     |
| --------------------------- | ---------------------------------------------------------------------------------- |
| **Component**         | Defines the interface for objects that can be dynamically decorated.               |
| **ConcreteComponent** | The base object that can be decorated.                                             |
| **Decorator**         | Implements the component interface and holds a reference to the wrapped component. |
| **ConcreteDecorator** | Adds specific additional behavior to the component.                                |

---

### **Example: Decorator Pattern in C++** 💻

#### **Scenario** : A Coffee Shop

```cpp
#include <iostream>
#include <memory>

// Component
class Beverage {
public:
    virtual ~Beverage() = default;
    virtual double cost() = 0;
    virtual std::string description() = 0;
};

// ConcreteComponent
class Coffee : public Beverage {
public:
    double cost() override {
        return 5.0; // Base price of coffee
    }

    std::string description() override {
        return "Coffee";
    }
};

// Decorator
class BeverageDecorator : public Beverage {
protected:
    std::shared_ptr<Beverage> beverage_;

public:
    BeverageDecorator(std::shared_ptr<Beverage> bev) : beverage_(bev) {}

    double cost() override {
        return beverage_->cost();
    }

    std::string description() override {
        return beverage_->description();
    }
};

// ConcreteDecorators
class MilkDecorator : public BeverageDecorator {
public:
    MilkDecorator(std::shared_ptr<Beverage> bev) : BeverageDecorator(bev) {}

    double cost() override {
        return beverage_->cost() + 1.5; // Adding milk
    }

    std::string description() override {
        return beverage_->description() + " with Milk";
    }
};

class SugarDecorator : public BeverageDecorator {
public:
    SugarDecorator(std::shared_ptr<Beverage> bev) : BeverageDecorator(bev) {}

    double cost() override {
        return beverage_->cost() + 0.5; // Adding sugar
    }

    std::string description() override {
        return beverage_->description() + " with Sugar";
    }
};

// Client code
int main() {
    std::shared_ptr<Beverage> myCoffee = std::make_shared<Coffee>();

    std::cout << "Basic coffee cost: " << myCoffee->cost() << "\n";
    std::cout << "Description: " << myCoffee->description() << "\n";

    // Adding Milk
    myCoffee = std::make_shared<MilkDecorator>(myCoffee);
    std::cout << "Cost after Milk: " << myCoffee->cost() << "\n";
    std::cout << "Description: " << myCoffee->description() << "\n";

    // Adding Sugar
    myCoffee = std::make_shared<SugarDecorator>(myCoffee);
    std::cout << "Cost after Sugar: " << myCoffee->cost() << "\n";
    std::cout << "Description: " << myCoffee->description() << "\n";

    return 0;
}
```

---

### **Example: Decorator Pattern in Python** 🐍

#### **Scenario** : A Simple Pizza Shop

```python
class Pizza:
    """Component"""
    def cost(self):
        return 10

    def description(self):
        return "Plain Pizza"


class PizzaDecorator(Pizza):
    """Decorator"""
    def __init__(self, pizza):
        self._pizza = pizza

    def cost(self):
        return self._pizza.cost()

    def description(self):
        return self._pizza.description()


class CheeseDecorator(PizzaDecorator):
    """Concrete Decorator"""
    def cost(self):
        return self._pizza.cost() + 2

    def description(self):
        return self._pizza.description() + " with Cheese"


class PepperoniDecorator(PizzaDecorator):
    """Concrete Decorator"""
    def cost(self):
        return self._pizza.cost() + 3

    def description(self):
        return self._pizza.description() + " with Pepperoni"


# Client Code
my_pizza = Pizza()
print(f"Cost: {my_pizza.cost()}")
print(f"Description: {my_pizza.description()}")

# Adding cheese
my_pizza = CheeseDecorator(my_pizza)
print(f"Cost with Cheese: {my_pizza.cost()}")
print(f"Description: {my_pizza.description()}")

# Adding pepperoni
my_pizza = PepperoniDecorator(my_pizza)
print(f"Cost with Cheese and Pepperoni: {my_pizza.cost()}")
print(f"Description: {my_pizza.description()}")
```

---

### **Advantages** ✅

1. **Dynamic Behavior** : Add features to objects at runtime without changing their classes.
2. **Flexibility** : Combine multiple decorators for different behaviors.
3. **Avoids Subclassing** : No need for a complex inheritance structure.
4. **Single Responsibility** : Adds responsibilities to objects without modifying them.

---

### **Disadvantages** ❌

1. **Complexity** : Can introduce many small classes, leading to complexity.
2. **Difficult to Track** : Multiple decorators may complicate understanding the final behavior.
3. **Overuse** : Too many decorators can lead to excessive abstraction.

---

### **When to Use the Decorator Pattern?** 📌

* When you need to add new responsibilities to an object without modifying its code.
* When you want to dynamically add or remove behaviors at runtime.
* When you want to avoid creating a large number of subclasses for different combinations of features.

---

By leveraging the  **Decorator Pattern** , you can **add new functionalities** to objects dynamically, making your design **more flexible** and **extensible** while avoiding deep inheritance hierarchies! 🚀
