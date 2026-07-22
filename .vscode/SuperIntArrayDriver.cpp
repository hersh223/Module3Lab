#include <iostream>
#include "SuperIntArray.h"

using namespace std;



int main()
{

    int values[] = {10,20,30};


    SuperIntArray a(values,3);


    cout << "A: " << a << endl;



    SuperIntArray b(5);


    cout << "B: " << b << endl;



    a.add(40);


    cout << "After add: " << a << endl;



    a.change(0,100);


    cout << "After change: " << a << endl;



    cout << "Index 2: " << a[2] << endl;



    a[2] = 999;


    cout << "After [] modification: "
         << a << endl;



    SuperIntArray c(a);


    cout << "Copy: "
         << c << endl;



    SuperIntArray d = a + b;


    cout << "Concatenation: "
         << d << endl;




    cout << "Max: "
         << SuperIntArray::getMax(values,3)
         << endl;



    cout << "Min: "
         << SuperIntArray::getMin(values,3)
         << endl;



    cout << "Mean: "
         << SuperIntArray::getMean(values,3)
         << endl;



    return 0;

}