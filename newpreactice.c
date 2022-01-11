#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int delete;
    struct node *left;
    struct node *right;
};

struct node* create_node(int d){
    struct node *n;
    n = malloc(sizeof(struct node));
    n->data = d;
    n->delete = 0;
    n->left = NULL;
    n->right = NULL;
}

struct node* find_min(struct node *root){
    struct node *t;
    if(root->left == NULL){
        t = root;
    }
    else{
        t = find_min(root->left);
    }
    return t;
}

struct node* search(int d, struct node *root){
    struct node *temp;
    if(root != NULL){
        if(d == root->data){
            temp = root;
        }
        else if(d > root->data){
            temp = search(d, root->right);
        }
        else if(d < root->data){
            temp = search(d, root->left);
        }
        else{
            temp = NULL;
        }
    }
    return temp;
}

struct node* insert(int d, struct node *root){
    if(root == NULL){
        root = create_node(d);
    }
    else{
        if(d > root->data){
            root->right = insert(d, root->right);
        }
        else{
            root->left = insert(d, root->left);
        }
    }
    return root;
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d (%d) ", root->data, root->delete);
        inorder(root->right);
    }
}

struct node* delete(int d, struct node *root){
    struct node *t, *temp;
    if(root == NULL){
        printf("error\n");
    }
    else if(d > root->data){
        root->right = delete(d, root->right);
    }
    else if(d < root->data){
        root->left = delete(d, root->left);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->right != NULL && root->left != NULL){
            temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete(temp->data, root->right);
            return root;
        }
        else{
            if(root->right == NULL){
                t = root->left;
                free(root);
                return t;
            }
            else{
                t = root->right;
                free(root);
                return t;
            }
        }
    }
    return root;
}

struct node* pre_delete(struct node *root){
    if(root != NULL){
        root->left = pre_delete(root->left);
        root->right = pre_delete(root->right);
        if(root->delete == 1){
            root = delete(root->data, root);
            return root;
        }
    }
    return root;
    
}

void lazy_delete(int d, struct node *root, int max, int i){
    if((i + 1) < max){
        struct node* temp;
        temp = search(d, root);
        temp->delete = 1;
    }
    else{
        struct node* temp;
        temp = search(d, root);
        temp->delete = 1;
        pre_delete(root);
    }
}

int main()
{
    int i = 0, max;
    struct node *root, *t;
    root = create_node(25);
    //insertion
    root = insert(20, root);
    root = insert(30, root);
    root = insert(10, root);
    root = insert(22, root);
    root = insert(27, root);
    root = insert(38, root);
    root = insert(5, root);
    root = insert(11, root);
    root = insert(21, root);
    root = insert(24, root);
    printf("after insertion : ");
    inorder(root);
    root = delete(30, root);
    root = delete(24, root);
    printf("\n after deletion : ");
    inorder(root);
    t = search(21, root);
    printf("\nsearched node data = %d", t->data);
    printf("\nafter lazy deletion if we delete elements less number than our threshold\n element which will be deleted after our limint will be marked as :\n element (1)");
    max = 4; //here our threshold  = 4;
    lazy_delete(5, root, max, 0);
    lazy_delete(38, root, max, 1);
    lazy_delete(22, root, max, 2);
    printf("\n after 3rd lazy deletion: ");
    inorder(root);
    lazy_delete(27, root, max, 3);
    printf("\nafter 4th lazy deletion: ");
    inorder(root);
}