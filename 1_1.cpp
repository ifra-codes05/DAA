/*Given an array of nonnegative integers, design a linear
algorithm and implement it using a program to find whether
given key element is present in the array or not. Also, find total
number of comparisons for each input case. (Time Complexity
= O(n), where n is the size of input)*/

#include <iostream>
#include<vector>
using namespace std;
bool ls(vector<int> &arr , int key , int &comp){
    for(int i = 0 ; i < arr.size() ; i++){
        comp++;
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n , key;
        cout<<"Enter the size of vector : ";
        cin>>n;
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        cout<<"Enter key : ";
        cin>>key;
        int comp = 0;
        bool found = ls(arr,key,comp);
        if(found){
            cout<<"key found !, after "<< comp << "comparion" << endl;
        }
        else{
            cout<<" key not found "<<endl;
        }
    }
    return 0;
}
