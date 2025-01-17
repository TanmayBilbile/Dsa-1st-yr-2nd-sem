#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
}*head=NULL,*tail,*newnode;

void push();
void display(int dis);

int main(){
    push();
    int dis;
    printf("Enter 1 for forward display or 2 for backward display : ");
    scanf("%d",&dis);
    display(dis);
return 0;
}

void push(){
    newnode=(struct node*)malloc(sizeof(struct node));
    int choice=1;
    while(choice==1){
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("Enter Data : ");
        int value;
        scanf("%d",&value);
        if(head==NULL){
            head=newnode;
            head->prev=NULL;
            tail=newnode;
            head->next=NULL;
            head->data=value;
        }else{
            newnode->data=value;
            newnode->prev=tail;
            newnode->next=NULL;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Enter choice 1 for another input : ");
        scanf("%d",&choice);
        
    }
}
void display(int dis){
    if(dis==1){    
    newnode=head;
    if(head==NULL){
        printf("Underflow\n");
        return ;
    }
    printf("Displaying the nodes : ");
    while(newnode!=NULL){
        printf("%d\t",newnode->data);
        newnode=newnode->next;
    }
    printf("\n");
}else if(dis==2){
    newnode=tail;
    if(tail==NULL){
        printf("Underflow\n");
        return;
    }
    printf("Displaying the nodes : ");
    while(newnode!=NULL){
        printf("%d\t",newnode->data);
        newnode=newnode->prev;
    }

    printf("\n");
}

}