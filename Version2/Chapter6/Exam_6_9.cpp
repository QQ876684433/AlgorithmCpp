//
// Created by steve on 18-8-31.
//

#include <iostream>

using namespace std;

bool is_in_equilibrium;

int solve(int Wl, int Dl, int Wr, int Dr);

int main() {
    int case_num;
    cin >> case_num;
    while (case_num--) {
        getchar();
        is_in_equilibrium = true;
        int Wl, Dl, Wr, Dr;
        cin >> Wl >> Dl >> Wr >> Dr;
        solve(Wl, Dl, Wr, Dr);
        cout << (is_in_equilibrium ? "YES" : "NO") << endl;
        if (case_num) cout << endl;
    }

    return 0;
}

int solve(int Wl, int Dl, int Wr, int Dr) {
    int wl, dl, wr, dr;

    if (Wl == 0) {
        cin >> wl >> dl >> wr >> dr;
        Wl = solve(wl, dl, wr, dr);
    }
    if (Wr == 0) {
        cin >> wl >> dl >> wr >> dr;
        Wr = solve(wl, dl, wr, dr);
    }

    if (Wl * Dl != Wr * Dr) is_in_equilibrium = false;
    return Wl + Wr;
}