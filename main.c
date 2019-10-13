

#include "headers/reduction.h"


int main()
{
    int len,height;
    scanf("%d %d",&height,&len);
    int **mass = (int**)malloc(sizeof(int*)*height);
    for (int i = 0; i < height; ++i)
    {
        mass[i] = (int*)malloc(sizeof(int)*len);
        for (int j = 0; j < len; ++j)
        {
          scanf("%d",&mass[i][j]);
        }
    }
    int **out = reduction(height, len, mass);
    for (int i = 0; i < height; ++i)
    {
        int j = 0;
        while (out[i][j] != NULL)
        {
            printf("%d ", out[i][j]);
            j++;
        }
        printf("\n");
    }
    for (int i = 0; i < height; ++i)
    {
        if (mass[i] != NULL)
            free(mass[i]);
    }
    if (mass != NULL)
        free(mass);
    if (out != NULL)
        free(out);
    return 0;
}