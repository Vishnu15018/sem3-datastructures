#include<iostream>
#include<cmath>
using namespace std;
class Heap{
    public:
            int thesize=0;
            int *arr = new int[80];
    void insert(int x){
            arr[0]=x;
           //  percoilate UP
            int hole = ++thesize;
            // p=floor(hole/2);
            for(;x<arr[hole/2];){

                 arr[hole]=arr[hole/2];
                 hole=hole/2;
                // p=floor(hole/2);
            }
            arr[hole]=x;

    }
    void percolate_down(int hole){
       int last_element=arr[hole];
        int child;
        for(;2*hole<=thesize;hole=child){
            child=2*hole;
           if(child!=thesize && arr[child+1]<arr[child])
                    child=child+1;
            if(arr[child]<last_element)
                    arr[hole]=arr[child];
else
            break;

        }
        arr[hole]=last_element;
    }
     void build_heap(int *a,int n ){
      thesize=n;

      for(int i=0;i<n;i++)
                arr[i+1]=a[i];
     for(int i = floor(thesize/2) ;i>0;i--){
          percolate_down(i);

      }
     //std::cout<<arr[2]<<endl;
 }
    int  delete_min(){

         int hole =1;
         int min_element = arr[1];

         int lastelement=arr[thesize--];
        // percolate_down
        arr[hole]=lastelement;
        percolate_down(hole);


        return min_element;
    }
};
int main(){
int arr[7]={0,12,3,4,6};
Heap h2;
h2.build_heap(arr,5);

 for(int i=1;i<=h2.thesize;i++)
        std::cout<<h2.arr[i]<<" " ;

// std::cout<<endl;
// std::cout<<"THIRD MAXIMUM"<<endl;
//  for(int k=0;k<2;k++){
//     h2.delete_min();
// }
// std::cout<<h2.delete_min()<<endl; 
// for(int i=1;i<=h2.thesize;i++)
//         std::cout<<h2.arr[i]<<" " ;
// 
}
