### **State Pattern: Allowing an Object to Change Its Behavior Based on Its State** 🔄

---

### **What is the State Pattern?** 🤔

The **State Pattern** is a **behavioral design pattern** that allows an object to **change its behavior** when its internal state changes. The object will appear to change its **class** when its state changes.

Think of it as a **traffic light** that behaves differently depending on whether it's in a "red," "yellow," or "green" state. Instead of having a long chain of `if-else` statements to check the current state, the **State Pattern** uses different objects to represent each state.

---

### **Real-World Analogy: Traffic Light** 🚦

Consider a **traffic light** with three states:

1. **Red** : Vehicles must stop.
2. **Green** : Vehicles are allowed to go.
3. **Yellow** : Vehicles should prepare to stop.

In the  **State Pattern** , the **traffic light** object changes its behavior based on its state. When the light is  **red** , it behaves one way (stopping traffic). When it's  **green** , it behaves differently (letting traffic go). You don't need to check the state manually; the object itself knows what to do based on its current state.

---

### **Why Use the State Pattern?** 🛠️

1. **Simplifies State Management** : By encapsulating the different behaviors associated with each state, the code is cleaner and easier to understand.
2. **Reduces Conditional Logic** : Instead of using multiple `if-else` or `switch` statements, you delegate behavior to state objects.
3. **Makes State Transitions Easy** : Changing state is as simple as changing the state object.

---

### **How Does It Work?** 🛠️

1. **Context** : The object that has a reference to a state object and delegates the behavior to the state.
2. **State** : An interface common to all concrete state classes. It defines the behavior for each state.
3. **Concrete States** : Specific implementations of the state, each representing a different state with its behavior.
4. **Client** : The code that interacts with the context, triggering state changes.

---

### **State Pattern Structure** 🏗️

| **Role**            | **Description**                                                                |
| ------------------------- | ------------------------------------------------------------------------------------ |
| **Context**         | Holds a reference to a state object and delegates work to the current state.         |
| **State Interface** | Declares methods that concrete states will implement.                                |
| **Concrete States** | Implements the behavior for each state, allowing the context to change its behavior. |
| **Client**          | Interacts with the context and triggers state changes.                               |

---

### **Example: State Pattern in C++** 💻

#### **Scenario** : A Traffic Light System

```cpp
#include <iostream>
using namespace std;

// State Interface
class TrafficLightState {
public:
    virtual void handleRequest() = 0;
};

// Concrete State 1: Red Light
class RedLight : public TrafficLightState {
public:
    void handleRequest() override {
        cout << "Red light - Stop!" << endl;
    }
};

// Concrete State 2: Green Light
class GreenLight : public TrafficLightState {
public:
    void handleRequest() override {
        cout << "Green light - Go!" << endl;
    }
};

// Concrete State 3: Yellow Light
class YellowLight : public TrafficLightState {
public:
    void handleRequest() override {
        cout << "Yellow light - Prepare to stop!" << endl;
    }
};

// Context Class
class TrafficLight {
private:
    TrafficLightState* state; // Current state
  
public:
    TrafficLight(TrafficLightState* initialState) : state(initialState) {}
  
    void setState(TrafficLightState* newState) {
        state = newState;
    }
  
    void request() {
        state->handleRequest(); // Delegate to current state
    }
};

// Client Code
int main() {
    // Initial state: Red
    TrafficLightState* red = new RedLight();
    TrafficLight trafficLight(red);
  
    // Request Red state
    trafficLight.request();
  
    // Change state to Green
    TrafficLightState* green = new GreenLight();
    trafficLight.setState(green);
    trafficLight.request();
  
    // Change state to Yellow
    TrafficLightState* yellow = new YellowLight();
    trafficLight.setState(yellow);
    trafficLight.request();
  
    delete red;
    delete green;
    delete yellow;
  
    return 0;
}
```

 **Output** :

```
Red light - Stop!
Green light - Go!
Yellow light - Prepare to stop!
```

---

### **Example: State Pattern in Python** 🐍

#### **Scenario** : A Traffic Light System

```python
from abc import ABC, abstractmethod

# State Interface
class TrafficLightState(ABC):
    @abstractmethod
    def handle_request(self):
        pass

# Concrete State 1: Red Light
class RedLight(TrafficLightState):
    def handle_request(self):
        print("Red light - Stop!")

# Concrete State 2: Green Light
class GreenLight(TrafficLightState):
    def handle_request(self):
        print("Green light - Go!")

# Concrete State 3: Yellow Light
class YellowLight(TrafficLightState):
    def handle_request(self):
        print("Yellow light - Prepare to stop!")

# Context Class
class TrafficLight:
    def __init__(self, state: TrafficLightState):
        self.state = state
  
    def set_state(self, state: TrafficLightState):
        self.state = state
  
    def request(self):
        self.state.handle_request()

# Client Code
red = RedLight()
traffic_light = TrafficLight(red)

# Request Red state
traffic_light.request()

# Change to Green
green = GreenLight()
traffic_light.set_state(green)
traffic_light.request()

# Change to Yellow
yellow = YellowLight()
traffic_light.set_state(yellow)
traffic_light.request()
```

 **Output** :

```
Red light - Stop!
Green light - Go!
Yellow light - Prepare to stop!
```

---

### **Advantages of State Pattern** ✅

1. **Cleaner Code** : By separating the behavior into state-specific classes, you avoid large, complex conditional statements (`if-else` or `switch`).
2. **Easy to Maintain and Extend** : Adding new states is simple, as you can add new state classes without modifying the existing code.
3. **Encapsulation** : State-specific behavior is encapsulated within concrete state classes, making it easier to manage.

---

### **Disadvantages of State Pattern** ❌

1. **Increased Number of Classes** : As each state is represented by a separate class, the number of classes can increase, leading to code bloat.
2. **Context Dependence** : The context object needs to be aware of the states and manage their transitions, which can be complex in some cases.

---

### **When to Use the State Pattern?** 📌

* When an object needs to behave differently depending on its  **internal state** , and you want to avoid complex conditionals.
* When **state-dependent behaviors** need to be **isolated** into separate classes, making the code cleaner and more maintainable.
* When you want to **dynamically change an object's behavior** based on its state, like a  **state machine** .

---

The **State Pattern** helps to manage **state-dependent behavior** and makes the system more modular and easier to extend. It’s perfect for situations where you need to model behavior changes without cluttering your code with `if-else` logic. 🌟
