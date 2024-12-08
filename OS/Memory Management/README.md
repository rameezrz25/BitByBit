
---

## 📘 **Memory Management (Based on Galvin)**  

### ❓ **What is Memory Management?**  
Memory management is the functionality of an operating system that handles and optimizes the use of a computer’s primary memory (RAM). It ensures:  
1. Efficient allocation of memory to processes.  
2. Protection of processes from interfering with each other.  
3. Maximization of CPU and memory utilization.  

---

### 🌟 **Key Concepts**
1. **Address Spaces**  
   - **Logical Address Space**: Address generated by the CPU (also called virtual address).  
   - **Physical Address Space**: Address in physical memory (RAM).  

   **Note:** Logical addresses are translated to physical addresses using a hardware device like the **Memory Management Unit (MMU)**.

2. **Binding of Instructions and Data**  
   - **Compile Time**: Absolute memory addresses are determined at compile time.  
   - **Load Time**: Addresses are generated at load time when the program is loaded into memory.  
   - **Execution Time**: Addresses are dynamically translated during program execution (used in modern systems).  

---

### 🛠️ **Memory Management Techniques**

#### 1. **Contiguous Memory Allocation**
   - Memory is allocated in a single contiguous block to each process.  
   - **Advantages**: Simple to implement.  
   - **Disadvantages**: Leads to **fragmentation**.

   **Types**:
   - **Fixed Partitioning**: Divides memory into fixed-sized blocks.  
   - **Dynamic Partitioning**: Partitions are created as processes arrive.

   **Problems**:
   - **External Fragmentation**: Free memory blocks are scattered.  
   - **Internal Fragmentation**: Allocated memory may have unused space.

#### 2. **Paging**  
   - Divides memory into fixed-size blocks called **frames**.  
   - Logical address space is divided into **pages** of the same size.  
   - A **page table** maps logical pages to physical frames.

   **Advantages**:
   - Eliminates external fragmentation.  
   - Allows efficient memory use.

   **Example**:
   ```plaintext
   Logical Address = Page Number + Offset
   Physical Address = Frame Number + Offset
   ```

   **Hardware Support**:
   - **Translation Lookaside Buffer (TLB)**: A high-speed cache for page table entries to speed up address translation.

#### 3. **Segmentation**
   - Divides memory into variable-sized segments based on logical divisions like code, data, stack, etc.  
   - A **segment table** maps segments to physical memory.

   **Advantages**:
   - Matches programmer's view of memory.  
   - Supports code sharing and protection.

   **Disadvantage**: Can lead to external fragmentation.

---

### 🚨 **Virtual Memory**  

Virtual memory is a technique that allows the execution of processes that may not be completely loaded in memory.  

#### 1. **Demand Paging**  
   - Only the required pages are loaded into memory.  
   - Uses a **page fault** mechanism to load missing pages.

   **Steps in Demand Paging**:
   1. A process accesses a page not in memory.  
   2. A page fault occurs, and the OS retrieves the page from the disk.  
   3. The page is loaded into a frame, and the process resumes execution.

   **Advantages**:
   - Efficient use of memory.  
   - Enables large programs to run on limited memory.  

#### 2. **Page Replacement Algorithms**  
   When memory is full, one page must be replaced. Common algorithms:  
   - **FIFO (First-In-First-Out)**: Removes the oldest page.  
   - **LRU (Least Recently Used)**: Removes the page least recently used.  
   - **Optimal**: Replaces the page that will not be used for the longest time (ideal but impractical).  

   **Example: FIFO**
   ```plaintext
   Reference String: 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
   Frames:          [1] [1,2] [1,2,3] [2,3,4] [3,4,1] ...
   ```

#### 3. **Thrashing**
   - Occurs when a process spends more time swapping pages in and out than executing.  
   - **Solutions**:
     - Use a **working set model** to keep frequently accessed pages in memory.  
     - Adjust the degree of multiprogramming to reduce page faults.

---

### 🛡️ **Memory Protection**
To prevent processes from accessing unauthorized memory, the OS uses:  
1. **Base and Limit Registers**: Define the boundaries of a process’s address space.  
2. **Segmentation and Paging**: Enforce protection at the segment or page level.  
3. **Access Control Bits**: Specify permissions for each segment/page (read, write, execute).  

---

### 🚧 **Fragmentation**
1. **External Fragmentation**  
   - Free memory is scattered into small non-contiguous blocks.  
   - Occurs in contiguous memory allocation.  

2. **Internal Fragmentation**  
   - Allocated memory may contain unused space.  
   - Common in paging systems.

---

### 🔍 **Example Problems and Solutions**
#### Example 1: Page Table Entry Calculation  
Given:  
- Logical address space = 16 bits.  
- Page size = 4 KB.

Find:  
1. Number of pages:  
   ```plaintext
   Number of pages = 2^(Logical Address Bits - Page Offset Bits)
                  = 2^(16 - 12) = 16 pages.
   ```

2. Page Table Size:  
   ```plaintext
   Page Table Entries = Number of Pages = 16.
   ```

---
