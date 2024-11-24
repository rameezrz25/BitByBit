### **Strategy Pattern: Defining a Family of Algorithms and Making Them Interchangeable** 🧩

---

### **What is the Strategy Pattern?** 🤔

The **Strategy Pattern** is a **behavioral design pattern** that defines a  **family of algorithms** , encapsulates each one, and makes them interchangeable. This pattern allows you to change the algorithm (strategy) used by an object at runtime without modifying the object itself.

Think of it like having **different routes** to reach a destination, and you can **switch between these routes** based on real-time conditions (like traffic or weather).

---

### **Real-World Analogy: Choosing the Best Route** 🛣️

Imagine you're traveling to a location, and you have different **routes** to choose from:

1. **Route A** : Takes you through highways for speed.
2. **Route B** : Takes you through scenic backroads to enjoy nature.
3. **Route C** : A shortcut that saves time but may be bumpy.

The **Strategy Pattern** is like having a **navigator** that selects the best route based on your current **needs** (e.g., time, experience, or scenic value). You can change the strategy without changing the vehicle or destination!

---

### **Why Use the Strategy Pattern?** 🛠️

1. **Avoids Conditional Statements** : Instead of using complex `if-else` or `switch` statements to decide which algorithm to use, the strategy pattern allows you to encapsulate algorithms in separate classes.
2. **Flexibility** : You can **switch algorithms** at runtime, making it easy to choose different strategies for different situations.
3. **Decoupling** : The object using the algorithm doesn't need to know the details of how the algorithm works, it only needs to know how to interact with the  **strategy interface** .

---

### **How Does It Work?** 🛠️

1. **Context** : The object that uses the algorithm (it delegates the work to the strategy).
2. **Strategy** : The interface common to all concrete strategies.
3. **Concrete Strategy** : The actual implementations of the strategy (the different algorithms).
4. **Client** : The code that selects a specific strategy for the context.

---

### **Strategy Pattern Structure** 🏗️

| **Role**                | **Description**                                                                              |
| ----------------------------- | -------------------------------------------------------------------------------------------------- |
| **Context**             | Contains a reference to the strategy object and may provide a way to change strategies at runtime. |
| **Strategy Interface**  | Defines the common interface for all strategies.                                                   |
| **Concrete Strategies** | Implements different algorithms that conform to the strategy interface.                            |
| **Client**              | Chooses which strategy to use and delegates the behavior to the context.                           |

---

### **Example: Strategy Pattern in C++** 💻

#### **Scenario** : Sorting Algorithms (Bubble Sort, Quick Sort, Merge Sort)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Strategy Interface
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
};

// Concrete Strategy 1: Bubble Sort
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Sorting using Bubble Sort\n";
        for (size_t i = 0; i < data.size() - 1; ++i) {
            for (size_t j = 0; j < data.size() - 1 - i; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// Concrete Strategy 2: Quick Sort
class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Sorting using Quick Sort\n";
        std::sort(data.begin(), data.end());  // Using C++ std::sort for simplicity
    }
};

// Context Class
class Sorter {
private:
    SortingStrategy* strategy;
  
public:
    Sorter(SortingStrategy* strategy) : strategy(strategy) {}
  
    void setStrategy(SortingStrategy* newStrategy) {
        strategy = newStrategy;
    }
  
    void executeSort(std::vector<int>& data) {
        strategy->sort(data);
    }
};

// Client Code
int main() {
    std::vector<int> data = {5, 2, 9, 1, 5, 6};
  
    // Using BubbleSort
    SortingStrategy* bubbleSort = new BubbleSort();
    Sorter sorter(bubbleSort);
    sorter.executeSort(data);
  
    // Switching to QuickSort
    SortingStrategy* quickSort = new QuickSort();
    sorter.setStrategy(quickSort);
    sorter.executeSort(data);
  
    delete bubbleSort;
    delete quickSort;
  
    return 0;
}
```

 **Output** :

```
Sorting using Bubble Sort
Sorting using Quick Sort
```

---

### **Example: Strategy Pattern in Python** 🐍

#### **Scenario** : Sorting Algorithms (Bubble Sort, Quick Sort, Merge Sort)

```python
from abc import ABC, abstractmethod

# Strategy Interface
class SortingStrategy(ABC):
    @abstractmethod
    def sort(self, data):
        pass

# Concrete Strategy 1: Bubble Sort
class BubbleSort(SortingStrategy):
    def sort(self, data):
        print("Sorting using Bubble Sort")
        for i in range(len(data)-1):
            for j in range(len(data)-1-i):
                if data[j] > data[j+1]:
                    data[j], data[j+1] = data[j+1], data[j]

# Concrete Strategy 2: Quick Sort
class QuickSort(SortingStrategy):
    def sort(self, data):
        print("Sorting using Quick Sort")
        data.sort()  # Using Python's built-in sort method for simplicity

# Context Class
class Sorter:
    def __init__(self, strategy: SortingStrategy):
        self.strategy = strategy
  
    def set_strategy(self, strategy: SortingStrategy):
        self.strategy = strategy
  
    def execute_sort(self, data):
        self.strategy.sort(data)

# Client Code
data = [5, 2, 9, 1, 5, 6]

# Using BubbleSort
bubble_sort = BubbleSort()
sorter = Sorter(bubble_sort)
sorter.execute_sort(data)

# Switching to QuickSort
quick_sort = QuickSort()
sorter.set_strategy(quick_sort)
sorter.execute_sort(data)
```

 **Output** :

```
Sorting using Bubble Sort
Sorting using Quick Sort
```

---

### **Advantages of Strategy Pattern** ✅

1. **Flexibility** : You can switch between different algorithms dynamically at runtime.
2. **Avoids Conditional Statements** : Replaces `if-else` or `switch` statements with separate strategy classes.
3. **Encapsulation** : Each algorithm is encapsulated in its own class, making the code more modular.
4. **Easy to Extend** : You can easily add new strategies without changing the context or the existing strategies.

---

### **Disadvantages of Strategy Pattern** ❌

1. **Increased Number of Classes** : Introducing different strategies results in more classes in your system, which could lead to code bloat.
2. **Complexity** : If too many strategies are used, managing them can become complex.

---

### **When to Use the Strategy Pattern?** 📌

* When you have **multiple algorithms** for a specific task, and you want to make them interchangeable.
* When you need to **decouple** the algorithm from the client, allowing you to modify or extend it without changing the client.
* When you want to **avoid code duplication** by encapsulating different algorithms in their respective classes.

---

The **Strategy Pattern** is like having a **flexible choice** between different options, allowing you to pick the best one based on current conditions. It helps to  **keep your code clean, modular** , and  **easily extendable** . 🌟
