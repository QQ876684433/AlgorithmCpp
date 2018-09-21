//
// Created by steve on 18-9-21.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int > in;
vector<int > out;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int type, val;
        int n;
        cin >> n;
        in.clear();
        out.clear();
        while (n--) {
            cin >> type >> val;
            if (type == 1) in.push_back(val);
            else out.push_back(val);
        }
        bool is_queue = true;
        for (int i = 0; i < in.size(); ++i) {
            if (in[i] != out[i]) {
                is_queue = false;
                break;
            }
        }
        if (is_queue) cout << "Queue\n";
        else cout << "Stack\n";
    }
    return 0;
}