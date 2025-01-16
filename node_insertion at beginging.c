#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* takeNode(){
    struct node * head,*temp,*newnode;
    head=NULL;
    int choice=1;
    while(choice==1){
        newnode=(struct node *)(malloc(sizeof(struct node)));
        printf("Enter Data : ");
        scanf("%d",&newnode->data);
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
            newnode->next=NULL;
        }
        printf("Enter choice 1 to continue 0 to stop :");
        scanf("%d",&choice);
    }
    return head;
}
void printNode(struct node *head){
    struct node *forward=NULL;
    forward=head;
    while(forward!=NULL){
        printf("%d ",forward->data);
        forward=forward->next;
    }
    printf("\n");

}

struct node * insert(struct node *head,int value){
    struct node *temp=NULL;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=head;
    head=temp;
    return head;
}

int main(){
    struct node *head= takeNode();
    printf("Before: ");
    printNode(head);
    int n;
    printf("Enter The Value To insert at beginging: ");
    scanf("%d",&n);
    head =insert(head,n);
    printf("After: ");
    printNode(head);

return 0;
}