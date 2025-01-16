#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*newnode,*top,*temp;

void push();
void display();
void pop();

int main(){
    push();
    display();
    pop();
    display();

    free(temp);
    free(top);
    free(newnode);

return 0;
}
void push(){
    int insert;
    int choice =1;
    top==NULL;
    temp=NULL;
    while(choice==1){
        printf("Enter Value : ");
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=temp;
        temp=newnode;
        top=newnode;
        printf("Enter 1 to continue : ");
        scanf("%d",&choice);
        
    }
}
void display(){
    struct node * temp=top;
    printf("Displaying the stack : ");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void pop(){
    int delete;
    printf("How many elements you want to pop : ");
    scanf("%d",&delete);
    printf("Elements poped : ");
    for(int i=1;i<=delete;i++){
        if(top==NULL){
            printf("Underflow\n");
            return;
        }else{
            printf("%d\t",top->data);
            top=top->next;
        }
     }

     printf("\n");
}