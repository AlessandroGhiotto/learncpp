#include <string>

const std::string& getConstRef(); // some function that returns a const reference

int main()
{
    auto ref1 { getConstRef() }; // std::string (reference and top-level const dropped)
    const auto ref2 { getConstRef() }; // const std::string (reference dropped, const dropped, const reapplied)

    auto& ref3 { getConstRef() }; // const std::string& (reference dropped and reapplied, low-level const not dropped)
    const auto& ref4 { getConstRef() }; // const std::string& (reference dropped and reapplied, low-level const not dropped)

    return 0;
}

// std::string* getPtr(); // some function that returns a pointer
// auto ptr1 { getPtr() }; // std::string*
// auto* ptr2 { getPtr() }; // std::string*
