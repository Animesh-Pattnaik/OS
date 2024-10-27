#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void rr(vector<vector<int>> &p, int tq){
    vector<vector<int>> abc = p;
    int start = 0, i = 0 ,xyz = -1;
    int n = p.size();
    sort(p.begin(), p.end());
    queue<int> q;
    while (1){
        while (i < n && p[i][0] <= start) q.push(i++);
        if (xyz != -1) q.push(xyz);
        if (q.size()){
            int temp = q.front();
            q.pop();
            if (p[temp][2] > tq){
                start += tq;
                p[temp][2] -= tq;
                xyz = temp;
            }
            else{
                start += p[temp][2];
                abc[p[temp][1]][3] = start;
                abc[p[temp][1]][4] = abc[p[temp][1]][3] - abc[p[temp][1]][0];
                abc[p[temp][1]][5] = abc[p[temp][1]][4] - abc[p[temp][1]][2];
                p[temp][2] = 0;
                xyz = -1;
            }
        }
        else if (i != n) start = p[i][0];
        else break;
    }
    float a = 0, b = 0;
    cout << "PID\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++){
        cout << abc[i][1] + 1 << "\t" << abc[i][0] << "\t" << abc[i][2] << "\t" << abc[i][3] << "\t" << abc[i][4] << "\t" << abc[i][5] << endl;
        a += abc[i][4];
        b += abc[i][5];
    }
    cout << "Avg tat :" << a / n << endl;
    cout << "Avg wt :" << b / n;
}
int main(){
    int n , tq;
    cout << "Enter number of processes:";
    cin >> n;
    vector<vector<int>> p(n, vector<int>(6, 0));
    for (int i = 0; i < n; i++){
        cout << "Enter AT and BT of process " << i + 1 << ":";
        cin >> p[i][0]>>p[i][2];
        p[i][1] = i;
    }
    cout << "Enter the value of time quantum:";
    cin >> tq;
    rr(p, tq);
}