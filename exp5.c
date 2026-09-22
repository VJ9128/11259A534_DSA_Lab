#include <stdio.h>

#define MAX 5

int queue[MAX];
int front= -1,rear= -1;

void enqueue(int val){
    if(rear==MAX-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)
    front=0;
queue[++rear]=val;
printf( "5d enqueued to queue.\n",val);
}
void dequeue(){
    if(front==1|| front>rear){
        printf("Queue underflow\n.");
        return;
    }
    printf("%d dequeued from queue.\n",queue[front]);
    front++;
    if(front>rear)
       front = rear = -1;
}
void display(){
    int i;
    if(front==-1||front>rear){
        printf("queue is empty.\n");
        return;
    }
    printf("queue elements:");
    for(i=front; i<+rear;i++)
        printf("%d",queue[i]);
    printf("\n");
}
int main(){
    int choice,val;
    do{
        printf("\n---SIMPLE QUEUE MENU---\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
               printf("enter value to enqueue:");
               scanf("%d",&val);
               enqueue(val);
               break;
            case 2:
             dequeue();
             break;
        case 3:
            display();
            break;
        case 4:
           printf("exiting program.\n");
           break;
        default:
            printf("invalid choice.\n");

        }
    } while(choice!=4);
    return 0;

}