# 14 - Introduction to classes

### 14.1 — Introduction to object-oriented programming

- procedural programming: the focus is on creating “procedures” (which in C++ are called functions) that implement our program logic
- OOP: creating program-defined data types that contain both properties and a set of well-defined behaviors
- inheritance, encapsulation, abstraction, and polymorphism: making your code less redundant, and easier to modify and extend.

### 14.2 — Introduction to classes

- structs: convenient package for storing and moving related data values.
- class invariant is a condition that must be true throughout the lifetime of an object in order for the object to remain in a valid state. Using an object whose class invariant has been violated may result in unexpected or undefined behavior.
- example: stuct{numerator, denominator} should always not hold 0 in the denominator. in struct we have no way to prevent to insert 0!
- From a technical standpoint, structs and classes are almost identical

### 14.3 — Member functions

- In programming, we represent properties with variables (weight, color size...), and actions with functions (open, damage,...).
- In addition to having member variables, class types (which includes structs, classes, and unions) can also have their own functions (member functions)
- member function is declared inside the struct definition
- implicit object: The object that a member function is called on is implicitly passed to the member function
- non-member functions: explicitly pass an object to the function to work with, and members are explicitly accessed through that object.
- member functions: we implicitly pass an object to the function to work with, and members are implicitly accessed through that object.
- you can access member variables and member functions before they are declared. But data members are initialized in order of declaration
- Member functions can be overloaded
- Member functions can be used with both structs and classes. However, structs should avoid defining constructor member functions, as doing so makes them a non-aggregate.
- It is possible to create class types with no data members, If your class type has no data members, prefer using a namespace.

### 14.4 - Const class and Const member functions

- const class object: an object of a class type that is declared with the const qualifier. We can't modify this object
- const member function: don't modify the state of the object
- const class object can only call const member functions. and we should always made const a member function that doesn't modify the state of the instance
- also a const reference to a class object can only call const member functions
- const participate to overloading (we can have a const and a non const member function)

### 14.5 — Public and private members and access specifiers

- access level: determines who can access that member.
  - PUBLIC: default for structs. can be accessed by other members of the class type, and by the public.
  - PRIVATE: default for classes. can be accessed by other members of the class, but can not be accessed by the public.
  - PROTECTED: can be accessed by the member and the derived classes.
- name private data members with "m*" prefix. as we do "s*" for static variables, "g\_" for global variables. this makes clear what we are doing
- access specifier: sets the access level
- best practices:
  - struct: we use them as aggregates so we should keep all member variables as public (as default - do nothing)
  - classes: private (or protected) member variables, public member functions
- access levels works per-class, not per-object. an object of a class che access private members of another object of the same class

### 14.6 — Access functions

