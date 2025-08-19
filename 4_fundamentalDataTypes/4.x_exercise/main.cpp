#include <iostream>

// EXERCISE 1
/*The user is asked to enter 2 floating point numbers (use doubles).
The user is then asked to enter one of the following mathematical symbols: +, -, *, or /.
The program computes the answer on the two numbers the user entered and prints the results.
If the user enters an invalid symbol, the program should print nothing.*/
double enterDouble()
{
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;
    return x;
}

char enterChar()
{
    std::cout << "Enter +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

double computeResult(double n1, double n2, char op)
{
    if (op == '+')
        return n1 * n2;
    else if (op == '-')
        return n1 - n2;
    else if (op == '*')
        return n1 * n2;
    else if (op == '/')
        return n1 / n2;
    else
        std::cout << op << " is not a valid operator.";
    return 0;
}

int main0()
{
    double n1{enterDouble()};
    double n2{enterDouble()};
    char op{enterChar()};

    std::cout << n1 << " " << op << " " << n2 << " is " << computeResult(n1, n2, op) << "\n";

    return 0;
}

// EXERCISE 2
/*Write a short program to simulate a ball being dropped off of a tower.
To start, the user should be asked for the height of the tower in meters.
Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start).
Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds.
The ball should not go underneath the ground (height 0).*/
double enterTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double h{};
    std::cin >> h;
    return h;
}

void fallenDistance(double max_h, int dt)
{
    double g{9.8};
    double distance_fallen{g * (dt * dt) / 2.0};
    double height{max_h - distance_fallen};
    if (height <= 0)
        std::cout << "At " << dt << " seconds, the ball is on the ground\n";
    else
        std::cout << "At " << dt << " seconds, the ball is at height: " << height << " meters\n";
}

int main()
{
    double max_h{enterTowerHeight()};

    fallenDistance(max_h, 0);
    fallenDistance(max_h, 1);
    fallenDistance(max_h, 2);
    fallenDistance(max_h, 3);
    fallenDistance(max_h, 4);
    fallenDistance(max_h, 5);

    return 0;
}
