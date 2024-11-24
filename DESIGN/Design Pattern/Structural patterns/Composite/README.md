### **Composite Pattern: Treating Individual Objects and Groups of Objects Similarly!** 🌳🔗

---

### **What is the Composite Pattern?** 🤔

The **Composite Pattern** is a **structural design pattern** that allows you to compose objects into tree-like structures. It enables clients to treat individual objects and compositions (groups of objects) uniformly. This is useful when you need to represent part-whole hierarchies, such as organization structures or file systems.

In simpler terms: **It lets you treat individual objects and groups of objects the same way.**

---

### **Real-World Analogy: A Folder System** 🗂️

Imagine your computer file system:

* A **folder** can contain **files** or  **other folders** .
* A **file** is an individual object, while a **folder** is a group of objects.
* Regardless of whether it’s a file or a folder, you can **open** or **delete** it in the same way.
* The **Composite Pattern** lets you treat files and folders as **the same type** (either a file or a folder) through a common interface.

---

### **Why Use the Composite Pattern?** 🛠️

1. **Uniformity** : Treat both individual objects and groups of objects the same way.
2. **Simplifies Code** : Clients don’t need to differentiate between individual objects and composite objects.
3. **Hierarchical Structures** : Perfect for tree structures, like organization charts, file systems, or graphics systems.
4. **Flexible** : You can dynamically add new components to the structure.

---

### **How Does It Work?** 🛠️

1. **Component** : The base class or interface that defines the common operations for both leaf and composite objects.
2. **Leaf** : A simple object that does not have any children. It implements the `Component` interface.
3. **Composite** : An object that holds a collection of `Component` objects, including other composites or leaves.
4. **Client** : Interacts with the `Component` interface, unaware whether it's dealing with a leaf or composite.

---

### **Composite Pattern Structure** 🏗️

| **Component** | **Role**                                                                                     |
| ------------------- | -------------------------------------------------------------------------------------------------- |
| **Component** | Defines the common interface for both leaf and composite objects.                                  |
| **Leaf**      | Represents an individual object with no children.                                                  |
| **Composite** | A group of objects (either leaves or other composites) that implements the `Component`interface. |
| **Client**    | Interacts with the components using the common `Component`interface.                             |

---

### **Example: Composite Pattern in C++** 💻

#### **Scenario** : A File System

```cpp
#include <iostream>
#include <vector>
#include <memory>

// Component
class FileSystemComponent {
public:
    virtual ~FileSystemComponent() = default;
    virtual void showDetails() = 0;
};

// Leaf
class File : public FileSystemComponent {
public:
    File(const std::string& name) : name_(name) {}

    void showDetails() override {
        std::cout << "File: " << name_ << "\n";
    }

private:
    std::string name_;
};

// Composite
class Folder : public FileSystemComponent {
public:
    void add(std::shared_ptr<FileSystemComponent> component) {
        components_.push_back(component);
    }

    void showDetails() override {
        std::cout << "Folder:\n";
        for (const auto& component : components_) {
            component->showDetails();
        }
    }

private:
    std::vector<std::shared_ptr<FileSystemComponent>> components_;
};

// Client Code
int main() {
    auto file1 = std::make_shared<File>("File1.txt");
    auto file2 = std::make_shared<File>("File2.txt");

    auto folder = std::make_shared<Folder>();
    folder->add(file1);
    folder->add(file2);

    folder->showDetails();  // Displays folder and file details

    return 0;
}
```

---

### **Example: Composite Pattern in Python** 🐍

#### **Scenario** : A Graphic Design System

```python
from abc import ABC, abstractmethod

class Graphic(ABC):
    """Component"""
    @abstractmethod
    def draw(self):
        pass


class Circle(Graphic):
    """Leaf"""
    def draw(self):
        print("Drawing Circle.")


class Rectangle(Graphic):
    """Leaf"""
    def draw(self):
        print("Drawing Rectangle.")


class GraphicGroup(Graphic):
    """Composite"""
    def __init__(self):
        self.graphics = []

    def add(self, graphic: Graphic):
        self.graphics.append(graphic)

    def draw(self):
        print("Drawing Group:")
        for graphic in self.graphics:
            graphic.draw()


# Client Code
circle = Circle()
rectangle = Rectangle()
group = GraphicGroup()
group.add(circle)
group.add(rectangle)

# Drawing group and its components
group.draw()
```

---

### **Advantages** ✅

1. **Uniform Treatment** : Clients treat individual objects and composite objects uniformly.
2. **Flexibility** : You can add new components easily.
3. **Simplifies Client Code** : No need for special handling of composites or leaves.
4. **Tree-Like Structure** : Perfect for representing hierarchical structures.

---

### **Disadvantages** ❌

1. **Complexity** : Can introduce unnecessary complexity when you only have a simple structure.
2. **Overhead** : Too many layers of composition can make the design harder to understand.
3. **Performance** : Some operations on large composite trees can be slower due to recursion and traversal.

---

### **When to Use the Composite Pattern?** 📌

* When you need to represent part-whole hierarchies.
* When you want to treat individual objects and groups of objects uniformly.
* In systems with tree-like structures, such as file systems or organization charts.
* When you want to make it easier to add new types of objects (like adding a new graphic object in a graphics system).

---

With the  **Composite Pattern** , you can create flexible and manageable **tree-like structures** while treating both simple objects and complex collections in the same way! 🌲
