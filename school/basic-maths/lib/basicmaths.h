#ifndef BASIC_MATHS_H
#define BASIC_MATHS_H

#include <stdbool.h>
#include <limits.h>

#define INFINITY INT_MAX
#define NEG_INFINITY INT_MIN

int multiply(int a, int b);

int divide(int a, int b);

int modulus(int a, int b);

bool prime(int n);

int power(int a, int b);

int gcd(int a, int b);

int lcm(int a, int b);

int sqroot(int n);

#endif // BASIC_MATHS_H
