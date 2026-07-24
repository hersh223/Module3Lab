#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "Term.h"

class Polynomial {
private:
    Term* terms;
    int numTerms;

    void simplify();

public:
    Polynomial();
    Polynomial(const Term* termsArray, int count);
    Polynomial(const Polynomial& poly);
    ~Polynomial();

    int getNumTerms() const;
    Term* getTerms() const;

    Polynomial& operator=(const Polynomial& right);
    Polynomial operator+(const Polynomial& right) const;
    Polynomial operator-(const Polynomial& right) const;
    Polynomial operator*(const Polynomial& right) const;

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
};

#endif