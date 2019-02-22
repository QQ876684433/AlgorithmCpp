//
// Created by steve on 19-2-22.
//

#include <stdio.h>
#include <stdlib.h>

#define RANGE 100

void play_game();

void welcome() {
    printf("欢迎来到猜数字游戏!\n");
    printf("\tq/Q\t退出游戏\n");
    printf("\ts/S\t开始游戏\n");
}

void handle_user_input() {
    char input;
    scanf("%c", &input);
    switch (input) {
        case 'q':
        case 'Q':
            exit(0);
        case 's':
        case 'S':
            //开始游戏
            play_game();
            break;
        default:
            break;
    }
}

void play_game() {
    printf("请在0-%d之间猜出系统指定的数：\n", RANGE-1);
    int input;
    int times = 0;
    int answer = rand() % RANGE;
    while (1) {
        scanf("%d", &input);
        times++;
        if (input == answer) {
            printf("答对啦！一共猜了%d次\n", times);
            break;
        }
        if (input < answer){
            printf("答案比%d大哦！\n",input);
        } else{
            printf("答案比%d小哦！\n",input);
        }
    }
}

int main() {
    while (1){
        welcome();
        handle_user_input();
    }
    return 0;
}