#include<stdio.h>

int front=-1;
int rear=-1;
void enqueue(int *queue,int size);
void display(int *queue);
void dequeue(int *queue);

int main(){
    int en,size;
    printf("Enter size of queue: ");
    scanf("%d",&size);
    int queue[size];
    printf("No of elements to enqueue : ");
    scanf("%d",&en);
    for(int i=1;i<=en;i++){
        enqueue(queue,size);
    }
    printf("Displaying the queue : ");
    display(queue);
    dequeue(queue);

return 0;
}
void enqueue(int *queue,int size){
    if(rear==size-1){
        printf("Overflow\n");
    }else{
        printf("Enter data : ");
        if(front==-1){
            front++;
        }
        scanf("%d",&queue[++rear]);

    }
}
void display(int *queue){
    if(front==-1){
        printf("Underflow\n");
    }else{
        int temp=front;
        while(rear>=temp){
            printf("%d\t",queue[temp++]);
        }
        printf("\n");
}
}

void dequeue(int *queue){
    if(front==-1){
        printf("Underflow\n");
    }else{
        int deq;
    printf("How many elements you want to dequeue : ");
    scanf("%d",&deq);
    int count=0;
    while(rear>=front && count<=deq){
        printf("%d\t",queue[front++]);
        count++;
    }
    }
    
}