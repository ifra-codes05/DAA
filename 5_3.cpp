/*You have been given two sorted integer arrays of size m and n.
Design an algorithm and implement it using a program to find
list of elements which are common to both. (Time Complexity =
O(m+n))*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> commonElements(vector<int> &a, vector<int> &b){
    
    int i = 0, j = 0;
    vector<int> ans;

    while(i < a.size() && j < b.size()){

        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i] < b[j]){
            i++;
        }
        else{
            j++;
        }
    }

    return ans;
}

int main(){

    int m, n;

    cout<<"Enter size of first array: ";
    cin>>m;

    vector<int> a(m);

    cout<<"Enter elements of first array:"<<endl;
    for(int i=0;i<m;i++)
        cin>>a[i];

    cout<<"Enter size of second array: ";
    cin>>n;

    vector<int> b(n);

    cout<<"Enter elements of second array:"<<endl;
    for(int i=0;i<n;i++)
        cin>>b[i];

    vector<int> res = commonElements(a,b);

    cout<<"Common elements: ";

    for(int x : res)
        cout<<x<<" ";

    return 0;
}
