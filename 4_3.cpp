/*Given an unsorted array of integers, design an algorithm and
implement it using a program to find Kth smallest or largest
element in the array. (Worst case Time Complexity = O(n))*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find(vector<int> &arr , int k , int n){
    if(k > n || k <= 0) return -1;
    sort(arr.begin(),arr.end());
    int num = arr[n-k];
    return num;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n , k;
        cout<<"Enter the size of array : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of array"<<endl;
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        cout<<"Enter the Kth largest element : ";
        cin>>k;
        int num = find(arr,k,n);
        cout<<"Kth largest element is "<<num<<endl;
    }
    return 0;
}
