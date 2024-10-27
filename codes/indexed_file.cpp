#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, fileLength, indexBlock, blockNum;
    cout << "Enter the number of memory blocks: ";
    cin >> n;

    int count=0;

    vector<bool> memory(n, false);
    
    map<int, vector<int>> indexTable;

    while (1)
    {
        vector<int> fileBlocks;
        cout << "Enter the index block: ";
        cin >> indexBlock;
        count++;



        if (indexBlock >= 0 && indexBlock < n && !memory[indexBlock])
        {
            memory[indexBlock] = true;

            cout << "Enter the length of the file: ";
            cin >> fileLength;

            if(count+fileLength>n){
                cout<<"Available size is only "<< n-count<<endl ;
                count--;
                memory[indexBlock]=0;
                continue;
            }

            for (int i = 0; i < fileLength; ++i)
            {
                cout << "Enter the block number to allocate (0 to " << n - 1 << "): ";
                cin >> blockNum;
                if (blockNum >= 0 && blockNum < n && !memory[blockNum])
                {
                    memory[blockNum] = true;
                    fileBlocks.push_back(blockNum);
                    count++;
                }
                else
                {
                    cout << "Block is already allocated or invalid!" << endl;
                    --i;
                }
            }

            indexTable[indexBlock] = fileBlocks;

            cout << "File allocated using indexed allocation." << endl;
            cout << "Index Block: " << indexBlock << endl;
            cout << "File Blocks: ";
            for (int block : fileBlocks)
            {
                cout << block << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Index block is already allocated or invalid!" << endl;
        }

        cout << "Enter y to continue ";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
        }
        else
            break;
    }

    return 0;
}