#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
    int height;
};

int max(int a,int b);
struct node*createNode(int key);
struct node*insert(struct node* node,int key);
int getHeight(struct node*n);
int balanceFactor(int a,int b);
struct node* leftRotation(struct node *y);
struct node* rightRotation(struct node *x);
void inorder(struct node* n);

int main(){
    struct node* root=NULL;
    root=insert(root,4);
    root=insert(root,10);
    root=insert(root,17);    
    root=insert(root,64);
    root=insert(root,13);
    root=insert(root,8);
    root=insert(root,45);
    root=insert(root,48);
    root=insert(root,90);

    inorder(root);

return 0;
}
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
struct node*createNode(int key){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=key;
    new->left=NULL;
    new->right=NULL;
    new->height=1;

    return new;
}
int getHeight(struct node*n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}
int balanceFactor(int a,int b){
    return a-b;
}
struct node* leftRotation(struct node *y){
    struct node * x=y->right;
    struct node* T2=x->left;

    x->left=y;
    y->right=T2;

    x->height=1+ max(getHeight(x->left),getHeight(x->right));
    y->height=1+ max(getHeight(y->left),getHeight(y->right));

    return x;
}
struct node* rightRotation(struct node *x){
    struct node * y=x->left;
    struct node* T2=y->right;

    x->left=T2;
    y->right=x;

    x->height=1+ max(getHeight(x->left),getHeight(x->right));
    y->height=1+ max(getHeight(y->left),getHeight(y->right));
    
    return y;
}
struct node*insert(struct node* node,int key){
    if(node==NULL){
        return createNode(key);
    }
    if(key > node->data){
        node->right=insert(node->right,key);
    }else if(key < node->data){
        node->left=insert(node->left,key);
    }
    node->height=1+max(getHeight(node->left),getHeight(node->right));

    int bf=balanceFactor(getHeight(node->left),getHeight(node->right));
    // left left
    if(bf>1 && key < node->left->data){
        node=rightRotation(node);
    }
    //right right
    if(bf<-1 && key > node->right->data){
        node=leftRotation(node);
    }
    // left right
    if(bf>1 && key > node->left->data){
        node->left=leftRotation(node->left);
        node=rightRotation(node);
    }
    // right left
    if(bf<-1 && key < node->right->data){
        node->right=rightRotation(node->right);
        node=leftRotation(node);
    }

    return node;
}
void inorder(struct node* n){
    if(n==NULL){
        return;
    }
    inorder(n->left);
    printf("%d\t",n->data);
    inorder(n->right);

}