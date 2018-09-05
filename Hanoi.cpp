//
// Created by steve on 18-9-4.
//

//
// Created by steve on 18-9-4.
//

#include <iostream>

void solve(int n, char from, char to, char temp);

using namespace std;

int times;

int main() {
    int n;
    cin >> n;
    times = 0;
    solve(n, 'A', 'B', 'C');
    cout << times << " times in total." << endl;
    return 0;
}

void solve(int n, char from, char to, char temp) {
    times++;
    if (n == 1) cout << from << " to " << to << endl;
    else {
        solve(n - 1, temp, from, to);
        cout << from << " to " << to << endl;
        solve(n - 1, temp, to, from);
    }
}