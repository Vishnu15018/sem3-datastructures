#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include <typeinfo>
using namespace std;



int main(){
    ifstream in("sample1.txt"); // file location
    string d[6]={"int","char","bool","void","float","double"};
    string ad[4]={"class","struct","union","enum"};
    string adv[15];
    int c[6]={0};
    int cd[15]={0};
    string str1;
    int k=0;
    string file[1000];
    while(in.eof()==0){
    
        in>>str1;
        for(int i=0;i<6;i++){
            if(str1==d[i]){
                c[i]=c[i]+1;
            }
        }
        file[k]=str1;
        
        k++;

    }
    int  v=0;
    for(int i=0;i<1000;i++){
        for(int l=0;l<4;l++){
            if(ad[l]==file[i]){
                adv[v]=file[i+1];
                v++;
            }
        }
    }
    for(int i=0;i<1000;i++){
        for(int l=0;l<v;l++){
            if(adv[l]==file[i]){
                cd[l]=cd[l]+1;
            }
        }
    }
    cout<<"|Sr No. | DataType | No. of uses|"<<endl;
    
    for(int j=0;j<6;j++){

       std::cout<<j+1<<"          "<< d[j] <<"           "<<c[j]<<"          "<<endl;
       
    }int m=7;
    for(int j=0;j<v;j++){

       std::cout<<m<<"          "<< adv[j] <<"           "<<cd[j]<<"          "<<endl;
       m++;
    }
    in.close();

}

