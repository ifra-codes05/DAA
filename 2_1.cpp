/* Given a sorted array of positive integers containing few
duplicate elements, design an algorithm and implement it using
a program to find whether the given key element is present in
the array or not. If present, then also find the number of copies
of given key. (Time Complexity = O(log n))*/

#include <iostream>
#include <vector>
using namespace std;
int firstocc(vector<int> &arr , int key , int n){
    int result = -1;
    int l = 0 ; 
    int r = n-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid]==key){
            result = mid;
            r = mid - 1;
        }
        else if(arr[mid]<key){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return result;
}
int lastocc(vector<int> &arr , int key , int n){
    int result = -1;
    int l = 0 ; 
    int r = n-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid]==key){
            result = mid;
            l = mid+1;
        }
        else if(arr[mid]<key){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return result;
}
int main(){
    int T ;
    cin>>T;
    while(T--){
        int n,key;
        cout<<"Enter the size of vector : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of vector "<<endl;
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        cout<<"Enter key : ";
        cin>>key;
        int f = firstocc(arr,key,n);
        if(f==-1){
            cout<<"key not found ";
        }
        else{
            int l = lastocc(arr,key,n);
            int count = l-f+1;
            cout<<key<<" - "<<count<<endl;
        }
    }
    return 0;
}
