#include <cmath>
#include <iostream>
#include <string>
#include <vector>

auto say_hello() -> void { std::cout << "Hello World" << '\n'; }
constexpr auto MAX_OPERATIONS = 6;

auto get_name() -> std::string
{
        std::string name {};
        std::cout << "Enter your full name: ";
        std::getline(std::cin, name);
        return name;
}
/*
    Add, Sub, Mul, Div
    New Operations: Power and Remainder
*/

auto get_two_ints(int& x, int& y)
{
        std::cout << "Enter two integers: ";
        std::cin >> x;
        std::cin >> y;
}
auto compute_addition(int x, int y) -> int { return x + y; }
auto compute_subtraction(int x, int y) -> int { return x - y; }
// Multiplication, Division, Power, and Remainder
auto           add(float x, float y) { return x + y; }
auto           sub(float x, float y) { return x - y; }
auto           mul(float x, float y) { return x * y; }
auto           div(float x, float y) { return x / y; }

using BinaryFn = int (*)(int, int);
using BinaryOp = float (*)(float, float);

auto main() -> int
{
        int x {}, y {};
        get_two_ints(x, y);

        std::vector<BinaryFn> functions {};
        functions.push_back(compute_subtraction);
        functions.push_back(compute_addition);

        int op {};
        std::cout << "Select Operation (1: add, 2: sub): ";
        std::cin >> op;
        if (op == 1)
        {
                const auto operation = functions[0];
                const auto res = operation(x, y);
                std::cout << res << '\n';
        }
        std::vector<BinaryOp> ops {add, sub, mul, div};

        std::cout << "Calc v0.1" << '\n';
        do {
                std::cout << "Enter 0 to exit." << '\n';
                std::cout << "Select operation (1: Add, 2: Sub, 3: Mul, 4: Div), (5-6) Slot Available for `Pow` and `Rem`: ";

                int uop {};
                std::cin >> uop;
                if (uop < 1 || uop > 4)
                {
                        if (uop == 0) { break; }

                        if (uop > 4 && uop < MAX_OPERATIONS)
                        {
                                // user probably wants to add new functions
                                if (ops.size() < (MAX_OPERATIONS + 1))
                                {
                                        std::cout << "(p)Pow, (r)Rem: ";
                                        char selection {};
                                        std::cin >> selection;
                                        if (selection == 'p') { ops.push_back(std::pow); }
                                        else if (selection == 'r') { ops.push_back(std::fmod); }
                                }
                        }
                        else
                        {
                                std::cout << "Invalid operation selected. Please try again!";
                                continue;
                        }
                }

                const auto op = ops[uop - 1];

                float      x {}, y {};
                std::cout << "Enter two numbers (a b): ";
                std::cin >> x;
                std::cin >> y;

                const auto res = op(x, y);
                std::cout << "Result: " << res << '\n';
        } while (true);