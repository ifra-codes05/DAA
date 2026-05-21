/*Given an array of nonnegative integers, design an algorithm and
a program to count the number of pairs of integers such that
their difference is equal to a given key, K.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countdiff(vector<int> &arr , int n , int k){
    sort(arr.begin(),arr.end());
    int i = 0 , j = 1 , cnt = 0;
    while(j<n){
        int diff = arr[j]- arr[i];
        if(diff==k){
            cnt++;
            i++; 
            j++;
        }
        else if(diff>k){
            i++;
        }
        else{
            j++;
        }
        if(i==j){
            j++;
        }

    }
    return cnt;
}
int main(){
    int T ;
    cin>>T;
    while(T--){
        int n ,k;
        cout<<"Enter the size of vector : ";
        cin>>n;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        cout<<"Enter the diffrence b/w to no.s : ";
        cin>>k;
        int cnt = countdiff(arr,n,k);
        if(cnt>0){
            cout<<"count = "<<cnt<<endl;
        }
        else{
            cout<<"diff not found "<<endl;
        }
    }
    return 0;
}
