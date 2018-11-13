//
// Created by steve on 18-10-30.
//
#include <iostream>
#include <cstring>
#include "Graph.cpp"
#include <queue>

using namespace std;

template<class T, class E>
class GraphMtx : public Graph<T, E> {
    friend ostream &operator<<(ostream &out, GraphMtx<T, E> &G);

    friend istream &operator>>(istream &in, GraphMtx<T, E> &G);

private:
    T *VerticesList;
    E **Edge;

    int getVertexPos(T vertex) {
        for (int i = 0; i < Graph<T, E>::numVertices; ++i) if (VerticesList[i] == vertex)return i;
        return -1;
    }

public:
    explicit GraphMtx(int sz = DefaultVertices);

    ~GraphMtx() {
        delete (VerticesList);
        delete (Edge);
    }

    T getValue(int i) { return i >= 0 && i < Graph<T, E>::numVertices ? VerticesList[i] : NULL; }

    E getWeight(int v1, int v2) { return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0; }

    int GetFirstNeighbor(int v);

    int GetNextNeighbor(int v, int w);

    bool insertVertex(const T &x);

    bool insertEdge(int v1, int v2, E cost);

    bool removeVertex(int v);

    bool removeEdge(int v1, int v2);

    void DFS(GraphMtx<T, E> &G, const T &v);

    void DFS(GraphMtx<T, E> &G, int v, bool visited[]);

    void BFS(GraphMtx<T, E> &G, const T &v);

    void Components(GraphMtx<T, E> &G);
};

template<class T, class E>
GraphMtx<T, E>::GraphMtx(int sz):Graph<T, E>(sz) {
    Graph<T, E>::maxVertices = sz;
    Graph<T, E>::numVertices = 0;
    Graph<T, E>::numEdges = 0;
    VerticesList = new T[Graph<T, E>::maxVertices];
    Edge = new E *[Graph<T, E>::maxVertices];
    for (int i = 0; i < Graph<T, E>::maxVertices; ++i) Edge[i] = new E[Graph<T, E>::maxVertices];
    for (int j = 0; j < Graph<T, E>::maxVertices; ++j)
        for (int k = 0; k < Graph<T, E>::maxVertices; ++k)
            Edge[j][k] = j == k ? 0 : Graph<T, E>::maxWeight;
}

template<class T, class E>
int GraphMtx<T, E>::GetFirstNeighbor(int v) {
    if (v != -1)
        for (int i = 0; i < Graph<T, E>::maxVertices; ++i)
            if (VerticesList[v][i] > 0 && VerticesList[v][i] < Graph<T, E>::maxWeight)
                return i;
    return -1;
}

template<class T, class E>
int GraphMtx<T, E>::GetNextNeighbor(int v, int w) {
    if (v != -1)
        for (int i = w + 1; i < Graph<T, E>::maxVertices; ++i)
            if (VerticesList[v][i] > 0 && VerticesList[v][i] < Graph<T, E>::maxWeight)
                return i;
    return -1;
}

template<class T, class E>
bool GraphMtx<T, E>::insertVertex(const T &x) {
    if (Graph<T, E>::numVertices >= Graph<T, E>::maxVertices)return false;
    VerticesList[Graph<T, E>::numVertices++] = x;
    return true;
}

template<class T, class E>
bool GraphMtx<T, E>::insertEdge(int v1, int v2, E cost) {
    if (v1 > -1 && v2 > -1 && v1 < Graph<T, E>::maxVertices && v2 < Graph<T, E>::maxVertices &&
        Edge[v1][v2] == Graph<T, E>::maxWeight) {//插入条件
        Edge[v1][v2] = Edge[v2][v1] = cost;
        Graph<T, E>::numEdges++;
        return true;
    }
    return false;
}

