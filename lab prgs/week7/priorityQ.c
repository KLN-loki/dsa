/**

7. Write a program to implement the following types of queues
i) Priority Queue ii) Circular Queue.

*/

// Priority Queue

#include <stdio.h>
#include <stdlib.h>
enqueue(){
    printf("Enter the element and its priority : ");
    int val, pri;
    scanf("%d%d", &val, &pri);
    for (int i = 0; i < n; i++){
        if (pri < q[])
    }
}
int main(){
    printf("Enter the length of the Queue : ");
    int n;
    scanf("%d", &n);
    int q[n][2];
    
    int front = 0;
    int rear = 0;
    while (true){
        printf("Select an option : \n 1.enqueue\n 2.dequeue\n 3.peek\n 4.size\n 5.quit\n");
        int option;
        scanf("%d", &option);
        switch(option){
            case 1:
                rear = enqueue(q, rear, n);
                break;
            case 2:
                front = dequeue(q, front, rear);
                break;
            case 3:
                peek(q, front, rear);
                break;
            case 4:
                size(front, rear);
                break;
            case 5:
                exit(0);
            default :
                printf("Select a valid option.\n");
                break;
        }
    }
    return 0;
}

