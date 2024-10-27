#include <iostream>
#include <vector>

using namespace std;

enum State { THINKING, HUNGRY, EATING };

void check(int id, vector<State>& state, vector<bool>& forks, int num) {
    int left = (id + num - 1) % num;
    int right = (id + 1) % num;

    if (state[id] == HUNGRY && forks[left] && forks[id]) {
        state[id] = EATING;
        forks[left] = false;
        forks[id] = false;
        cout << "Philosopher " << id << " is eating.\n";
    }
}

void pick(int id, vector<State>& state, vector<bool>& forks, int num) {
    if (state[id] == EATING) {
        cout << "Philosopher " << id << " continues eating.\n";
        return;
    }
    
    state[id] = HUNGRY;
    cout << "Philosopher " << id << " is hungry.\n";
    check(id, state, forks, num);
}

void putdown(int id, vector<State>& state, vector<bool>& forks, int num) {
    int left = (id + num - 1) % num;

    if (state[id] == EATING) {
        state[id] = THINKING;
        forks[left] = true;
        forks[id] = true;
        cout << "Philosopher " << id << " has released the forks.\n";
        cout << "Philosopher " << id << " is now thinking.\n";
    } else {
        cout << "Philosopher " << id << " is not holding the forks.\n";
    }
}

int main() {
    int num;
    cout << "Enter the number of philosophers at the dining table: ";
    cin >> num;

    vector<State> state(num, THINKING);
    vector<bool> forks(num, true);

    cout<<"'p' (pick) or 'd' (putdown)? \n";
    
    for (int i = 0; i < 2; ++i) {
        for (int id = 0; id < num; ++id) {
            char action;
            cout << "Philosopher " << id << ": ";
            cin >> action;

            if (action == 'p') {
                pick(id, state, forks, num);
            } else if (action == 'd') {
                putdown(id, state, forks, num);
            } else {
                cout << "Invalid action\n";
            }
        }
    }
    return 0;
}