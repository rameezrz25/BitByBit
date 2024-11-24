### **Flyweight Pattern: Sharing is Caring!** 🎨✨

---

### **What is the Flyweight Pattern?** 🤔

The **Flyweight Pattern** is a **structural design pattern** used to **minimize memory usage** by sharing as much data as possible with similar objects. It focuses on reducing the overhead of creating many similar objects by **reusing shared objects** instead of creating new ones.

---

### **Real-World Analogy: Chess Game Pieces** ♟️

Imagine a  **chess game** :

* The board has  **64 squares** , and you need pieces for both players.
* Instead of creating **64 separate objects** for black and white pieces, you reuse the same "piece objects" and store their **position** separately.
* Shared data: The shape and type of each piece (e.g., pawn, knight).
* Unique data: The position of the piece on the board.

---

### **Why Use the Flyweight Pattern?** 🛠️

1. **Memory Optimization** : Reduce the memory footprint when dealing with a large number of similar objects.
2. **Performance Improvement** : Avoid redundant object creation and initialization.
3. **Separation of Concerns** : Separate intrinsic (shared) data from extrinsic (unique) data.

---

### **Key Concepts** 🗂️

| **Term**              | **Description**                                                      |
| --------------------------- | -------------------------------------------------------------------------- |
| **Intrinsic State**   | Shared data that is common across multiple objects.                        |
| **Extrinsic State**   | Unique data that varies for each instance and must be provided at runtime. |
| **Flyweight Factory** | Manages and reuses Flyweight objects to ensure memory efficiency.          |

---

### **How Does It Work?** 🛠️

1. **Flyweight Object** : Contains intrinsic state (shared data).
2. **Flyweight Factory** : Ensures that flyweights are shared and reused.
3. **Client** : Supplies extrinsic state (unique data) and works with flyweights.

---

### **Flyweight Pattern Structure** 🏗️

| **Component**          | **Role**                                                 |
| ---------------------------- | -------------------------------------------------------------- |
| **Flyweight**          | Defines the interface for objects that can be shared.          |
| **Concrete Flyweight** | Implements the Flyweight interface and stores intrinsic state. |
| **Flyweight Factory**  | Creates and manages flyweight objects, ensuring reuse.         |
| **Client**             | Uses flyweight objects and provides extrinsic state as needed. |

---

### **Example: Flyweight Pattern in C++** 💻

#### **Scenario** : A Text Editor with Shared Characters

```cpp
#include <iostream>
#include <unordered_map>
#include <memory>

// Flyweight Interface
class Character {
public:
    virtual void display(int size, int x, int y) = 0; // Extrinsic data: size, position
    virtual ~Character() = default;
};

// Concrete Flyweight
class ConcreteCharacter : public Character {
public:
    ConcreteCharacter(char symbol) : symbol_(symbol) {}

    void display(int size, int x, int y) override {
        std::cout << "Character '" << symbol_ << "' at (" << x << ", " << y << ") with size " << size << "\n";
    }

private:
    char symbol_; // Intrinsic data
};

// Flyweight Factory
class CharacterFactory {
public:
    std::shared_ptr<Character> getCharacter(char symbol) {
        if (characters_.find(symbol) == characters_.end()) {
            characters_[symbol] = std::make_shared<ConcreteCharacter>(symbol);
        }
        return characters_[symbol];
    }

private:
    std::unordered_map<char, std::shared_ptr<Character>> characters_;
};

// Client Code
int main() {
    CharacterFactory factory;

    auto charA = factory.getCharacter('A');
    auto charB = factory.getCharacter('B');
    auto anotherCharA = factory.getCharacter('A');

    charA->display(12, 1, 1);
    charB->display(14, 2, 2);
    anotherCharA->display(16, 3, 3); // Reuses 'A'

    return 0;
}
```

---

### **Example: Flyweight Pattern in Python** 🐍

#### **Scenario** : A Game with Trees

```python
class TreeType:
    """Flyweight: Shared intrinsic data."""
    def __init__(self, name, color, texture):
        self.name = name
        self.color = color
        self.texture = texture

    def display(self, x, y):
        print(f"Tree '{self.name}' at ({x}, {y}) with color {self.color} and texture {self.texture}")


class TreeFactory:
    """Flyweight Factory: Ensures tree types are reused."""
    _tree_types = {}

    @staticmethod
    def get_tree_type(name, color, texture):
        key = (name, color, texture)
        if key not in TreeFactory._tree_types:
            TreeFactory._tree_types[key] = TreeType(name, color, texture)
        return TreeFactory._tree_types[key]


class Tree:
    """Client: Stores extrinsic data like position."""
    def __init__(self, x, y, tree_type):
        self.x = x
        self.y = y
        self.tree_type = tree_type

    def display(self):
        self.tree_type.display(self.x, self.y)


# Example Usage
forest = []
tree_type = TreeFactory.get_tree_type("Oak", "Green", "Rough")
forest.append(Tree(10, 20, tree_type))
forest.append(Tree(15, 25, tree_type))

# Reusing the same tree type
tree_type2 = TreeFactory.get_tree_type("Oak", "Green", "Rough")
forest.append(Tree(30, 40, tree_type2))

for tree in forest:
    tree.display()
```

---

### **Advantages** ✅

1. **Memory Efficiency** : Reduces memory usage by sharing objects.
2. **Performance Optimization** : Reuses objects instead of creating new ones.
3. **Scalability** : Handles a large number of similar objects easily.

---

### **Disadvantages** ❌

1. **Complexity** : Adds extra layers (factory and flyweights).
2. **Limited Use** : Only applicable when objects have a significant amount of shared data.

---

### **When to Use the Flyweight Pattern?** 📌

* When you have a large number of similar objects.
* When object creation is costly in terms of memory and time.
* When objects share most of their data but have some unique attributes.

---

By leveraging the  **Flyweight Pattern** , you can save resources while maintaining functionality, making your application leaner and faster! 🏎️
