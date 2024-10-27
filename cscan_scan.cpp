#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to calculate the SCAN (Elevator) algorithm
int SCAN(vector<int> requests, int head, int diskSize, bool direction) {
    int seekOperations = 0;
    vector<int> left, right;

    // Separate requests into left and right of the head position
    for (int req : requests) {
        if (req < head) left.push_back(req);
        else right.push_back(req);
    }

    // Sort the requests in ascending order
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    cout << "SCAN Sequence: ";
    if (direction) { // Moving right
        for (int i = 0; i < right.size(); i++) {
            cout << right[i] << " ";
            seekOperations += abs(head - right[i]);
            head = right[i];
        }
        if (!left.empty()) {
            seekOperations += abs(head - (diskSize - 1));
            head = diskSize - 1;
            for (int i = left.size() - 1; i >= 0; i--) {
                cout << left[i] << " ";
                seekOperations += abs(head - left[i]);
                head = left[i];
            }
        }
    } else { // Moving left
        for (int i = left.size() - 1; i >= 0; i--) {
            cout << left[i] << " ";
            seekOperations += abs(head - left[i]);
            head = left[i];
        }
        if (!right.empty()) {
            seekOperations += head;
            head = 0;
            for (int i = 0; i < right.size(); i++) {
                cout << right[i] << " ";
                seekOperations += abs(head - right[i]);
                head = right[i];
            }
        }
    }
    cout << endl;
    return seekOperations;
}

// Function to calculate the C-SCAN (Circular SCAN) algorithm
int CSCAN(vector<int> requests, int head, int diskSize, bool direction) {
    int seekOperations = 0;
    vector<int> left, right;

    for (int req : requests) {
        if (req < head) left.push_back(req);
        else right.push_back(req);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    cout << "C-SCAN Sequence: ";
    if (direction) { // Moving right
        for (int i = 0; i < right.size(); i++) {
            cout << right[i] << " ";
            seekOperations += abs(head - right[i]);
            head = right[i];
        }
        if (!left.empty()) {
            seekOperations += abs(head - (diskSize - 1));
            seekOperations += (diskSize - 1); // Move to the start of the disk
            head = 0;
            for (int i = 0; i < left.size(); i++) {
                cout << left[i] << " ";
                seekOperations += abs(head - left[i]);
                head = left[i];
            }
        }
    } else { // Moving left
        for (int i = left.size() - 1; i >= 0; i--) {
            cout << left[i] << " ";
            seekOperations += abs(head - left[i]);
            head = left[i];
        }
        if (!right.empty()) {
            seekOperations += head; // Move to the start of the disk
            seekOperations += (diskSize - 1);
            head = diskSize - 1;
            for (int i = right.size() - 1; i >= 0; i--) {
                cout << right[i] << " ";
                seekOperations += abs(head - right[i]);
                head = right[i];
            }
        }
    }
    cout << endl;
    return seekOperations;
}

int main() {
    int diskSize, head;
    bool direction;

    // Input disk size and head position
    cout << "Enter disk size: ";
    cin >> diskSize;
    cout << "Enter initial head position: ";
    cin >> head;
    cout << "Enter direction (1 for right, 0 for left): ";
    cin >> direction;

    int n;
    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++) cin >> requests[i];

    // Perform SCAN and C-SCAN algorithms
    int scanSeekCount = SCAN(requests, head, diskSize, direction);
    int cscanSeekCount = CSCAN(requests, head, diskSize, direction);

    cout << "Total seek operations for SCAN: " << scanSeekCount << endl;
    cout << "Total seek operations for C-SCAN: " << cscanSeekCount << endl;

    return 0;
}