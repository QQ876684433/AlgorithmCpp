//
// Created by steve on 18-8-30.
//

#include <iostream>
#include <list>

using namespace std;

int main() {
    string input;
    list<char> output;
    while (cin >> input && input[0] != EOF) {
        output.clear();
        auto cur = output.begin();
        for (char ch :input) {
            if (ch == '[') {
                cur = output.begin();
            } else if (ch == ']') {
                cur = output.end();
            } else {
                output.insert(cur, ch);
            }
        }
        for (char ch :output) {
            cout << ch;
        }
        cout << endl;
    }
    return 0;
}