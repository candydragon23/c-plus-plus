void insertionSort (int *arr, int size)
{
    int buf;
    int i, j;
    for (i = 1; i < size; i++)
    {
        buf = arr[i];
        for (j = i - 1; j >= 0 && buf < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = buf;
    }
}

