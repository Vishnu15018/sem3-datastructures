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
void pre_order_traver(node* root) {
  if(root != NULL){
        std::cout << root->data <<" "; // VISIT(DATA);
       
      pre_order_traver(root->left); // TO traverse  THE  left subtree
      pre_order_traver(root->right); // TO traverse THE  right subtree
  }
}
void post_order_traver(node* root) {
  if(root != NULL){
      post_order_traver(root->left); // TO traverse THE  left subtree
      post_order_traver(root->right); // TO traverse THE  right subtree
      
       std::cout << root->data <<" ";  // VISIT(DATA);
  }

}


int main(){
    int n;
    std::cout<<"Enter the size of an array"<<endl;
    scanf("%d",&n);
    int *arr=new int[n];
    std::cout<<"Enter the elements of an array"<<endl;
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    node *root=btree_array_inp(root,arr,0,n);
    std::cout<<"preorder traversal ";
    pre_order_traver(root);
    std::cout<<endl;
    std::cout<<"post order traversal ";
    post_order_traver(root);
    
}




