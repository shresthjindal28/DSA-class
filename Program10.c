#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
       struct node *left,*right;
};
struct node *create(int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
struct node *insertNode(struct node *root,int data){
     struct node *newnode;
    newnode=create(data);
    if(root==NULL){
        root=newnode;
        return root;
    }
    if(root->data > data){
        root->left=insertNode(root->left,data);
    }
    if(root->data < data){
        root->right=insertNode(root->right,data);
    }
    return root;
}
int inorder(struct node *root){
    if(root==NULL){
        return 0;
    }
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
}
int preorder(struct node *root){
    if(root==NULL){
        return 0;
    }
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int postorder(struct node *root){
    if(root==NULL){
        return 0;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
}
int searchNode(struct node *root,int key){
    if(root==NULL){
        return 0;
    }
    if(root->data==key){
        return 1;
    }
    if(root->data>key){
        return searchNode(root->left,key);
    }
        if(root->data<key){
        return searchNode(root->right,key);
    }
}
int main(){
    int choice,n,key;
    int val;
    struct node *root=NULL;
    
    while(choice!=4){
        printf("\n1.Create BST");
        printf("\n2.Traverse BST(inorder/preorder/postorder)");
        printf("\n3.Search Key element");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nEnter the number of elements:");
                   scanf("%d",&n);
                   for(int i=1;i<=n;i++){
                    printf("\nEnter element %d",i);
                    scanf("%d",&val);
                    root=insertNode(root,val);
                   }
                   break;
            case 2:printf("\nInorder:");
                   inorder(root);
                   printf("\nPre-order:");
                   preorder(root);
                   printf("\nPost-order:");
                   postorder(root);
                   break;
            case 3:printf("\nEnter value you waant to search:");
                   scanf("%d",&key);
                   int result=searchNode(root,key);
                   if(result==0){
                    printf("\nElement not found");
                   }
                   else{
                    printf("\nElemet found");
                   }
                   break;
            case 4:printf("\nExiting the program");
                    exit(0);
        }
    }

}