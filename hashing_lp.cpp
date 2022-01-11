#include<iostream>
#include<vector>
using namespace std;

class hashing{
	public:
		int tablesize;
			int *hasharray = new int[tablesize];
            //vector<int>hasharray(tablesize);
	    hashing();
	    hashing(int capacity){
	    	tablesize=capacity;
			//hasharray[tablesize];
	    	//hasharray[0]=0;

		}
	
		int hashfunc(int key);
		void insert(int key);
};
int hashing::hashfunc(int key){
     return key%tablesize;
}
void hashing::insert(int key){
	int hashindex=hashfunc(key);
	if(hashindex>=tablesize){
		std::cout<<"hash index value is beyond the size of hash table"<<endl;
	}
   	else{
		while(hasharray[hashindex]!=0){
		
			     hashindex++;
				 hashindex=hashindex%tablesize;
		}
		
	}
	hasharray[hashindex]=key;

}
int main(){
	hashing h1(10);
		    	for(int i=0;i<h1.tablesize;i++){
	    		h1.hasharray[i]=0;
			}
    h1.insert(10);
    h1.insert(20);
    h1.insert(25);
    h1.insert(23);
      h1.insert(5);
    for(int i=0;i<h1.tablesize;i++){
    	std::cout<<h1.hasharray[i]<<"   ";
	}
}
