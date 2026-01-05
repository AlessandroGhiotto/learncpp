# 24 - Inheritance

### 24.1 — Introduction to inheritance

- Inheritance: is-a relationship. hierarchies

### 24.2 — Basic inheritance in C++

- class being inherited from is called the parent class, base class, or superclass, and the class doing the inheriting is called the child class, derived class, or subclass
- Inheriting from a base class means we don’t have to redefine the information from the base class in our derived classes

### 24.3 — Order of construction of derived classes

- let's say that Derived inherit from Base
- we can consider Derived as a two part class: one part Derived, and one part Base
- when we instantiate an instance of Derived, first the Base portion of Derived is constructed (using the Base default constructor). Once the Base portion is finished, the Derived portion is constructed (using the Derived default constructor)
- C++ always constructs the “first” or “most base” class first

### 24.4 — Constructors and initialization of derived classes

- inherited variables can still have their values changed in the body of the constructor using an assignment
- When a derived class is destroyed, each destructor is called in the reverse order of construction

### 24.5 — Inheritance and access specifiers

- access levels
  - public: can be accessed by anybody
  - protected: can be accessed by Base members, friends, and derived classes
  - private: can only be accessed by Base members and friends (but not derived classes)
- Favor private members over protected members. isolation is good for maintainability
- kinds of inheritance: public, protected, and private. the access specifier for an inherited member may be changed (in the derived class only) depending on the type of inheritance used.
- PUBLIC (most used): public -> public, protected -> protected, private -> inaccessible
- PRIVATE: public, protected -> private, private -> inaccessible
- PROTECTED: public, protected -> protected, private -> inaccessible
- this effect only the members you inherit, not your own!

### 24.6 — Adding new functionality to a derived class

- deriving your own class and add functionality is the way to update some piece of code.
- in some cases it's also the only thing allowed, like the code of the standard library comes precompiled. we can't change it, but we can inherit from it.

### 24.7 — Calling inherited functions and overriding behavior

- when calling a function we first look at the derived class. Base::funz() is used if Derived::funz() doesn’t exist
- we can make functions work differently with our derived classes by redefining them in the derived class!
- instead of just replacing, we can add functionality to a given inherited function, we can do it by doing a call to Base::funz() from inside Derived::funz()
- we need to be carefoul for overload resolution. if we have Base::print(int), Base::print(double), Derived::print(double). if I run Derived::print(5) this is going to call the double version! We need to put 'using Base::print;' inside Derived, for telling the compiler that all Base functions named print should be visible in Derived.

### 24.8 — Hiding inherited functionality

- with the using declaration we can make a protected member a puboic one, in the inherited class
- hiding: in the same way we make a public member a private one.
- we can also mark them as deleted (not accessible)

### 24.9 — Multiple inheritance

- Multiple inheritance enables a derived class to inherit members from more than one parent.
- A mixin is a small class that can be inherited from in order to add properties to a class. is intended to be mixed into other classes, not instantiated on its own.
- Avoid multiple inheritance unless alternatives lead to more complexity.
