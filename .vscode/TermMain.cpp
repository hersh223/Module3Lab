#include <iostream>
#include "Term.h"
#include "Polynomial.h"

using namespace std;

int main() {
    Term t1(3.0, 2, 'x');
    Term t2(5.0, 2, 'x');
    Term t3(2.0, 1, 'x');

    cout << "t1 compatible with t2: " << (t1.compatible(t2) ? "Yes" : "No") << endl;
    cout << "t1 compatible with t3: " << (t1.compatible(t3) ? "Yes" : "No") << endl;
    cout << "t1 > t3: " << (t1 > t3 ? "True" : "False") << endl;

    Term p1Terms[] = { Term(3, 2, 'x'), Term(4, 1, 'x'), Term(5, 0, 'x') };
    Term p2Terms[] = { Term(2, 2, 'x'), Term(-1, 1, 'x'), Term(3, 0, 'x') };

    Polynomial poly1(p1Terms, 3);
    Polynomial poly2(p2Terms, 3);

    cout << "Poly 1: " << poly1 << endl;
    cout << "Poly 2: " << poly2 << endl;

    Polynomial sum = poly1 + poly2;
    cout << "Poly 1 + Poly 2: " << sum << endl;

    Polynomial diff = poly1 - poly2;
    cout << "Poly 1 - Poly 2: " << diff << endl;

    Polynomial prod = poly1 * poly2;
    cout << "Poly 1 * Poly 2: " << prod << endl;

    return 0;
}