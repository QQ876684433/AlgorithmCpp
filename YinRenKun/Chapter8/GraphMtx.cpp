//
// Created by steve on 18-10-30.
//
#include <iostream>
#include "Graph.cpp"

using namespace std;

template<class T, class E>
class GraphMtx : public Graph<T, E> {
    friend ostream &operator<<(ostream &out, GraphMtx<T, E> &G);

    friend istream &operator>>(istream &out, GraphMtx<T, E> &G);

private:
    T *VerticesList;
    E **Edge;

    int getVertexPos(T vertex) {
        for (int i = 0; i < Graph<T, E>::numVertices; ++i) if (VerticesList[i] == vertex)return i;
        return -1;
    }

public:
    GraphMtx(int sz = DefaultVertices);

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
    VerticesList[v] = VerticesList[Graph<T, E>::numVertices - 1];   //delete the vth vertex, which replaced by the last vertex
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
    if (v1>-1&&v1<Graph<T, E>::maxWeight&&v2>-1&&v2<Graph<T, E>::maxWeight&&Edge[v1][v2]>0&&Edge[v1][v2<Graph<T, E>::maxWeight]){
        Edge[v1][v2]=Edge[v2][v1]=Graph<T, E>::maxWeight;
        Graph<T, E>::numEdges--;
        return true;
    }
    return false;
};

