#include<iostream>

using namespace std;

class node{
	public:
		int key;

        
		node* nxt;
		
};
node* create_node(int data){
	node *newnode = new node();

	newnode->key=data;
	newnode->nxt=NULL;
	return newnode;
}
node* insert_end(node* head, int data){
	if(head==NULL){

	    head = create_node(data);   
	}
	else{

	node* k=head;
	node* prev=head;
		while(k!=NULL){
		prev=k;
	    k=k->nxt;
	}
	prev->nxt=create_node(data);
}
return head;
}
class hashing{
	public:
		int tablesize ;
		node *hasharray[];
		
		hashing(int capacity){
			
			tablesize=capacity;
			hasharray[capacity];
			for(int i=0;i<tablesize;i++){
				hasharray[i]=NULL;
			}
		}
		int hash_func(node* item){
			return (item->key % tablesize);
		}
		void insert(node* item){
			int hashindex=hash_func(item);
			hasharray[hashindex]=insert_end(hasharray[hashindex],item->key);
			//std::cout<<item->key<<endl;
		}
		node*  find(node* item){
			int hashindex=hash_func(item);
			node* k =hasharray[hashindex];
			while(k!=NULL){
				if(k->key==item->key){
					return item;
				}
				k=k->nxt;
			}
			return NULL;
		}
      
};
int main(){
	hashing h1(10);
	node* item1=create_node(20);
	node* item2=create_node(1);
		node* item3=create_node(30);
				node* item4=create_node(40);

	h1.insert(item1);
	h1.insert(item2);
	h1.insert(item3);
	h1.insert(item4);
	node* d =h1.find(item4);
	std::cout<<d->key<<endl;
	//std::cout<<item2<<endl;
    //h1.print();
}
