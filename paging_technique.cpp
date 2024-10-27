#include <iostream>
#include <vector>
using namespace std;

// Function to simulate paging technique
void pagingTechnique(int totalPages, int pageSize, int totalFrames) {
    vector<int> pageTable(totalPages, -1);  // Page table initialized to -1 (no mapping yet)
    vector<bool> framesAllocated(totalFrames, false);  // Keeps track of allocated frames

    // Assign frames to pages
    for (int i = 0; i < totalPages; i++) {
        int frameNumber;
        cout << "Enter frame number to allocate for page " << i << " (0 to " << totalFrames - 1 << "): ";
        cin >> frameNumber;
        
        if (frameNumber >= 0 && frameNumber < totalFrames && !framesAllocated[frameNumber]) {
            pageTable[i] = frameNumber;  // Map the page to the frame
            framesAllocated[frameNumber] = true;  // Mark the frame as allocated
        } else {
            cout << "Invalid or already allocated frame! Try again.\n";
            i--;  // Repeat this iteration
        }
    }

    // Display the page table (page-to-frame mapping)
    cout << "\nPage Table (Page -> Frame):\n";
    for (int i = 0; i < totalPages; i++) {
        cout << "Page " << i << " -> Frame " << pageTable[i] << endl;
    }

    // Logical to Physical Address Translation
    int logicalAddress;
    cout << "\nEnter a logical address to translate (in the format 'page_number offset'):\n";
    int pageNumber, offset;
    while (cin >> pageNumber >> offset) {
        if (pageNumber >= 0 && pageNumber < totalPages && offset >= 0 && offset < pageSize) {
            int frameNumber = pageTable[pageNumber];
            if (frameNumber != -1) {
                int physicalAddress = frameNumber * pageSize + offset;
                cout << "Logical Address (" << pageNumber << ", " << offset << ") -> Physical Address: " << physicalAddress << endl;
            } else {
                cout << "Page " << pageNumber << " is not allocated!\n";
            }
        } else {
            cout << "Invalid page number or offset. Try again.\n";
        }
        
        cout << "\nEnter another logical address (page_number offset), or Ctrl+C to exit:\n";
    }
}

int main() {
    int totalPages, pageSize, totalFrames;

    // Input the number of pages, page size, and total number of frames in physical memory
    cout << "Enter the total number of pages in the logical memory: ";
    cin >> totalPages;
    
    cout << "Enter the size of each page (and frame): ";
    cin >> pageSize;
    
    cout << "Enter the total number of frames in physical memory: ";
    cin >> totalFrames;

    // Call the paging technique simulation
    pagingTechnique(totalPages, pageSize, totalFrames);

    return 0;
}
