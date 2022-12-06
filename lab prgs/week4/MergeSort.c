// Merge sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeSort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);

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
    mergeSort(a, 0, l - 1);
    for (int i = 0; i < l; i++)
    {
        printf("%d,", a[i]);
        fprintf(fp2, "%d,", a[i]);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
void mergeSort(int a[], int l, int r)
{
    if (r > l) // to check array has atleast two elements...
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = a[m + j + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}