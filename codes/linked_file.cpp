#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, fL, bN;
    cout << "Enter the number of m blocks: ";
    cin >> n;

    int count = 0;

    vector<bool> m(n, false);
    while (1)
    {

        list<int> fB;

        cout << "Enter the length of the file: ";
        cin >> fL;

        if (count + fL > n)
        {
            cout << "Available size is only " << n - count << endl;
            continue;
        }

        for (int i = 0; i < fL; ++i)
        {
            cout << "Enter the block number to allocate (0 to " << n - 1 << "): ";
            cin >> bN;

            if (bN >= 0 && bN < n && !m[bN])
            {
                m[bN] = true;
                fB.push_back(bN);
                count++;
            }
            else
            {
                cout << "Block is already allocated or invalid!" << endl;
                --i;
            }
        }
        cout << "File allocated in linked allocation at blocks: ";
        for (int block : fB)
        {
            cout << block << " ";
        }
        cout << endl;

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