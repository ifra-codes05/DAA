/*Given an unsorted array of alphabets containing duplicate
elements. Design an algorithm and implement it using a
program to find which alphabet has maximum number of
occurrences and print it. (Time Complexity = O(n)) (Hint: Use
counting sort)*/

#include <iostream>
#include<vector>
using namespace std;

void findMaxOcc(vector<char>& arr) {
    vector<int> count(26, 0);

    for (char ch : arr) {
        count[ch - 'a']++;
    }

    int maxCount = 0;
    char result = '\0';

    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            result = char(i + 'a');
        }
    }

    if (maxCount <= 1) {
        cout << "No Duplicates Present\n";
    } else {
        cout << result << " " << maxCount << "\n";
    }
}

int main() {
    int T;
    cin >> T;

    vector<char> arr;  

    while (T--) {
        int n;
        cin >> n;

        char ch;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        arr.push_back(ch);
    }
        findMaxOcc(arr);
    }

    return 0;
}
