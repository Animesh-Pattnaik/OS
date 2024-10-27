#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the size of each process: ";
    vector<int> pr(n);
    for (int i = 0; i < n; i++) {
        cin >> pr[i];
    }

    int block;
    cout << "Enter the number of blocks: ";
    cin >> block;
    cout << "Enter the size of each block: ";
    vector<vector<int>> bl(block, vector<int>(2));
    for (int i = 0; i < block; i++) {
        cin >> bl[i][0];
        bl[i][1] = i + 1;
    }

    sort(bl.begin(), bl.end());

    vector<int> allocation(n, -1);

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < block; j++) {
            if (bl[j][0] >= pr[i]) {
                if (bestIdx == -1 || bl[j][0] > bl[bestIdx][0]) {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bl[bestIdx][1];
            bl[bestIdx][0] -= pr[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << pr[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << allocation[i] << endl;
        } else {
            cout << "Not Allocated" << endl;
        }
    }

    return 0;
}