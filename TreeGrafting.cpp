//
// Created by steve on 18-8-2.
//

//#include <stdio.h>
//
//int main() {
//    char str[20000];
//    int count = 0;
//    while (scanf("%s", str) && str[0] != '#') {
//        count++;
//        int ptr = 0, height1 = 0, height2 = 0, son_ptr = 0, temp_height = 0;
//        int son_stack[10000] = {0};
//        while (str[ptr]) {
//            if (str[ptr] == 'd') {
//                temp_height++;
//                if (ptr > 0 && str[ptr - 1] == 'u')
//                    son_stack[son_ptr++]++;
//                else son_stack[son_ptr++] = 1;
//            } else {
//                if (temp_height > height1) height1 = temp_height;
//                if (temp_height + son_stack[son_ptr - 1] - 1 > height2) height2 = temp_height + son_stack[son_ptr - 1] - 1;
//                temp_height--;
//                son_ptr--;
//            }
//            ptr++;
//        }
//        printf("Tree %d: %d => %d", count, height1, height2);
//    }
//    return 0;
//}

#include <iostream>
#define maxn 20005
using namespace std;
char s[maxn];
int height1,height2;
int i;

void dfs(int a,int b)
{
    int tempson=0;
    while(s[i]=='d')
    {
        i++;
        tempson++;  //tempson 代表第几个 儿子
        dfs(a+1,b+tempson);
    }
    i++;
    height1=a>height1?a:height1;
    height2=b>height2?b:height2;
}

int main()
{
    int n=1;
    while(cin>>s)
    {

        if(s[0]=='#')
            break;

        i=0;
        height1=height2=0;
        dfs(0,0);
        cout<<"Tree "<<n  <<": "<<height1<<" => "<<height2<<endl;
        n++;
    }

    return 0;
}
