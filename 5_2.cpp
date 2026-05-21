/*Given an unsorted array of integers, design an algorithm and
implement it using a program to find whether two elements exist
such that their sum is equal to the given key element. (Time
Complexity = O(n log n))*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool findPair(vector<int>& arr, int key) {
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = arr.size() - 1;

    while (i < j) {
        int sum = arr[i] + arr[j];

        if (sum == key) {
            cout << "Pair found: "
                 << arr[i] << " and " << arr[j] << endl;
            return true;
        }
        else if (sum < key) {
            i++;
        }
        else {
            j--;
        }
    }

    return false;
}

int main() {
    int n, key;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter key: ";
    cin >> key;

    if (!findPair(arr, key)) {
        cout << "No such pair exists";
    }

    return 0;
}