template<class T, class E>
bool GraphMtx<T, E>::removeVertex(int v) {
    if (v < 0 || v > Graph<T, E>::numVertices || Graph<T, E>::numVertices == 1)
        return false;//关键是numVertices==1这个，因为图的顶点集非空
    VerticesList[v] = VerticesList[Graph<T, E>::numVertices -
                                   1];   //delete the vth vertex, which replaced by the last vertex
    for (int k = 0; k < Graph<T, E>::numVertices - 1; ++k)  //remove the edges of other vertices related to vth vertex
        if (VerticesList[k][v] > 0 && VerticesList[k][v] < Graph<T, E>::maxWeight)
            Graph<T, E>::numEdges--;
    for (int l = 0; l < Graph<T, E>::numVertices; ++l)  //replace the vth column with the last column
        VerticesList[l][v] = VerticesList[l][Graph<T, E>::numVertices - 1];
    Graph<T, E>::numVertices--; //reduce the number of vertices
    for (int m = 0; m < Graph<T, E>::numVertices; ++m)  //replace the vth row with the last row
        VerticesList[v][m] = VerticesList[v][Graph<T, E>::numVertices];
    return true;
}

template<class T, class E>
bool GraphMtx<T, E>::removeEdge(int v1, int v2) {
    //remove the edge(v1, v2)
    if (v1 > -1 && v1 < Graph<T, E>::maxWeight && v2 > -1 && v2 < Graph<T, E>::maxWeight && Edge[v1][v2] > 0 &&
        Edge[v1][v2 < Graph<T, E>::maxWeight]) {
        Edge[v1][v2] = Edge[v2][v1] = Graph<T, E>::maxWeight;
        Graph<T, E>::numEdges--;
        return true;
    }
    return false;
}

template<class T, class E>
istream &operator>>(istream &in, GraphMtx<T, E> &G) {
    int T_num, E_num;
    E weight;
    T e1, e2;
    in >> T_num >> E_num;
    for (int i = 0; i < T_num; ++i) {
        in >> e1;
        G.insertVertex(e1);
    }
    while (E_num--) {
        in >> e1 >> e2 >> weight;
        int j = G.getVertexPos(e1), k = G.getVertexPos(e2);
        if (j == -1 || k == -1)cout << "Something wrong with your input! Try again please." << endl;
        else G.insertEdge(j, k, weight);
    }
    return in;
}

template<class T, class E>
ostream &operator<<(ostream &out, GraphMtx<T, E> &G) {
    int T_num, E_num;
    E weight;
    T e1, e2;
    T_num = G.NumberOfVertices();
    E_num = G.NumberOfEdges();
    out << T_num << ", " << E_num << endl;
    for (int i = 0; i < T_num; ++i)
        for (int j = 0; j < T_num; ++j) {
            weight = G.getWeight(i, j);
            if (weight > 0 && weight < G.maxWeight) {
                e1 = G.getValue(i);
                e2 = G.getValue(j);
                out << '(' << e1 << ',' << e2 << ',' << weight << ')' << endl;
            }
        }
    return out;
}

template<class T, class E>
void GraphMtx<T, E>::DFS(GraphMtx<T, E> &G, const T &v) {
    int loc, n = G.NumberOfVertices();
    bool *visited = new bool[n];
    memset(visited, false, sizeof(visited));
    loc = G.getVertexPos(v);
    DFS(G, loc, visited);
    delete[] (visited);
}

template<class T, class E>
void GraphMtx<T, E>::DFS(GraphMtx<T, E> &G, int v, bool *visited) {
    cout << G.getValue(v) << " ";
    visited[v] = true;
    int w = G.GetFirstNeighbor(v);
    while (w != -1) {
        if (!visited[w])DFS(G, w, visited);
        w = G.GetNextNeighbor(v, w);
    }
}

template<class T, class E>
void GraphMtx<T, E>::BFS(GraphMtx<T, E> &G, const T &v) {
    int loc, n = G.NumberOfVertices();
    bool *visited = new bool[n];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    loc = G.getVertexPos(v);
    q.push(loc);
    while (!q.empty()) {
        loc = q.front();
        q.pop();
        if (!visited[loc]) {
            cout << G.getValue(loc) << " ";
            visited[loc] = true;
        }
        int w = G.GetFirstNeighbor(loc);
        while (w != -1) {
            q.push(w);
            w = G.GetNextNeighbor(loc, w);
        }
    }
    delete[]visited;
}

template<class T, class E>
void GraphMtx<T, E>::Components(GraphMtx<T, E> &G) {
    int n = G.NumberOfVertices();
    bool *visited = new bool[n];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++i)
        if (!visited[i]) {
            DFS(G, i, visited);
            // output the components
        }
    delete[]visited;
};

