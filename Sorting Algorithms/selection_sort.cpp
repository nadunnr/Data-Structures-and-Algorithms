#include <iostream>
using namespace std;

void selection_sort(int* arr, int n)
{
    int min_id, temp;

    for (int i = 0; i < n - 1; i++)
    {
        min_id = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_id])
                min_id = j;
        }

        if (min_id != i)
        {
            temp = arr[i];
            arr[i] = arr[min_id];
            arr[min_id] = temp;
        }
    }
}

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // array to be sorted
    int test_array[] = {2, 46, 24, 35, 98, 75, 15, 23, 48, 67, 11, 84};
    int size = sizeof(test_array) / sizeof(test_array[0]);

    selection_sort(test_array, size);

    cout << "Sorted array: \n";
    print_array(test_array, size);

    return 0;
}
