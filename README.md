# Scientific Computing in C++

This repository contains practical exercises and projects for the "Scientific Programming in C++" course. The code demonstrates a progressive journey through C++, from fundamental syntax to more advanced concepts like object-oriented programming, templates, and memory management.

## Course Description

This course will introduce students to C++ as a language widely used in scientific computing. The course will cover most aspects of C++ to an intermediate level, with the aim being to teach students sufficient C++ to program non-trivial algorithms in a robust and efficient manner. The course should be accessible to all students, irrespective of any prior programming knowledge.

Students should leave the course knowing:
* Fundamentals of C++ programming, from variables, loops, to functions.
* Object Oriented Programming in C++ and polymorphism.
* Performance characteristics of data structures.

*(Note: Course description from the official course syllabus.)*
`[Link to official course description](https://www.your-university.edu/path/to/course)`

---

## Practicals

This repository is structured by "Practicals," with each folder corresponding to a specific topic from the course.

### Practical 1: C++ Fundamentals
* **Files:** `HelloWorld.cpp`, `DivOfNegNum.cpp`, `IntOverflow.cpp`, `FloatIntConversion.cpp`
* **Concepts:** Covers C++ basics, including program structure (`main`), standard output (`std::cout`), and data types. Explores the numerical properties of C++, such as integer division, integer overflow, and type-casting.

### Practical 2: Functions and File I/O
* **Files:** `quadratic.cpp`, `squares.cpp`
* **Concepts:** Introduces functions, user input (`std::cin`), and basic file output (`std::ofstream`). This practical includes a robust quadratic equation solver and a program that writes the squares of numbers to a `.dat` file.

### Practical 3: Numerical Methods (ODE Solver)
* **Files:** `odeSolver.cpp`, `odeplotter.py`
* **Concepts:** Implements simple numerical methods in C++ to solve an ordinary differential equation (ODE). The code demonstrates the **Euler method** and the **2nd-order Runge-Kutta** method. A Python script is included to plot the resulting `.dat` files using `matplotlib`.

### Practical 4: Functions, References, and Arrays
* **Files:** `problem_1.cpp`, `1dArray.cpp`, `matrixOperations.cpp`
* **Concepts:** Explores function mechanics like pass-by-value vs. pass-by-reference. Introduces modern C++ `std::vector` for handling 1D arrays and 2D matrices, including calculations for matrix trace and determinant.

### Practical 5: Pointers and Heap Allocation
* **Files:** `MultiDimArray.cpp`, `PascalTriangleHeapAllocation.cpp`
* **Concepts:** Demonstrates manual memory management on the heap. This includes a program for N-dimensional matrix multiplication using raw pointers (`new`/`delete[]`) and a more modern, efficient Pascal's Triangle generator using smart pointers (`std::make_unique`) and `std::span` (C++20).

### Practical 7: Object-Oriented Programming (Classes)
* **Files:** `date.hpp`, `date.cpp`, `main.cpp`
* **Concepts:** Introduces object-oriented programming by creating a robust `Date` class. This practical is a key exercise in OOP, demonstrating encapsulation, header/source file separation, member functions, constructors, `const`-correctness, and error handling (`std::invalid_argument`).

### Practical 9: Operator Overloading
* **File:** `rational.cpp`
* **Concepts:** Expands on OOP by implementing a `Rational` class for fractional numbers. This code demonstrates extensive use of **operator overloading** (e.g., `+`, `-`, `*`, `/`, `+=`, `<<`, `>>`) as well as `friend` functions. It includes a `static` helper function (`euclidGCF`) to automatically reduce fractions.

### Practical 11: C++ Templates
* **Files:** `vectSumTemplate.cpp`, `vectSumExtended.cpp`
* **Concepts:** Covers C++ templates for writing generic, type-safe functions.
    1.  `vectSumTemplate.cpp`: Implements a `sumVector` function and provides a **template specialization** for `double` to use a more numerically stable algorithm (Kahan summation).
    2.  `vectSumExtended.cpp`: Shows a more advanced, modern C++ approach using `std::enable_if_t` and type traits (e.g., `std::is_floating_point_v`) to automatically select the correct summation algorithm at compile time based on the vector's type.

### Practical 12: STL Containers and File I/O
* **Files:** `analysisBritishPMs.cpp`, `PMs.txt`
* **Concepts:** Demonstrates reading from files (`std::ifstream`) and processing data using STL containers (`std::vector`, `std::string`). The program is designed to read and parse a list of names from a text file.

---

## How to Compile and Run

A C++20 compatible compiler (like `g++` or `clang++`) is required. The `.gitignore` is set up to ignore compiled binaries.

### Single-File Practicals
Most practicals consist of single `.cpp` files and can be compiled directly.

**Example (Practical 2):**
```bash
# Compile
g++ -std=c++20 Practical_2/quadratic.cpp -o quadratic

# Run
./quadratic
```

### Multi-File Practicals
Practicals with header (`.hpp`) and source (`.cpp`) files require compiling all relevant `.cpp` files.

**Example (Practical 7):**
```bash
# Compile (link main.cpp and date.cpp)
g++ -std=c++20 Practical_7/main.cpp Practical_7/date.cpp -o date_program

# Run
./date_program
```

### Python Dependencies
The plotter script in Practical 3 requires `matplotlib` and `numpy`.

**Example (Practical 3):**
```bash
# First, compile and run the C++ code to generate the data
g++ -std=c++20 Practical_3/odeSolver.cpp -o odeSolver
./odeSolver

# Install Python dependencies
pip install matplotlib numpy

# Run the plotter
python3 Practical_3/odeplotter.py
```
