
# 📘 **Process Synchronization**

### ❓ **What is Process Synchronization?**

Process synchronization is the coordination of processes to ensure that they execute in a controlled sequence when accessing shared resources. It prevents **race conditions** and ensures data consistency.

---

### 🌟 **Key Concepts**

1. **Race Condition**
   * A race condition occurs when two or more processes access shared resources simultaneously, and the outcome depends on the order of execution.
   * 🔑 **Goal:** Avoid race conditions by controlling process interactions.
2. **Critical Section Problem**
   * The critical section is a segment of code where shared resources are accessed.
   * **Problem:** Ensure that no two processes are in their critical sections simultaneously.
3. **Solution Requirements**
   * **Mutual Exclusion:** Only one process can access the critical section at a time.
   * **Progress:** If no process is in the critical section, others waiting should be able to proceed.
   * **Bounded Waiting:** No process should wait indefinitely to enter its critical section.

---

### 🛠️ **Synchronization Tools**

#### 1. **Locks**

* Simplest mechanism to enforce mutual exclusion.
* **Spinlocks** : Processes spin in a loop while waiting, suitable for short critical sections.
* **Mutexes** : Use OS-level mechanisms to enforce mutual exclusion with blocking.

#### 2. **Semaphores**

* A synchronization tool using integer variables to control access.
* Two types:
  * **Binary Semaphore** : Acts as a lock (value is 0 or 1).
  * **Counting Semaphore** : Allows a fixed number of processes to access resources.
* Operations:
  * `wait()` or `P()`: Decrements the semaphore. If the value becomes negative, the process is blocked.
  * `signal()` or `V()`: Increments the semaphore, waking up blocked processes.

**Example:**

```cpp
semaphore mutex = 1;

void criticalFunction() {
    wait(mutex);      // Enter critical section
    // Critical section code
    signal(mutex);    // Exit critical section
}
```

#### 3. **Monitors**

* A high-level abstraction combining synchronization primitives.
* Encapsulates shared variables, procedures, and synchronization within a single module.
* **Condition Variables** : Use `wait()` and `signal()` to manage waiting processes.

**Example:**

```cpp
monitor Example {
    condition condVar;

    void synchronizedFunction() {
        if (!condVar.signalAvailable())
            condVar.wait();
        // Critical section
        condVar.signal();
    }
}
```

#### 4. **Peterson’s Algorithm**

* A software-based solution for mutual exclusion for two processes.
* Relies on a `turn` variable and two boolean flags.

---

### 🚨 **Common Synchronization Problems**

#### 1. **Bounded Buffer Problem (Producer-Consumer Problem)**

* **Scenario:** A producer adds items to a buffer, and a consumer removes them.
* **Goal:** Prevent producer from adding to a full buffer and consumer from removing from an empty one.

**Solution with Semaphores:**

```cpp
semaphore empty = N;  // Number of empty slots
semaphore full = 0;   // Number of filled slots
semaphore mutex = 1;  // Mutual exclusion

void producer() {
    wait(empty);
    wait(mutex);
    // Add item to buffer
    signal(mutex);
    signal(full);
}

void consumer() {
    wait(full);
    wait(mutex);
    // Remove item from buffer
    signal(mutex);
    signal(empty);
}
```

#### 2. **Readers-Writers Problem**

* **Scenario:** Multiple processes want to read or write a shared resource.
* **Goal:** Prevent readers and writers from accessing the resource simultaneously.

**Solution:**

* **First Readers-Writers Problem:** No reader is kept waiting unless a writer has started.
* **Second Readers-Writers Problem:** Writers have priority over readers.

#### 3. **Dining Philosophers Problem**

* **Scenario:** Philosophers alternately eat and think, but need two chopsticks to eat.
* **Goal:** Avoid deadlock while ensuring fairness.

**Solution with Semaphores:**

```cpp
semaphore chopstick[5];

void philosopher(int i) {
    wait(chopstick[i]);
    wait(chopstick[(i + 1) % 5]);
    // Eat
    signal(chopstick[i]);
    signal(chopstick[(i + 1) % 5]);
}
```

---

### 🚧 **Challenges in Synchronization**

1. **Deadlock** : Processes wait indefinitely for resources.
2. **Starvation** : A process waits indefinitely due to lack of fairness.
3. **Priority Inversion** : High-priority tasks are blocked by low-priority tasks holding resources.

---

### 🔍 **Tips for Designing Synchronization**

* Use **atomic operations** where possible.
* Minimize the time spent in critical sections.
* Avoid **nested locks** to reduce deadlock risk.
* Use **timeout mechanisms** for acquiring locks.
* Prefer high-level abstractions like monitors for readability and maintainability.
