#include<iostream>

#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
     std::string name;
     int IP;
};


int main ()
{
	std::vector<int> vec { 10, 20, 30, 40 };
	
	// Iterator used to store the position
	// of searched element
	std::vector<int>::iterator it;
	
	// Print Original Vector
	std::cout << "Original vector :";
	for (int i=0; i<vec.size(); i++)
		std::cout << " " << vec[i];
		
	std::cout << "\n";
	
	// Element to be searched
	int ser = 30;
	
	// std::find function call
	it = std::find (vec.begin(), vec.end(), ser);
	if (it != vec.end())
	{
		std::cout << "Element " << ser <<" found at position : " ;
		std::cout << it - vec.begin() << " (counting from zero) \n" ;
	}
	else
		std::cout << "Element not found.\n\n";
		
	return 0;
}

/* int main(){
    node n1;
    node n2;
      n1.name="123";
    n1.IP=123345;
    n2.name="vishnu";
    n2.IP=123456;
    std::vector < node> vec1;
    vec1.push_back(n1);
    std::vector<node>::iterator it;
    it= std::find(vec1.begin(),vec1.end(),n1);
  if(it!=vec1.end()){
      std::cout<<"The elemnt is present"<<std::endl;
      
  }
  else{
      std::cout<<"The element is not present"<<std::endl;
  }
  

    std::cout<<vec1[0].name<<"  "<<vec1[0].IP<<std::endl;
}
 */