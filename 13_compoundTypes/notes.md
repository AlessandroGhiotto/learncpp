# 13. Compound Types

### 13.1 — Introduction to program-defined (user-defined) types

- A program-defined type must have a name and a definition before it can be used. The other compound types require neither.
- Don’t forget to end your type definitions with a semicolon.
- Name your program-defined types starting with a capital letter and do not use a suffix.
- A program-defined type used in multiple code files should be defined in a header file with the same name as the program-defined type and then #included into each code file as needed. (because we need to see the full definition of the type to use it)

### 13.2 — Unscoped enumerations

- An enumeration (enumerated type or enum) is a compound data type whose values are restricted to a set of named symbolic constants (called enumerators).
- Name your enumerated types starting with a capital letter. Name your enumerators starting with a lower case letter.
- when you have a smallish set of related constants, and objects only need to hold one of those values at a time.
- Enumerationsare defined in the global scope -> Prefer putting your enumerations inside a named scope region (such as a namespace or class) so the enumerators don’t pollute the global namespace.

### 13.3 — Unscoped enumerator integral conversions

- By default, the first enumerator is given the integral value 0, and each subsequent enumerator has a value one greater than the previous enumerator
- you can explicitly give values to enumerators
- empty initialization initialize to the enumerator associated to 0. Make the enumerator representing 0 the one that is the best default meaning for your enumeration
- Unscoped enumerations will implicitly convert to integral values
- Since enumerators are constexpr, their values must also be constexpr

### 13.4 — Converting an enumeration to and from a string

- We need to use switch statements or arrays of strings to convert enumerators to strings

### 13.5 — Introduction to overloading the I/O operators

Basic operator overloading:

- Define a function using the name of the operator as the function’s name.
- Add a parameter of the appropriate type for each operand (in left-to-right order). One of these parameters must be a user-defined type.
- Set the return type.
- Use a return statement to return the result of the operation

`std::ostream& operator<<(std::ostream& out, Color color)`

### 13.6 — Scoped enumerations (enum classes)

- unscoped enumerations aren't safe
- scoped enumerations (enum class):

  - They won’t implicitly convert to integers,
  - the enumerators are placed into the scope region of the enumeration (not into the scope region where the enumeration is defined).

- use unscoped enumerations only if you need to abuse implicit conversion to integers and if you don't need the extra namespacing.
- using enum statement imports all of the enumerators from an enum into the current scope

### 13.7 — Introduction to structs, members, and member selection

- A struct is a class type (as are classes and unions). As such, anything that applies to class types applies to structs.
- a member is a variable, function, or type that belongs to a struct (or class). All members must be declared within the struct (or class) definition.
- we only need to create one new name per struct variable

### 13.8 — Struct aggregate initialization

- data members are not initialized by default
- an aggregate is any type that can contain multiple data members
- Aggregates use a form of initialization called aggregate initialization, which allows us to directly initialize the members of aggregates.
  To do this, we provide an initializer list as an initializer, which is just a braced list of comma-separated values
- we can make struct const
- Designated initializers allow you to explicitly define which initialization values map to which members
- when adding a member to a struct is safer to atìdd it to the bottom, or we need to update all the initialization lists

### 13.9 — Default member initialization

- Using default member initializers, structs and classes can self-initialize even when no explicit initializers are provided!
- Provide a default value for all members. This ensures that your members will be initialized even if the variable definition doesn’t include an initializer list.
- For aggregates, prefer value initialization (with an empty braces initializer) to default initialization (with no braces).

### 13.10 — Passing and returning structs

- Structs are generally passed by reference (typically by const reference) to avoid making copies
- for returning structs, we just need to return by value.

### 13.11 — Struct miscellany

- structs (and classes) can have members that are other program-defined types
- types can also be nested inside other types, if they exists only inside that struct
- Owners manage their own data, and control when it is destroyed. Viewers view someone else’s data, and do not control when it is altered or destroyed. Structs that are owners should have data members that are owners. So we have:
  - The data members will be valid for as long as the struct (or class) is.
  - The value of those data members won’t change unexpectedly

==> we want our structs (and classes) to be owners. Ensure each data member has an owning type (e.g. not a viewer, pointer, or reference).

a struct will be at least as large as the size of all the variables it contains. But it could be larger! For performance reasons, the compiler will sometimes add gaps into structures (this is called padding).

### 13.12 — Member selection with pointers and references

- the member selection operator (.) can be used to access references (as for normal structs)
- for pointers, we need to first dereference the pointer, then use the member selection operator
- member selection from pointer operator (->) (arrow operator) that can be used to select members from a pointer to an object
- if the memeber is a class type, we can chain the member selection operators (also mix . and ->)

### 13.13 — Class templates

- a class template is a template definition for instantiating class types.
- to combo a class that we generate with a template with a function taking as input that class, we need to make the function a template too
  template `<typename T> void print(Pair<T> p)`
- std::pair that holds two values of (possibly) different types, accessible via the members first and second.
- as for function templates, class templates goes in header files.

### 13.14 — Class template argument deduction (CTAD) and deduction guides

- CTAD is only performed if no template argument list is present (std::pair p(42, 3.14);)
- as for standard type deduction, we can use literal suffixes to change the deduced type (1 vs 1.0f vs 1.0 vs 1u...)
- CTAD doesn’t know how to deduce the template arguments for aggregate class templates. We can provide the compiler with a deduction guide
  `template <typename T, typename U> Pair(T, U) -> Pair<T, U>;`
  if the compiler sees a declaration of a Pair with two arguments (of types T and U), it should deduce the type to be a `Pair<T, U>`.

- CTAD doen't work when initializing the member of a class type using non-static member initialization
- CTAD doesn’t work with function parameters

### 13.15 — Alias templates

- Creating a type alias for a class template where all template arguments are explicitly specified works just like a normal type alias:
- we might want a type alias for a template class where not all of the template arguments are defined as part of the alias (and will instead be provided by the user of the type alias). To do this, we can define an alias template, which is a template that can be used to instantiate type aliases.
