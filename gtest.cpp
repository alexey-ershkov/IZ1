//
// Created by Алексей on 2019-10-09.
//

#include "gtest/gtest.h"
#include <iostream>

extern "C"
{
    #include "headers/reduction.h"
};


#define HEIGHT 4
#define LEN 3


class Reduction_test : public ::testing::Test {
public:
    int ** mass;
    int ** expected;
protected:
    virtual void SetUp() {
        mass = (int**)malloc(sizeof(int*)*HEIGHT);
        for (int i = 0; i < HEIGHT; ++i)
        {
            mass[i] = (int*)malloc(sizeof(int)*LEN);
            for (int j = 0; j < LEN; ++j)
            {
                mass[i][j] = 0;
            }
        }

        expected = (int**)malloc(sizeof(int*)*HEIGHT);
        for (int i = 0; i < HEIGHT; ++i)
        {
            expected[i] = (int*)malloc(sizeof(int)*LEN);
            for (int j = 0; j < LEN; ++j)
            {
                expected[i][j] = 0;
            }
        }
    }


    virtual void TearDown() {
        for (int i = 0; i < HEIGHT; ++i)
        {
            if (mass[i] != NULL)
                free(mass[i]);
        }
        if (mass != NULL)
            free(mass);

        for (int i = 0; i < HEIGHT; ++i)
        {
            if (expected[i] != NULL)
                free(expected[i]);
        }
        if (expected != NULL)
            free(expected);
    }

    
};


void ArraysMatch(int** actual, int** expected){
    for (int i = 0; i < HEIGHT; ++i){
        int j = 0;
        while (actual[i][j] != NULL)
        {
            EXPECT_EQ(expected[i][j],actual[i][j]);
            ++j;
        }
        EXPECT_EQ(NULL,actual[i][j]);
    }
}

TEST_F(Reduction_test, without_zero)
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < LEN; ++j)
        {
            mass[i][j] = 1;
        }
    }
    int ** buffer = reduction(HEIGHT, LEN, reinterpret_cast<int**>(mass));
    ArraysMatch(buffer,mass);
}

TEST_F(Reduction_test, with_some_zeroes)
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < LEN; ++j)
        {
            if ((i+j)%2 == 0)
                mass[i][j] = 1;
            else
                mass[i][j] = 0;
        }
    }
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < LEN; ++j)
        {
            expected[i][j] = 1;
        }
    }
    int ** buffer = reduction(HEIGHT, LEN, reinterpret_cast<int**>(mass));
    ArraysMatch(buffer,expected);
}

TEST_F(Reduction_test, only_zeroes)
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < LEN; ++j)
        {
            expected[i][j] = NULL;
        }
    }
    int ** buffer = reduction(HEIGHT, LEN, reinterpret_cast<int**>(mass));
    ArraysMatch(buffer,expected);
}
