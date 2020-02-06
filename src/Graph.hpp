//
//  Graph.hpp
//  STL_DirGraph
//
//  Created by Bill Komanetsky on 11/27/17.
//  Copyright © 2017 Bill Komanetsky. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

const int STARTSIZE = 500;

struct GraphVertex {
    int Value;
    bool Visited;
};

struct Edge {
    GraphVertex* destVertex;
    int weight;
};//Edge

struct Path {
	GraphVertex* Vertex;
	GraphVertex* From;
	int weight;
	bool visited;
};

class Graph {
public:
    Graph();
    virtual ~Graph();
    
    Graph(vector<Edge>);
    vector<GraphVertex*>* getDestVertex(int);
    void addEdgeUnDir(int source, int destination);
    void addEdgeDir(int source, int destination);
    void addVertex(int);
    vector<GraphVertex*> searchDFS(int start);
    vector<GraphVertex*> searchBFS(int start);
    void clearAllVisited(void);

    void addWeightVertex(int);
    void addWeightEdgeUnDir(int source, int destination, int weight);
    vector<GraphVertex*> djShortestPath(unsigned int, unsigned int);
private:
    pair<GraphVertex*, vector<GraphVertex*>*> edgeArray[STARTSIZE];
    void initGraph(void);

    pair<GraphVertex*, vector<Edge>*> weightArray[STARTSIZE];
    void initWeightGraph(void);
};//Graph

#endif /* Graph_hpp */
