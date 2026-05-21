/*Given an unsorted array of integers, design an algorithm and
implement a program to sort this array using selection sort. Your
program should also find number of comparisons and number of
swaps required.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Ss(vector <int> &arr , int &swaps , int &comp , int n){
    for(int i = 0 ; i < n-1 ; i++){
        int midi = i;
        for(int j = i+1 ; j < n ; j++){
            comp++;
            if(arr[j]<arr[midi]){
                midi = j;
            }
        }
        if(midi != i){
            swaps++;
            swap(arr[i],arr[midi]);
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n ;
        cout<<"Enter the size of vector : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the array ";
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        int comp = 0;
        int swap = 0;
        Ss(arr,swap,comp,n);
        for(int x : arr){
            cout<< x << " "; 
        }
        cout<<"Comparisons = "<<comp<<endl;
        cout<<"Swap = "<<swap<<endl;
    }
    return 0;
}
