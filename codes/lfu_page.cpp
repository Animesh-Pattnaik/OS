#include <bits/stdc++.h>
using namespace std;

int main() {
    int numPages;
    cout << "Enter the number of pages in the string: ";
    cin >> numPages;

    vector<int> pages(numPages);
    cout << "Enter the pages: ";
    for (int &page : pages) {
        cin >> page; // Read each page into the vector
    }

    cout << "Frames\tHit\tFault" << endl;

    for (int frameSize = 1; frameSize <= 7; frameSize++) {
        unordered_map<int, int> frequency;
        vector<int> order;                 
        int faults = 0;                  

        for (int i = 0; i < numPages; i++) {
            int currentPage = pages[i];

            if (frequency.find(currentPage) != frequency.end()) {
                frequency[currentPage]++;
                auto it = find(order.begin(), order.end(), currentPage);
                if (it != order.end()) {
                    order.erase(it);    
                }
                order.push_back(currentPage);
            } else {
                faults++;

                if (order.size() == frameSize) {
                    int lfuPage = order[0];

                    for (int p : order) { 
                        if (frequency[p] < frequency[lfuPage]) {
                            lfuPage = p;
                        }
                    }

                    order.erase(find(order.begin(), order.end(), lfuPage)); 
                    frequency.erase(lfuPage);
                }

                frequency[currentPage]++;            
                order.push_back(currentPage);         
            }
        }
    
        cout << frameSize << "\t" << numPages - faults << "\t" << faults << endl;
    }

    return 0;
}
