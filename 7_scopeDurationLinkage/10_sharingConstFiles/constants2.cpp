#include "constants2.h"

// we define them in the cpp file
namespace constants2
{
    // We use extern to ensure these have external linkage
    extern constexpr double pi{3.14159};
    extern constexpr double avogadro{6.0221413e23};
    extern constexpr double myGravity{9.2}; // m/s^2 -- gravity is light on this planet
}
