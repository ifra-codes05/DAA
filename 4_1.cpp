/*Given an unsorted array of integers, design an algorithm and
implement it using a program to sort an array of elements by
dividing the array into two subarrays and combining these
subarrays after sorting each one of them. Your program should
also find number of comparisons and inversions during sorting
the array.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long comp = 0;
long long inv = 0;
void merge(vector<int> &arr, int start , int mid , int end){
    int i = start , j = mid+1;
    vector<int> temp;
    while(i<=mid && j<=end){
        comp++;
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            inv += (mid-i+1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i = 0 ; i < temp.size(); i++){
        arr[start+i]=temp[i];
    }
}
void ms(vector<int> &arr , int start , int end){
    if(start>=end) return;
    int mid = start + (end - start)/2;
    ms(arr,start,mid);
    ms(arr,mid+1,end);
    merge(arr,start,mid,end);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cout<<"Enter the size of vector : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of vector"<<endl;
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        ms(arr,0,n-1);
        cout<<"Array after sorting : ";
        for( int x : arr){
            cout<<x<<" ";
        }
        cout<<"Comparison = "<<comp<<endl;
        cout<<"Inversion = "<<inv<<endl;
    }
    return 0;
}
