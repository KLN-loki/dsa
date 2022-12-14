//fibonnaci search
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int min(int x, int y);
int fibMonaccianSearch(int a[], int x, int n);
int main(void)
{
 int a[100]; 
 char buff[100];
 FILE *fp1 = fopen("input.csv", "r");
 FILE *fp2 = fopen("output.csv", "w");
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
 int x;
 printf("Enter key to be searched: ");
 scanf("%d", &x);
 int ind = fibMonaccianSearch(a, x, l);
 if (ind >= 0)
 {
  printf("Found at index: %d", ind);
  fprintf(fp2, "Found at index: %d", ind);
 }
 else
 {
  printf("Not found.");
  fprintf(fp2, "Not found.");
 }
 fclose(fp1);
 fclose(fp2);
 return 0;
}

int min(int x, int y)
{
 return (x <= y) ? x : y;
}

int fibMonaccianSearch(int a[], int x, int n)
{
 int q = 0;
 int p = 1;
 int r = q + p;
 while (r < n)
 {
  q = p;
  p = r;
  r = q + p;
 }
 int offset = -1;
 while (r > 1)
 {
  int i = min(offset + q, n - 1);
  if (a[i] < x)
  {
   r = p;
   p = q;
   q = r - p;
   offset = i;
  }
  else if (a[i] > x)
  {
   r = q;
   p = p - q;
   q = r - p;
  }
  else
   return i;
 }
 if (p && a[offset + 1] == x)
  return offset + 1;
 return -1;
}
