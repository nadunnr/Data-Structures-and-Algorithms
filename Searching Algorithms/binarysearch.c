#include <stdio.h>

void partition(int arr[], int low, int high);
void mergesort(int arr[], int low, int mid, int high);
void binarysearch(int arr[], int low, int high, int f);

int list[50];

int main(void)
{
    int size;
    printf("Enter the size of the list: ");
    scanf("%i", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%i", &list[i]);
    }

    //mergesort
    partition(list, 0, size - 1);

    //printing
    printf("Sorted List: {%i", list[0]);

    for(int c = 1; c <size; c++)
    {
        printf(", %i", list[c]);
    }

    printf("}\n");

    int f;
    printf("What is the number you are looking for? ");
    scanf("%i", &f);

    //binary search
    binarysearch(list, 0, size - 1, f);
    }

void partition(int arr[], int low, int high)
{
    int mid = (int) (high + low)/2;

    if(low < high)
    {
        //partitioning
        partition(arr, low, mid);
        partition(arr, mid + 1, high);

        //sorting
        mergesort(arr, low, mid, high);
    }

}

void mergesort(int arr[], int low, int mid, int high)
{
    //temporary array
    int temp[50];

    //temp variables
    int lc = 0, rc = 0, tc = 0;

    while(((low + lc) <= mid) && ((mid + 1 + rc) <= high))
    {
        if(arr[low + lc]<= arr[(mid+1) + rc])
        {
            temp[low + tc] = arr[low + lc];
            lc++;
        }

        else
        {
            temp[low + tc] = arr[(mid+1) + rc];
            rc++;
        }

        tc++;
    }

    if (low + lc > mid)
    {
        while((mid + 1 + rc) <= high)
        {
            temp[low + tc] = arr[mid + 1 + rc];
            rc++;
            tc++;
        }
    }

    else
    {
        while((low + lc) <= mid)
        {
            temp[low + tc] = arr[low + lc];
            lc++;
            tc++;
        }
    }

    for (int i = 0; i < tc; i++)
    {
        list[low + i] = temp[low + i];
    }
}

void binarysearch(int arr[], int low, int high, int f)
{
    int mid = (int) (low + high)/2;

    if(low != high)
    {
        if(arr[mid] == f)
        {
        printf("Found. It's at the %ith position.\n", mid + 1);
        }

        else if(arr[mid] < f)
        {
        binarysearch(arr, mid + 1, high, f);
        }

        else
        {
        binarysearch(arr, low, mid, f);
        }
    }

    else
    {
        if(arr[low] == f)
        {
            printf("Found. It's at the %ith position.\n", low + 1);
        }

        else
        {
            printf("Not Found.\n");
        }
    }
}
