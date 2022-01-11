#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include <typeinfo>
using namespace std;



int main(){
    ifstream in("sample1.txt"); // file location
    string d[11]={"int","char","bool","void","float","double","class","struct","union","enum"};
    string ad[4]={"class","struct","union","enum"};
    //string k[4];
    int c[11]={0};
    string str1;
    int k=0;
    
    while(in.eof()==0){
    
        in>>str1;
        if(str1=="int"){        //for checking the datatypes
            c[0]=c[0]+1;
        }
        if(str1=="char"){
            c[1]=c[1]+1;
        }
        if(str1=="bool"){
            c[2]=c[2]+1;
        }
        if(str1=="void"){
            c[3]=c[3]+1;
        }
        if(str1=="float"){
            c[4]=c[4]+1;
        }
        if(str1=="double"){
            c[5]=c[5]+1;
        }
        if(str1=="class"){
            c[6]=c[6]+1;
        }
        if(str1=="struct"){
            c[7]=c[7]+1;
        }
        if(str1=="union"){
            c[8]=c[8]+1;
        }
        if(str1=="enum"){
            c[9]=c[9]+1;
        }
        if(str1=="typedef"){
            c[10]=c[10]+1;
        }
        
        k++;

    }
    cout<<"---------------------------------"<<endl;
    cout<<"|Sr No. | DataType | No. of uses|"<<endl;
    cout<<"---------------------------------"<<endl;
    for(int j=0;j<k;j++){

       std::cout<<j+1<<"          "<< d[j] <<"           "<<c[j]<<"          "<<endl;
       
    }
    in.close();

}

