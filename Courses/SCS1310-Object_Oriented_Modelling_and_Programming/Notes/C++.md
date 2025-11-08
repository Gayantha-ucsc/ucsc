## Contents

- [Introduction](#introduction)
    - [Hello World (Basic Structure and Standard out)](#hello-world-basic-structure-and-standard-out)
        - [Standard I/O Library](#standard-io-library)
        - [Namespace](#namespace)
        - [`using namespace`](#`using-namespace`)
        - [`cout`](#`cout`)
---
<br>
<br>

# Introduction

## Hello World (Basic Structure and Standard out)

```cpp
#include <iostream>

int main(void){
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

### Standard I/O Library

- The header `iostream` contains the I/O stream based I/O objects.
    - cout - For ourputs like printf
    - cin - For inputs like scanf
    - cerr - For error outputs
    - clog - For logging messages
- In C++ version C++23 or above `printf()` functionality is available in the standard namespace similar to C.

### Namespace

- The **namespace** is a concept that has been introduced in C++ and not in C.
- A **namespace** is a way to group related **functions**, **variables** and **classes** together to avoid name conflicts.
- Because of namespaces two or more variables/ functions/ classes can have same name and not conflit with each other.
- In the library `iostream` which is a C++ standard library, only `std` name space is there.
- The `std` namespace stands for **standard** and all the fuctionality of the standard library like `cout, cin, endl` are inside the `std` namespace.
- When using anyting within a namespace it sould be written before, For example `std::cout` will call the `cout` function in side `std` namespace.
- The `::` operator mean look inside. If `x::y` mean look for `y` inside `x`.

### `using namespace`

- The entire nemaspace can be imported into global scope of the current program with the help of `using` keyword.
- This is similar to the `from 'something' import 'something'` in python.
- This functionality makes it so the namespace specification in each an every place of the code where some function or class or variable is used from that namespace unneccessary.
- So when this is used, the above hello world program can be written as, 
- Only the required objects can be retrieved to the global scope using this method everyting in that nmespace will not be taken into the global scope. For example `using namespace std::cout;`.

```cpp
#include <iostream>
using namespace std;

int main(void){
    cout << "Hello World!" << endl;
    return 0;
}
```

- Using this is not recommended because, It can caues unintended name conflicts in larger codebases and cause unintended behaviours.

### `cout`

- `cout` stands for **character output strea**.
- This represents the standard output stream, usualy the screen/terminal.
- This is an **object** define in the class `std::ostream` which is from the `<ostream>` library which is also included in the `<iostream>`.

### Stream insertion Operator

```cpp
std::cout << "Data" << endl;
```

- In the above code `<<` is the stream insertion operator.
- For now think as it says "send the data("Data") to the output stream."
- This is chanable to add multiple diffrent strings and variables.


# Variables

- Variables are defined and used in the exact same way as C.

```cpp

int integer_variable = 0;
double double_precition_floating_point_variable = 0.0;
char character_variable = 'a';
string string_variable = "Word";
bool boolean_variable = true;
```

# User Input

- To get the user input `cin` objct is used from `<iostream>` module.

```cpp
#include <iostream>

int main(void){

    int number;

    std::cout << "Enter a number, ";
    std::cin >> number;

    return 0;
}
```

- Similar to the code for the print `>>` will redirect the data that was inputed into the variablw.








