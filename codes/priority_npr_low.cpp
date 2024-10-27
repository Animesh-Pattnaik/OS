#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void priority(vector<vector<int>> &p)
{
    vector<vector<int>> v = p;
    vector<vector<int>> temp;
    sort(p.begin(), p.end());
    int start = 0;
    int n = p.size();
    int i = 0;
    while (1)
    {
        while (i < n && p[i][0] <= start)
        {
            temp.push_back(p[i]);
            i++;
        }
        auto cbs = [](vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        };
        if (temp.size())
            sort(temp.begin(), temp.end(), cbs);

        if (temp.size())
        {
            vector<int> a = temp[0];
            temp.erase(temp.begin());
            int pr = a[2];
            v[pr][4] = start + v[pr][3];
            start = v[pr][4];
            v[pr][5] = v[pr][4] - v[pr][0];
            v[pr][6] = v[pr][5] - v[pr][3];
        }
        else if (i != n)
        {
            start = p[i][0];
        }
        else
        {
            break;
        }
    }
    cout << "\nThe process on completion gives: \n";
    cout << "PID\tAT\tBT\tPrority\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i][2] + 1 << " \t" << v[i][0] << " \t" << v[i][3] << " \t" << v[i][1] << " \t" << v[i][4] << " \t" << v[i][5] << " \t" << v[i][6] << endl;
    }
    float a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        a += v[i][5];
        b += v[i][6];
    }
    cout << "Avg TAT: " << a / n << endl;
    cout << "Avg WT: " << b / n;
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<vector<int>> v(n, vector<int>(7));

    for (int i = 0; i < n; i++)
    {
        v[i][2] = i;
        cout << "Arrival time, Priority and Burst Time of P" << i + 1 << " : ";
        cin >> v[i][0] >> v[i][1] >> v[i][3];
    }

    priority(v);
}