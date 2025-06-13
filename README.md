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
| **CPP09** | STL containers, algorithms, and real-world applications (Bitcoin Exchange, RPN Calculator, Merge-Insert Sort) | **100** |

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
- Takes an array's address, its length, and a function.
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

This module focuses on **C++ containers, iterators, and template functions/classes**. You'll create custom container classes and utility functions, learning how to manipulate collections of data efficiently using modern C++ techniques.

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

## 📌 CPP09 - STL, Containers & Algorithms

This module focuses on advanced usage of the C++ Standard Template Library (STL), containers, and algorithms. You will implement real-world inspired programs using containers, error handling, and efficient algorithms.

### 🛠 Topics Covered:
- STL containers: `std::map`, `std::vector`, `std::deque`, etc.
- File parsing and validation
- Error handling and custom error messages
- Efficient searching and sorting algorithms
- Time measurement and performance comparison

### 🚀 Completed Exercises:

#### 📦 Exercise 00 — *Bitcoin Exchange*

**Description:**  
Create a program (`btc`) that outputs the value of a certain amount of bitcoin on a certain date, using a provided CSV database of bitcoin prices. The program takes an input file with lines in the format `date | value` and outputs the value multiplied by the exchange rate for that date (or the closest lower date in the database). Handles invalid input, out-of-range values, and errors with clear messages. Uses at least one STL container.

**Features:**
- Reads and parses a CSV database of bitcoin prices.
- Validates input dates and values (date format: `YYYY-MM-DD`, value: float or positive integer between 0 and 1000).
- For missing dates, uses the closest lower date in the database.
- Handles errors: file not found, bad input, negative/too large values, invalid dates.
- Example output:
  ```
  2011-01-03 => 3 = 0.9
  2011-01-03 => 2 = 0.6
  2011-01-03 => 1 = 0.3
  2011-01-03 => 1.2 = 0.36
  2011-01-09 => 1 = 0.32
  Error: not a positive number.
  Error: bad input => 2001-42-42
  2012-01-11 => 1 = 7.1
  Error: too large a number.
  ```

---

#### 📦 Exercise 01 — *Reverse Polish Notation (RPN)*

**Description:**  
Create a program (`RPN`) that evaluates an expression in Reverse Polish Notation (postfix notation) passed as a command-line argument. Only supports single-digit numbers and the operators `+`, `-`, `*`, `/`. Uses at least one STL container. Handles errors with clear messages.

**Features:**
- Parses and evaluates RPN expressions from the command line.
- Supports operators: `+`, `-`, `*`, `/` (no brackets or decimals).
- Handles errors: invalid input, bad tokens, division by zero, etc.
- Example output:
  ```
  $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
  42
  $> ./RPN "7 7 * 7 -"
  42
  $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
  0
  $> ./RPN "(1 + 1)"
  Error
  ```

---

#### 📦 Exercise 02 — *PmergeMe (Ford-Johnson Merge-Insert Sort)*

**Description:**  
Create a program (`PmergeMe`) that sorts a sequence of positive integers using the Ford-Johnson merge-insert sort algorithm. The program must use at least two different STL containers (e.g., `std::vector` and `std::deque`) and display timing information for each. Handles at least 3000 integers and provides clear error messages for invalid input.

**Features:**
- Accepts a sequence of positive integers as command-line arguments.
- Implements merge-insert sort (Ford-Johnson algorithm) for two containers.
- Displays the unsorted and sorted sequences.
- Measures and displays the time taken for each container.
- Handles errors: invalid input, negative numbers, duplicates (optional handling).
- Example output:
  ```
  Before: 3 5 9 7 4
  After: 3 4 5 7 9
  Time to process a range of 5 elements with std::vector : 0.00031 us
  Time to process a range of 5 elements with std::deque : 0.00014 us
  ```

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

