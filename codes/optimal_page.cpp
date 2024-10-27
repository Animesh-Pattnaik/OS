// 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6
// 1 2 3 4 5 3 4 1 6 7 8 7 8 9 7 8 9 5 4 5 4 2
#include <bits/stdc++.h>
using namespace std;
int find_optimal_page(const vector<int>& frames, const vector<int>& pages, int current, int total_pages) {
    int farthest = current, ri = -1;
    for (int i = 0; i < frames.size(); i++) {
        auto it = find(pages.begin() + current, pages.end(), frames[i]);
        if (it == pages.end()) return i;
        int idx = distance(pages.begin(), it);
        if (idx > farthest) {
            farthest = idx;
            ri = i;
        }
    }
    return (ri == -1) ? 0 : ri;
}
int main() {
    cout << "Enter the number of pages in the string: ";
    int x; cin >> x;
    vector<int> temp(x);
    for (int& page : temp) cin >> page;
    cout << "Frames\tHit\tFault" << endl;
    for (int n = 1; n <= 7; n++) {
        vector<int> frames;
        int page_faults = 0, hits = 0;
        for (int i = 0; i < x; i++) {
            if (find(frames.begin(), frames.end(), temp[i]) != frames.end()) {
                hits++;
                continue;
            }
            if (frames.size() < n) frames.push_back(temp[i]);
            else frames[find_optimal_page(frames, temp, i + 1, x)] = temp[i];
            page_faults++;
        }
        cout << n << "\t" << hits << "\t" << page_faults << endl;
    }
    return 0;
}