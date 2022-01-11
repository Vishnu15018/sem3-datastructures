/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class node{
    public:
      int data;
      node *left;
      node* right;
};
node* create_node(int data){
    node* newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* search(node* root, int data){
    while(root){
        if(root->data==data){
            return root;
        }
        else if(data<root->data){
            root=root->left;
        }
        else if(data>root->data){
            root=root->right;
        }
    }
    return NULL;
}
node* insert(node* root, int data){
    if(root==NULL){
        root=create_node(data);
    }
    else if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    else{
        return NULL;
    }
    return root;
}
node* find_min(node* root){
    if(root==NULL){
        std::cout<<"EMpty BST"<<endl;
    }
    if(root->left==NULL){
        return root;
    }
    else{
        return find_min(root->left);
    }
}
node* Delete(node* root,int data){
    node* tempptr=NULL;
    if(search(root,data)){
       if(root==NULL){
            std::cout<<"EMPTY BST"<<endl;
       } 
       else if(data<root->data){
            root->left=Delete(root->left,data);
       }
        else if(data>root->data){
            root->right=Delete(root->right,data);
       }
       else{
           if(root->left==NULL && root->right==NULL){
               tempptr=root;
               delete(tempptr);
               return NULL;
           }
           else if(root->left!=NULL && root->right!=NULL){
               tempptr=find_min(root->right);
               root->data=tempptr->data;
               root->right=Delete(root->right,root->data);
           }
           else if(root->right==NULL){
               root->data=root->left->data;
               root->left=Delete(root->left,root->data);
           }
        else if(root->left==NULL){
               root->data=root->right->data;
               root->right=Delete(root->right,root->data);
           }
       }
    }
    else{
        std::cout<<"THE ELEMENT IS NOT PRESENT"<<endl;
    }
    return root;
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        std::cout<<root->data<<endl;

        inorder(root->right);
    }
}
node* lazy_delete(node *root,int data,int *arr,int n,int i){
    if(search(root,data)){
        if(i<n){
           arr[i-1]=data; 
        }
        else{
            for(int k=0;k<n;k++){
                root=Delete(root,arr[i]);
            }
        }
    }
    else{
        std::cout<<"The element is not present in tree"<<endl;
    }
    return root;
}
int main()
{   node* root=NULL;
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,12);
    root=insert(root,9);
    root=insert(root,35);
    //cout<<"Hello World";
    //inorder(root);
    root=Delete(root,20);
    inorder(root);

    return 0;
}
