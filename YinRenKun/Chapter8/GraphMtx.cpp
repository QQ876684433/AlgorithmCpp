//
// Created by steve on 18-10-30.
//
#include <iostream>
#include <cstring>
#include "Graph.cpp"
#include <queue>
#include "MinSpanTree.cpp"
#include "../Chapter5/MinHeap.cpp"
#include "../Chapter6/UFSets.cpp"

using namespace std;

template<class T, class E>
class GraphMtx : public Graph<T, E> {
    friend ostream &operator<<(ostream &out, GraphMtx<T, E> &G);

    friend istream &operator>>(istream &in, GraphMtx<T, E> &G);

    friend void Kruskal(GraphMtx<T, E> &G, MinSpanTree<T, E> &MST);

    friend void Prim(GraphMtx<T, E> &G, const T u0, MinSpanTree<T, E> &MST);

    friend void Dijkstra(GraphMtx<T, E> &G, T v, E dist[], int path[]);

    friend void Bellman_Ford(GraphMtx<T, E> &G, int v, E dist[], int path[]);

    friend void Floyd(GraphMtx<T, E> &G, E a[][], int path[][]);

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

template<class T, class E>
void Kruskal(GraphMtx<T, E> &G, MinSpanTree<T, E> &MST) {
    MSTEdgeNode<T, E> ed;
    int u, v, count;
    int n = G.NumberOfVertices();
    int m = G.NumberOfEdges();
    MinHeap<MSTEdgeNode<T, E>> H(m);
    UFSets F(n);
    for (u = 0; u < n; ++u) {
        for (v = 0; v < m; ++v) {
            int w = G.getWeight(u, v);
            if (w != MaxValue) {
                ed.tail = u;
                ed.head = v;
                ed.key = w;
                H.Insert(ed);
            }
        }
    }
    count = 1;
    while (count < n) {
        H.RemoveMin(ed);
        u = F.Find(ed.tail);
        v = F.Find(ed.head);
        if (u != v) {
            F.Union(u, v);
            MST.Insert(ed);
            count++;
        }
    }
}

template<class T, class E>
void Prim(GraphMtx<T, E> &G, const T u0, MinSpanTree<T, E> &MST) {
    MSTEdgeNode<T, E> ed;
    int i, u, v, count;
    int n = G.NumberOfVertices();
    int m = G.NumberOfEdges();
    u = G.getVertexPos(u0);
    MinHeap<MSTEdgeNode<T, E>> H(m);
    bool *Vmst = new bool[n];
    for (int j = 0; j < n; ++j) {
        Vmst[j] = false;
    }
    Vmst[n] = true;
    count = 1;
    do {
        v = G.GetFirstNeighbor(u);
        while (v != -1) {
            if (!Vmst[v]) {
                ed.tail = u;
                ed.head = v;
                ed.key = G.getWeight(u, v);
                H.Insert(ed);
            }
            v = G.GetNextNeighbor(u, v);
        }
        while (!H.IsEmpty() && count < n) {
            H.RemoveMin(ed);
            if (!Vmst[ed.head]) {
                MST.Insert(ed);
                u = ed.head;
                Vmst[u] = true;
                count++;
                break;
            }
        }
    } while (count < n);
}

/**
 * 非负权值最短路径算法
 *
 * @tparam T
 * @tparam E
 * @param G
 * @param v 源点
 * @param dist 用来存放源点到各点的最短距离
 * @param path 存放最短路径
 */
template<class T, class E>
void Dijkstra(GraphMtx<T, E> &G, T v, E *dist, int *path) {
    int n = G.NumberOfVertices();
    bool *S = new bool[n];// 用来标记顶点是否包含在最短路径中
    for (int i = 0; i < n; ++i) {
        //遍历所有点，用来初始化辅助数组
        dist[i] = G.getWeight(i, v);
        S[i] = false;
        //dist[i] < MaxValue 说明i点与源点v有边
        if (i != v && dist[i] < MaxValue)path[i] = v;
        else path[i] = -1;
    }
    S[v] = true;//将v点加入最短路径顶点集合中
    dist[v] = 0;
    E min;
    //寻找不在S中的有最短路径的顶点u
    for (int i = 0; i < n - 1; ++i) {
        min = MaxValue;//最小权值
        int u = v;
        for (int j = 0; j < n; ++j)
            if (!S[j]//不在S中
                && dist[j] < min//最短路径比min还小，则dist[j]成为最小权值
                    ) {
                u = j;
                min = dist[j];
            }
        //将不在S中的具有最短路径的顶点u加入S中
        S[u] = true;
        //更新各点到源点的最短路径值
        for (int k = 0; k < n; ++k) {
            E w = G.getWeight(u, k);
            if (!S[k] //不在S中
                && w < MaxValue //顶点k与已找出的最短路径顶点有边
                && dist[u] + w < dist[k]) {
                dist[k] = dist[u] + w;
                //将到k的最短路径的顶点设为u，即源点到k的最短路径为(S,u,k)
                path[k] = u;
            }
        }
    }

    printShortestPath(G, v, dist, path);
}

template<class T, class E>
void Bellman_Ford(GraphMtx<T, E> &G, int v, E *dist, int *path) {
    int n = G.NumberOfVertices();
    for (int i = 0; i < n; ++i) {
        dist[i] = G.getWeight(v, i);
        if (i != v && dist[i] < MaxValue) path[i] = v;
        else path[i] = -1;
    }

    //初始化时已经计算了k=1的情况，接下来就是计算2<=k<=n-1的情况
    for (int k = 2; k < n; ++k) {
        //遍历各个除了起点v的所有顶点
        for (int u = 0; u < n; ++u) {
            if (u != v)//除了顶点v
                for (int i = 0; i < n; ++i) {
                    //此时u为要计算最短距离的点，i是从v->i->u的中间顶点，要判断该路径是否比上一轮计算的v->u更短
                    E w = G.getWeight(i, u);//i->u的距离
                    //w>0是指？
                    if (w > 0 && w < MaxValue && dist[u] > dist[i] + w) {
                        dist[u] = dist[i] + w;
                        path[u] = i;
                    }
                }
        }
    }
}

template<class T, class E>
void Floyd(GraphMtx<T, E> &G, E (*a)[], int **path) {
    int n = G.NumberOfVertices();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = G.getWeight(i, j);
            if (i != j && a[i][j] < MaxValue)path[i][j] = i;
            else path[i][j] = 0;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

template<class T, class E>
void printShortestPath(GraphMtx<T, E> &G, int v, E dist[], const int path[]) {
    cout << "从顶点" << G.getValue(v) << "到其他各顶点的最短路径为：" << endl;
    int n = G.NumberOfVertices();
    int *d = new int[n];
    for (int i = 0; i < n; ++i) {
        if (i != v) {
            int j = i;
            int k = 0;
            while (j != v) {
                d[k++] = j;
                j = path[j];
            }
            cout << "顶点" << G.getValue(i) << "的最短路径为：" << G.getValue(v);
            while (k) { cout << G.getValue(d[--k]) << " "; }
            cout << "最短路径长度为：" << dist[i] << endl;
        }
    }
}