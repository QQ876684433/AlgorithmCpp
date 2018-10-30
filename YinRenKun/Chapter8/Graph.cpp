//
// Created by steve on 18-10-30.
//

#include <iostream>

using namespace std;

const int DefaultVertices = 30;

template<class T, class E>
class Graph {
protected:
    int maxVertices;
    int numEdges;
    int numVertices;

    virtual int getVertexPos(T vertex);

public:
    const E maxWeight = 2147483647;

    Graph(int sz = DefaultVertices);

    ~Graph();

    bool GraphEmpty() const { return numEdges == 0; }

    bool GraphFull() const { return (numVertices >= maxVertices || numEdges == (maxVertices - 1) * maxVertices / 2); }

    int NumberOfVertices() { return numVertices; }

    int NumberOfEdges() { return numEdges; }

    virtual T getValue(int i);

    virtual E getWeight(int v1, int v2);

    virtual int GetFirstNeighbor(int v);

    virtual int GetNextNeighbor(int v, int w);

    virtual bool insertVertex(const T &x);

    virtual bool insertEdge(int v1, int v2, E cost);

    virtual bool removeVertex(int v);

    virtual bool removeEdge(int v1, int v2);
};