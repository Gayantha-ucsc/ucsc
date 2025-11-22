# Data Structures and Program Design in C - Comprehensive Study Notes

## Table of Contents
1. [Introduction to C Programming](#introduction)
2. [Types, Operators, and Expressions](#types-operators)
3. [Control Flow and Iteration](#control-flow)
4. [Pointers, Functions, and Arrays](#pointers-functions-arrays)
5. [Advanced Pointers, Structs, Unions, and Macros](#advanced-concepts)
6. [File Handling](#file-handling)
7. [Analysis of Algorithms](#algorithm-analysis)
8. [Stacks and Queues](#stacks-queues)
9. [Dynamic Memory Allocation and Linked Lists](#dynamic-memory-linked-lists)
10. [Sorting Algorithms](#sorting-algorithms)

---

## 1. Introduction to C Programming {#introduction}

### What is C?
- **Created**: 1972 by Dennis Ritchie
- **Evolved from**: BCPL and B languages
- **Famous for**: Implementation language of UNIX
- **Classification**: Third-generation programming language
- **Compilation**: Compiled language (faster than interpreted languages)

### Why Learn C?
- Widely used in operating systems, real-time systems, embedded systems
- Provides deep understanding of memory management and pointers
- Forms foundation for understanding other programming languages
- Steep learning curve but highly rewarding

### C Program Structure
```c
#include <stdio.h>  // Preprocessor directive

// Comments: single line (//) or multiline (/* */)
int main()          // Main function - entry point
{
    printf("Hello World!");  // Function call
    return 0;               // Return statement
}
```

### Compilation Process
1. **Preprocessing** (`gcc -E`): Processes directives (#include, #define)
2. **Compilation** (`gcc -S`): Converts to assembly code
3. **Assembly** (`gcc -c`): Creates object file
4. **Linking** (`gcc`): Creates executable

---

## 2. Types, Operators, and Expressions {#types-operators}

### Data Types
#### Numerical Types
- **Primitive Types**: `int`, `float`, `double`
- **Modifiers**: `short`, `long`, `unsigned`, `signed`
- **Size Information**: Use `sizeof()` operator
- **Limits**: Defined in `<limits.h>` and `<float.h>`

#### Character Types
- **Size**: 1 byte
- **Encoding**: ASCII (128 characters using 7 bits)
- **Declaration**: `char c = 'A';`

### Operators

#### Arithmetic Operators
- **Binary**: `+`, `-`, `*`, `/`, `%` (modulo)
- **Unary**: `++`, `--`, `+` (unary plus), `-` (unary minus)
- **Integer Division**: Truncates decimal part

#### Relational and Logical Operators
- **Relational**: `>`, `>=`, `<`, `<=`, `==`, `!=`
- **Logical**: `&&` (AND), `||` (OR), `!` (NOT)

#### Bitwise Operators
- **Operations**: `&` (AND), `|` (OR), `^` (XOR), `~` (complement)
- **Shifts**: `<<` (left shift), `>>` (right shift)
- **Applicable to**: `char`, `short`, `int`, `long` only

#### Assignment Operators
- **Basic**: `=`
- **Compound**: `+=`, `-=`, `*=`, `/=`, `%=`

### Constants
```c
// Using const keyword
const int MAX_SIZE = 100;

// Using #define preprocessor
#define PI 3.14159
```

### Enumerations
```c
enum days {SUN, MON, TUE, WED, THU, FRI, SAT};
typedef enum days WEEKDAYS;  // Creating alias
```

### Type Conversions
- **Implicit**: Narrow to wide types (automatic)
- **Explicit**: `(type_name) expression`
- **Considerations**: Precision loss, overflow/underflow risks

---

## 3. Control Flow and Iteration {#control-flow}

### Statements and Blocks
- **Statement**: Single line ending with `;`
- **Block**: Group of statements enclosed in `{}`

### Selection Constructs

#### if-else Statement
```c
if (condition) {
    // code when true
} else {
    // code when false
}
```

#### switch Statement
```c
switch (expression) {
    case constant1:
        // statements
        break;
    case constant2:
        // statements
        break;
    default:
        // default statements
}
```

#### Ternary Operator
```c
result = (condition) ? value_if_true : value_if_false;
```

### Iteration Constructs

#### while Loop (Entry-controlled)
```c
while (condition) {
    // loop body
}
```

#### for Loop (Entry-controlled)
```c
for (initialization; condition; update) {
    // loop body
}
```

#### do-while Loop (Exit-controlled)
```c
do {
    // loop body
} while (condition);
```

### Jump Statements
- **break**: Terminates immediately enclosing loop/switch
- **continue**: Skips to next iteration
- **goto**: Explicit jump to label
- **return**: Returns from function

---

## 4. Pointers, Functions, and Arrays {#pointers-functions-arrays}

### Pointers

#### Concept
- **Definition**: Variable holding memory address of another variable
- **Declaration**: `data_type *ptr;`
- **Address Operator**: `&variable`
- **Dereference Operator**: `*ptr`

#### Memory Types
- **Logical Memory**: Virtual addresses seen by program
- **Physical Memory**: Actual RAM
- **Pointer Size**: 4 bytes (32-bit), 8 bytes (64-bit)

#### Basic Operations
```c
int x = 10;
int *ptr = &x;    // Assignment
int value = *ptr; // Dereferencing
*ptr = 20;        // Modifying value through pointer
```

### Functions

#### Structure
```c
return_type function_name(parameter_list) {
    // function body
    return value;  // if return_type is not void
}
```

#### Parameter Passing
- **Pass by Value**: Copies values (safer, default in C)
- **Pass by Reference**: Uses pointers to pass addresses

### Arrays

#### Declaration and Initialization
```c
int arr[10];                    // Declaration
int arr[] = {1, 2, 3, 4, 5};   // Initialization
int arr[5] = {1, 2, 3, 4, 5};  // Both
```

#### Properties
- **Indexing**: Zero-based
- **Size**: Fixed at compile time
- **Memory**: Contiguous allocation
- **Access**: Random access via index or pointer arithmetic

#### Multidimensional Arrays
```c
int matrix[3][4];  // 3 rows, 4 columns
// Storage: Row-major order (C default) or Column-major order
```

### scanf() Function
```c
int scanf(const char *format, variable_addresses);
// Returns: >0 (successful conversions), 0 (no assignments), <0 (error/EOF)
```

---

## 5. Advanced Pointers, Structs, Unions, and Macros {#advanced-concepts}

### Types of Pointers

#### Void Pointers
```c
void *ptr;  // Can hold address of any type
// Cannot be dereferenced directly
// Requires typecasting: (data_type*)ptr
```

#### Function Pointers
```c
return_type (*ptr_name)(param_types);
// Enable generic functions and callbacks
```

#### Constant Pointers
```c
const int *ptr;        // Pointer to constant (data read-only)
int *const ptr;        // Constant pointer (address fixed)
const int *const ptr;  // Both constant
```

#### Null and Wild Pointers
- **Null Pointer**: Points to nothing (`NULL` or `0`)
- **Wild Pointer**: Uninitialized pointer (dangerous)

### Strings
- **Definition**: Array of characters terminated by `'\0'`
- **Declaration**: `char str[size];` or `char str[] = "text";`
- **Functions**: Available in `<string.h>`

### Structures
```c
struct student {
    int id;
    char name[50];
    float gpa;
};

// Usage
struct student s1;
s1.id = 123;           // Direct access
struct student *ptr = &s1;
ptr->id = 123;         // Pointer access
```

### Unions
```c
union data {
    int i;
    float f;
    char c;
};
// All members share same memory location
// Size = largest member size
```

### Macros
```c
#define PI 3.14159              // Object-like macro
#define MAX(a,b) ((a)>(b)?(a):(b))  // Function-like macro
```

### Storage Classes
- **auto**: Stack storage (default for local variables)
- **static**: Data segment, persists entire program
- **extern**: External linkage across files
- **register**: CPU register (compiler suggestion)

---

## 6. File Handling {#file-handling}

### Why File Handling?
- **Persistence**: Data survives program termination
- **Applications**: Text editors, databases, configuration files

### File Operations

#### Opening Files
```c
FILE *fp = fopen("filename", "mode");
if (fp == NULL) {
    // Handle error
}
```

#### File Modes
- **"r"**: Read only
- **"w"**: Write (creates/truncates)
- **"a"**: Append
- **"r+"**: Read and write
- **"w+"**: Write and read (truncates)
- **"a+"**: Append and read

#### File I/O Functions
```c
// Writing
fprintf(fp, "format", variables);
fputs("string", fp);
fputc(character, fp);

// Reading
fscanf(fp, "format", addresses);
fgets(buffer, size, fp);
char ch = fgetc(fp);

// Closing
fclose(fp);
```

#### Error Checking
```c
if (feof(fp))    // Check end of file
if (ferror(fp))  // Check for errors
```

### Common Mistakes
- Forgetting to close files
- Not checking if file opened successfully
- Wrong mode usage
- Reading past EOF

---

## 7. Analysis of Algorithms {#algorithm-analysis}

### Why Study Algorithm Analysis?
- **Efficiency**: Create efficient programs
- **Performance**: Understand time and space complexity
- **Comparison**: Compare different algorithms objectively

### Measurement Units
- **Time Complexity**: Number of operations vs input size
- **Tools**: `clock()` in C, system timing functions

### Order of Growth
- **Definition**: How computation time increases with input size
- **Focus**: Rough estimates, not exact values
- **Example**: `f(n) = n² + 100n + 10⁴` → Focus on `n²` term

### Big-O Notation
**Definition**: `f(n) is O(g(n))` if there exist positive constants `c` and `N` such that `f(n) ≤ c·g(n)` for all `n ≥ N`

#### Properties
- **Upper Bound**: Describes worst-case scenario
- **Transitive**: If `f(n) is O(g(n))` and `g(n) is O(h(n))`, then `f(n) is O(h(n))`
- **Addition**: If `f(n) is O(h(n))` and `g(n) is O(h(n))`, then `f(n) + g(n) is O(h(n))`

#### Common Complexities
- **O(1)**: Constant time
- **O(log n)**: Logarithmic time
- **O(n)**: Linear time
- **O(n log n)**: Linearithmic time
- **O(n²)**: Quadratic time
- **O(2ⁿ)**: Exponential time

### Other Notations
- **Big-Ω (Omega)**: Lower bound (`f(n) ≥ c·g(n)`)
- **Big-Θ (Theta)**: Tight bound (`c₁·g(n) ≤ f(n) ≤ c₂·g(n)`)

### Algorithm Analysis Examples
```c
// O(1) - Constant
a = 5; b = 7; print(a*b);

// O(n) - Linear
for(i = 0; i < n; i++) { /* operations */ }

// O(n²) - Quadratic
for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) { /* operations */ }

// O(log n) - Logarithmic
for(i = 1; i < n; i = i*2) { /* operations */ }
```

---

## 8. Stacks and Queues {#stacks-queues}

### Data Structure Classification
- **Linear**: Elements arranged sequentially (Arrays, Linked Lists, Stacks, Queues)
- **Non-linear**: Non-sequential arrangement (Trees, Graphs)

### Abstract Data Types (ADT)
- **Definition**: Behavior defined by values and operations
- **Implementation**: Provided by data structures

### Stacks

#### Concept
- **Policy**: Last In, First Out (LIFO)
- **Access Point**: Single entry/exit point (top)
- **Applications**: Function calls, backtracking, expression evaluation

#### Operations
```c
push(element)  // Insert at top
pop()         // Remove and return top element
peek()        // Return top element without removing
```

#### Implementation Approaches
- Array-based implementation
- Linked list-based implementation

### Queues

#### Concept
- **Policy**: First In, First Out (FIFO)
- **Access Points**: Two pointers (front and rear)
- **Applications**: Process scheduling, keyboard buffers

#### Operations
```c
enqueue(element)  // Insert at rear
dequeue()        // Remove and return front element
```

### Memory Layout
#### Program Memory Sections
1. **Text Segment**: Executable instructions
2. **Data Segment**: 
   - Initialized global/static variables
   - Uninitialized (BSS) global/static variables
3. **Heap**: Dynamic memory allocation
4. **Stack**: Function call management

### Recursion
- **Definition**: Function calling itself
- **Requirements**: Base case + recursive step
- **Implementation**: Uses stack memory
- **Examples**: Factorial, Fibonacci

---

## 9. Dynamic Memory Allocation and Linked Lists {#dynamic-memory-linked-lists}

### Dynamic Memory Allocation

#### Concept
- **Purpose**: Runtime memory assignment
- **Benefits**: Flexibility, efficiency
- **Location**: Heap memory

#### Functions (from `<stdlib.h>`)
```c
// Memory allocation
void *malloc(size_t size);        // Allocate uninitialized memory
void *calloc(size_t n, size_t size); // Allocate zero-initialized memory
void *realloc(void *ptr, size_t size); // Resize memory block
void free(void *ptr);             // Deallocate memory
```

#### size_t Data Type
- **Purpose**: Represent sizes and counts
- **Portability**: Adapts to system architecture
- **Range**: Always non-negative

### Memory Management Issues

#### Memory Leaks
- **Cause**: Allocated memory not freed
- **Detection**: Tools like Valgrind
- **Prevention**: Always pair malloc/calloc with free

#### Pointer Problems
- **Aliasing**: Multiple pointers to same memory
- **Dangling Pointers**: Pointers to freed memory
- **Wild Pointers**: Uninitialized pointers

### Storage Classes Summary
- **auto**: Stack storage (local scope)
- **static**: Data segment (program lifetime)
- **extern**: External linkage (multiple files)
- **register**: CPU register hint (local, fast access)

### Linked Lists

#### Node Structure
```c
struct Node {
    int data;              // Data component
    struct Node *next;     // Link component
};
```

#### Singly Linked List Operations
```c
// Insertion
AddToHead(value)    // Insert at beginning
AddToTail(value)    // Insert at end
Insert(value, pos)  // Insert at position

// Deletion
DeleteFromHead()    // Remove from beginning
DeleteFromTail()    // Remove from end
Delete(value)       // Remove specific value

// Utility
Search(value)       // Find element
PrintList()         // Display all elements
```

#### Implementation Considerations
- **Head/Tail Pointers**: Track first and last nodes
- **Special Cases**: Empty list, single element
- **Memory Management**: Proper allocation and deallocation

#### Variants
- **Doubly Linked List**: Nodes have `next` and `prev` pointers
- **Circular Linked List**: Last node points to first node

#### Stack/Queue Implementation
```c
// Stack using Linked List
push(x) → AddToHead(x)
pop() → DeleteFromHead()

// Queue using Linked List
enqueue(x) → AddToTail(x)
dequeue() → DeleteFromHead()
```

---

## 10. Sorting Algorithms {#sorting-algorithms}

### The Sorting Problem
- **Definition**: Arrange elements in predefined order
- **Importance**: Fundamental algorithmic problem
- **Applications**: Data organization, search optimization

### Basic Sorting Algorithms

#### Insertion Sort
```c
// Algorithm: Sort one element at a time
for(i = 1; i < n; i++) {
    temp = array[i];
    for(j = i; j > 0 && temp < array[j-1]; j--) {
        array[j] = array[j-1];
    }
    array[j] = temp;
}
```
- **Best Case**: O(n) - already sorted
- **Worst Case**: O(n²) - reverse sorted
- **Average Case**: O(n²)
- **Properties**: Stable, adaptive, in-place

#### Selection Sort
```c
// Algorithm: Find minimum and place in correct position
for(i = 0; i < n-1; i++) {
    min_index = i;
    for(j = i+1; j < n; j++) {
        if(array[j] < array[min_index])
            min_index = j;
    }
    swap(array, i, min_index);
}
```
- **All Cases**: O(n²)
- **Properties**: Unstable, not adaptive, in-place

#### Bubble Sort
```c
// Algorithm: Bubble smallest element to correct position
for(i = 0; i < n-1; i++) {
    for(j = n-1; j > i; j--) {
        if(array[j] < array[j-1])
            swap(array, j, j-1);
    }
}
```
- **Best Case**: O(n) - already sorted
- **Worst Case**: O(n²) - reverse sorted
- **Properties**: Stable, adaptive, in-place

### Advanced Sorting Algorithms

#### Merge Sort
```c
// Divide and conquer approach
mergesort(array, first, last) {
    if(first < last) {
        mid = (first + last) / 2;
        mergesort(array, first, mid);
        mergesort(array, mid+1, last);
        merge(array, first, mid, last);
    }
}
```
- **All Cases**: O(n log n)
- **Properties**: Stable, not adaptive, out-of-place
- **Space Complexity**: O(n)

#### Quick Sort
```c
// Pivot-based partitioning
quicksort(array, first, last) {
    if(first < last) {
        pivot = partition(array, first, last);
        quicksort(array, first, pivot-1);
        quicksort(array, pivot+1, last);
    }
}
```
- **Best/Average Case**: O(n log n)
- **Worst Case**: O(n²) - already sorted with poor pivot choice
- **Properties**: Unstable, not adaptive, in-place

### Algorithm Classification

#### By Complexity
- **Elementary**: O(n²) - Insertion, Selection, Bubble
- **Advanced**: O(n log n) - Merge, Quick

#### By Memory Usage
- **In-place**: Sorts within original array
- **Out-of-place**: Requires additional memory

#### By Stability
- **Stable**: Maintains relative order of equal elements
- **Unstable**: May change relative order of equal elements

#### By Adaptability
- **Adaptive**: Performance improves on partially sorted data
- **Non-adaptive**: Performance independent of input order

### Additional Notations
- **Big-Ω (Omega)**: Lower bound analysis
- **Big-Θ (Theta)**: Tight bound (both upper and lower)

---

## Key Programming Practices

### Code Organization
- Use header files for declarations
- Implement conditional compilation (`#ifndef`, `#define`, `#endif`)
- Compile multiple files: `gcc file1.c file2.c`

### Memory Safety
- Always check malloc/calloc return values
- Pair every malloc/calloc with free
- Initialize pointers to NULL
- Avoid accessing freed memory

### Error Handling
- Check file operations return values
- Validate function parameters
- Handle edge cases (empty lists, null pointers)

### Performance Considerations
- Choose appropriate data structures
- Consider algorithm complexity
- Use profiling tools for optimization
- Balance memory usage vs. speed

---

## Summary

This comprehensive overview covers the fundamental concepts in C programming and data structures:

1. **Language Fundamentals**: Syntax, data types, operators, control structures
2. **Memory Management**: Pointers, dynamic allocation, storage classes
3. **Data Structures**: Arrays, linked lists, stacks, queues
4. **Algorithm Analysis**: Complexity analysis using Big-O notation
5. **Sorting Algorithms**: From basic O(n²) to advanced O(n log n) algorithms
6. **File Operations**: Reading from and writing to files
7. **Advanced Concepts**: Structures, unions, macros, function pointers

Understanding these concepts provides a solid foundation for systems programming, algorithm design, and software development in C and related languages.