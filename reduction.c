
#include "headers/reduction.h"



int** reduction (int height, int len, int **mass)
{
    int **output = (int**)malloc(sizeof(int*) * height);
    for (int i = 0; i < height; ++i)
    {
        int count = 0;
        for (int j = 0; j < len; ++j)
        {
            if (mass[i][j] != 0)
                count++;
        }
        output[i] = (int*)malloc(sizeof(int) * (count + 1));
        int k = 0;
        for (int j = 0; j < len; ++j)
        {
            if (count == k - 1)
                break;
            if (mass[i][j] != 0)
            {
                output[i][k] = mass[i][j];
                k++;
            }
            output[i][count] = (int) NULL;
        }
    }
    return output;
}