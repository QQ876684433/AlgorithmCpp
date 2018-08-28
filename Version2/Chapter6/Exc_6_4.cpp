//
// Created by steve on 18-8-28.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int steps;

void bfs(char start[4], char end[3]);

int main() {
    char start[4], end[3];
    while (cin >> start >> end && start[0] != EOF) {
        steps = 0;
        start[2] = '0';
        start[3] = '\0';
        bfs(start, end);
        start[2] = '\0';
        printf("To get from %s to %s takes %d knight moves.\n", start, end, steps);
    }
    return 0;
}

void bfs(char start[4], char end[3]) {
    queue<char *> q;
    q.push(start);
    while (true) {
        start = q.front();
        q.pop();
        if (start[0] == end[0] && start[1] == end[1]) {
            steps = start[2]-'0';
            return;
        }

        if (start[0] >= 'c' && start[1] >= '2') {
            char *temp = (char *) malloc(sizeof(char) * 4);
            temp[0] = static_cast<char>(start[0] - 2);
            temp[1] = static_cast<char>(start[1] - 1);
            temp[2] = static_cast<char>(start[2] + 1);
            temp[3] = '\0';
            q.push(temp);
        }
        if (start[0] >= 'b' && start[1] >= '3') {
            char *temp = (char *) malloc(sizeof(char) * 4);
            temp[0] = static_cast<char>(start[0] - 1);
            temp[1] = static_cast<char>(start[1] - 2);
            temp[2] = static_cast<char>(start[2] + 1);
            temp[3] = '\0';
            q.push(temp);
        }
        if (start[0] <= 'g' && start[1] >= '3') {
            char *temp = (char *) malloc(sizeof(char) * 4);
            temp[0] = static_cast<char>(start[0] + 1);
            temp[1] = static_cast<char>(start[1] - 2);
            temp[2] = static_cast<char>(start[2] + 1);
            temp[3] = '\0';
            q.push(temp);
        }
        if (start[0] <= 'f' && start[1] >= '2') {
            char *temp = (char *) malloc(sizeof(char) * 4);
            temp[0] = static_cast<char>(start[0] + 2);
            temp[1] = static_cast<char>(start[1] - 1);
            temp[2] = static_cast<char>(start[2] + 1);
            temp[3] = '\0';
            q.push(temp);
        }
        if (start[0] <= 'f' && start[1] <= '7') {
            char *temp = (char *) malloc(sizeof(char) * 4);
            temp[0] = static_cast<char>(start[0] + 2);
            temp[1] = static_cast<char>(start[1] + 1);
            temp[2] = static_cast<char>(start[2] + 1);
            temp[3] = '\0';
            q.push(temp);
        }
        if (start[0] <= 'g' && start[1] <= '6') {
            char *temp = (char *) malloc(sizeof(char) * 4);
            temp[0] = static_cast<char>(start[0] + 1);
            temp[1] = static_cast<char>(start[1] + 2);
            temp[2] = static_cast<char>(start[2] + 1);
            temp[3] = '\0';
            q.push(temp);
        }
        if (start[0] >= 'b' && start[1] <= '6') {
            char *temp = (char *) malloc(sizeof(char) * 4);
            temp[0] = static_cast<char>(start[0] - 1);
            temp[1] = static_cast<char>(start[1] + 2);
            temp[2] = static_cast<char>(start[2] + 1);
            temp[3] = '\0';
            q.push(temp);
        }
        if (start[0] >= 'c' && start[1] <= '7') {
            char *temp = (char *) malloc(sizeof(char) * 4);
            temp[0] = static_cast<char>(start[0] - 2);
            temp[1] = static_cast<char>(start[1] + 1);
            temp[2] = static_cast<char>(start[2] + 1);
            temp[3] = '\0';
            q.push(temp);
        }
    }
}