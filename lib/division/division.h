#pragma once
#include <exception>

class DivisionByZero : public std::exception
{
   public:
    const char *what() { return "Division by zero is illegal"; }
};

struct Fraction
{
    int numerator;    // the number to be divided
    int denominator;  // the number to divide by
};

struct DivisionResult
{
    long division;
    long remainder;

    friend bool operator==(const DivisionResult &lhs, const DivisionResult &rhs)
    {
        return lhs.division == rhs.division ? lhs.remainder < rhs.remainder
                                            : lhs.division < rhs.division;
    }
};

class Division
{
   public:
    explicit Division(Fraction fraction)
        : fraction{fraction}, result{.division = 0, .remainder = 0}
    {
    }

    ~Division() = default;

    DivisionResult divide() const;

   private:
    Fraction fraction;
    DivisionResult result;
};
