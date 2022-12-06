// selection sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void selectSort(int a[], int n);

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
    selectSort(a, l);
    for (int i = 0; i < l; i++)
    {
        printf("%d,", a[i]);
        fprintf(fp2, "%d,", a[i]);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
void selectSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_ind])
                min_ind = j;
        }
        int t = a[i];
        a[i] = a[min_ind];
        a[min_ind] = t;
    }
}