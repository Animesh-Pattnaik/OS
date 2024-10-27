#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void fcfs(vector<vector<int>>&p){
    sort(p.begin(), p.end());

    int start=0;
    int n=p.size();
    for(int i=0;i<p.size();i++){
        if(start<p[i][0]){
            start=p[i][0];
        }
        start+=p[i][2];
        p[i][3]=start;
    }
    for (int i = 0; i < n; i++){
        p[i][4]=p[i][3]-p[i][0];
        p[i][5]=p[i][4]-p[i][2];
    }
    cout<<"PID"<<"\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"TAT"<<"\t"<<"WT"<<endl;
    for (int i = 0; i < n; i++){
        cout<<p[i][1]<<"\t"<<p[i][0]<<"\t"<<p[i][2]<<"\t"<<p[i][3]<<"\t"<<p[i][4]<<"\t"<<p[i][5]<<endl;
    }
    float tat, wt=0;
    for(int i=0;i<n;i++){
        tat+=p[i][4];
        wt+=p[i][5];
    }
    cout<<"Avg Turn-around time: "<<tat/n<<endl;
    cout<<"Avg Waiting time: "<<wt/n;

}

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<vector<int>> p(n, vector<int>(6,0));

    for (int i = 0; i < n; i++){
        cout<<"Enter arrival time of the process "<<i+1<<" :";
        cin>>p[i][0];
        cout<<"Enter burst time of the process "<<i+1<<" :";
        cin>>p[i][2];
        p[i][1]=i;
    }
    fcfs(p);
}