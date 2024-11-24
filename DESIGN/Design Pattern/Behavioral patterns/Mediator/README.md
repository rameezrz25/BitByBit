### **Mediator Pattern: The Communicator!** 🗣️

---

### **What is the Mediator Pattern?** 🤔

The **Mediator Pattern** is a **behavioral design pattern** that defines an object (the  **mediator** ) that controls how a set of objects communicate with each other. Instead of objects communicating directly, they send messages to the mediator, which then coordinates the interaction. This reduces the **coupling** between objects and makes the system more flexible and easier to maintain.

---

### **Real-World Analogy: Air Traffic Control** ✈️

Imagine an **air traffic control tower** at an airport. Each plane needs to communicate with the tower, not with other planes. The tower manages all communication, ensuring planes don't collide and are guided to their correct destinations.

Similarly, in the  **Mediator Pattern** , objects don't communicate directly with each other. Instead, they interact with the  **mediator** , which coordinates the communication and ensures everything works smoothly.

---

### **Why Use the Mediator Pattern?** 🛠️

1. **Reduced Complexity** : By centralizing communication, objects don’t need to keep track of multiple other objects, making the system easier to manage.
2. **Loose Coupling** : It helps in reducing the direct dependencies between objects, making the system more flexible.
3. **Simplified Maintenance** : If you need to modify communication logic, you only need to change the  **mediator** , not each individual object.

---

### **How Does It Work?** 🛠️

* **Mediator** : This is the central object that manages communication between other objects. It’s responsible for coordinating actions between colleagues.
* **Colleague Objects** : These are the objects that need to communicate. They don't directly interact with each other, but instead communicate via the mediator.

---

### **Mediator Pattern Structure** 🏗️

| **Role**              | **Description**                                                         |
| --------------------------- | ----------------------------------------------------------------------------- |
| **Mediator**          | The central object that coordinates interactions between objects.             |
| **Colleague Objects** | The objects that communicate with each other indirectly through the mediator. |

---

### **Example: Mediator Pattern in C++** 💻

#### **Scenario** : Chat Room

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Mediator Interface
class Mediator {
public:
    virtual void sendMessage(const string& message, class Colleague* colleague) = 0;
};

// Colleague Class
class Colleague {
protected:
    Mediator* mediator;
public:
    Colleague(Mediator* mediator) : mediator(mediator) {}
    virtual void send(const string& message) = 0;
    virtual void receive(const string& message) = 0;
};

// Concrete Mediator
class ChatRoom : public Mediator {
private:
    vector<Colleague*> colleagues;
public:
    void addColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
    }

    void sendMessage(const string& message, Colleague* colleague) override {
        for (Colleague* c : colleagues) {
            if (c != colleague) {
                c->receive(message);
            }
        }
    }
};

// Concrete Colleague
class User : public Colleague {
private:
    string name;
public:
    User(const string& name, Mediator* mediator) : Colleague(mediator), name(name) {}

    void send(const string& message) override {
        cout << name << " sends: " << message << endl;
        mediator->sendMessage(message, this);
    }

    void receive(const string& message) override {
        cout << name << " received: " << message << endl;
    }
};

int main() {
    ChatRoom chatRoom;

    User user1("Alice", &chatRoom);
    User user2("Bob", &chatRoom);
    User user3("Charlie", &chatRoom);

    chatRoom.addColleague(&user1);
    chatRoom.addColleague(&user2);
    chatRoom.addColleague(&user3);

    user1.send("Hi everyone!");
    user2.send("Hello Alice!");
    user3.send("Good morning all!");

    return 0;
}
```

 **Output** :

```
Alice sends: Hi everyone!
Bob sends: Hello Alice!
Charlie sends: Good morning all!
Alice received: Hello Alice!
Alice received: Good morning all!
Bob received: Hi everyone!
Bob received: Good morning all!
Charlie received: Hi everyone!
Charlie received: Hello Alice!
```

---

### **Example: Mediator Pattern in Python** 🐍

#### **Scenario** : Chat Room

```python
# Mediator Interface
class Mediator:
    def send_message(self, message, colleague):
        pass

# Colleague Class
class Colleague:
    def __init__(self, mediator):
        self._mediator = mediator

    def send(self, message):
        pass

    def receive(self, message):
        pass

# Concrete Mediator
class ChatRoom(Mediator):
    def __init__(self):
        self.colleagues = []

    def add_colleague(self, colleague):
        self.colleagues.append(colleague)

    def send_message(self, message, colleague):
        for c in self.colleagues:
            if c != colleague:
                c.receive(message)

# Concrete Colleague
class User(Colleague):
    def __init__(self, name, mediator):
        super().__init__(mediator)
        self.name = name

    def send(self, message):
        print(f"{self.name} sends: {message}")
        self._mediator.send_message(message, self)

    def receive(self, message):
        print(f"{self.name} received: {message}")

# Client code
chat_room = ChatRoom()

user1 = User("Alice", chat_room)
user2 = User("Bob", chat_room)
user3 = User("Charlie", chat_room)

chat_room.add_colleague(user1)
chat_room.add_colleague(user2)
chat_room.add_colleague(user3)

user1.send("Hi everyone!")
user2.send("Hello Alice!")
user3.send("Good morning all!")
```

 **Output** :

```
Alice sends: Hi everyone!
Bob sends: Hello Alice!
Charlie sends: Good morning all!
Alice received: Hello Alice!
Alice received: Good morning all!
Bob received: Hi everyone!
Bob received: Good morning all!
Charlie received: Hi everyone!
Charlie received: Hello Alice!
```

---

### **Advantages of Mediator Pattern** ✅

1. **Reduced Complexity** : Instead of having multiple communication channels, the mediator centralizes and controls the communication between objects, making the system simpler.
2. **Loose Coupling** : Objects don’t need to know each other directly, making them easier to maintain and modify.
3. **Centralized Control** : The mediator can easily control the interactions and enforce rules about how communication occurs between objects.

---

### **Disadvantages of Mediator Pattern** ❌

1. **Single Point of Failure** : If the mediator has too many responsibilities, it may become a **bottleneck** or a  **single point of failure** .
2. **Overhead** : Using a mediator can add extra layers of communication and complexity, especially if the objects don't need that much coordination.
3. **Complexity in Large Systems** : In large systems, the mediator can become too complex, handling too many responsibilities.

---

### **When to Use the Mediator Pattern?** 📌

* When you have many objects needing to communicate with each other, and you want to centralize their interactions.
* When you want to **reduce dependencies** between objects, so that each object only knows about the mediator.
* When the system requires a **complex communication protocol** between objects, but you want to keep objects loosely coupled.

---

The **Mediator Pattern** helps coordinate communication between objects without letting them know too much about each other, like a **neutral intermediary** that ensures smooth operation. It’s perfect for **complex systems** where you want to reduce direct dependencies between objects! 👥💬
