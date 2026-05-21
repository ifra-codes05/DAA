/*Given an unsorted array of integers, design an algorithm and
implement it using a program to sort an array of elements by
partitioning the array into two subarrays based on a pivot
element such that one of the sub array holds values smaller than
the pivot element while another sub array holds values greater
than the pivot element. Pivot element should be selected
randomly from the array. Your program should also find number
of comparisons and swaps required for sorting the array*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int comp = 0;
int swaps = 0;
int find_pivot(vector<int> &arr, int st , int end){
    int idx = st - 1;
    int pivot = arr[end];
    for(int j = st ; j < end ; j++){
        comp++;
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j],arr[idx]);
            swaps++;
        }
    }
    swap(arr[idx+1],arr[end]);
    swaps++;
    return idx+1;
}
void qs(vector<int> &arr,int st , int end){
    if(st>=end) return;
    int pvt_indx = find_pivot(arr,st,end);
    qs(arr,st,pvt_indx-1);
    qs(arr,pvt_indx+1,end);

}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cout<<"Enter the size of vector : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of vector "<<endl;
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        qs(arr,0,n-1);
        cout<<"Array after sorting : ";
        for(int x : arr){
            cout<<x<<" ";
        }
        cout<<"comparison = "<<comp<<endl;
        cout<<"swap = "<<swaps<<endl;
    }
    return 0;
}
