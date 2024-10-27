#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

bool compareArrivalTime(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

void srtn(vector<vector<int>>& p) {
    int n = p.size();
    sort(p.begin(), p.end(), compareArrivalTime);

    auto compare = [](const vector<int>& a, const vector<int>& b) {
        return a[6] > b[6];  
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

    int time = 0;
    int index = 0;
    float tat = 0, wt = 0;

    while (index < n || !pq.empty()) {
        while (index < n && p[index][0] <= time) {
            p[index][6] = p[index][2];
            pq.push(p[index]);
            index++;
        }

        if (pq.empty()) {
            time = p[index][0];
            continue;
        }

        vector<int> current = pq.top();
        pq.pop();

        int nextArrival = (index < n) ? p[index][0] : INT_MAX;
        int runTime = min(current[6], nextArrival - time);
        time += runTime;
        current[6] -= runTime;

        if (current[6] == 0) {
            current[3] = time;            
            current[4] = current[3] - current[0];  
            current[5] = current[4] - current[2];

            tat += current[4];
            wt += current[5];

            p[current[1]] = current;
        } else {
            pq.push(current);
        }
    }

    cout << "PID" << "\t" << "AT" << "\t" << "BT" << "\t" << "CT" << "\t" << "TAT" << "\t" << "WT" << endl;
    for (const auto& a : p) {
        cout << a[1] << "\t" << a[0] << "\t" << a[2] << "\t" << a[3] << "\t" << a[4] << "\t" << a[5] << endl;
    }

    cout << "Avg Turn-around time: " << tat / n << endl;
    cout << "Avg Waiting time: " << wt / n << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<vector<int>> processes(n, vector<int>(7, 0));

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time of the process " << i + 1 << " :";
        cin >> processes[i][0];
        cout << "Enter burst time of the process " << i + 1 << " :";
        cin >> processes[i][2];
        processes[i][1] = i;
    }
    srtn(processes);
}