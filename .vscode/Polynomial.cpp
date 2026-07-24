#include "Polynomial.h"

void Polynomial::simplify() {
    if (numTerms <= 0) return;

    Term* temp = new Term[numTerms];
    int tempCount = 0;

    for (int i = 0; i < numTerms; ++i) {
        if (terms[i].getCoefficient() == 0) continue;

        bool merged = false;
        for (int j = 0; j < tempCount; ++j) {
            if (temp[j].compatible(terms[i])) {
                temp[j].setCoefficient(temp[j].getCoefficient() + terms[i].getCoefficient());
                merged = true;
                break;
            }
        }

        if (!merged) {
            temp[tempCount++] = terms[i];
        }
    }

    int finalCount = 0;
    for (int i = 0; i < tempCount; ++i) {
        if (temp[i].getCoefficient() != 0) {
            finalCount++;
        }
    }

    delete[] terms;

    if (finalCount == 0) {
        terms = new Term[1];
        terms[0] = Term(0, 0, 'x');
        numTerms = 1;
    } else {
        terms = new Term[finalCount];
        numTerms = 0;
        for (int i = 0; i < tempCount; ++i) {
            if (temp[i].getCoefficient() != 0) {
                terms[numTerms++] = temp[i];
            }
        }
    }

    delete[] temp;
}

Polynomial::Polynomial() : numTerms(1) {
    terms = new Term[1];
    terms[0] = Term(0, 0, 'x');
}

Polynomial::Polynomial(const Term* termsArray, int count) : numTerms(count) {
    terms = new Term[count];
    for (int i = 0; i < count; ++i) {
        terms[i] = termsArray[i];
    }
    simplify();
}

Polynomial::Polynomial(const Polynomial& poly) : numTerms(poly.numTerms) {
    terms = new Term[numTerms];
    for (int i = 0; i < numTerms; ++i) {
        terms[i] = poly.terms[i];
    }
}

Polynomial::~Polynomial() {
    delete[] terms;
}

int Polynomial::getNumTerms() const { return numTerms; }
Term* Polynomial::getTerms() const { return terms; }

Polynomial& Polynomial::operator=(const Polynomial& right) {
    if (this != &right) {
        delete[] terms;
        numTerms = right.numTerms;
        terms = new Term[numTerms];
        for (int i = 0; i < numTerms; ++i) {
            terms[i] = right.terms[i];
        }
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& right) const {
    int total = numTerms + right.numTerms;
    Term* combined = new Term[total];

    for (int i = 0; i < numTerms; ++i) combined[i] = terms[i];
    for (int i = 0; i < right.numTerms; ++i) combined[numTerms + i] = right.terms[i];

    Polynomial result(combined, total);
    delete[] combined;
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& right) const {
    int total = numTerms + right.numTerms;
    Term* combined = new Term[total];

    for (int i = 0; i < numTerms; ++i) combined[i] = terms[i];
    for (int i = 0; i < right.numTerms; ++i) {
        Term negated = right.terms[i];
        negated.setCoefficient(-negated.getCoefficient());
        combined[numTerms + i] = negated;
    }

    Polynomial result(combined, total);
    delete[] combined;
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& right) const {
    int total = numTerms * right.numTerms;
    Term* combined = new Term[total];
    int idx = 0;

    for (int i = 0; i < numTerms; ++i) {
        for (int j = 0; j < right.numTerms; ++j) {
            double c = terms[i].getCoefficient() * right.terms[j].getCoefficient();
            int e = terms[i].getExponent() + right.terms[j].getExponent();
            char v = terms[i].getVariable();
            combined[idx++] = Term(c, e, v);
        }
    }

    Polynomial result(combined, total);
    delete[] combined;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    for (int i = 0; i < poly.numTerms; ++i) {
        double c = poly.terms[i].getCoefficient();
        int e = poly.terms[i].getExponent();
        char v = poly.terms[i].getVariable();

        if (i > 0 && c >= 0) os << " + ";
        else if (i > 0 && c < 0) {
            os << " - ";
            c = -c;
        }

        os << c;
        if (e != 0) {
            os << v;
            if (e != 1) os << "^" << e;
        }
    }
    return os;
};