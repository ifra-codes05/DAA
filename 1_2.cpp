/*Given an already sorted array of positive integers, design an
algorithm and implement it using a program to find whether
given key element is present in the array or not. Also, find total
number of comparisons for each input case. (Time Complexity
= O(nlogn), where n is the size of input).*/

#include<iostream>
#include<vector>
using namespace std;
bool bs(vector<int> &arr , int key , int &comp){
    int l = 0;
    int r = arr.size()-1;
    while(l<=r){
        comp++;
        int mid = l + (r-l)/2;
        if(arr[mid]==key){
            return true;
        }
        else if (arr[mid]>key){
            r = mid -1;
        }
        else{
            l = mid + 1;
        }
    }
    return false;
}
int main(){
    int T ;
    cin>>T;
    while(T--){
        int n , key , comp = 0;
        cout<<"Enter the size of vector : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the values of vector"<<endl;
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        cout<<"Enter key : ";
        cin>>key;
        bool found = bs(arr,key,comp);
        if(found){
            cout<<"key found !, after "<< comp << " comparion" << endl;
        }
        else{
            cout<<" key not found "<<endl;
        }
    }
    return 0;
}
