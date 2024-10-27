#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sjf(vector<vector<int>> &p){
    vector<vector<int>>abc=p;
    vector<vector<int>> temp;

    sort(p.begin(), p.end());

    int start = 0;
    int n = p.size();
    int i = 0;

    while (1){
        while (i<n && p[i][0] <= start){
            temp.push_back(p[i]);
            i++;
        }

        auto compareBySecond = [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        };

        if(temp.size())
        sort(temp.begin(), temp.end(), compareBySecond );

        if(temp.size()){
            vector<int>a=temp[0];
            temp.erase(temp.begin());
            int process=a[1];
            abc[process][3]= start+abc[process][2];
            start=abc[process][3];
            abc[process][4]=abc[process][3]-abc[process][0];
            abc[process][5]=abc[process][4]-abc[process][2];
        }else if(i!=n){
            start=p[i][0];
        }else{
            break;
        }
    }

    cout<<"PID\tAT\tBT\tCT\tTAT\tWT"<<endl;

    for(int i=0;i<n;i++){
        cout<<abc[i][1]+1<<"\t"<<abc[i][0]<<"\t"<<abc[i][2]<<"\t"<<abc[i][3]<<"\t"<<abc[i][4]<<"\t"<<abc[i][5]<<endl;
    }

    float a=0 , b=0;

    for(int i=0;i<n;i++){
        a+=abc[i][4];
        b+=abc[i][5];
    }

    cout<<"Avg tat :"<<a/n<<endl;
    cout<<"Avg wt :"<<b/n;
}

int main()
{
    int n;
    cout << "Enter number of processes:";
    cin >> n;
    vector<vector<int>> p(n, vector<int>(6, 0));

    for (int i = 0; i < n; i++){
        cout << "Enter arrival time of process " << i + 1 << ":";
        cin >> p[i][0];
        cout << "Enter burst time of process " << i + 1 << ":";
        cin >> p[i][2];
        p[i][1] = i;
    }

    sjf(p);
}