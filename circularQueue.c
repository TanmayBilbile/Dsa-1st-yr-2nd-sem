#include<stdio.h>

int front=-1;
int rear=-1;

void enqueue(int n,int *queue);
void dequeue(int n,int *queue);
void display(int n,int *queue);

int main(){
    int size;
    printf("ENter size : ");
    scanf("%d",&size);
    int queue[size];
    
    int choice;
    
    do{
        printf("MENU\n1.Enqueue\n2.Deuqueue\n3.Display\n4.exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);

    switch(choice){
        case 1:{
            enqueue(size,queue);
            break;
        }
        case 2:{
           dequeue(size,queue);
            break;
        }
        case 3:{
            display(size,queue);
            break;
        }
        case 4:{
            printf("Exiting the program .....\n");
            break;
        }
        default:printf("Enter correct input \n");
    }
    }while(choice!=4);
    
return 0;
}
void enqueue(int n,int *queue){
    if((rear+1)%n==front){
        printf("overflow\n");
        return;
    }else{
        printf("Enter value : ");
        int value;
        scanf("%d",&value);
        if(front==-1 && rear==-1){
            rear++;
            front++;
            queue[rear]=value;
        }else{
            rear=(rear+1)%n;
            queue[rear]=value;

            printf("Element enqueued : %d\n",value);
        }
    }
printf("\n");
}    
void dequeue(int n,int *queue){
    if(front==-1 && rear==-1){
        printf("Underflow\n");
        printf("\n");
        return;
    }else if(front==rear){
        printf("Element dequeued : ");
        printf("%d\t",queue[front]);
        rear=-1;
        front=-1;
    }else{
        printf("Element dequeued : ");
        printf("%d\t",queue[front]);
        front=(front+1)%n;
    }

    printf("\n");
}
void display(int n,int *queue){
    if(front==-1 && rear==-1){
        printf("Underflow\n");
    }else{
        printf("Displaying the queue : ");
        int temp=front;
        do{
            printf("%d\t",queue[temp]);
            temp=(temp+1)%n;
        }while(temp!=(rear+1)%n);
    }
    printf("\n");
}