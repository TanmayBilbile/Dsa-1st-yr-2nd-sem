#include<stdio.h>

int front=-1;
int rear=-1;

void enqueue(int size,int *queue);
void display(int *queue);
void dequeue(int *queue);

int main(){
    int size;
    printf("Enter size of queue : ");
    scanf("%d",&size);

    int queue[size];

    enqueue(size,queue);
    display(queue);
    dequeue(queue);
    display(queue);
    
    return 0;
}

void enqueue(int size,int *queue){
    printf("How many elements you want to enqueue : ");
    int insert;
    scanf("%d",&insert);

    for(int i=0;i<insert;i++){

        if(i>size-1){
            printf("Overflow\n");
            return;
        }else{
            printf("Enter data : ");
            int value;
            scanf("%d",&value);
            if(front==-1){
                front++;
            }
            queue[++rear]=value;
        }

    }
}
void display(int *queue){
    if(front==-1){
        printf("Underflow\n");
    }else{
        int temp=front;
        printf("Displaying the queue : ");
        while(temp<=rear){
            printf("%d\t",queue[temp++]);
        }

        printf("\n");
    }
}
void dequeue(int *queue){
    int delete;
    printf("How much elements you want to dequeue : ");
    scanf("%d",&delete);
    int count=0;
    if(front==-1){
        printf("Underflow\n");
    }else{
        printf("Elements dequeued :");
    while(count<delete && front<=rear){
        printf("%d\t",queue[front++]);
        count++;
    }
    }

    printf("\n");
}