### **Memento Pattern: Remembering the Past!** 🕰️

---

### **What is the Memento Pattern?** 🤔

The **Memento Pattern** is a **behavioral design pattern** that allows you to capture and externalize an object's internal state without violating its  **encapsulation** , so that it can be restored to this state later.

It’s like taking a **snapshot** of an object’s state at a certain moment in time and storing it, so you can **restore** it to that exact point in the future.

---

### **Real-World Analogy: Photo Album** 📸

Think of the **Memento Pattern** as taking a picture. Let’s say you want to **preserve** the memories of your favorite moments in a  **photo album** . Each photo represents a snapshot of a moment (the  **state** ) in time. Later, if you want to go back and relive that moment, you can look at the photo (restore the state) without changing the other photos in your album.

Just like you store memories in a photo album, the Memento pattern allows you to **capture and save the state** of an object at a certain time and **restore** it later.

---

### **Why Use the Memento Pattern?** 🛠️

1. **Undo/Redo functionality** : The Memento Pattern is commonly used in applications that require undo/redo operations (like text editors or graphic design tools).
2. **State Preservation** : You can save an object's state and revert back to it without revealing its inner workings, preserving  **encapsulation** .
3. **Historical Tracking** : You can track the state of an object over time, allowing you to maintain historical versions.

---

### **How Does It Work?** 🛠️

* **Originator** : The object whose state needs to be saved and restored. It knows how to create a **Memento** of its state and restore it from a Memento.
* **Memento** : A snapshot of the originator’s state at a particular moment in time. It stores the internal state of the originator and makes it possible to restore it later.
* **Caretaker** : The object responsible for keeping the memento. It asks the originator to create a memento and stores it. The caretaker doesn’t modify or look into the memento; it only stores and retrieves it.

---

### **Memento Pattern Structure** 🏗️

| **Role**       | **Description**                                                |
| -------------------- | -------------------------------------------------------------------- |
| **Originator** | Creates a Memento object that contains its internal state.           |
| **Memento**    | Stores the state of the originator so it can be restored later.      |
| **Caretaker**  | Maintains the memento without modifying its state or looking inside. |

---

### **Example: Memento Pattern in C++** 💻

#### **Scenario** : Saving and Restoring a Document's Text

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Memento: The snapshot of the originator's state
class Memento {
private:
    string state;

public:
    Memento(const string& state) : state(state) {}

    string getState() const {
        return state;
    }
};

// Originator: The object whose state we want to save and restore
class Document {
private:
    string text;

public:
    void setText(const string& newText) {
        text = newText;
    }

    string getText() const {
        return text;
    }

    Memento* createMemento() {
        return new Memento(text);
    }

    void restoreMemento(Memento* memento) {
        text = memento->getState();
    }
};

// Caretaker: The object that stores the memento
class Caretaker {
private:
    vector<Memento*> mementos;

public:
    void addMemento(Memento* memento) {
        mementos.push_back(memento);
    }

    Memento* getMemento(int index) {
        return mementos.at(index);
    }
};

int main() {
    Document doc;
    Caretaker caretaker;

    doc.setText("First version of the document.");
    cout << "Original Text: " << doc.getText() << endl;

    // Save the current state
    caretaker.addMemento(doc.createMemento());

    doc.setText("Second version of the document.");
    cout << "Modified Text: " << doc.getText() << endl;

    // Restore the previous state
    doc.restoreMemento(caretaker.getMemento(0));
    cout << "Restored Text: " << doc.getText() << endl;

    return 0;
}
```

 **Output** :

```
Original Text: First version of the document.
Modified Text: Second version of the document.
Restored Text: First version of the document.
```

---

### **Example: Memento Pattern in Python** 🐍

#### **Scenario** : Saving and Restoring a Document's Text

```python
# Memento: The snapshot of the originator's state
class Memento:
    def __init__(self, state):
        self._state = state

    def get_state(self):
        return self._state

# Originator: The object whose state we want to save and restore
class Document:
    def __init__(self):
        self._text = ""

    def set_text(self, text):
        self._text = text

    def get_text(self):
        return self._text

    def create_memento(self):
        return Memento(self._text)

    def restore_memento(self, memento):
        self._text = memento.get_state()

# Caretaker: The object that stores the memento
class Caretaker:
    def __init__(self):
        self._mementos = []

    def add_memento(self, memento):
        self._mementos.append(memento)

    def get_memento(self, index):
        return self._mementos[index]

# Client code
doc = Document()
caretaker = Caretaker()

doc.set_text("First version of the document.")
print("Original Text:", doc.get_text())

# Save the current state
caretaker.add_memento(doc.create_memento())

doc.set_text("Second version of the document.")
print("Modified Text:", doc.get_text())

# Restore the previous state
doc.restore_memento(caretaker.get_memento(0))
print("Restored Text:", doc.get_text())
```

 **Output** :

```
Original Text: First version of the document.
Modified Text: Second version of the document.
Restored Text: First version of the document.
```

---

### **Advantages of Memento Pattern** ✅

1. **Encapsulation Preservation** : The memento captures the state of an object without exposing its internal details.
2. **Undo/Redo** : It provides an easy way to implement undo/redo functionality.
3. **State Management** : It helps in managing and restoring the state of objects over time.

---

### **Disadvantages of Memento Pattern** ❌

1. **Memory Overhead** : Storing multiple mementos for each state can consume a lot of memory.
2. **Complexity** : The pattern can introduce complexity if overused, especially in systems where state changes frequently.

---

### **When to Use the Memento Pattern?** 📌

* When you need **undo/redo** functionality in your application (e.g., text editors, drawing apps).
* When you want to **preserve** and **restore** the state of an object without breaking  **encapsulation** .
* When an object’s state is complex, and you want to **capture and store** its state for later use.

---

The **Memento Pattern** is perfect when you need to **save and restore** an object's state while keeping the inner workings of the object hidden. It’s like capturing the moments in time and keeping them safely stored for later retrieval! 🕰️✨
