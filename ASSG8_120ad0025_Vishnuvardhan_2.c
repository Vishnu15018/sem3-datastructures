
#include<stdio.h>
#include<stdlib.h>
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
struct node{
    int data;
     int height;
    struct node* left;
    struct node* right;
   
};
int height(struct node *root){
    if(root==NULL){
         return -1;
    }
    else{
        return (root->height);
    }
}
struct node* create_node(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=0;
    return temp;
}
struct node* sin_rot_leftchild(struct node *k2){
    struct node* k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k1->height=1+max(height(k1->left),height(k1->right));
    k2->height=1+max(height(k2->left),height(k2->right));
    k2=k1;
    return k1;

}
struct node* sin_rot_rightchild(struct node *k2){
    struct node* k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k1->height=1+max(height(k1->left),height(k1->right));
    k2->height=1+max(height(k2->left),height(k2->right));
    k2=k1;
    return k1;

}
struct node* double_rot_lr(struct node *k3){
      k3->left=sin_rot_rightchild(k3->left);
      k3=sin_rot_leftchild(k3);
      return k3;
}
struct node* double_rot_rl(struct node *k3){
      k3->right=sin_rot_leftchild(k3->right);
      k3=sin_rot_rightchild(k3);
      return k3;
}

struct node*  insert(struct node* root,int data){
    if(root==NULL){
        root= create_node(data);
    }
    else if(data< root->data){
       root->left= insert(root->left,data);
       
      if(!((height(root->left)-height(root->right))>=-1 && (height(root->left)-height(root->right))<=1)){
           if(data<root->left->data){
               root=sin_rot_leftchild(root);
           }
           else{
               root=double_rot_lr(root);
           }
       }
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
        
        if(!((height(root->left)-height(root->right))>=-1 && (height(root->left)-height(root->right))<=1)){
           if(data>root->right->data){
               root=sin_rot_rightchild(root);
           }
           else{
               root=double_rot_rl(root);
           }
       }
    }
    root->height=1+max(height(root->left),height(root->right));
    return root;

}
void preorder(struct node* root){
    if(root!=NULL){
        
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
        struct node *root=NULL,*temp1=NULL,*temp2=NULL;
root=insert(root,12);
root=insert(root,15);
root=insert(root,10);
root=insert(root,9);
root=insert(root,8); 
    
    printf("Height and preorder after rotations respectively \n");
    printf("Height: %d \n",root->height);
    printf("Preorder : \n");
    preorder(root);
}