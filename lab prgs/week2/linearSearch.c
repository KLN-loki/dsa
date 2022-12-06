//linear search

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int key, flag = 0, loc = -1;
    printf("Enter key to be searched: ");
    scanf("%d", &key);
    for(int j = 0;j < i; j++)
    {
        if (a[j] == key)
        {
            loc = j;
            printf("The element %d found at %d", key, loc);
            fprintf(fp2,"The element %d found at %d", key, loc);
            flag++;
        }
    }
    if(flag == 0)
    {
        printf("Not found.");
        fprintf(fp2,"Not found.");
    }
    fclose(fp1);
    fclose(fp2); 
    return 0;
}
