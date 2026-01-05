# 15 - More on classes

### 15.1 — The hidden “this” pointer and member function chaining

- Inside every member function, the keyword this is a const pointer that holds the address of the current implicit object.
- return \*this by reference for chainging function calls together. we modify it, but we also return it for chaining, as we do for overloading the operator<<

### 15.2 — Classes and header files

- put class definitions in a header file with the same name as the class. Trivial member functions (such as access functions, constructors with empty bodies, etc…) can be defined inside the class definition.
- define non-trivial member functions in a source file with the same name as the class.
- Types are exempt from the part of the one-definition rule (ODR) that says you can only have one definition per program (we can put classes in .h)
- Functions defined inside the class definition are implicitly inline, which allows them to be #included into multiple code files without violating the ODR.
- Functions defined outside the class definition are not implicitly inline. They can be made inline by using the inline keyword.

### 15.3 — Nested types (member types)

- nested types (or member types): define the type inside the class.
- Define any nested types at the top of your class type. We need to define them before we use them
- since the class itself act as a scope region, we use unscoped enumerator.
- we can also use type aliases
- nested classes (members of the outer class) can access any private members of the outer class that are in scope.

### 15.4 — Introduction to destructors

- destructor: called automatically when an object of a non-aggregate class type is destroyed. Destructors are designed to allow a class to do any necessary clean up before an object of the class is destroyed.
- there is a default destructor, doing nothing, if no cleaup is needed
- be awaew of exceptions and std::exit(), the stack may not be unrolled and the destructors not called.

### 15.5 — Class templates with member functions

- private members -> not an aggregate -> we can't use aggregate initialization. so we actually need to put the template parameters also in the constructor
- When we define a member function outside the class definition, we need to resupply a template parameter declaration
- inside the class definition we have used 'Pair' instead of 'Pair<T>'. We can because: in the scope of the Pair<T> class template, any use of Pair is shorthand for Pair<T>!
- Any member function templates defined outside the class definition should be defined just below the class definition (in the same file).

### 15.6 — Static member variables

- When we instantiate a class object, each object gets its own copy of all normal member variables
- static member variables are shared by all objects of the class. they are global variables in the scope of the class.
- Access static members using the class name and the scope resolution operator (::).
- Make your static members inline or constexpr so they can be initialized inside the class definition.

### 15.7 — Static member functions

- static member functions are not associated with a particular object, they can be called directly by using the class name and the scope resolution operator
- Static member functions have no this pointer
- static member functions can directly access other static members (variables or functions), but not non-static members

### 15.8 — Friend non-member functions

- a friend is a class or function (member or non-member) that has been granted full access to the private and protected members of another class
- Friendship is always granted by the class whose members will be accessed (not by the class or function desiring access).
- Friend functions defined inside a class are non-member functions
- A function can be a friend of more than one class at the same time
- A friend function should prefer to use the class interface over direct access whenever possible.
- Prefer to implement a function as a non-friend when possible and reasonable.

### 15.9 — Friend classes and friend member functions

- A friend class is a class that can access the private and protected members of another class.
- friendship is not reciprocal, not transitive and not inherited.
- Instead of making an entire class a friend, you can make a single member function a friend

### 15.10 — Ref qualifiers

- ref-qualifier that allows us to overload a member function based on whether it is being called on an lvalue or an rvalue implicit object
