#include <stdio.h>  // Including the standard input-output header file for functions like printf.
#include <stdlib.h> // Including the standard library header for functions like malloc and exit.

// Defines a structure representing a polynomial with integer coefficients A, B, and C.
typedef struct {
    int A, B, C;
} PolynomialLCM;

/**
 * Computes the greatest common divisor (GCD) of two integers.
 *
 * @param a: An integer.
 * @param b: Another integer.
 * @return: The greatest common divisor of a and b.
 */
int GCD(int a, int b) {
    if (b == 0)  // Base case: if b is zero, the GCD is a.
        return a;
    return GCD(b, a % b);  // Recursive case: continue with b and the remainder of a divided by b.
}

/**
 * Initializes and allocates memory for a new PolynomialLCM object.
 *
 * @param a: Coefficient for x^2.
 * @param b: Coefficient for x.
 * @param c: Constant coefficient.
 * @return: A pointer to the allocated PolynomialLCM object.
 * @exception: Exits the program if any of the coefficients are zero or if memory allocation fails.
 */
PolynomialLCM* PolynomialLCM_init(int a, int b, int c) {
    if (a == 0 || b == 0 || c == 0) {  // Checking for zero coefficients.
        printf("Coefficients should not be zero.\n");
        exit(EXIT_FAILURE);  // Exiting the program with a failure status.
    }

    // Allocating memory for a PolynomialLCM object.
    PolynomialLCM* polynomial = (PolynomialLCM*) malloc(sizeof(PolynomialLCM));

    if (polynomial == NULL) {  // Checking for unsuccessful memory allocation.
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);  // Exiting the program with a failure status.
    }

    // Assigning the passed coefficients to the polynomial object.
    polynomial->A = a;
    polynomial->B = b;
    polynomial->C = c;

    return polynomial;  // Returning the initialized polynomial object.
}

/**
 * Retrieves the coefficient A of a PolynomialLCM object.
 *
 * @param polynomial: A pointer to the PolynomialLCM object.
 * @return: The coefficient A.
 */
int getA(const PolynomialLCM* polynomial) {
    return polynomial->A;
}

/**
 * Retrieves the coefficient B of a PolynomialLCM object.
 *
 * @param polynomial: A pointer to the PolynomialLCM object.
 * @return: The coefficient B.
 */
int getB(const PolynomialLCM* polynomial) {
    return polynomial->B;
}

/**
 * Retrieves the coefficient C of a PolynomialLCM object.
 *
 * @param polynomial: A pointer to the PolynomialLCM object.
 * @return: The coefficient C.
 */
int getC(const PolynomialLCM* polynomial) {
    return polynomial->C;
}

/**
 * Calculates the least common multiple (LCM) of the coefficients of a PolynomialLCM object.
 *
 * @param polynomial: A pointer to the PolynomialLCM object.
 * @return: The LCM of the coefficients.
 */
int CalculateLCM(PolynomialLCM* polynomial) {
    // Calculate LCM of A and B using the formula (A*B)/GCD(A,B).
    int lcmAB = (polynomial->A * polynomial->B) / GCD(polynomial->A, polynomial->B);
    // Calculate LCM of the previous result and C.
    int lcmABC = (lcmAB * polynomial->C) / GCD(lcmAB, polynomial->C);
    return lcmABC;  // Returning the computed LCM.
}

/**
 * Evaluates a Second-degree Polynomial using Given Coefficients and a Value of x.
 *
 * @param polynomial: A pointer to a PolynomialLCM object that holds the coefficients A, B, and C.
 * @param x: A double precision floating point value representing the input to the polynomial.
 * @return: A double precision floating point value which is the result of evaluating Ax^2 + Bx + C for the given x.
 */
double EvaluatePolynomial(PolynomialLCM* polynomial, double x) {
    return polynomial->A * x * x + polynomial->B * x + polynomial->C;
}
