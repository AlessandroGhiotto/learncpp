#include <chrono>
#include <iostream>
#include <random>

class Something
{
  private:
    static inline int s_value { 1 };

  public:
    static int getValue() { return s_value; } // static member function
};

class IDGenerator
{
  private:
    static inline int s_nextID { 1 };

  public:
    static int getNextID(); // Here's the declaration for a static function
};

// Here's the definition of the static function outside of the class.  Note we don't use the static keyword here.
int IDGenerator::getNextID() { return s_nextID++; }

int main0()
{
    std::cout << Something::getValue() << '\n';

    for (int count { 0 }; count < 5; ++count)
        std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

    return 0;
}

// -----------------------------------------------------
/// EXERCISE

class Random
{
  private:
    static std::mt19937 generate()
    {
        std::random_device rd {};

        // Create seed_seq with high-res clock and 7 random numbers from std::random_device
        std::seed_seq ss {
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
            rd(), rd(), rd(), rd(), rd(), rd(), rd()
        };

        return std::mt19937 { ss };
    }

    static inline std::mt19937 mt { generate() }; // generates a seeded std::mt19937 and copies it into our global object

  public:
    // Generate a random int between [min, max] (inclusive)
    static int get(int min, int max)
    {
        return std::uniform_int_distribution { min, max }(mt);
    }
};

int main()
{
    // Print a bunch of random numbers
    for (int count { 1 }; count <= 10; ++count)
        std::cout << Random::get(1, 6) << '\t';

    std::cout << '\n';

    return 0;
}
