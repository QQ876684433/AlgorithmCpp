//
// Created by steve on 18-11-30.
//

#include <iostream>
#include <map>

using namespace std;

int P,Q,R;

int main(){
    map<string,int> vertices;
    cin >> P;
    string vertex;
    for (int i = 0; i < P; ++i) {
        cin >> vertex;
        vertices.insert(pair<string,int>(vertex,i));
    }
    cin>>Q;
    int edges[P][P];
    for (int i = 0; i < Q; ++i) {

    }
    return 0;
}