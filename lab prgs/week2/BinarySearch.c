//Binary search

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int binarysearch(int a[], int l, int h, int x);
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
    int i = 0;
    while (token != NULL)
    {
        a[i] = atoi(token);
        i++;
        token = strtok(NULL, ",");
    }
    int key;
    printf("Enter key to be searched: ");
    scanf("%d", &key);
    int res = binarysearch(a, 0, i - 1, key);
    if (res == -1)
    {
        printf("Not Found.");
        fprintf(fp2, "Not Found.");
    }
    else
    {
        printf("Element %d found at %d.", key, res);
        fprintf(fp2, "Element %d found at %d.", key, res);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

int binarysearch(int a[], int l, int h, int x)
{
    if (h >= l) {
        int mid = (l + h) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return binarysearch(a, l, mid - 1, x);
        return binarysearch(a, mid + 1, h, x);
    }
    return -1;
}

