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

    SuperIntArray();

    SuperIntArray(int array[], int size);

    SuperIntArray(int num);

    SuperIntArray(vector<int> array);

    SuperIntArray(const SuperIntArray& arr);

    ~SuperIntArray();


    int* getNums();

    int getNumberOfNums();

    void setNums(int array[], int size);


    void add(int num);

    int get(int index);

    void change(int index, int value);


    SuperIntArray& operator=(const SuperIntArray& right);

    SuperIntArray operator+(const SuperIntArray& right);

    int& operator[](int index);


    friend ostream& operator<<(ostream& stream,
                               const SuperIntArray& right);


    static int getMax(int nums[], int size);

    static int getMin(int nums[], int size);

    static double getMean(int nums[], int size);

};


#endif