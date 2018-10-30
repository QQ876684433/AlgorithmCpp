//
// Created by steve on 18-10-30.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int M, N;
queue<int> men;

struct Queue {
    int maxSize;
    int *data;

    bool isFull() { return men.size() >= maxSize; }

    bool contains(int word) {
        if (data[word])return true;
        addWord(word);
        return false;
    }

    void addWord(int word) {
        if (isFull()) {
            data[men.front()] = 0;
            men.pop();
        }
        data[word] = 1;
        men.push(word);
    }

    Queue(int max) : maxSize(max) {
        data = new int[max + 1];
        for (int i = 0; i <= max; ++i) data[i]=0;
    }
};

int main() {
    cin >> M >> N;
    int word;
    Queue q(M);
    int times = 0;
    while (N--) {
        cin >> word;
        if (!q.contains(word))times++;
    }
    cout << times << endl;
    return 0;
}