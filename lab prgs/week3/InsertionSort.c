// Insertion sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertSort(int a[], int n);
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
    insertSort(a, l);
    for (int i = 0; i < l; i++)
    {
        printf("%d,", a[i]);
        fprintf(fp2, "%d,", a[i]);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
void insertSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
