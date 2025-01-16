#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*front=NULL,*rear=NULL,*newnode;

void enqueue();
void display();
void dequeue();

int main(){
    enqueue();
    display();
    dequeue();
    display();
}
void enqueue(){
    int choice=1;
    while(choice==1){
        printf("Enter data : ");
        int value;
        scanf("%d",&value);
        newnode=(struct node*)malloc(sizeof(struct node));
        if(front==NULL){
            front=newnode;
            rear=newnode;
            front->next=NULL;
            front->data=value;
        }else{
            rear->next=newnode;
            newnode->data=value;
            newnode->next=NULL;
            rear=newnode;
        }

        printf("Enter 1 to take another input : ");
        scanf("%d",&choice);
    }
}
void display(){
    struct node *temp=front;
    if(front==NULL){
        printf("Displaying the queue : ");
        printf("Underflow\n");
        return;
    }else{
    printf("Displaying the queue : ");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    }
    printf("\n");
}
void dequeue(){
    int delete;
    printf("How many elements you want to delete : ");
    scanf("%d",&delete);
    printf("Displaying dequeued elements : ");
    for(int i=1;i<=delete;i++){
    if(front==NULL){
        printf("\n");
        printf("Underflow\n");
        return ;
    }else{
        printf("%d\t",front->data);
        front=front->next;
    }

    }
    printf("\n");
}