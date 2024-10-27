// 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6
// 1 2 3 4 5 3 4 1 6 7 8 7 8 9 7 8 9 5 4 5 4 2
#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cout << "Enter no of pages in string: ";
    cin >> x;
    vector<int> temp(x);
    for (int &page : temp)
        cin >> page;
    cout << "Frames\tHit\tFault" << endl;
    for (int n = 1; n <= 7; n++){
        vector<int> frames;
        int pagefaults = 0;
        for (int i = 0; i < x; i++){
            int page = temp[i];
            auto it = find(frames.begin(), frames.end(), page);
            if (it != frames.end()){
                frames.erase(it);
                frames.push_back(page);
            }else{
                pagefaults++;
                if (frames.size() == n)
                    frames.erase(frames.begin());
                frames.push_back(page);
            }
        }
        cout << n << "\t" << x - pagefaults << "\t" << pagefaults << endl;
    }
}