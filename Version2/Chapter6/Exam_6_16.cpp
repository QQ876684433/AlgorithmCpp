//
// Created by steve on 18-9-6.
//

#include <iostream>
#include <cstring>

using namespace std;

int nodes[26][2];

int main() {
    int n, m;
    cin >> n;
    while (n--) {
        cin >> m;
        memset(nodes, 0, sizeof(nodes));
        while (m--) {
            string input;
            cin >> input;
            nodes[input[0]-'a'][0]++;
            nodes[input[input.length()-1]-'a'][1]++;
        }


    }
    return 0;
}