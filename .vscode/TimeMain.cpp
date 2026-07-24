#include <iostream>
#include "Time.h"

using namespace std;



void assignmentTest()
{

    Time a(1,2,30,15);

    Time b;


    b = a;


    cout << "Assignment Test:" << endl;

    cout << b << endl;

}





void testTimeAddition()
{

    Time a(1,23,59,50);

    Time b(0,0,0,20);


    a + b;


    cout << "Addition Test:" << endl;

    cout << a << endl;

}





void testTimeSubtraction()
{

    Time a(2,0,0,0);

    Time b(1,5,30,0);


    // using negative time
    Time result(-1,-5,-30,0);


    a + result;


    cout << "Subtraction Test:" << endl;

    cout << a << endl;

}





void testTimeRelationalOperators()
{

    Time a(1,0);

    Time b(2,0);


    cout << "Relational Test:" << endl;


    cout << (a < b) << endl;

    cout << (a > b) << endl;

    cout << (a == b) << endl;

}





void testTimeOutStreamOperator()
{

    Time a(5,10,20);


    cout << "Output Test:" << endl;

    cout << a << endl;

}





void testTimeIntegerConversion()
{

    Time a(1,1,1,1);


    int seconds = a;


    cout << "Integer Conversion:" << endl;

    cout << seconds << endl;

}





int main()
{

    assignmentTest();

    testTimeAddition();

    testTimeSubtraction();

    testTimeRelationalOperators();

    testTimeOutStreamOperator();

    testTimeIntegerConversion();


    return 0;
}