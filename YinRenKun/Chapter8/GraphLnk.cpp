//
// Created by steve on 18-11-6.
//

#include <iostream>
#include "Graph.cpp"

using namespace std;

template<class T, class E>
struct Edge {
    int dest;
    E cost;
    Edge<T, E> *link;

    Edge() {}

    Edge(int num, E weight) : dest(num), cost(weight), link(NULL) {}

    bool operator!=(Edge<T, E> &R) { return dest != R.dest; }
};

template<class T, class E>
struct Vertex {// definition of vertex 顶点
    T data;
    Edge<T, E> *adj;// head pointer of the edge link
};

template<class T, class E>
class GraphLnk : public Graph<T, E> {

    friend istream &operator>>(istream &in, GraphLnk<T, E> &G);

    friend ostream &operator<<(ostream &out, GraphLnk<T, E> &G);

private:
    Vertex<T, E> *NodeTable;

    int getVertexPos(const T vertex) {
        for (int i = 0; i < Graph<T, E>::numVertices; ++i) {
            if (NodeTable[i].data == vertex)return i;
        }
        return -1;
    }

public:
    GraphLnk(int sz = DefaultVertices);

    ~GraphLnk();

    T getValue(int i) {
        return i >= 0 && i < Graph<T, E>::numVertices ? NodeTable[i] : 0;
    }

    E getWeight(int v1, int v2);

    bool insertVertex(const T &vertex);

    bool removeVertex(int v);

    bool insertEdge(int v1, int v2, E cost);

    bool removeEdge(int v1, int v2);

    int getFirstNeighbor(int v);

    int getNextNeighbor(int v, int w);

};

template<class T, class E>
GraphLnk<T, E>::GraphLnk(int sz):Graph<T, E>(sz) {
    Graph<T, E>::maxVertices = sz;
    Graph<T, E>::numVertices = 0;
    Graph<T, E>::numEdges = 0;
    NodeTable = new Vertex<T, E>[Graph<T, E>::maxVertices];
    if (NodeTable == NULL)cerr << "Failed to allocate the memory!" << endl;
    for (int i = 0; i < Graph<T, E>::maxVertices; ++i) {
        NodeTable->adj = NULL;
    }
}

template<class T, class E>
GraphLnk<T, E>::~GraphLnk() {
    for (int i = 0; i < Graph<T, E>::numVertices; ++i) {
        Edge<T, E> *p = NodeTable[i].adj;
        while (p) {
            NodeTable[i].adj = p->link;
            delete (p);
            p = NodeTable[i].adj;
        }
    }
    delete (NodeTable);
}

template<class T, class E>
int GraphLnk<T, E>::getFirstNeighbor(int v) {
    if (v != -1) {
        Edge<T, E> *p = NodeTable[v].adj;
        if (p) return p->dest;
    }
    return -1;
}

template<class T, class E>
int GraphLnk<T, E>::getNextNeighbor(int v, int w) {
    if (v != -1) {
        Edge<T, E> *p = NodeTable[v].adj;
        while (p && p->dest != w)p = p->link;
        if (p && p->link)return p->link->dest;
    }
    return -1;
}

template<class T, class E>
E GraphLnk<T, E>::getWeight(int v1, int v2) {
    if (v1 != -1 && v2 != -1) {
        Edge<T, E> *p = NodeTable[v1];
        while (p && p->dest != v2)p = p->link;
        if (p)return p->cost;
    }
    return 0;
}

template<class T, class E>
bool GraphLnk<T, E>::insertVertex(const T &vertex) {
    if (Graph<T, E>::numVertices == Graph<T, E>::maxVertices)return false;
    NodeTable[Graph<T, E>::numVertices++].data = vertex;
    return true;
}

template<class T, class E>
bool GraphLnk<T, E>::removeVertex(int v) {
    // list empty or number of vertex out of bound
    if (Graph<T, E>::numVertices == 1 || v < 0 || v > Graph<T, E>::numVertices)return false;
    Edge<T, E> *p, *s, *t;
    int i, k;
    while (NodeTable[v].adj != NULL) {
        p = NodeTable[v].adj;
        k = p->dest;
        s = NodeTable[k].adj;
        t = NULL;
        while (s && s->dest != v) {
            t = s;
            s = s->link;
        }
        if (s) {
            if (t == NULL)// 说明s的第一个邻接点就是v，此时t=NULL
                NodeTable[k].adj = s->link;
            else // 否则此时t为s的前驱
                t->link = s->link;
            delete (s);
        }
        NodeTable[v] = p->link;
        delete (p);
        Graph<T, E>::numEdges--;
    }
    GraphLnk<T, E>::numVertices--;
    NodeTable[v].data = NodeTable[GraphLnk<T, E>::numVertices].data;
    p = NodeTable[v].adj = NodeTable[GraphLnk<T, E>::numVertices].adj;
    while (p) {
        s = NodeTable[p->dest].adj;
        while (s)
            if (s->dest == GraphLnk<T, E>::numVertices) {
                s->dest = v;
                break;
            } else s = s->link;
    }
    return true;
}

template<class T, class E>
bool GraphLnk<T, E>::insertEdge(int v1, int v2, E cost) {
    
}

