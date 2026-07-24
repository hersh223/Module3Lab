#ifndef TERM_H
#define TERM_H

class Term {
private:
    double coefficient;
    int exponent;
    char variable;

public:
    Term();
    Term(double coef, int exp, char var);
    Term(const Term& term);

    double getCoefficient() const;
    void setCoefficient(double coef);

    int getExponent() const;
    void setExponent(int exp);

    char getVariable() const;
    void setVariable(char var);

    Term& operator=(const Term& right);

    bool operator<=(const Term& right) const;
    bool operator>=(const Term& right) const;
    bool operator<(const Term& right) const;
    bool operator>(const Term& right) const;
    bool operator==(const Term& right) const;

    bool compatible(const Term& term) const;
};

#endif