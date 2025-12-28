void quickSort (int* arr, int first, int last)
{
    int i = first, j = last;
    int buf, comp;
    comp = arr[(first + last) / 2];
    do
    {
        while (arr[i] < comp && i < last)
            i++;
        while (arr[j] > comp && j > first)
            j--;
        if (i <= j)
        {
            if (arr[i] > arr[j])
            {
                buf = arr[i];
                arr[i] = arr[j];
                arr[j] = buf;
            }
            i++;
            j--;
        }
    } while(i <= j);
    if (first < j)
        quickSort(arr, first, j);
    if (i < last)
        quickSort(arr, i, last);
}
