//
//  main.c
//  LeastKNumber
//
//  Created by chenyufeng on 8/6/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

// 数组中最小的k个数
#include <stdio.h>
#include <stdlib.h>

void LeastKNumber(int *arr, int start, int end, int k);
int Partition(int *arr, int start, int end);

int main(int argc, const char * argv[])
{
    int array[] = {2,3,4,5,6,7};
    LeastKNumber(array, 0, 5, 5);

    return 0;
}

void LeastKNumber(int *arr, int start, int end, int k)
{
    int index = Partition(arr, start, end);

    while (index != k)
    {
        if (index > k)
        {
            index = Partition(arr, start, index - 1);
        }
        else
        {
            // index < k
            index = Partition(arr, index + 1, end);
        }
    }

    if (index == k)
    {
        for (int i = 0; i < k; i++)
        {
            printf("%d ",arr[i]);
        }
        return;
    }
}


int Partition(int *arr, int start, int end)
{
    int i = start, j = end, x = arr[start];

    while (i < j)
    {
        while (i < j && arr[j] >= x)
        {
            j--;
        }
        if (i < j)
        {
            arr[i++] = arr[j];
        }

        while (i < j && arr[i] < x)
        {
            i++;
        }
        if (i < j)
        {
            arr[j--] = arr[i];
        }
    }

    arr[i] = x;
    
    return i;
}
