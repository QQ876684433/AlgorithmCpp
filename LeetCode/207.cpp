//
// Created by steve on 18-12-1.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int key;
    int in;
    Node *next;

    Node(int k,int i) : key(k), next(NULL),in(i) {}
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Node *> vertex;
        bool *ver=new bool[numCourses];

        for (int i = 0; i < numCourses; ++i) {
            Node *node = new Node(i,0);
            vertex.push_back(node);
            ver[i]= false;
        }

        for (auto pair : prerequisites) {
            Node *next_node = new Node(pair.first,0);
            next_node->next = vertex[pair.second]->next;
            vertex[pair.second]->next = next_node;
            vertex[pair.first]->in++;
        }

        stack<int> S;

        int count=0;
        for (int j = 0; j < numCourses; ++j) {
            if (vertex[j]->in==0){
                S.push(j);
            }
        }

        while (!S.empty()){
            int v=S.top();S.pop();
            if (ver[v])return false;
            ver[v]= true;
            count++;
            Node*tail=vertex[v];
            while (tail->next){
                vertex[tail->next->key]->in--;
                tail=tail->next;
                if (vertex[tail->key]->in==0)S.push(tail->key);
            }
        }

        return count >= numCourses;
    }
};

/**
 * 3
[[1,0],[1,2],[0,1]]
 *
 * 3
 *
 * 2,0
 * 2,1
 * @return
 */

int main(){
    vector<pair<int,int>>pre;
//    pair<int,int> pair1;pair1.first=1;pair1.second=0;
//    pair<int,int> pair2;pair2.first=1;pair2.second=2;
//    pair<int,int> pair3;pair3.first=0;pair3.second=1;
//    pre.push_back(pair1);
//    pre.push_back(pair2);
//    pre.push_back(pair3);
    pair<int,int> pair1;pair1.first=2;pair1.second=0;
    pair<int,int> pair2;pair2.first=2;pair2.second=1;
    pre.push_back(pair1);
    pre.push_back(pair2);
    Solution s;
    cout << s.canFinish(3,pre)<<endl;
    return 0;
}