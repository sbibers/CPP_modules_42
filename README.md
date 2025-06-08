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
| **CPP06** | C++ type casting, serialization, and RTTI-free type identification | **100** |
| **CPP07** | C++ Function and Class Templates | **100** |
| **CPP08** | Templated containers, iterators, algorithms, custom containers | **100** |

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

## 📌 CPP06 - Type Conversion, Serialization, and Type Identification

This module explores **C++ type casting**, memory address serialization, and identifying dynamic types without using RTTI.

### 🛠 Topics Covered:
- Scalar type conversion
- C++ casting
- Serialization and deserialization using `uintptr_t`
- Type identification using inheritance and virtual functions (without `typeinfo`)

### 🚀 Completed Exercises:
1. **Exercise 00** — *Conversion of Scalar Types*
   - Created a `ScalarConverter` class with a single static method `convert()`.
   - Converts a string representing a C++ literal into:
     - `char`
     - `int`
     - `float`
     - `double`
   - Handles conversions, overflows, and pseudo-literals like `nan`, `+inf`, `-inf`.
   - Displays appropriate messages for impossible or non-displayable conversions.

2. **Exercise 01** — *Serialization*
   - Implemented a `Serializer` class with:
     - `uintptr_t serialize(Data* ptr);` — Converts a pointer to a `uintptr_t`.
     - `Data* deserialize(uintptr_t raw);` — Converts a `uintptr_t` back to a pointer.
   - Created a simple `Data` structure with non-empty members.
   - Validated serialization-deserialization correctness.

3. **Exercise 02** — *Identify Real Type*
   - Implemented a `Base` class with a virtual destructor.
   - Created three derived classes `A`, `B`, and `C`.
   - Wrote:
     - `Base* generate(void);` — Randomly creates instances of `A`, `B`, or `C`.
     - `void identify(Base* p);` — Identifies type from a pointer.
     - `void identify(Base& p);` — Identifies type from a reference (without using pointers or `typeinfo`).

---

## 📌 CPP07 - C++ Templates

This module introduces **function templates and class templates** in C++. It teaches how to create reusable, type-independent code using templates, a foundational feature of generic programming in C++.

### 🛠 Topics Covered:
- Function templates
- Class templates
- Template instantiation
- Supporting different data types with a single generic implementation
- Handling const and non-const references in template functions

### 🚀 Completed Exercises:

#### 📦 Exercise 00 — *Start with a few functions*

**Description:**  
Implemented three simple function templates:
- `swap(T& a, T& b)`
- `min(const T& a, const T& b)`
- `max(const T& a, const T& b)`

**Features:**
- Works with any type that supports comparison operators.
- Functions are fully defined in the header file.
- Tested with both `int` and `std::string` types.

---

#### 📦 Exercise 01 — *Iter*

**Description:**  
Implemented a function template `iter` that:
- Takes an array’s address, its length, and a function.
- Applies the function to each element of the array.
- Supports both `const` and non-`const` elements.

**Features:**
- Generic and type-safe.
- Works with any type of array and any callable (function, lambda, etc.).
- Custom functions can take arguments by const reference or by value.

**Example Use:**
- Print each element in an array.
- Increment or modify elements in an array.

---

#### 📦 Exercise 02 — *Array*

**Description:**  
Implemented a class template `Array<T>` that behaves like a simplified, type-safe, dynamic array with:
- A default constructor.
- A parameterized constructor accepting a size.
- A copy constructor and assignment operator.
- An overloaded `[]` operator for element access with bounds checking.
- A `size()` member function returning the number of elements.

**Features:**
- Throws a custom `std::out_of_range` exception when accessing out-of-bounds elements.
- Works with any type `T`.
- Safe and memory-leak-free, verified with `valgrind`.

**Example Use:**
- Create an array of `int` or `std::string`.
- Access and modify elements.
- Handle out-of-range access gracefully with exceptions.

---

## 📌 CPP08 - Templated Containers, Iterators & Algorithms

This module focuses on **C++ containers, iterators, and template functions/classes**. You’ll create custom container classes and utility functions, learning how to manipulate collections of data efficiently using modern C++ techniques.

### 🛠 Topics Covered:
- Function and class templates
- Custom containers
- Iterators and STL compatibility
- Algorithms like `std::find`
- Exception handling in containers
- Iterable adaptations of non-iterable containers

### 🚀 Completed Exercises:
1. **Exercise 00** — *Easy find*
   - Implemented a function template `easyfind()` that searches for an integer in any STL container.
   - Returns an iterator to the first occurrence or throws an exception if not found.
   - Custom test cases written to ensure correct behavior on different containers.

2. **Exercise 01** — *Span*
   - Created a `Span` class that can hold up to `N` integers.
   - Methods:
     - `addNumber()`
     - `addNumbers()` for adding a range of numbers.
     - `shortestSpan()` and `longestSpan()` for calculating the minimum and maximum differences.
   - Exception handling for overflow and insufficient data.
   - Performance tested with **10,000+ numbers**.

3. **Exercise 02** — *Mutated abomination*
   - Developed a `MutantStack` class that inherits from `std::stack`.
   - Made it **iterable** by exposing its underlying container iterators.
   - Preserved all `std::stack` functionalities while adding iteration.
   - Verified compatibility with `std::list` by matching behaviors.

---

## ⚠️ Notes:
- All exercises follow the **C++98 standard**.
- No external libraries are allowed.
- **Memory leaks are prevented and checked with `valgrind`**.
- Makefiles included for each exercise directory.

---

## 📌 Author:
**Salam Baybars**  
*42 Amman Student | Computer Science Enthusiast*

- 📧 [salambaybars@gmail.com](mailto:salambaybars@gmail.com)
- 📸 [Instagram](https://www.instagram.com/salam._.baybars/)

---

