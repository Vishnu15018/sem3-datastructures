#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

};
node* create_node(int data){
    node* temp=new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}
node*  insert(node* root,int data){
    if(root==NULL){
        root= create_node(data);
    }
    if(data< root->data){
       root->left= insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;

}
node* search(node* root, int data){
    while(root!=NULL){
        if(data==(root->data)){
             return root;

        }
        else if(data>root->data){
            root=root->right;
        }
        else if(data<root->data){
            root=root->left;
        }
    }
    return NULL;
}
node* find_min(node* root){
    if(root==NULL){
        std::cout<<"Tree is Empty"<<endl;
    }
    else if(root->left==NULL){
        return root;
    }
    else{
        return find_min(root->left);
    }
}

node* delete_tree(node* root,int data){
     node* tempnode=NULL;
     if(root==NULL){
         cout<<"Empty"<<endl;
     }
     else if(data> (root -> data)){
         root->right=delete_tree(root->right,data);
     }
    else if(data<(root -> data)){
         root->left = delete_tree(root->left,data);
     }
     else{
         if(root->left!=NULL && root->right!=NULL){
               tempnode=find_min(root->right);
               root->data=tempnode->data;
               root->right=delete_tree(root->right,root->data);
         }
         else if(root->left==NULL && root->right==NULL){
            tempnode=root;
             delete(tempnode);
             return NULL;
         }
         else if(root->left==NULL){
             root->data=root->right->data;
             root->right=delete_tree(root->right,root->data);
         }
        else if(root->right==NULL){
             root->data=root->left->data;
             root->left=delete_tree(root->left,root->data);
         }


     }
     return root;
}
node* lazy_delete(node *root,int x,node **markptr,int n,int num){
    int i=num;
    markptr[i]=search(root,x);

    if((i+1)<n){
       return root;
    }
    else{
        int arr[n];
        for(int k=0;k<n;k++){
               arr[k]=markptr[k]->data;
        }
        for(int j=0;j<n;j++){
            
            root=delete_tree(root,arr[j]);
        }
        return root;
    }
    
    
}
void print(node* root){
    if(root!=NULL){
        print(root->left);
        std::cout<<root->data<<endl;
        print(root->right);
    }
}

int main(){
    node *root=NULL,*temp=NULL;
    std::cout<<"Enter the no of nodes in a BST"<<endl;
int size=0;
scanf("%d",&size);
std::cout<<"Enter the elments to insert into BST"<<endl;
int a=0;
    for(int i=0;i<size;i++){
        scanf("%d",&a);
        root=insert(root,a);

    }
    std::cout<<"After inserting elements of Bst"<<endl;
    print(root);
    int c=1;
    while(c){
    std::cout<<"Enter 1 to perform delete opeartion 0 to exit"<<endl;

    scanf("%d",&c);
    if(c==1){
    int p;
    std::cout<<"Enter the element you want to delete"<<endl;
     scanf("%d",&p);
  
    root=delete_tree(root,p);
    std::cout<<"After deleting elements of Bst"<<endl;
    
    print(root);
    }
    else{
        break;
    }

    
    }


    int n=0;
    std::cout<<"Enter the limit of lazy deletion"<<endl;
    scanf("%d",&n);
    node* makeptr[n]={NULL};
    int k=1,q=0;
    while(k){
    std::cout<<"Enter 1 to perform lazydelete opeartion 0 to exit"<<endl;

    int m;
    scanf("%d",&k);
   if(k==1){
           std::cout<<"Enter the element you want to delete"<<endl;
scanf("%d",&m);
    root=lazy_delete(root,m,makeptr,n,q);
    q++;
   }
   else{
       break;
   }
    }
    std::cout<<"After lazy_deletion elements of Bst"<<endl;
    
    print(root);
    

}
        if((height(root->left)-height(root->right))>=-1 && (height(root->left)-height(root->right))<=1){
           if(data>root->right->data){
               sin_rot_rightchild(root);
           }
           else{
               double_rot_rl(root);
           }
       }
             if((height(root->left)-height(root->right))>=-1 && (height(root->left)-height(root->right))<=1){
           if(data<root->left->data){
               sin_rot_leftchild(root);
           }
           else{
               double_rot_lr(root);
           }
       }