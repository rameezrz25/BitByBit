### **Proxy Pattern: The Middleman of Object Access** 🕵️‍♂️✨

---

### **What is the Proxy Pattern?** 🤔

The **Proxy Pattern** is a **structural design pattern** where a **proxy object** acts as a substitute or intermediary for another object. This pattern provides controlled access to the real object by performing additional operations like authentication, caching, or logging.

---

### **Real-World Analogy: A Receptionist** 🏢

Imagine a **receptionist** at a company:

* You can’t meet the CEO directly; the receptionist screens visitors, books appointments, and ensures that only the right people meet the CEO.
* **Receptionist** : The  **proxy** .
* **CEO** : The  **real subject** .
* The receptionist controls and manages access to the CEO.

---

### **Why Use the Proxy Pattern?** 🛠️

The proxy pattern is useful when:

1. **Access Control** : Restrict or authenticate access to sensitive objects.
2. **Lazy Initialization** : Delay the creation or heavy computations of an object until it’s actually needed.
3. **Logging/Monitoring** : Track or log access to an object.
4. **Remote Access** : Represent objects that exist on a remote server.

---

### **Types of Proxies** 🗂️

1. **Virtual Proxy** :

* Delays object creation or initialization until necessary.
* Example: Loading images in a document viewer only when they are visible.

1. **Protection Proxy** :

* Controls access based on permissions or roles.
* Example: An admin panel accessible only to authorized users.

1. **Remote Proxy** :

* Represents an object located on a remote server.
* Example: Invoking methods on an object in a distributed system.

1. **Cache Proxy** :

* Stores temporary results to reduce load.
* Example: Storing recent API responses to avoid redundant requests.

---

### **How Does It Work?** 🛠️

1. The **client** interacts with the **proxy** instead of the  **real object** .
2. The **proxy** can:
   * Forward requests to the  **real object** .
   * Perform additional operations (e.g., caching, logging, access control).

---

### **Proxy Pattern Structure** 🏗️

| **Component**    | **Role**                                                        |
| ---------------------- | --------------------------------------------------------------------- |
| **Subject**      | Defines the interface for the real object and proxy.                  |
| **Real Subject** | The actual object that performs the operations.                       |
| **Proxy**        | Intercepts requests to the real subject and adds extra functionality. |

---

### **Example: Proxy Pattern in C++** 💻

#### **Scenario** : Access Control for a Document

```cpp
#include <iostream>
#include <memory>

// Subject Interface
class Document {
public:
    virtual void display() = 0;
    virtual ~Document() = default;
};

// Real Subject
class RealDocument : public Document {
public:
    RealDocument(const std::string& filename) : filename_(filename) {
        std::cout << "Loading document: " << filename_ << std::endl;
    }

    void display() override {
        std::cout << "Displaying document: " << filename_ << std::endl;
    }

private:
    std::string filename_;
};

// Proxy
class DocumentProxy : public Document {
public:
    DocumentProxy(const std::string& filename) : filename_(filename), realDocument_(nullptr) {}

    void display() override {
        if (!realDocument_) {
            realDocument_ = std::make_unique<RealDocument>(filename_);
        }
        realDocument_->display();
    }

private:
    std::string filename_;
    std::unique_ptr<RealDocument> realDocument_;
};

// Client Code
int main() {
    DocumentProxy proxy("example.pdf");
  
    // Document not loaded yet
    std::cout << "Proxy created, but document not loaded yet.\n";

    // Document loaded on demand
    proxy.display();
    proxy.display(); // Already loaded; no reloading

    return 0;
}
```

---

### **Example: Proxy Pattern in Python** 🐍

#### **Scenario** : Protection Proxy for a Secure Server

```python
from abc import ABC, abstractmethod

# Subject Interface
class Server(ABC):
    @abstractmethod
    def access(self):
        pass

# Real Subject
class RealServer(Server):
    def access(self):
        print("Accessing the secure server!")

# Proxy
class ProxyServer(Server):
    def __init__(self, user_role):
        self.user_role = user_role
        self.real_server = RealServer()

    def access(self):
        if self.user_role == "admin":
            self.real_server.access()
        else:
            print("Access denied. Admins only.")

# Client Code
proxy = ProxyServer("guest")
proxy.access()  # Access denied

proxy = ProxyServer("admin")
proxy.access()  # Access granted
```

---

### **Advantages** ✅

1. **Controlled Access** : Adds a layer of security or logging.
2. **Improved Performance** : Optimizes resource use (e.g., lazy loading or caching).
3. **Encapsulation** : Hides the complexity of the real object.

---

### **Disadvantages** ❌

1. **Increased Complexity** : Adds more classes and layers.
2. **Performance Overhead** : Proxy operations can add delays.

---

### **When to Use the Proxy Pattern?** 📌

* You need to **control access** to an object.
* You want to **lazy-load resources** or objects.
* You need to **cache data** for efficiency.
* You’re dealing with  **remote resources** .

---

By introducing a  **proxy** , you get a **middleman** that helps manage access, optimize performance, or simplify remote interactions while keeping the real object safe and hidden!
