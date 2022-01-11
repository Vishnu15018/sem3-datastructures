#include<iostream>
using namespace std;
//template <class T>

class node{
    public:
    int data;
    node* left;
    node* right;


};
node* create_node(int x){
    node* newnode=new node();
    newnode->data=x;
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
node* insert_node(node* root ,int x){
    if(root==NULL){
        root=create_node(x);
        
    }
    else if(x<root->data){
        root->left=insert_node(root->left,x);
    }
    else if(x>root->data){
        root->right=insert_node(root->right,x);
    }
    else{
        //donothing;

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
 node* delete_node(node* root, int x){
    node* tempcell =NULL;
    
    if(root==NULL){
       
        std::cout<<"error"<<endl;
    }
    else if(x<root->data){
        root->left=delete_node(root->left,x);
    }
    else if(x>root->data){
        root->right=delete_node(root->right,x);
    }
    else{
        if(root->left==NULL && root-> right==NULL){
                 tempcell=root;
                 delete(tempcell);
                 return NULL;
        }
        else if(root->left!=NULL && root->right!=NULL){
            tempcell=find_min(root->right);
            root->data=tempcell->data;
            root->right=delete_node(root->right,root->data);
        }

        else if(root->right==NULL){
            root->data=root->left->data;
            root->left=delete_node(root->left,x);
        }
        else if(root->left==NULL){
            root->data=root->right->data;
            root->right=delete_node(root->right,x);
        }
    }

    return root;
}  
 
void inorder(node* root){
    if(root!=NULL){
        
        std::cout<<root->data<<endl;
        inorder(root->left);
        inorder(root->right);
    }
}
int main(){
    node *root=NULL;
    root = insert_node(root,14);
    root = insert_node(root,17);
    root = insert_node(root,16);
    root = insert_node(root,88);
    root = insert_node(root,5);
    //std::cout<<min_term(root)->data;
    inorder(root);
    root=delete_node(root,14);
    std::cout<<"after deleting"<<endl;
    inorder(root);
}