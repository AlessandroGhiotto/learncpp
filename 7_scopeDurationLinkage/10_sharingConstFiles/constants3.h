#ifndef CONSTANTS3_H
#define CONSTANTS3_H

// define your own namespace to hold constants
// INLINE allows us to de-duplicate multiple definitions of the same variable
// so we can just include the header in multiple files
namespace constants3
{
    inline constexpr double pi{3.14159}; // note: now inline constexpr
    inline constexpr double avogadro{6.0221413e23};
    inline constexpr double myGravity{9.2}; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif
