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
int countNode(struct node *head){
    int count=0;
    struct node *nextnode=head;
    while(nextnode!=NULL){
        count++;
        nextnode=nextnode->next;
    }

    return count;
}
void delete(struct node * head,int pos,int count){
    struct node * temp=NULL;
    if(pos>count){
        printf("Invalid Input ");
        return head;
    }else{
        int index=0;
        while(index!=pos-1){
            if(temp=NULL){
                temp=head;
                index++;
            }else{
                temp=temp->next;
                index++;
            }
        }
        temp->next=temp->next->next;
    }
}

int main(){
    struct node *head= takeNode();
    printf("Before : ");
    printNode(head);
    int pos,count=countNode(head);
    printf("Enter which position node you want to delete : ");
    scanf("%d",&pos);
    delete(head,pos,count);
    printf("After : ");
    printNode(head);

return 0;
}