- access functions: public member functions whose job is to retrieve (getters) or change (setters) the value of a private member variable
- a setter is a mutator, since it modifies the state of the object.
- Getters should return by value (if copying is inexpensive) or by const lvalue reference (if it's expensive). this because getters provide read-only access to data.

### 14.7 — Member functions returning references to data members

- don't return local variables by reference. it is safe to return by ref parameters passed by ref, or variables with static duration
- returning data members by value is expensive. a safe and inexpensive solution is to return data members by const lvalue reference
- A member function returning a reference should return a reference of the same type as the data member being returned, to avoid unnecessary conversions. we can also use const auto&
- be carefoul when using rvalues, that may remain dangling
- always return by CONST reference the members of an object. luckily if we do things well we don't fall here, since const member functions can’t return non-const references to data members. so if we say that a getter is a const member fun, we get an error if we don't return a const ref

### 14.8 — The benefits of data hiding (encapsulation)

- The interface of a class type (class interface) defines how a user will interact with objects of the class type. the public members of a class type form its interface (since are the only one that can be accessed outside of the class type).
- The implementation of a class type consists of the code that actually makes the class behave as intended
- data hiding: enforce the separation of interface and implementation by hiding the implementation of a program-defined data type from users.
- structs should be used as aggregates, so we don't do "data hiding"
- Data hiding allows us to maintain class invariants. invariants are conditions to be satisfied for an object to be in a valid state. we do it for classes by making members private
- data hiding allows to change implementation w/o breaking existing programs (= w/o changeing the interface)
- Prefer implementing functions as non-members when possible (especially functions that contain application specific data or logic).
- Declare public members first, protected members next, and private members last. This spotlights the public interface.

### 14.9 — Introduction to constructors

- A constructor is a special member function that is automatically called after a non-aggregate class type object is created. It acts on the uninitialized objects.
  - They typically perform initialization of any member variables (via a member initialization list)
  - They may perform other setup functions (via statements in the body of the constructor)
  - must have the same name of the class and no return type
- constructors should be non-const
- constructors do inmplicit conversions as normal functions
- --> constructors = initialize an object at instantiation

### 14.10 — Constructor member initializer lists

- we initialize members using a member initialization list
- the members in a member initializer list are always initialized in the order in which they are defined inside the class (not in the order they are defined in the member initializer list). so member variables in a member initializer list should be listed in order that they are defined in the class.
- initialization of members (order):
  1. member initializer list. : m_x {x}
  2. default member initializer. int m_x {5}
  3. default-initialized. int m_x {}

### 14.11 — Default constructors and default arguments

- A default constructor is a constructor that accepts no argumentsn
- Prefer value initialization (Foo foo{}) over default initialization for all class types (Foo foo).
- since constructors are functions, they can be overloaded.
- implicit default constructor Foo(){}
- explicitly defaulted default constructor: Foo() = default
- create a default constructor when it makes sense to have a default value to all members

### 14.12 — Delegating constructors

- we can't call constructors, but we can use them in the initialization list. So we can create a specialized version of a constructor that delegate the job to the general one (that actually initialize)
- a constructor can only delegate or initialize
- this is kind of the same as using default argument for initializing some of them

### 14.13 — Temporary class objects

- we can construct temporary objects also for classes, which is better when you need to use the object only once.
  print(IntPair { 5, 6 }) or print({ 7, 8 }) which does the implicit conversion

### 14.14 — Introduction to the copy constructor

- A copy constructor is a constructor that is used to initialize an object with an existing object of the same type
- implicit copy constructor: does memberwise initialization
- Copy constructors should have no side effects beyond copying.
- Prefer the implicit copy constructor, unless you have a specific reason to create your own. (is exactly what we want, usually)
- If you write your own copy constructor, the parameter should be a const lvalue reference.
- the copy constructor is the one used to clone object passed by value
- disallows copies: Foo(const Foo& foo) = delete;

### 14.15 — Class initialization and copy elision

- all the ways to initialize are the same also for classes, the best are again the same

  - Foo() (default) : Foo f2 {}
  - Foo(int) (normal) : Foo f5 { 5 }
  - Foo(const Foo&) (copy) : Foo f9 { f5 }

- try to avoid unnecessary copies
- Copy elision is a compiler optimization technique that allows the compiler to remove unnecessary copying of objects

### 14.16 — Converting constructors and the explicit keyword

- A constructor that can be used to perform an implicit conversion is called a converting constructor. By default, all constructors are converting constructors.
- explicit: the constructor can't be used for conversions
- Make any constructor that accepts a single argument explicit by default. If an implicit conversion between types is both semantically equivalent and performant, you can consider making the constructor non-explicit.
- Do not make copy or move constructors explicit, as these do not perform conversions.

### 14.17 — Constexpr aggregates and classes

- we can make member functions constexpr
- we can create constexpr class members
- A literal type is a type that can be used as the type of a constexpr value
  - Scalar types (those holding a single value, such as fundamental types and pointers)
  - Reference types
  - Most aggregates
  - Classes that have a constexpr constructor -> if a class to be evaluated ad compile time, I need constexpr constructors
