// #include <stdio.h>

// int fact (int n );

// int main(){
//     int n ;
//     printf("Enter the number : ");
//     printf("Factorial of %d is %d", n, fact(n));
    
// }

// int fact(int n){
//     // int fact = 1
//     int fact;
//     if (n == 1 || n == 0){
//         return 1;
//     }
//     if (n > 1){
//         fact = n*fact(n-1);
//     }
//     return fact;
// }



// #include<stdio.h>  
  
// long factorial(int n)  
// {  
//   if (n == 0)  
//     return 1;  
//   else  
//     return(n * factorial(n-1));  
// }  
   
// void main()  
// {  
//   int number;  
//   long fact;  
//   printf("Enter a number: ");  
//   scanf("%d", &number);   
   
//   fact = factorial(number);  
//   printf("Factorial of %d is %ld\n", number, fact); 
// }



#include <stdio.h>

long factorial(int n);

int main(){
    int n ;
    printf("Enter the number : ");
    scanf("%d", &n);
    int fact ;
    fact = factorial(n);
    printf("Factorial of %d is %d.", n, fact);
    return 0;
}
long factorial (int n){
    if (n == 1 || n == 0){
        return 1;
    }
    else {
        return (n * factorial(n - 1));
    }
}