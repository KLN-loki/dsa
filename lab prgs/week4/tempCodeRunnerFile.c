// quicksort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int partition(int a[], int low, int high);
void quickSort(int a[], int low, int high);

int main()
{
    int a[100];
    FILE *fp1 = fopen("input.csv", "r");
    FILE *fp2 = fopen("output.csv", "w");
    char buff[100];
    do
    {
        fgets(buff, 100, (FILE *)fp1);
    } while ((getc(fp1)) != EOF);
    char *token = strtok(buff, ",");
    int l = 0;
    while (token != NULL)
    {
        a[l] = atoi(token);
        l++;
        token = strtok(NULL, ",");
    }
    quickSort(a, 0, l-1);    
    for (int i = 0; i < l; i++)
    {
        printf("%d,", a[i]);
        fprintf(fp2, "%d,", a[i]);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1, j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i >= j)
            return j;
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi);
        quickSort(a, pi + 1, high);
    }
}
