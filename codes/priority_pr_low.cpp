#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void preemptivePriority(vector<vector<int>> &p)
{
    vector<vector<int>> v = p;           // Copy of the input process table
    vector<int> remainingTime(p.size()); // To track remaining burst time of each process
    int n = p.size();
    int completed = 0, start = 0;

    // Initialize remaining burst times for each process
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = p[i][2]; // Burst time
    }

    while (completed != n)
    {
        vector<vector<int>> temp;

        // Find all processes that have arrived by current time and have remaining burst time
        for (int i = 0; i < n; i++)
        {
            if (p[i][0] <= start && remainingTime[i] > 0)
            {
                temp.push_back(p[i]);
            }
        }

        // Sort the processes based on priority, and in case of tie, based on arrival time
        auto cbs = [&](vector<int> &a, vector<int> &b)
        {
            if (a[1] == b[1]) // If priorities are the same, sort by arrival time
                return a[0] < b[0];
            return a[1] < b[1]; // Lower priority value means higher priority
        };

        if (temp.size())
            sort(temp.begin(), temp.end(), cbs);

        if (temp.size())
        {
            int pr = temp[0][4]; // Process ID

            // Execute the process for 1 unit of time
            remainingTime[pr]--;
            start++;

            // If the process is completed, update its completion, TAT, and waiting time
            if (remainingTime[pr] == 0)
            {
                completed++;
                v[pr][3] = start;               // Completion time
                v[pr][4] = v[pr][3] - v[pr][0]; // Turnaround time
                v[pr][5] = v[pr][4] - v[pr][2]; // Waiting time
            }
        }
        else
        {
            start++; // No processes are ready, move time forward
        }
    }

    // Output the result
    cout << "\nThe process completion order is: \n";
    cout << "PID\tAT\tBT\tPrio\tCT\tTAT\tWT" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i][4] + 1 << " \t" << v[i][0] << " \t" << v[i][2] << " \t" << v[i][1] << " \t" << v[i][3] << " \t" << v[i][4] << " \t" << v[i][5] << endl;
    }

    float totalTAT = 0, totalWT = 0;

    for (int i = 0; i < n; i++)
    {
        totalTAT += v[i][4];
        totalWT += v[i][5];
    }

    cout << "Avg TAT: " << totalTAT / n << endl;
    cout << "Avg WT: " << totalWT / n << endl;
}

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<vector<int>> p(n, vector<int>(6, 0));

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time, priority, and burst time of process P" << i + 1 << ": ";
        cin >> p[i][0] >> p[i][1] >> p[i][2];
        p[i][4] = i; // Storing process ID
    }

    preemptivePriority(p);
}
