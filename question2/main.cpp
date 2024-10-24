#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printNGE(vector<int> &arr) {
    stack<int> s;
    vector<int> nge(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() {
    int n, elem;
    vector<int> arr;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> elem;
        arr.push_back(elem);
    }

    printNGE(arr);

    return 0;
}
