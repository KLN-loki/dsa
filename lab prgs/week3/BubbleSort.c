// Bubble_sort
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
void Bubble(int a[], int n);
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
    Bubble(a, l);
    for (int i = 0; i < l; i++)
    {
        printf("%d,", a[i]);
        fprintf(fp2,"%d,", a[i]);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
void Bubble(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}