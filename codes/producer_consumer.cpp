#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the buffer: ";
    cin >> size;
    vector<int> buffer;
    int x = 0;
    int y = 0;
    while(1) { 
        char work;
        cout << "Enter 'p' to produce or 'c' to consume: ";
        cin >> work;
        if (work == 'p') {
            if (y < size) {
                ++x;
                buffer.push_back(x);
                ++y;
                cout << "Produced item: " << x << ". Items in buffer: " << y << "\n";
            } else {
                cout << "Buffer is full, cannot produce more items.\n";
            }
        } else if (work == 'c') {
            if (y > 0) {
                cout << "Consumed item: " << buffer.back() << ". Items in buffer: " << --y << "\n";
                buffer.pop_back();
            } else {
                cout << "Buffer is empty, cannot consume more items.\n";
            }
        } else {
            cout << "Invalid input. Use 'p' to produce or 'c' to consume.\n";
        }
        cout<<"Enter y to continue: ";
        char ch;
        cin>>ch;
        if(ch=='y' || ch=='Y'){

        }else break;
    }
    return 0;
}