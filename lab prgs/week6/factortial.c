// 6. Write a program to implement the following Stack applications
// i)Factorial

#include <stdio.h>
#include <stdbool.h>

bool isfull(int *top, int n)
{
    if (*top == n)
        return true;
    return false;
}
bool isempty(int *top)
{
    if (*top == 0)
        return true;
    return false;
}
void push(int arr[], int *top, int x, int n)
{
    if (isfull(top, n) == false)
    {
        arr[*top] = x;
        *top = *top + 1;
    }
    else
    {
        printf("stack is full.\n");
    }
}
int pop(int arr[], int *top)
{
    if (isempty(top) == false)
    {
        int val = arr[*top - 1];
        *top = *top - 1;
        return val;
    }
    else
    {
        printf("Stack is empty.\n");
    }
}

int main()
{
    // int n;
    // printf("Enter n of Stack: ");
    // scanf("%d", &n);
    
    int n;
    printf("Enter value To Calculate Factorial: ");
    scanf("%d", &n);
    int arr[n];
    int top = 0;
    for (int i = n; i >= 1; i--)
    {
        push(arr, &top, i, n);
    }
    int pro = 1;
    for (int i = 1; i <= n; i++)
    {
        int f = pop(arr, &top);
        pro *= f;
    }
    printf("The Factorial of %d is %d", n, pro);
    return 0;
}