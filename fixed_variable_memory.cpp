#include <bits/stdc++.h>
using namespace std;

// Function for Fixed Memory Partitioning
void fixedPartition(vector<int>& partitions, vector<int>& processes) {
    int n = partitions.size();
    int m = processes.size();
    vector<int> allocation(m, -1);  // Tracks allocated partition for each process

    cout << "\n--- Fixed Partition Allocation ---\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (processes[i] <= partitions[j]) {
                allocation[i] = j;  // Allocate process to partition j
                partitions[j] -= processes[i];  // Reduce available space in partition
                break;
            }
        }
    }

    // Display allocation
    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " of size " << processes[i] << " allocated to partition " << allocation[i] + 1 << "\n";
        else
            cout << "Process " << i + 1 << " of size " << processes[i] << " could not be allocated\n";
    }
}

// Function for Variable Memory Partitioning (First Fit)
void variablePartition(int memorySize, vector<int>& processes) {
    int m = processes.size();
    vector<int> memoryAvailable(1, memorySize);  // Initialize with total memory
    vector<int> allocation(m, -1);  // Tracks allocated partition for each process

    cout << "\n--- Variable Partition Allocation (First Fit) ---\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < memoryAvailable.size(); j++) {
            if (processes[i] <= memoryAvailable[j]) {
                allocation[i] = j;  // Allocate process to this block
                memoryAvailable[j] -= processes[i];  // Reduce available memory
                if (memoryAvailable[j] == 0) memoryAvailable.erase(memoryAvailable.begin() + j);  // Remove partition if fully used
                break;
            }
        }
    }

    // Display allocation
    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " of size " << processes[i] << " allocated memory block\n";
        else
            cout << "Process " << i + 1 << " of size " << processes[i] << " could not be allocated\n";
    }
}

int main() {
    int memorySize;

    // Fixed Partitioning Input
    cout << "Enter the total memory size: ";
    cin >> memorySize;

    int fixedPartitions;
    cout << "Enter the number of fixed memory partitions: ";
    cin >> fixedPartitions;

    vector<int> partitions(fixedPartitions);
    cout << "Enter sizes of each partition: ";
    for (int i = 0; i < fixedPartitions; i++) {
        cin >> partitions[i];
    }

    // Process Input
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<int> processes(numProcesses);
    cout << "Enter size of each process: ";
    for (int i = 0; i < numProcesses; i++) {
        cin >> processes[i];
    }

    // Simulate Fixed Partitioning
    fixedPartition(partitions, processes);

    // Reset partitions (since they were modified during fixed partitioning)
    for (int i = 0; i < fixedPartitions; i++) {
        cout << "Re-enter size of partition " << i + 1 << ": ";
        cin >> partitions[i];
    }

    // Simulate Variable Partitioning
    variablePartition(memorySize, processes);

    return 0;
}
