
---

# 🧠 **Bitwise Operations in C/C++**

Bitwise operations are used to manipulate data at the level of individual bits. These operations are faster than arithmetic operations and are often used in low-level programming such as embedded systems, cryptography, and network protocols.

## 📊 **Bitwise Operators**

| **Operator**    | **Symbol** | **Description**                                  | **Example** |
| --------------------- | ---------------- | ------------------------------------------------------ | ----------------- |
| **AND**         | `&`            | Sets each bit to `1` if both bits are `1`.          | `a & b`         |
| **OR**          | `|`            | Sets each bit to `1` if at least one of the bits is `1`. | `a | b`         |
| **XOR**         | `^`            | Sets each bit to `1` if bits are different.           | `a ^ b`         |
| **NOT**         | `~`            | Inverts each bit.                                      | `~a`            |
| **Left Shift**  | `<<`           | Shifts bits to the left, adding `0`s on the right.   | `a << 2`        |
| **Right Shift** | `>>`           | Shifts bits to the right, discarding bits shifted out. | `a >> 2`        |

---

## 🚀 **Examples of Bitwise Operations**

### 1. **Printing the Binary Representation of Any Number**

```cpp
void pr_binary(int num){
    for(int i=31; i>=0; i--) 
        cout << ((num >> i) & 1); 
    cout << endl;
}
```

This function prints the binary representation of any number.

---

### 2. **Checking if the i-th Bit is Set or Not**

To check if the `i`th bit is set (1):

```cpp
if((num & (1 << i)) != 0)
    cout << "Bit " << i << " is set." << endl;
else
    cout << "Bit " << i << " is not set." << endl;
```

---

### 3. **Counting the Number of Set Bits (1s)**

To count the number of `1`s in the binary representation:

```cpp
int count = 0;
int num = 15;
for (int i = 31; i >= 0; --i) 
    if ((num & (1 << i)) != 0) count++;
cout << "Number of set bits: " << count << endl;
```

---

### 4. **Check if a Given Number is a Power of 2**

Numbers that are powers of `2` have exactly one `1` in their binary representation. You can check this with the following function:

```cpp
bool isPowerOfTwo(int x) {
    return (x && !(x & (x - 1)));
}
```

**Example:**

```cpp
cout << isPowerOfTwo(16);  // Output: true (16 is a power of 2)
```

---

### 5. **Dividing or Multiplying Any Number by Two**

Using bitwise operations, you can quickly multiply or divide numbers by `2`:

```cpp
int n = 5;
n = n >> 1;  // Divide by 2
n = n << 1;  // Multiply by 2
```

---

### 6. **Playing with Characters and Case Conversion**

#### Converting an Upper Case Character to Lower Case

```cpp
cout << char('A' | (1 << 5)) << endl;  // Output: 'a'
```

#### Converting a Lower Case Character to Upper Case

```cpp
cout << char('a' & (~(1 << 5))) << endl;  // Output: 'A'
```

#### Find a Letter’s Position in Alphabet

To get the position of a letter (1-26), use bitwise `AND` with `31`:

```cpp
cout << ('A' & 31);  // Output: 1 (position of 'A')
cout << ('c' & 31);  // Output: 3 (position of 'c')
```

---

### 7. **Swapping Two Numbers Using XOR**

You can swap two numbers without a temporary variable using XOR:

```cpp
int a = 4;
int b = 5;
a = a ^ b;
b = b ^ a;
a = a ^ b;
// Now a = 5, b = 4
```

---

### 8. **Clearing the Set Bits Up to the i-th Bit**

To clear the bits up to the `i`-th bit (inclusive):

```cpp
int i = 4;
int a = 59;  // 00111011
int b = (a & (~((1 << (i + 1)) - 1))); // Clears the LSB upto 5th bit
```

To clear the most significant bits (MSB) up to the `i`-th bit:

```cpp
int i = 3;
int c = (a & ((1 << (i + 1)) - 1));  // Clears the MSB upto 3rd bit
```

---

## 🧩 **Other Common Bitwise Operations**

### Set Union, Intersection, and Subtraction

* **Set Union** : `A | B`
* **Set Intersection** : `A & B`
* **Set Subtraction** : `A & ~B`
* **Set Negation** : `ALL_BITS ^ A` or `~A`

### Set Bit

To set a specific bit to `1`:

```cpp
A |= (1 << bit);
```

### Clear Bit

To clear a specific bit (set it to `0`):

```cpp
A &= ~(1 << bit);
```

### Test Bit

To test if a specific bit is set (1):

```cpp
(A & (1 << bit)) != 0
```

### Extract Last Set Bit

To extract the last set bit (rightmost `1`):

```cpp
A & -A  // or A & ~(A - 1)
```

### Remove Last Set Bit

To remove the last set bit:

```cpp
A & (A - 1)
```

### Get All 1-bits

To get all 1-bits:

```cpp
~0 == -1
```

---

### Two's Complement Representation

In two’s complement representation, the most significant bit (MSB) is used as the sign bit. If it's `1`, the number is negative; otherwise, it's positive. The formula for two’s complement of a number `num` is:

```cpp
negative_number = ~positive_number + 1
```

**Example:**
For `num = 1`, the two's complement of `-1` is represented as:

```cpp
11111111111111111111111111111111 // -1
```

Subtraction in two's complement can be performed by adding the two numbers and taking the two's complement of the result:

```cpp
num = num1 + (~num2 + 1);  // Subtraction via two's complement
```

---

## 📝 **Summary of All Bitwise Operations**

* **AND (`&`)** : `1` if both bits are `1`.
* **OR (`|`)** : `1` if at least one bit is `1`.
* **XOR (`^`)** : `1` if bits are different.
* **NOT (`~`)** : Inverts the bits.
* **Left Shift (`<<`)** : Shifts bits to the left (multiply by `2`).
* **Right Shift (`>>`)** : Shifts bits to the right (divide by `2`).

### Common Applications:

* Set, clear, toggle, and check bits.
* Counting the number of set bits.
* Checking if a number is a power of 2.

---

## 🌟 **Conclusion**

Bitwise operations are powerful tools for manipulating data at the lowest level. They are essential for performance optimization and are widely used in systems programming, cryptography, networking, and more. Understanding these operations can help you write more efficient and low-level code. Happy coding! 🚀

---

This updated `README.md` includes the extra bitwise operations you've provided, with explanations and clear code examples for practical use.
