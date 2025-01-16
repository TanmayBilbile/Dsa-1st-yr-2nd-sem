#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node * inputNode(){
    struct node *newnode,*temp,*head;
    head=NULL;
    int choice=1;
    while(choice==1){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
            newnode->next=NULL;
        }

        printf("Enter choice 1 to take input 0 to stop : ");
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
int countNode(struct node *head){
    int count=0;
    struct node *nextnode=head;
    while(nextnode!=NULL){
        count++;
        nextnode=nextnode->next;
    }

    return count;
}

void insert(int pos,int count,struct node *head){
    if(pos>count){
        printf("position cant be greater than no of nodes try again \n");
    }else{
        int index=0;
        struct node *p2,*p3,*p1=NULL;
        while(index!=pos){
            if(p1==NULL){
                p1=head;
                index++;
            }else{
                p1=p1->next;
                index++;
            }
        }
        p2=(struct node *)malloc(sizeof(struct node));
        printf("Enter value to insert : ");
        scanf("%d",&p2->data);
        p3=p1->next;
        p1->next=p2;
        p2->next=p3;
    }
}

int main(){
    struct node* head=NULL;
    head=inputNode();
    printf("Before : ");
    printNode(head);
    int count=countNode(head);
    int pos;
    printf("Enter after which position you want to insert : ");
    scanf("%d",&pos);
    insert(pos,count,head);
    printf("After : ");
    printNode(head);

    return 0;


}