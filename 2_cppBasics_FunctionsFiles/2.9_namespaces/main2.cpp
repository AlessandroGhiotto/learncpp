#include <iostream> // imports the declaration of std::cout into the global scope

// this is a very bad practice!!
using namespace std; // makes std::cout accessible as "cout"

int cout() // defines our own "cout" function in the global namespace
{
    return 5;
}

int main()
{
    // Compile error!  Which cout do we want here?  The one in the std namespace or the one we defined above?
    cout << "Hello, world!";
    return 0;
}
