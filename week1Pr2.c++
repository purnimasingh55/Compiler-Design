#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    string str;
    cout<<"Enter a string of your choice: ";
    cin>>str;
    int l = str.length();
    //for(int i = l;i>0;i--){
        if(str[l-1]==str[l-2]){
            cout<<"Input string is accepted.";
        }
        else{
            cout<<"Input string is not accepted";
        }
    
}