#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, l;
    cout << "Enter the number of memory blocks: ";
    cin >> n;

    vector<int> memory(n, 0);

    while (1)
    {
        cout << "Enter the starting block of the file: ";
        cin >> s;
        cout << "Enter the length of the file: ";
        cin >> l;

        if (s + l > n)
        {
            cout << "File cannot be allocated, not enough space." << endl;
        }
        else
        {
            bool spaceAvailable = true;
            for (int i = s; i < s + l; ++i)
            {
                if (memory[i] == 1)
                {
                    spaceAvailable = false;
                    break;
                }
            }

            if (spaceAvailable)
            {
                for (int i = s; i < s + l; ++i)
                {
                    memory[i] = 1;
                }
                cout << "File allocated sequentially from block " << s << " to " << s + l - 1 << "." << endl;
            }
            else
            {
                cout << "File cannot be allocated, blocks are occupied." << endl;
            }
        }

        cout<<"Enter y to continue ";
        char ch;
        cin>>ch;
        if(ch=='y' || ch=='Y'){

        }else break;
        
    }
    return 0;
}