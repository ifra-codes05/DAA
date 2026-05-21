/*Given a sorted array of positive integers, design an algorithm
and implement it using a program to find three indices i, j, k
such that arr[i] + arr[j] = arr[k].*/

#include<iostream>
#include<vector>
using namespace std;
bool seq(vector<int> &arr , int n){
    for(int k = n-1 ; k >= 0 ; k--){
        int i = 0 ; 
        int j = k-1;
        while(i < j){
            int sum = arr[i] + arr[j];

            if(sum == arr[k]){
                cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<endl;
                return true;
            }
            else if(sum < arr[k]){
                i++;
            }
            else{
                j--;
            }
        }
    }
    return false;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cout<<"Enter the size of vector : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of vector : "<<endl;
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        bool found = seq(arr,n);
        if(0){
            cout<<"Sequence not found ! "<<endl;
        }
    }
    return 0;
}
