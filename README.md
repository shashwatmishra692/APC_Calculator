# Arbitrary Precision Calculator (APC)

## 📖 Project Description
This project implements an **Arbitrary Precision Calculator (APC)** in **C**, capable of performing arithmetic operations on very large integers that exceed the limits of standard C data types.

Instead of relying on built-in numeric types, the calculator represents numbers using a **Doubly Linked List**, where each node stores a single digit. This approach enables accurate computation of numbers of any length.

The program supports **addition, subtraction, multiplication, and division** using command-line arguments and demonstrates strong usage of **data structures, dynamic memory allocation, and pointer manipulation**.


---

## ✨ Features
- Supports **large integer arithmetic** beyond standard limits
- Operations implemented:
  - ➕ Addition
  - ➖ Subtraction (with sign handling)
  - ✖ Multiplication
  - ➗ Division
- Numbers stored digit-by-digit using **Doubly Linked Lists**
- Input validation for operands and operators
- Handles leading zeros and edge cases
- Modular and well-structured codebase

---

---

## 🛠 Technologies Used
- **Programming Language:** C
- **Data Structure:** Doubly Linked List
- **Compiler:** GCC
- **Platform:** Linux
- **Concepts Used:**
  - Dynamic Memory Allocation
  - Pointers & Structures
  - Command Line Arguments
  - Modular Programming

---


## 📂 Project Structure

```

APC/
│
├── main.c # Header file declarations and macros
├── validation.c # Main driver file and input handling
├── header.h # Function prototypes and structure definitions
└── README.md # Project documentation

```

## ▶ How to Compile
Use GCC to compile the project:
bash
gcc *.c -o apc

## How to Run
`./apc <number1> <operator> <number2>` 

## Example
`./apc 123456789123456789 + 987654321987654321`

---

## Supported Operators

```

| Operator | Operation      |
| -------- | -------------- |
| +        | Addition       |
| -        | Subtraction    |
| X        | Multiplication |
| /        | Division       |

```

## Internal Working

Each digit of the input number is stored in a node of a Doubly Linked List

Arithmetic operations are performed digit-by-digit similar to manual calculation

Carry, borrow, and intermediate results are handled using linked list traversal

Division is implemented using repeated subtraction

---
