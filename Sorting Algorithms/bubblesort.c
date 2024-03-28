#include <stdio.h>

void print(int arr[], int n);
void bubblesort(int arr[], int n);

int main(void)
{
    int marks[] = {1,5,2,4,3,8,6,9,7,7,15,4};
    int n = sizeof(marks) / sizeof(marks[0]);
    print(marks, n);
    printf("\n");
    bubblesort(marks, n);
    printf("Sorted Array: ");
    print(marks, n);
    printf("\n");
}

void print(int arr[], int n)
{
    printf("{");
    for(int i = 0; i < n; i++)
    {
        printf("%i, ", arr[i]);
    }
    printf("}");
}

void bubblesort(int arr[], int n)
{
    int swapcount = -1, gtcount = 0;
    while (swapcount != 0)
    {
        swapcount = 0;
        for (int i = 0; i < n - gtcount -1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapcount++;
            }
        }

        gtcount++;
    }
}