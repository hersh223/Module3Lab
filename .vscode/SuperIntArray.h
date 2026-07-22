#ifndef SUPERINTARRAY_H
#define SUPERINTARRAY_H

#include <iostream>
#include <vector>

using namespace std;


class SuperIntArray
{

private:

    int* nums;
    int numberOfNums;


public:

    // Constructors
    SuperIntArray();

    SuperIntArray(int nums[], int size);

    SuperIntArray(int num);

    SuperIntArray(vector<int> nums);

    SuperIntArray(const SuperIntArray &arr);


    // Destructor
    ~SuperIntArray();



    // Getters / Setters
    int* getNums();

    void setNums(int nums[], int size);

    int getNumberOfNums();



    // Functions
    void add(int num);

    int get(int index);

    void change(int index, int value);



    // Operators
    SuperIntArray& operator=(const SuperIntArray& right);

    SuperIntArray operator+(const SuperIntArray& right);

    int& operator[](int index);



    friend ostream& operator<<(ostream& stream, const SuperIntArray& right);



    // Static functions
    static int getMax(int nums[], int size);

    static int getMin(int nums[], int size);

    static double getMean(int nums[], int size);


};


#endif