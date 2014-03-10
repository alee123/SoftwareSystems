#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int numer;
    int denom;
} Rational;

// Returns a new Rational with the given numer and denom.
// If unable to allocate, prints an error message and exits.
Rational *make_rational(int numer, int denom) {
    // FILL THIS IN
    //Rational r = (Rational) malloc(sizeof (Rational));
    Rational r;
    r.numer = numer;
    r.denom = denom;
    return &r;
}

// Computes a floating-point approximation of a Rational.
double rational_to_double(Rational *rational) {
    Rational temp = *rational;
    double d = (double) temp.numer / (double) temp.denom;
    return d;
}

// Multiplies two rational numbers; returns a new Rational.
Rational *mult_rational(Rational *r1, Rational *r2) {
    // FILL THIS IN
    //Rational mult = (Rational) malloc(sizeof (Rational));
    Rational mult;
    Rational r1Temp = *r1;
    Rational r2Temp = *r2;
    mult.numer = r1Temp.numer * r2Temp.numer;
    mult.denom = r1Temp.denom * r2Temp.denom;
    return &mult;
}

// Frees a Rational.
void free_rational(Rational *rational) {
    free(rational);
}

// Prints a rational in fraction form.
void print_rational(Rational *rational) {
    printf("%d / %d\n", rational->numer, rational->denom);
}

int main(void)
{
    Rational *rational = make_rational(3, 7);
    print_rational(rational);

    double d = rational_to_double(rational);
    printf("%lf\n", d);

    Rational *square = mult_rational(rational, rational);
    print_rational(square);
	
    free_rational(rational);
    free_rational(square);

    return EXIT_SUCCESS;
}
