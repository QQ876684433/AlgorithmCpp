//
// Created by steve on 18-8-29.
//

#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    int case_num;
    cin >> case_num;
    while (case_num--) {
        getchar();

        bool is_locked = false;//标记变量是否被锁定
        int variables[26], runtime[5], Q, n;
        memset(variables, 0, sizeof(variables));
        vector<queue<string *> *> programs;
        deque<int> ready_queue;
        queue<int> stop_queue;
        cin >> n;
        for (int &i : runtime) {
            cin >> i;
        }
        cin >> Q;
        getchar();
        int i = -1;
        while (++i < n) {
//            queue<string *> * program = (queue<string *> *) malloc(sizeof(queue<string *>));
            queue<string *> *program = new queue<string *>;
            while (true) {
                string *line = new string;
                getline(cin, *line);
                program->push(line);
                if (*line == "end") break;
            }
            programs.push_back(program);
            ready_queue.push_back(i);
        }

        //下面开始模拟程序
        while (!ready_queue.empty()) {
            //取出程序执行
            int running = ready_queue.front();
            ready_queue.pop_front();
            int time = Q;
            bool is_stopped = false;//标记是否被阻止执行
            while (time > 0) {
                //取出正在执行程序的第一行代码
                string *code = programs[running]->front();
                if (*code == "lock") {
                    if (is_locked) {
                        stop_queue.push(running);
                        is_stopped = true;
                        break;
                    } else {
                        is_locked = true;
                        time -= runtime[2];
                        //该行代码执行完毕，出队列
                        programs[running]->pop();
                    }
                } else if (*code == "unlock") {
                    is_locked = false;
                    time -= runtime[3];
                    //该行代码执行完毕，出队列
                    programs[running]->pop();
                    //阻止队列的第一个程序进入等待队列的首部
                    if (!stop_queue.empty()) {
                        //这里出错过，避免阻止队列为空时也pop()
                        ready_queue.push_front(stop_queue.front());
                        stop_queue.pop();
                    }
                } else if (*code == "end") {
                    //主要是避免程序再次被加入到等待队列尾部
                    is_stopped = true;
                    break;
                } else if ((*code)[0] == 'p' && (*code)[1] == 'r') {
                    time -= runtime[1];
                    printf("%d: %d\n", running + 1, variables[(*code)[6] - 'a']);
                    //该行代码执行完毕，出队列
                    programs[running]->pop();
                } else {
                    time -= runtime[0];
                    int val = 0;
                    for (int j = 4; j < code->length(); ++j) {
                        val = val * 10 + (*code)[j] - '0';
                    }
                    variables[(*code)[0] - 'a'] = val;
                    //该行代码执行完毕，出队列
                    programs[running]->pop();
                }
            }
            //如果没有被阻止，则移动到等待队列末尾
            if (!is_stopped) ready_queue.push_back(running);
        }
        if (case_num)
            cout << endl;
    }
    return 0;
}