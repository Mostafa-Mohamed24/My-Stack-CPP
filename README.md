# My Stack (C++ Template)

A **Stack (LIFO)** implementation in C++, built as a layered hierarchy:

```
clsDblLinkedList  --->  clsMyQueue  --->  clsMyStack
   (Linked List)         (Queue)          (Stack)
```

- A **Doubly Linked List** (`clsDblLinkedList`) was implemented first as the core data structure.
- A **Queue** (`clsMyQueue`) was then built on top of it, using the linked list internally.
- Finally, a **Stack** (`clsMyStack`) was implemented, inheriting from the Queue and overriding the insertion behavior (`push`) to achieve LIFO instead of FIFO.

---

## 🧱 Class: `clsMyStack<T>`

```cpp
template <class T>
class clsMyStack : public clsMyQueue<T>
```

The Stack class inherits all of the Queue's members and adds/overrides behavior on top of it to act as a true Stack.

---

## 📋 Methods Available on the Stack

### 🔹 Methods defined in the Stack itself

| Method | Description |
|---|---|
| `void push(T value)` | Adds a new element to the **top** of the stack (at the beginning of the linked list). |
| `T Top()` | Returns the element at the **top** of the stack (the last one pushed). |
| `T Bottom()` | Returns the element at the **bottom** of the stack (the first one pushed). |

### 🔹 Methods inherited from the Queue and available on the Stack object

| Method | Description |
|---|---|
| `void Print()` | Prints all elements of the stack. |
| `int Size()` | Returns the number of elements in the stack. |
| `void pop()` | Removes the element at the top of the stack. |
| `bool IsEmpty()` | Returns `true` if the stack is empty. |
| `T GetItem(int Index)` | Returns the value of the element at the given index. |
| `void UpdateItem(int Index, T NewValue)` | Updates the value of the element at the given index. |
| `void InsertAfter(int Index, T Value)` | Inserts a new element right after the element at the given index. |
| `void InsertAtFront(T Value)` | Inserts an element at the front of the stack. |
| `void InsertAtBack(T Value)` | Inserts an element at the back of the stack. |
| `void Reverse()` | Reverses the order of the stack's elements. |
| `void Clear()` | Removes all elements from the stack. |

---

## 💻 Usage Example

```cpp
clsMyStack<int> Stack;

Stack.push(10);
Stack.push(20);
Stack.push(30);

Stack.Print();          // Print the stack
Stack.Top();            // Element at the top
Stack.Bottom();         // Element at the bottom
Stack.pop();            // Remove the top element
```

---

## 🏗️ Architecture Overview

1. **`clsDblLinkedList<T>`** → The core data structure (a doubly linked list) supporting insertion/deletion at the front and back, searching, reversing, and getting/updating an element by index.
2. **`clsMyQueue<T>`** → Uses the linked list internally (`_Queue`) and exposes a Queue (FIFO) interface such as `Push`, `pop`, `front`, `back`.
3. **`clsMyStack<T>`** → Inherits from `clsMyQueue<T>` and **overrides** the insertion behavior via `push()` so that new elements are added at the **front** of the list instead of the back — meaning the last element pushed is the first one popped (LIFO).
