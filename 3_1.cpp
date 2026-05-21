/*Given an unsorted array of integers, design an algorithm and a
program to sort the array using insertion sort. Your program
should be able to find number of comparisons and shifts ( shifts
total number of times the array elements are shifted from their
place) required for sorting the array.*/

#include <iostream>
#include <vector>
using namespace std;
void Is(vector<int> &arr , int &comp , int &shift){
    for(int i = 1 ; i < arr.size() ; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            comp++;
            arr[j+1]=arr[j];
            shift++;
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cout<<"Enter the size of vector : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the size of array ";
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        int comp = 0 ;
        int shift = 0;
        Is(arr,comp,shift);
        cout<<"Array after sorting : ";
        for(int x : arr){
            cout<< x << " "; 
        }
        cout<<"Comparisons = "<<comp<<endl;
        cout<<"Shift = "<<shift<<endl;
    }
    return 0;
}
