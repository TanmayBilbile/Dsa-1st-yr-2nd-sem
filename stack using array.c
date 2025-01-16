#include<stdio.h>


int push(int value,int top,int *arr,int n){
    if(top== n-1){
        printf("Overflow\n");
        return top;
    }else{
        top++;
        arr[top]=value;
        return top;
        
    }
}
void display(int *arr,int top){
    if(top==-1){
        printf("Stack is empty\n");
        return ;
    }
    while(top>=0){
        printf("%d\t",arr[top]);
        top--;
    }
    printf("\n");
}
int pop(int top,int *arr){
    if(top!=-1){
    printf("%d\t",arr[top]);
    top--;
    }else{
        printf("Underflow stack is empty");
    }

    return top;
}


int main(){
    int n;
    printf("Enter size of stack : ");
    scanf("%d",&n);
    int stack[n];
    int top=-1;
    int insert;
    printf("how many values you want to push : ");
    scanf("%d",&insert);
    for(int i=1;i<=insert;i++){
        int value;
        printf("Enter value : ");
        scanf("%d",&value);
        top=push(value,top,stack,n);
    }
    display(stack,top);

    int delete;
    printf("Enter how many values you want to pop : ");
    scanf("%d",&delete);
    printf("Popped elements : ");
    for(int i=1;i<=delete;i++){
       top=pop(top,stack);
    }
    printf("\n");
    display(stack,top);


}    