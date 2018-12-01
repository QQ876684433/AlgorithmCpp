//
// Created by steve on 18-12-1.
//

#include <vector>

using namespace std;

class Solution {
    vector<int> *vex;   //vex[a]={b,c}：要学习a，须先学b,c
    char *visit;        //0：从未访问，1：正在访问，2：曾经访问
    //若成环，返回false
    bool DFS(int vID) {
        if (visit[vID] == 1)
            return false;   //成环了
        if (visit[vID] == 0) {  //0：从未访问
            visit[vID] = 1;   //1：正在访问
            for (int i = 0; i < vex[vID].size(); ++i) {
                if (!DFS(vex[vID][i]))return false;  //成环了
            }
            visit[vID] = 2;   //2：曾经访问
        }
        return true;    //访问过了
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vex = new vector<int>[numCourses];
        visit = new char[numCourses];
        fill(visit, visit + numCourses, 0);         //0：从未访问
        for (int i = 0; i < prerequisites.size(); ++i) {
            auto &edge = prerequisites[i];
            vex[edge.first].push_back(edge.second);  //[1,0]，学习课程 1 之前，你需要完成课程 0。
        }
        //逐个访问
        for (int i = 0; i < numCourses; ++i) {
            if (!DFS(i))return false;
        }
        return true;   //没有成环即可
    }
};