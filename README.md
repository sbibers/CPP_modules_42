
# 📖 C++ | 42Cursus Complete

## 📊 CPP Modules Progress

| Module  | Subject Concepts | Grade |
|:---------|:---------------------|:-------|
| **CPP00** | Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basics | **80** |
| **CPP01** | Memory allocation, pointers to members, references, switch statement | **90** |
| **CPP02** | Ad-hoc polymorphism, operator overloading, and Orthodox Canonical class form | **80** |
| **CPP03** | Inheritance | **80** |
| **CPP04** | Subtype polymorphism, abstract classes, interfaces | **80** |
| **CPP05** | Exception handling, abstract classes, form execution, polymorphism | **100** |

---

## 📌 CPP00 - Introduction to C++

This module introduces **basic C++ syntax**, input/output operations, and command-line arguments.

### 🛠 Topics Covered:
- Using `iostream`, `cin`, and `cout`
- `std::string` manipulation
- Understanding `argc` and `argv`
- Basic class structures

### 🚀 Completed Exercises:
1. **Exercise 00** — `megaphone`: A simple program that converts input text to uppercase.
2. **Exercise 01** — Exploring `std::string` and memory management.
3. **Exercise 02** — Implementing a basic **PhoneBook** using an array.

---

## 📌 CPP01 - Memory Allocation & Pointers

This module covers **dynamic memory management, references, and constructors/destructors**.

### 🛠 Topics Covered:
- Pointers and references
- Stack vs. Heap memory
- `new` and `delete` for memory allocation
- Class constructors & destructors

### 🚀 Completed Exercises:
1. **Exercise 00** — Basics of pointers and references.
2. **Exercise 01** — Dynamic memory allocation using `new` and `delete`.
3. **Exercise 02** — Implementing a simple class with a constructor and destructor.

---

## 📌 CPP02 - OOP & Orthodox Canonical Form

This module introduces **Object-Oriented Programming (OOP)** concepts like the **Orthodox Canonical Form**.

### 🛠 Topics Covered:
- Access modifiers: `public`, `private`
- Function overloading
- Operator overloading
- Orthodox Canonical Form: constructor, copy constructor, destructor, and assignment operator

---

## 📌 CPP03 - Inheritance

This module introduces **class inheritance** in C++.

### 🛠 Topics Covered:
- Base and Derived classes
- Inheritance types: `public`, `protected`, `private`
- Constructors and destructors in inheritance
- Virtual functions and method overriding

---

## 📌 CPP04 - Subtype Polymorphism & Abstract Classes

This module introduces **subtype polymorphism and abstract classes**.

### 🛠 Topics Covered:
- Abstract base classes
- Pure virtual functions
- Polymorphism in object-oriented design
- Function overriding in derived classes

---

## 📌 CPP05 - Exceptions & Repetition

This module introduces **exception handling, abstract classes, and form execution logic** — simulating a bureaucratic workflow using C++ classes, exceptions, and polymorphism.

### 🛠 Topics Covered:
- C++ Exception handling (`try`, `catch`, `throw`)
- Custom exception classes
- Abstract base classes
- Subclass specialization and inheritance
- Function overriding
- Polymorphic function execution

### 🚀 Completed Exercises:

1. **Exercise 00** — *Mommy, when I grow up, I want to be a bureaucrat!*
   - Implemented the `Bureaucrat` class.
   - Constant name and a grade (1 to 150) with increment and decrement functionality.
   - Custom exceptions `GradeTooHighException` and `GradeTooLowException`.
   - Overloaded `<<` operator for clean, formatted output.

2. **Exercise 01** — *Form up, maggots!*
   - Created a `Form` class with:
     - Constant name.
     - Boolean signed status.
     - Constant required grades for signing and execution.
   - Integrated exception handling for invalid grades.
   - Bureaucrats can attempt to sign forms; if their grade is insufficient, exceptions are thrown.
   - Overloaded `<<` operator to display form details.

3. **Exercise 02** — *No, you need form 28B, not 28C...*
   - Converted `Form` to an abstract base class `AForm`.
   - Created three specialized forms:
     - `ShrubberyCreationForm`: Creates a file with ASCII trees.
     - `RobotomyRequestForm`: 50% chance to "robotomize" the target.
     - `PresidentialPardonForm`: Announces a pardon from Zaphod Beeblebrox.
   - Implemented the `execute()` method with grade checks and exception handling.
   - Bureaucrats can now execute forms via the `executeForm()` method.

---

## ⚠️ Notes:
- All exercises follow the **C++98 standard**.
- No external libraries are allowed.
- **Memory leaks must be avoided** (checked with `valgrind`).
