#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();
    queue<int> firstHalf;

    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    int n, elem;
    queue<int> q;

    cout << "Enter the number of elements (must be even): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Error: Number of elements must be even." << endl;
        return 1;
    }

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> elem;
        q.push(elem);
    }

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    printQueue(q);

    return 0;
}
