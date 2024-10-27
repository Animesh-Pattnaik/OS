#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int type;
    cout << "Enter number of resources: ";
    cin >> type;
    vector<vector<int>> allocated(n, vector<int>(type));
    vector<vector<int>> max(n, vector<int>(type));
    vector<int>ans;
    for (int i = 0; i < n; i++){
        cout << "Enter allocated values for process " << i + 1<<": ";
        for (int j = 0; j < type; j++) cin >> allocated[i][j];
        cout << "Enter required value for process " << i + 1<<": ";
        for (int j = 0; j < type; j++) cin >> max[i][j];
    }
    vector<int> available(type);
    cout << " Enter available number for each resources \n";
    for (int i = 0; i < type; i++) cin >> available[i];
    cout<<"Need matrix will be :\n";
    vector<vector<int>> need(n, vector<int>(type));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < type; j++){
            need[i][j] = max[i][j] - allocated[i][j];
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<bool> completed(n, 0);
    while (1){
        bool x=1;
        for (int i = 0; i < n; i++){
            int temp=1;
            for(int j=0;j<type;j++){
                if(need[i][j]>available[j]) temp=0;
            }
            if(temp==1 && completed[i]==0){
                completed[i]=1;
                x=0;
                ans.push_back(i);
                for(int j=0;j<type;j++){
                    available[j]+=allocated[i][j];
                }
            }
        }
        if(x==1) break;
    }
    int safe=1;
    for(int i=0;i<n;i++) if(completed[i]==0) safe=0;
    if(safe==0) cout<<" System is not in safe state \n";
    else {
        cout<<" System is in safe state \n";
        cout<<"Safe sequence will be \n";
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    }
}