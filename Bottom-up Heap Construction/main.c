#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void maxHeapify (int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapBottomUp (int arr[], int n)
{
    int i;
    for (i = (n/2)-1; i >= 0 ; i--)
        maxHeapify(arr, n, i);
}

int main()
{
    system("color 5f");
    int n, i;
    printf ("\n");
    printf ("** Bottom-up Heap Construction **\n\n");
    printf ("* Enter the number of terms : ");
    scanf ("%d",&n);
    printf ("\n");
    int arr[n];

    for (i = 0 ; i < n ; i++)
    {
        printf ("* Enter the term #%d : ",i+1);
        scanf ("%d",&arr[i]);
        printf ("\n");
    }

    heapBottomUp(arr, n);

    printf ("* Heap Representation : \n\n");
    for (i = 0 ; i < n ; i++)
    {
        printf ("  %d\n", arr[i]);
    }

    printf ("\n*** Thanks ! ***\n\n");
}
