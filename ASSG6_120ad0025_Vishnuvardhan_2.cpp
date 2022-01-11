#include<iostream>
using namespace std;
class node
{
    public:
      int data;
      node *left;
      node * right;
};
node* create_node(int a){
    node* newnode=new node();
    newnode->data=a;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}


node* btree_array_inp( node* root,int *arr,int i, int n)
{
    if (i < n)
    {
        node* temp = create_node(arr[i]);
        root = temp;
 
        // for  left child
        root->left = btree_array_inp(root->left,arr, 2 * i + 1, n);
 
        // for right child
        root->right = btree_array_inp(root->right,arr, 2 * i + 2, n);
    }
    return root;
}
int same_parent_check(node *root,int m1,int m2){
    if(root==NULL){
        return 0;
    }
    if(root->left !=NULL && root->right!=NULL){
        if(root->left->data == m1 && root->right->data==m2 || root->left->data == m2 && root->right->data==m1){
            return 1;
        }
    }
    if(root->left!=NULL){
        if(same_parent_check(root->left,m1,m2)){
            return 1;
        }
    }
    if(root->right!=NULL){
        if(same_parent_check(root->right,m1,m2)){
            return 1;
        }
    }
}
int Level_Check(node *root,int a,int x){
    if(root==NULL){
        return 0;
    }
 
    if(root->data ==a){
        return x;
    }
    
   int h1= Level_Check(root->left,a,x+1);
   if(h1!=0){
       return h1;
   }
   else{
    return Level_Check(root->right,a,x+1);
   }
}
void check_pair(node* root,int a,int b){
    if(!same_parent_check(root,a,b)&& (Level_Check(root,a,0)==Level_Check(root,b,0))){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
       
}

int main(){
    int n; // n represents no of students
    std::cout<<"Enter the size of an array"<<endl;
    scanf("%d",&n);
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;  //here the students are taken as natural numbers from 1 to n
    }
    node *root=btree_array_inp(root,arr,0,n);

    int c=1,m1,m2;
    while(c){
        cout<<"Enter Member 1 of a team ";
        scanf("%d",&m1);
        cout<<"Enter Member 2 of a team ";
        scanf("%d",&m2);
        check_pair(root,m1,m2);
        cout<<"Enter 1 to check with another input pair otherwise press 0 to exit ";
        scanf("%d",&c);
        cout<<endl;
    }
    
}



