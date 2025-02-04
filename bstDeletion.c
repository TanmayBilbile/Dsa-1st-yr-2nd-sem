#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
}*root=NULL,*inpre;

struct node* create(int key);
void insert(struct node*root,struct node*new);
void inorder(struct node*root);
struct node *deleteNode(struct node *root,int value);
struct node *inorderpredi(struct node*root);



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
    printf("\n");
    int value;
    printf("Which value you want to delete : ");
    scanf("%d",&value);

    deleteNode(root,value);
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
struct node *deleteNode(struct node *root,int value){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }

    if(root->data > value){
        root->left=deleteNode(root->left,value);

    }else if(root->data <value){
        root->right=deleteNode(root->right,value);

    }else{
        inpre=inorderpredi(root);
        root->data=inpre->data;
        root->left=deleteNode(root->left,inpre->data);
    }

    return root;
}
struct node *inorderpredi(struct node*root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }

    return root;
}