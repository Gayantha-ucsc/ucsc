
## Contents
- [Software Development and Programming Paradigms](#software-development-and-programming-paradigms)
    - [Procedual Programming](#procedual-programming)
        - [Problems with Large Procedual Programs](#problems-with-large-procedual-programs)
    - [Object Oriented Programming](#object-oriented-programming)
        - [Benifits in Using Object Oriented Paradigm](#benifits-in-using-object-oriented-paradigm)
    - [Difference Between Procedual and Object Oriented Programming Paradigms](#difference-between-procedual-and-object-oriented-programming-paradigms)
    - [Key Object Oriented Concepts](#key-object-oriented-concepts)
        - [Classes](#classes)
        - [Objects](#objects)
        - [Inheritance](#inheritance)
        - [Abstraction](#abstraction)
        - [Encapsulation](#encapsulation)
        - [Polymorphism](#polymorphism)

---
<br>
<br>

# Software Development and Programming Paradigms

## Procedual Programming

- Programs consist of sequential instructions
- Programs tell the hardware what to do instruction by instruction
- Focuses on functionality and not entieies (data). 
- Common programming languates,
    - C
    - Pascal
    - FORTRAN
    - BASIC
    - COBOL
    - ALGOL

### Problems with Large Procedual Programs

- Complex Structure - Difficult to maintain and visualize
- Global Data can be accessed by any function (static global variables in that module) leading to unintended data access by funtions.
- Adding new data or concepts to the structure is not easy and need a lot of refatroting and modeling to do properly.
- Hard to model real world scenarios.

## Object Oriented Programming

- Created using a combination of data and funcions into one object.
- Promotes reusability with reusable classes.
- More maintainable and scalable due to the structure.
- Common programming languages,
    - C++
    - Java
    - Python
    - PHP
    - Ruby
    - Swift
    - C#

### Benifits in Using Object Oriented Paradigm

- Comparatively easier to understand, modify and debug.
- Improved security using data encapsulation.
- Increase code reuse through inheritence and class-heritence.

## Difference Between Procedual and Object Oriented Programming Paradigms


| **Procedual Programming**                                             | **Object Oriented Programmign**                                                               |
|-                                                                      |-                                                                                              |
| Divides the program into functions based on the functionality         | Divides the program into objects using common properties and data                             |
| There is no access specifiers                                         | Have access specifiers to limit data access by variout parts of the program                   |
| Data is not secure, Fuctions have access to data in the entire scope  | Data is encapsulated and stored safe and only the specifit functions can access them          |
| Based on unreal world modeling                                        | Based on realworld modeling                                                                   |
| Focus on actions and fuctions                                         | Focus on entities and data                                                                    |


## Key Object Oriented Concepts

### Classes

- Basicaly a user defined data type.
- Blueprint/Instructions on how to create a object of that type.
- When a class is defined momory is not allocated to it, when an object is defined using that calls, memory is allocated to that object and not the class.
- Contains,
    - Attributes - Variables that is specific to that class.
    - Methods - Functions that is specific to that class.

```cpp
class Car{
    int wheels;
    double distance;

    public:
        void drive(double distance);
        void stop(void);
}
```

### Objects

- Instance of an class.
- An entity defined using the class
- Has every attribute and method of that class but can vary between diffent objects in the same class.
- When an object is defined memory is allocated to it unlike for classes.

### Inheritance

- Sub classes of the main class are connected through inheritance.
- Helps in code reusability because all attributes and methods of the parent class is inherited to the subclass so objects of the sub-class have the attributes and methods of the parent class too.

### Abstraction

- Hides the imolementaion details and only show the essiontial details to interact with the object.

### Encapsulation

- Wraps data and methods to a single unit preventing external access.
- This is also known as information hiding, preventing external access to internal implementation.

### Polymorphism

- Ability of different classes to respond to same method in different ways.
- An entity(object) or a method can take many forms from one definition.
- An object can be defined in many differnt ways using the same class, similarly an single method can be used in multiple classes if the functionality is the same.
- There are 2 types of polymorphism,
    1. Static (Compile time) - Function overloading/ Operator overloading.
    2. Dynamic (Runtime) - Method overloading, Virtual functions, dynamic dispatch.

<br>
<br>

# Introduction to C++

## Background 

### History

- Developed by some guy (Bjarne Stroustrup) in Bell Labs.
- Inspired by the forst OOP Language, Simula
- Magor Updates C++11, C++14, C++17

### Characteristics

- General pourpose, Compiles, Case-Sensitive
- Supports across different machines but not between different operating systems(Platform dependent).
- Supports dynamic memory allocation and have rich library support.

### Hello World!

```cpp
#include <iostream>

int main(void){
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

# Data Types

- Variables are categorizet into differnt types based on how much their memory is allocated and structured.
- Based on this data types, the compiler allocates memory to the variables.

## Types of data types

1. Primitive data types

- Built in to the compiler/programming language.
- Can be directly used without any additional steps to use them.

> Integer `int`
> Character `char`
> Boolean `bool`
> Floatint Point Number `float`
> Double Precision Floating Point Number `double`
> Void `void`
> Wide Character `wchar_t`

2. Derived data types

- These data typed are extensions of the primitive types.

> Functions - Code block that can be recalled again.
> Arrys - Collection of items stored continiously.
> Pointers - Representation of an address to data.
> References - An alternative name for an existing variable

3. User defined data types

- These data types can vary based on user need and implementation.
- Custom data types are made using predefined methods.

> Structures
> Enums
> Class
> Union
> Typedef

















