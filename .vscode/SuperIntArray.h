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

    SuperIntArray(int nums[], int size);

    SuperIntArray(int num);

    SuperIntArray(vector<int> nums);

    SuperIntArray(SuperIntArray &arr);

    ~SuperIntArray();


    int* getNums();

    void setNums(int nums[], int size);

    int getNumberOfNums();


    void add(int num);

    int get(int index);

    void change(int index, int value);



    SuperIntArray& operator=(SuperIntArray& right);


    SuperIntArray operator+(SuperIntArray& right);


    int& operator[](int index);



    friend ostream& operator<<(ostream& stream, SuperIntArray& right);



    static int getMax(int nums[], int size);

    static int getMin(int nums[], int size);

    static double getMean(int nums[], int size);


};


#endif