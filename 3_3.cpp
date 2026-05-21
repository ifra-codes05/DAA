/*Given an unsorted array of positive integers, design an
algorithm and implement it using a program to find whether
there are any duplicate elements in the array or not. (use sorting)
(Time Complexity = O(n log n))*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool found(vector<int> &arr , int n){
    sort(arr.begin(),arr.end());
    for(int i = 1 ; i < n ; i++){
        if(arr[i]==arr[i-1]){
            return true;
        }
    }
    return false;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cout<<"Enter the size of vector :";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of array : ";
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        bool ans = found(arr,n);
        if(ans){
            cout<<"duplicate element are present ";
        }
        else{
            cout<<"duplicate elements are not present ";
        }
    }
    return 0;
}
