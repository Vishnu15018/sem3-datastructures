
#include <iostream> //I/O
#include <vector> // container
#include <algorithm> // sorting//
using namespace std;
int main() 
{ int input; 
vector<int> ivec; // input
while (cin >> input ) 
ivec.push_back(input);// 
sort(ivec.begin(), ivec.end());
// output
vector<int>::iterator it1;
for ( it1 = ivec.begin();it1 != ivec.end(); ++it )
{cout << *it1 << " ";} 
cout <<endl;
return 0;
    
}