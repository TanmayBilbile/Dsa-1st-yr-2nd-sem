#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
}*root=NULL;

struct node* create(int key);
void insert(struct node*root,struct node*new);
void inorder(struct node*root);



int main(){
    int n;
    printf("How many nodes you want : ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        int key;
        printf("Enter value : ");
        scanf("%d",&key);

       create(key);
    }
    inorder(root);

return 0;
}

struct node* create(int key){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=key;
    new->left=new->right=NULL;

    if(root==NULL){
        root=new;
    }else{
        insert(root,new);
    }
}

void insert(struct node*root,struct node*new){
    if(root->data < new->data){
        if(root->right==NULL){
            root->right=new;
        }else{
            insert(root->right,new);
        }
    }else{
        if(root->data > new->data){
            if(root->left==NULL){
                root->left=new;
            }else{
                insert(root->left,new);
            }
        }
    }
}

void inorder(struct node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}