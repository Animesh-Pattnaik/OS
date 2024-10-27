#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cout << "Enter the number of pages in the string: ";
    cin >> x;
    vector<int> temp(x);
    cout << "Enter the pages: ";
    for (int &page : temp) cin >> page;

    cout << "f\tHit\tFault" << endl;

    for (int n = 1; n <= 7; n++) {
        unordered_map<int, int> fr;
        list<int> f;
        unordered_map<int, list<int>::iterator> pp;
        int ans = 0;

        for (int i = 0; i < x; i++) {
            int page = temp[i];

            if (fr.find(page) != fr.end()) {
                fr[page]++;
                f.erase(pp[page]);
                f.push_back(page);
                pp[page] = --f.end();
            } else {
                ans++;
                if (f.size() == n) {
                    int temp = f.front();
                    for (int p : f) {
                        if (fr[p] < fr[temp]) temp = p;
                    }
                    f.erase(pp[temp]);
                    fr.erase(temp);
                    pp.erase(temp);
                }
                fr[page]++;
                f.push_back(page);
                pp[page] = --f.end();
            }
        }
        cout << n << "\t" << x - ans << "\t" << ans << endl;
    }
}