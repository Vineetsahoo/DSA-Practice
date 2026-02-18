# Data Structures and Algorithms Practice

A comprehensive collection of data structures and algorithms implementations in C, including solutions to various LeetCode problems and fundamental computer science concepts.

## Overview

This repository contains implementations of essential algorithms, data structures, and compiler design concepts. Each module is organized into dedicated directories with solved problems and practice exercises.

## Topics Covered

### Sorting Algorithms
- **Bubble Sort** - O(n²) comparison-based algorithm with optimizations
- **Insertion Sort** - Efficient for small datasets and nearly sorted arrays
- **Selection Sort** - Simple in-place comparison sort
- **Merge Sort** - Divide-and-conquer algorithm with O(n log n) complexity
- **Quick Sort** - Efficient partitioning-based sorting algorithm

### Two-Pointer Techniques
- Array manipulation and duplicate removal
- Palindrome validation and substring problems
- Sliding window patterns for subarray optimization
- Fixed and dynamic window implementations

### Data Structures
- **Linked Lists** - Singly linked list implementation with CRUD operations
- **Stacks** - LIFO data structure implementations
- **Queues** - FIFO data structure implementations
- **Trees** - Binary tree fundamentals and traversals

### Algorithms
- **Searching** - Binary search and linear search implementations
- **Factorial Computations** - Factorial calculations and related problems
- **Sorting & Searching** - Combined algorithm applications

### Compiler Design
- **Lexical Analysis** - Flex-based lexer for tokenizing source code
- **Calculator Parser** - Bison/Yacc parser with mathematical expression evaluation
- **Left Recursion Elimination** - Grammar transformation for parser optimization
- Token recognition for keywords, identifiers, operators, and symbols
- Support for arithmetic operations, power, and trigonometric functions (sinh, cosh, asin, acos)

## Featured Projects

### Mathematical Expression Calculator
A fully functional calculator built using **Bison** (parser generator) and **Flex** (lexer generator) that evaluates mathematical expressions with:

**Supported Operations:**
- Basic arithmetic: `+`, `-`, `*`, `/`
- Power operator: `^`
- Parentheses for precedence: `( )`
- Trigonometric functions: `SINH()`, `COSH()`, `ASIN()`, `ACOS()`
- Floating-point precision support

**Implementation Details:**
- Uses LALR(1) parsing with Bison
- Proper operator precedence and associativity
- Error handling for division by zero
- Type-safe union types for semantic values

## Project Structure

```
dsa_Practice/
├── 2_pointer_techniques/     # Two-pointer algorithm implementations
│   ├── Plaindrome.c          # Palindrome validation problems
│   ├── Remove_Duplicates.c   # Array duplicate removal
│   ├── Sliding_Window.c      # Sliding window pattern problems
│   └── output/
├── Assessment/               # Assessment problems
├── Compiler_Design/          # Compiler construction
│   ├── calculator.y         # Bison parser for calculator
│   ├── calculator.l         # Flex lexer for calculator
│   ├── calculator.tab.c     # Generated parser C code
│   ├── calculator.tab.h     # Generated parser header
│   ├── calculator.exe       # Compiled calculator executable
│   ├── expt5.c              # Left recursion elimination
│   ├── lexer.l              # Flex lexical analyzer
│   ├── lex.yy.c             # Generated lexer C code
│   ├── lexer.exe            # Compiled lexer executable
│   └── test_input.txt       # Sample input file
├── Factorial/                # Factorial-related problems
│   └── Factorial.c          # LeetCode 172, 60
├── Linked_List_&_Trees/      # Linked list and tree problems
├── Marque_Company/           # Company-specific problems
├── Single_linked_list/       # Linked list implementation
│   └── implmentation.c      # LeetCode 707: Design Linked List
├── Sorting_&_Searching_Algo/ # Combined sorting and searching
├── Sorting_techniques/       # Sorting algorithm implementations
│   ├── Bubble_sort.c
│   ├── Insertion_sort.c
│   ├── Merge_sort.c
│   ├── Quick_Sort.c
│   └── Selection_sort.c
├── Stack_&_Queues/           # Stack and queue implementations
├── move_exe.bat              # Batch script for file organization
├── move_exe.ps1              # PowerShell script for file organization
└── README.md
```

## Build Instructions

### Compiling C Programs

**Using VS Code Task:**
```
Ctrl+Shift+B (Windows/Linux) or Cmd+Shift+B (Mac)
```

**Using GCC (MSYS2):**
```powershell
gcc -Wall -Wextra -g3 <source_file>.c -o output/<executable>.exe
```

### Compiling Flex Lexer

**Prerequisites:**
- MSYS2 with flex package installed
- GCC compiler

**Steps:**
1. Generate lexer C code:
   ```powershell
   C:\msys64\usr\bin\flex.exe lexer.l
   ```

2. Compile the generated code:
   ```powershell
   gcc lex.yy.c -o lexer.exe
   ```

3. Run the lexer:
   ```powershell
   .\lexer.exe
   ```
   Enter the input filename when prompted.

### Compiling Bison/Flex Calculator

**Prerequisites:**
- MSYS2 with bison and flex packages installed
- GCC compiler

**Installation (if not already installed):**
```powershell
C:\msys64\usr\bin\bash.exe -lc "pacman -S --noconfirm bison flex"
```

**Compilation Steps:**

**Option 1 - Step by Step:**
```powershell
# Add MSYS2 to PATH
$env:Path = "C:\msys64\usr\bin;C:\msys64\ucrt64\bin;$env:Path"

# Generate parser from Bison file
bison -d calculator.y

# Generate lexer from Flex file
flex calculator.l

# Compile the generated C files
gcc calculator.tab.c lex.yy.c -o calculator.exe -lm
```

**Option 2 - Single Command:**
```powershell
$env:Path = "C:\msys64\usr\bin;C:\msys64\ucrt64\bin;$env:Path"; bison -d calculator.y; flex calculator.l; gcc calculator.tab.c lex.yy.c -o calculator.exe -lm
```

**Running the Calculator:**
```powershell
.\calculator.exe
```

**Example Expressions:**
- `2 + 3` → Result = 5.000000
- `10.5 * 2` → Result = 21.000000
- `2 ^ 3` → Result = 8.000000
- `SINH(1)` → Result = 1.175201
- `(5 + 3) * 2` → Result = 16.000000
- Press Ctrl+C to exit

## Utility Scripts

### Move Executables
Automatically organize compiled executables into output folders:

**Windows Batch:**
```cmd
move_exe.bat
```

**PowerShell:**
```powershell
.\move_exe.ps1
```

## Environment

- **Language:** C
- **Compiler:** GCC (MSYS2 UCRT64)
- **Lexer Generator:** Flex 2.6.4
- **Parser Generator:** Bison 3.8.2
- **Build System:** VS Code Tasks
- **Platform:** Windows

## License

This project is for educational purposes.