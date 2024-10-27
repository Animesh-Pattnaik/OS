#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Function to perform Round Robin Scheduling
void rr(vector<vector<int>> &p, int tq) {
    // Copy of the original process list to keep track of results
    vector<vector<int>> abc = p;
    
    // Initialize variables
    int start = 0, i = 0, xyz = -1;
    int n = p.size();
    
    // Sort processes based on Arrival Time (AT)
    sort(p.begin(), p.end());
    
    // Queue to manage processes in Round Robin fashion
    queue<int> q;
    
    // Main loop to simulate the scheduling process
    while (true) {
        // Enqueue processes that have arrived up to the current time 'start'
        while (i < n && p[i][0] <= start) {
            q.push(i++);
        }

        // If there's a process that was preempted, re-add it to the queue
        if (xyz != -1) {
            q.push(xyz);
        }

        // If the queue has processes, simulate execution
        if (!q.empty()) {
            int temp = q.front();
            q.pop();
            
            // Check if the process requires more than the time quantum to complete
            if (p[temp][2] > tq) {
                start += tq;
                p[temp][2] -= tq; // Reduce the remaining burst time
                xyz = temp;        // Mark the process as preempted
            } else {
                // Process will complete within the time quantum
                start += p[temp][2];
                abc[p[temp][1]][3] = start;                          // Completion Time (CT)
                abc[p[temp][1]][4] = abc[p[temp][1]][3] - abc[p[temp][1]][0]; // Turnaround Time (TAT)
                abc[p[temp][1]][5] = abc[p[temp][1]][4] - (abc[p[temp][1]][2] - p[temp][2]); // Waiting Time (WT)
                p[temp][2] = 0; // Set remaining burst time to 0
                xyz = -1;       // Reset preempted process
            }
        } else if (i != n) {
            // If no processes are in the queue but some have yet to arrive
            start = p[i][0];
        } else {
            // All processes are completed
            break;
        }
    }

    // Calculate and display average Turnaround Time (TAT) and Waiting Time (WT)
    float a = 0, b = 0;
    cout << "PID\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++) {
        cout << abc[i][1] + 1 << "\t" << abc[i][0] << "\t" << (abc[i][2] - p[abc[i][1]][2]) << "\t" << abc[i][3] << "\t" << abc[i][4] << "\t" << abc[i][5] << endl;
        a += abc[i][4];
        b += abc[i][5];
    }
    cout << "Avg TAT: " << a / n << endl;
    cout << "Avg WT: " << b / n << endl;
}

int main() {
    int n, tq;

    // Input number of processes
    cout << "Enter number of processes: ";
    cin >> n;

    // Initialize process data structure
    vector<vector<int>> p(n, vector<int>(6, 0));

    // Input Arrival Time (AT) and Burst Time (BT) for each process
    for (int i = 0; i < n; i++) {
        cout << "Enter AT and BT of process " << i + 1 << ": ";
        cin >> p[i][0] >> p[i][2];
        p[i][1] = i; // Process ID
    }

    // Input Time Quantum
    cout << "Enter the value of time quantum: ";
    cin >> tq;

    // Call the Round Robin scheduler
    rr(p, tq);

    return 0;
}
