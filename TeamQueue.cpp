//
// Created by steve on 18-8-2.
//

#include <iostream>
#include <cstring>

using namespace std;

int person_to_team[1000005];
int team_to_queue[1005];

int get_team_id(int person) {
    return person_to_team[person];
}

int get_block_id(int team) {
    return team_to_queue[team];
}

struct Team {
    int head, total;
    int people[1005];
};
Team block[1005];
int block_head, block_total;

int main() {
    int team_num, person_num, person_id, scenario_count = 1, team_id, block_id;
    char command[10];
    while (cin >> team_num && team_num != 0) {
        memset(person_to_team, -1, sizeof(person_to_team));
        memset(team_to_queue, -1, sizeof(team_to_queue));
        block_head = 0;
        block_total = 0;
        for (int i = 0; i < team_num; ++i) {
            cin >> person_num;
            for (int j = 0; j < person_num; ++j) {
                cin >> person_id;
                person_to_team[person_id] = i;//ｉ即为团队id值
            }

        }
        cout << "Scenario #" << scenario_count++ << endl;
        while (cin >> command) {
            if (command[0] == 'S') {
                break;
            } else if (command[0] == 'E') {
                //排队
                cin >> person_id;
                team_id = get_team_id(person_id);
                block_id = get_block_id(team_id);
                if (block_id == -1) {
                    //说明该person对应的team没有对应任何一个block
                    block[block_total]//队列尾部新开辟的block
                            .people[block[block_total].total++]//纯粹为了让block[block_total].total加1
                            = person_id;
                    team_to_queue[team_id] = block_total;//将新增的block添加到team_to_queue映射表中
                    block_total++;//block的数量加1
                } else {
                    //说明person对应的team已经存在于queue的某个block中了
                    block[block_id].people[block[block_id].total++] = person_id;
                }
            } else {
                //出队,删除人物
                cout << block[block_head].people[block[block_head].head++] << endl;
                if (block[block_head].head >= block[block_head].total) {
                    team_id = get_team_id(block[block_head].people[0]);
                    team_to_queue[team_id] = -1;
                    block_head++;
                }
            }
        }
        cout << endl;
    }

    return 0;
}