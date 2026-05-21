/*Given an already sorted array of positive integers, design an
algorithm and implement it using a program to find whether a
given key element is present in the sorted array or not. For an
array arr[n], search at the indexes arr[0], arr[2],
arr[4], .... ,arr[2k] and so on. Once the interval (arr[2k] < key <
arr[ 2k+1] ) is found, perform a linear search operation from the
index 2k to find the element key. (Complexity < O(n), where n
is the number of elements need to be scanned for searching):
Jump Search*/

#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;
bool jumpSearch(vector<int> &arr , int key , int &comp , int n){
    int step = sqrt(n);
    int prev = 0;
    while(prev < n && arr[min(step,n)-1]<key){
        comp++;
        prev = step;
        step += sqrt(n);
        if(prev>=n){
            return false;
        }
    }
    for(int i = prev ; i < min(step,n) ; i++){
        comp++;
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}
int main(){
    int t;
    cout<<"Enter number of test cases : ";
    cin>>t;
    while(t--){
        int n , comp = 0;
        cout<<"Enter the size of array : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of array : ";
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        int key;
        cout<<"Enter key : ";
        cin>>key;
        bool found = jumpSearch(arr,key,comp,n);
        if(found){
            cout<<"Key found at "<<comp<<" Comparison ";
        }
        else{
            cout<<"Key not found ";
        }
    }
}
