#include <bits/stdc++.h>
using namespace std;

void roundRobin(vector<vector<int>> &p, int tq, int cs)
{
    int n = p.size(), time = cs, completed = 0, prev = -1;
    vector<int> rbt(n), inQueue(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
        rbt[i] = p[i][2];

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
            if (p[i][0] <= time && !inQueue[i] && rbt[i] > 0)
                q.push(i), inQueue[i] = 1;

        if (!q.empty())
        {
            int idx = q.front();
            q.pop();
            if (prev != idx)
                time += cs;
            prev = idx;
            time += min(tq, rbt[idx]);
            rbt[idx] -= min(tq, rbt[idx]);
            if (!rbt[idx])
                p[idx][3] = time, completed++;
            if (rbt[idx])
                q.push(idx);
        }
        else
            time++;
    }

    for (int i = 0; i < n; i++)
        p[i][4] = p[i][3] - p[i][0], p[i][5] = p[i][4] - p[i][2];
    cout << "PiD\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
        cout << p[i][1] << "\t" << p[i][0] << "\t" << p[i][2] << "\t" << p[i][3] << "\t" << p[i][4] << "\t" << p[i][5] << endl;
}

int main()
{
    int n, tq, cs;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter Context Switching Time: ";
    cin >> cs;
    vector<vector<int>> p(n, vector<int>(6, 0));

    for (int i = 0; i < n; i++)
    {
        p[i][1] = i + 1;
        cout << "Enter arrival time and burst time for P" << i + 1 << ": ";
        cin >> p[i][0] >> p[i][2];
    }

    cout << "Enter time quantum: ";
    cin >> tq;
    roundRobin(p, tq, cs);
}