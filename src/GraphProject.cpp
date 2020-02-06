//*****************
//Project Name: DFS/BFS Graph Implementation
//Project Description: Create DFS and BFS function for a graph
//Project Author: Macaldo, Aaron Jay
//Is this an extra credit Project:  No (but it includes extra credit)
//Date completed: 12/18/2018
//Operating system used: Windows 10 Education
//IDE Used:  Eclipse Photon
//*****************
//
//  main.cpp
//  STL_DirGraph
//
//  Created by Bill Komanetsky on 11/27/17.
//  Copyright © 2017 Bill Komanetsky. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"
using namespace std;

void printGraph(Graph*);

int main(int argc, const char * argv[]) {

    Graph* myGraph = new Graph();

    //Graph Example #1
//    myGraph->addVertex(1);
//    myGraph->addVertex(2);
//    myGraph->addVertex(3);
//    myGraph->addVertex(4);
//    myGraph->addVertex(5);
//    myGraph->addVertex(6);
//    myGraph->addVertex(7);
//    myGraph->addVertex(8);
//
//    myGraph->addEdgeUnDir(1, 3);
//    myGraph->addEdgeUnDir(1, 2);
//    myGraph->addEdgeUnDir(2, 4);
//    myGraph->addEdgeUnDir(2, 5);
//    myGraph->addEdgeUnDir(2, 6);
//    myGraph->addEdgeUnDir(3, 7);
//    myGraph->addEdgeUnDir(3, 8);
//
//    myGraph->addWeightVertex(1);
//    myGraph->addWeightVertex(2);
//    myGraph->addWeightVertex(3);
//    myGraph->addWeightVertex(4);
//    myGraph->addWeightVertex(5);
//    myGraph->addWeightVertex(6);
//    myGraph->addWeightVertex(7);
//    myGraph->addWeightVertex(8);

     //INSERTS THE VERTEX AND EDGES TO BE TESTED FOR DISKSTRAS METHOD

//    myGraph->addWeightEdgeUnDir(1, 3, 7);
//    myGraph->addWeightEdgeUnDir(1, 2, 3);
//    myGraph->addWeightEdgeUnDir(2, 4, 10);
//    myGraph->addWeightEdgeUnDir(2, 5, 14);
//    myGraph->addWeightEdgeUnDir(2, 6, 2);
//    myGraph->addWeightEdgeUnDir(3, 7, 22);
//    myGraph->addWeightEdgeUnDir(3, 8, 19);
    //End Graph Example #1


    //Graph Example #2
//    myGraph->addVertex(0);
//    myGraph->addVertex(1);
//    myGraph->addVertex(2);
//    myGraph->addVertex(3);
//    myGraph->addVertex(4);
//    myGraph->addVertex(5);
//
//    myGraph->addEdgeUnDir(0, 1);
//    myGraph->addEdgeUnDir(0, 2);
//    myGraph->addEdgeUnDir(1, 2);
//    myGraph->addEdgeUnDir(1, 3);
//    myGraph->addEdgeUnDir(2, 4);
//    myGraph->addEdgeUnDir(2, 3);
//    myGraph->addEdgeUnDir(3, 4);
//    myGraph->addEdgeUnDir(3, 5);
//    myGraph->addEdgeUnDir(5, 4);

      //INSERTS THE VERTEX AND EDGES TO BE TESTED FOR DISKSTRAS METHOD

//    myGraph->addWeightVertex(0);
//    myGraph->addWeightVertex(1);
//    myGraph->addWeightVertex(2);
//    myGraph->addWeightVertex(3);
//    myGraph->addWeightVertex(4);
//    myGraph->addWeightVertex(5);
//    myGraph->addWeightVertex(6);
//
//	  myGraph->addWeightEdgeUnDir(0, 1, 4);
//	  myGraph->addWeightEdgeUnDir(0, 2, 1);
//    myGraph->addWeightEdgeUnDir(1, 2, 5);
//    myGraph->addWeightEdgeUnDir(1, 3, 2);
//    myGraph->addWeightEdgeUnDir(2, 3, 7);
//    myGraph->addWeightEdgeUnDir(2, 4, 32);
//    myGraph->addWeightEdgeUnDir(3, 5, 53);
//    myGraph->addWeightEdgeUnDir(3, 4, 9);
//    myGraph->addWeightEdgeUnDir(4, 5, 13);
//    myGraph->addWeightEdgeUnDir(4, 6, 17);
//    myGraph->addWeightEdgeUnDir(6, 5, 11);
    //End Graph Example #2


    //Graph Example #3
    myGraph->addVertex(0);
    myGraph->addVertex(1);
    myGraph->addVertex(2);
    myGraph->addVertex(3);
    myGraph->addVertex(4);
    myGraph->addVertex(5);
    myGraph->addVertex(6);
    myGraph->addVertex(7);

    myGraph->addEdgeUnDir(0, 1);
    myGraph->addEdgeUnDir(0, 2);
    myGraph->addEdgeUnDir(0, 3);
    myGraph->addEdgeUnDir(1, 3);
    myGraph->addEdgeUnDir(1, 5);
    myGraph->addEdgeUnDir(2, 4);
    myGraph->addEdgeUnDir(3, 5);
    myGraph->addEdgeUnDir(3, 6);
    myGraph->addEdgeUnDir(3, 4);
    myGraph->addEdgeUnDir(3, 2);
    myGraph->addEdgeUnDir(4, 6);
    myGraph->addEdgeUnDir(5, 7);
    myGraph->addEdgeUnDir(5, 6);
    myGraph->addEdgeUnDir(6, 7);

    //INSERTS THE VERTEX AND EDGES TO BE TESTED FOR DISKSTRAS METHOD

    myGraph->addWeightVertex(0);
    myGraph->addWeightVertex(1);
    myGraph->addWeightVertex(2);
    myGraph->addWeightVertex(3);
    myGraph->addWeightVertex(4);
    myGraph->addWeightVertex(5);
    myGraph->addWeightVertex(6);
    myGraph->addWeightVertex(7);

    myGraph->addWeightEdgeUnDir(0, 1, 34);
    myGraph->addWeightEdgeUnDir(0, 2, 21);
    myGraph->addWeightEdgeUnDir(0, 3, 44);
    myGraph->addWeightEdgeUnDir(1, 3, 54);
    myGraph->addWeightEdgeUnDir(1, 5, 76);
    myGraph->addWeightEdgeUnDir(2, 4, 21);
    myGraph->addWeightEdgeUnDir(3, 5, 33);
    myGraph->addWeightEdgeUnDir(3, 6, 87);
    myGraph->addWeightEdgeUnDir(3, 4, 59);
    myGraph->addWeightEdgeUnDir(3, 2, 20);
    myGraph->addWeightEdgeUnDir(4, 6, 33);
    myGraph->addWeightEdgeUnDir(5, 7, 12);
    myGraph->addWeightEdgeUnDir(5, 6, 23);
    myGraph->addWeightEdgeUnDir(6, 7, 71);
    //End Graph Example #3

    printGraph(myGraph);

    vector<GraphVertex*> aVertex;

    aVertex = myGraph->searchDFS(0);
    cout << "Printing the graph navigated starting at 0 using DFS" << endl;
    for (GraphVertex* i: aVertex) {
        cout << i->Value << endl;
    }//for
    aVertex.clear();

    aVertex = myGraph->searchBFS(0);
    cout << "Printing the graph navigated starting at 0 using BFS" << endl;
    for (GraphVertex* i: aVertex) {
        cout << i->Value << endl;
    }//for
    aVertex.clear();

    //TESTS THE SHORTEST PATH ALGORITH<+M

    aVertex = myGraph->djShortestPath(0, 7);
    cout << "Checking for shortest path from 0 to 7" << endl;
    for (GraphVertex* i: aVertex) {
        cout << i->Value << endl;
    }//for
    aVertex.clear();

    delete myGraph;

    std::cout << "Program ending, have a great day!" << endl;
    return 0;
}

void printGraph(Graph* theGraph) {
    for (int i=0; i<STARTSIZE; i++) {
        vector<GraphVertex*>* tempVector = theGraph->getDestVertex(i);
        if (tempVector != nullptr && tempVector->size() > 0) {
            for (int j=0; j<tempVector->size(); j++) {
                cout << i << "--" << tempVector->at(j)->Value << endl;
            }//for
        }//if
        else {}
    }//for
}//printGraph
