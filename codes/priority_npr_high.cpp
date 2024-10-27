#include <bits/stdc++.h>
using namespace std;

void priority(vector<vector<int>> &p) {
    vector<vector<int>> v = p, temp;
    sort(p.begin(), p.end());
    int start = 0, n = p.size(), i = 0;
    while (1) {
        while (i < n && p[i][0] <= start) temp.push_back(p[i++]);
        if (!temp.empty()) sort(temp.begin(), temp.end(), [](auto &a, auto &b) { return a[1] > b[1]; });
        if (!temp.empty()) {
            auto a = temp[0]; temp.erase(temp.begin());
            int pr = a[2];
            v[pr][4] = start += v[pr][3];
            v[pr][5] = v[pr][4] - v[pr][0];
            v[pr][6] = v[pr][5] - v[pr][3];
        } else if (i != n) start = p[i][0];
        else break;
    }
    cout << "\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    float a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        cout << v[i][2] + 1 << " \t" << v[i][0] << " \t" << v[i][3] << " \t" << v[i][1] << " \t" << v[i][4] << " \t" << v[i][5] << " \t" << v[i][6] << endl;
        a += v[i][5], b += v[i][6];
    }
    cout << "Avg TAT: " << a / n << "\nAvg WT: " << b / n;
}

int main() {
    int n;
    cout << "Enter number of processes: "; cin >> n;
    vector<vector<int>> v(n, vector<int>(7));
    for (int i = 0; i < n; i++) {
        v[i][2] = i;
        cout << "AT, Priority, BT of P" << i + 1 << ": "; cin >> v[i][0] >> v[i][1] >> v[i][3];
    }
    priority(v);
}