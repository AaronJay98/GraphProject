//
//  Graph.cpp
//  STL_DirGraph
//
//  Created by Bill Komanetsky on 11/27/17.
//  Copyright © 2017 Bill Komanetsky. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph() {
    initGraph();
    initWeightGraph();
}//Graph()

//The Destructor will go through each array entry and delete the vertex at that array
//position if it has been created.  It will then clear the vector of adjacent vertecies
//You don't need to worry about loosing those vertices because they will be deleted
//when we get to their position in the array
Graph::~Graph() {
    for (int i=0; i<STARTSIZE; i++) {
        if (edgeArray[i].first != nullptr) {
            delete edgeArray[i].first;      //Delete the vertex
            edgeArray[i].first = nullptr;   //Set its poiner to nullptr since it's been deleted
            edgeArray[i].second->clear();   //Clear the vector of adjacent vertices
            delete edgeArray[i].second;     //Now, delete the dynamically allocated vector
        }//if
        else {}
    }//for i

    for (int j=0; j<STARTSIZE; j++) {
        if (weightArray[j].first != nullptr) {
            delete weightArray[j].first;      //Delete the vertex
            weightArray[j].first = nullptr;   //Set its poiner to nullptr since it's been deleted
            weightArray[j].second->clear();   //Clear the vector of adjacent vertices
            delete weightArray[j].second;     //Now, delete the dynamically allocated vector
        }//if
        else {}
    }//for i
}//~Graph()

//Set everything up in the array so we can store vertices and their adjacent vertices (edges)
//Each of the array's memory locations shall contain a pair of data
//      first:  A vertex structure
//      second: A vector of vertex structures
//              Each of these will be the end-point of an edge eminating from the vertex (first)
void Graph::initGraph(void) {
    for (int i=0; i<STARTSIZE; i++) {
        edgeArray[i].first = nullptr;
        edgeArray[i].second = new vector<GraphVertex*>;
    }//for
}//initGraph

//Return the pointer to a vector of vertex pointers which shall contain all
//of the end-points for each edge eminating from the vertex (first) in that pair
vector<GraphVertex*>* Graph::getDestVertex(int sourceVertex) {
    if (sourceVertex >= STARTSIZE) {
        return nullptr;
    }//if
    else {
        return edgeArray[sourceVertex].second;
    }//else
}//getDestVertex(int)

//Add a vertex to the array if that vertex hasn't yet been created
//Will return doing nothing if that vertex has already been setup, or, if the value
//which the vertex shall contain is greater than the arrayt capacity or less than zero
void Graph::addVertex(int vertexValue) {
    //If the vertex value is larger than the graph capacity or
    //  the vertex already exists, then leave.
    if (vertexValue >= STARTSIZE || vertexValue < 0 || this->edgeArray[vertexValue].first != nullptr) {
        return;
    }//if
    else {
        //Create a new vertex and populate its value
        GraphVertex* tempVertex = new GraphVertex;
        tempVertex->Value = vertexValue;
        tempVertex->Visited = false;
        //Now, add it to the first of the pair
        edgeArray[vertexValue].first = tempVertex;
    }//else
}//addVertex

//Add a directed edge
//Will do nothing if the range of the source or destination values are beyond the size of the
//array, or, if the source or destination vertices have not yet been added, in other words, if
//you try to create an edge for a vertex that does not yet exist, this function will do nothing
void Graph::addEdgeDir(int source, int destination) {
    //if the source or destination vertex values are grater than the size of the array of vectors
    //or if the soruce or destination vertecis do not exist, then return
    if (source >= STARTSIZE || source < 0 || destination >= STARTSIZE || destination < 0 ||
        edgeArray[source].first == nullptr ||
        edgeArray[destination].first == nullptr) {
        return;
    }//if
    else {
        //Add to the source vector an existing vertex located at destination in the array
        edgeArray[source].second->push_back(edgeArray[destination].first);
    }//else
}//adEdge(int, int)

//Add a directed edge
//Will do nothing if the range of the source or destination values are beyond the size of the
//array, or, if the source or destination vertices have not yet been added, in other words, if
//you try to create an edge for a vertex that does not yet exist, this function will do nothing
void Graph::addEdgeUnDir(int source, int destination) {
    //if the source or destination vertex values are grater than the size of the array of vectors
    //or if the soruce or destination vertecis do not exist, then return
    if (source >= STARTSIZE || source < 0 || destination >= STARTSIZE || destination < 0 ||
        edgeArray[source].first == nullptr ||
        edgeArray[destination].first == nullptr) {
        return;
    }//if
    else {
        //Add to the source vector an existing vertex located at destination in the array
        edgeArray[source].second->push_back(edgeArray[destination].first);
        //Add to the destination vector an existing vertex located at source in the array
        edgeArray[destination].second->push_back(edgeArray[source].first);
    }//else
}//adEdge(int, int)

//Do a Depth first Search for the graph
//This function will return a vector of vertices showing how the graph was navigated
//If you try to start with a vertex which does not exist, this function will return
//an empty vector
vector<GraphVertex*> Graph::searchDFS(int start) {

    vector<GraphVertex*> returnVector;
    stack<pair<GraphVertex*, vector<GraphVertex*>*>> theStack;
    pair<GraphVertex*, vector<GraphVertex*>*> popPair;
    int destVertex;

    if(edgeArray[start].first == nullptr) {
    	return returnVector;
    }

    theStack.push(edgeArray[start]);

    while(!theStack.empty()) {
    	popPair = theStack.top();
    	theStack.pop();
    	if(popPair.first->Visited) {
    		continue;
    	}
    	else {
    		returnVector.push_back(popPair.first);
    		popPair.first->Visited = true;
    	}

    	for(int i = 0; i < popPair.second->size(); i++) {
    		int destVertex = popPair.second->at(i)->Value;
    		theStack.push(edgeArray[destVertex]);
    	}
    }

    clearAllVisited();

    return returnVector;
}//searchDFS

//Do a Breadth first Search for the graph
//This function will return a vector of vertices showing how the graph was navigated
//If you try to start with a vertex which does not exist, this function will return
//an empty vector
vector<GraphVertex*> Graph::searchBFS(int start) {
    vector<GraphVertex*> returnVector;
    queue<pair<GraphVertex*, vector<GraphVertex*>*>> theQueue;
    pair<GraphVertex*, vector<GraphVertex*>*> popPair;
    int destVertex;

    if(edgeArray[start].first == nullptr) {
    	return returnVector;
    }

    theQueue.push(edgeArray[start]);

    while(!theQueue.empty()) {
    	popPair = theQueue.front();
    	theQueue.pop();
    	if(popPair.first->Visited) {
    		continue;
    	}
    	else {
    		returnVector.push_back(popPair.first);
    		popPair.first->Visited = true;
    	}

    	for(int i = 0; i < popPair.second->size(); i++) {
    		int destVertex = popPair.second->at(i)->Value;
    		theQueue.push(edgeArray[destVertex]);
    	}
    }

    clearAllVisited();
    
    return returnVector;
}//searchBFS

//This function shall set to false all vertices visited variable to false
void Graph::clearAllVisited(void) {
    for (int i=0; i<STARTSIZE; i++) {
        if (edgeArray[i].first != nullptr) {
            edgeArray[i].first->Visited = false;
        }//if
        else {}
    }//for
}//clearAllVisited



//EVERYTHING BELOW IS USED FOR THE EXTRA CREDIT AND NOTHING ON TOP (Except for constructor and destructor)
//BASICALLY COPIES OF YOUR FUNCTIONS BUT WITH THE ADDED WEIGHT FUNCTIONALITY
//IN ORDER TO SEPERATE THE NORMAL PROJECT FROM THE EXTRA CREDIT



void Graph::addWeightVertex(int vertexValue) {
    if (vertexValue >= STARTSIZE || vertexValue < 0 || this->weightArray[vertexValue].first != nullptr) {
        return;
    }//if
    else {
        //Create a new vertex and populate its value
        GraphVertex* tempVertex = new GraphVertex;
        tempVertex->Value = vertexValue;
        tempVertex->Visited = false;
        //Now, add it to the first of the pair
        weightArray[vertexValue].first = tempVertex;
    }//else
}

void Graph::addWeightEdgeUnDir(int source, int destination, int weight) {
    //if the source or destination vertex values are grater than the size of the array of vectors
    //or if the soruce or destination vertecis do not exist, then return

    if (source >= STARTSIZE || source < 0 || destination >= STARTSIZE || destination < 0 || weightArray[source].first == nullptr || weightArray[destination].first == nullptr) {
        return;
    }//if
    else {
    	Edge destSourceEdge;
    	Edge sourceDestEdge;

    	sourceDestEdge.destVertex = weightArray[destination].first;
    	sourceDestEdge.weight = weight;

        weightArray[source].second->push_back(sourceDestEdge);

        destSourceEdge.destVertex = weightArray[source].first;
        destSourceEdge.weight = weight;

        weightArray[destination].second->push_back(destSourceEdge);
    }//else
}

vector<GraphVertex*> Graph::djShortestPath(unsigned int start, unsigned int searchVertex) {
	vector<GraphVertex*> returnVector;
	vector<GraphVertex*> reverseVector;
	Path* thePaths[STARTSIZE];
	Path* aPath;
	GraphVertex* tempVertex;
	Edge currEdge;
	int minWeight = -1;
	GraphVertex* currVertex = weightArray[start].first;

	if(weightArray[start].first == nullptr || weightArray[searchVertex].first == nullptr) {
		return returnVector;
	}

	for(int l = 0; l < STARTSIZE; l++) { //initializes the thePaths array
		if(weightArray[l].first == nullptr) { //if the weightArray doesnt contain a vector at a point, thePath doesnt either
			aPath = new Path;				  //Instead initialize all to default values
			aPath->Vertex = nullptr;
			aPath->From = nullptr;
			aPath->weight = -99;
			thePaths[l] = aPath;
			continue;
		}

		aPath = new Path;
		aPath->Vertex = weightArray[l].first;
		if(l == start) {
			aPath->weight = 0;				 // 0 because we start with this
		}
		else {
			aPath->weight = -1;				 // -1 for the rest
		}
		aPath->From = nullptr;
		aPath->visited = false;
		thePaths[l] = aPath;
	}

	while(currVertex != weightArray[searchVertex].first) {								//Checks to see if the current vertex is equal to the vertex we are looking for
		for(int k = 0; k < weightArray[currVertex->Value].second->size(); k++) {        //Loops for each vertex the current vertex is connected too
			currEdge = weightArray[currVertex->Value].second->at(k);					//Assigns currEdge to be the "k"th edge of the current vertex (edge includes dest Vertex and weight)

			if(thePaths[currEdge.destVertex->Value]->weight == -1) {					//Checks if the weight of the vertex on this edge is -1
				thePaths[currEdge.destVertex->Value]->weight = currEdge.weight + thePaths[currVertex->Value]->weight;	//Assigns the dest. vertex weight to the curr. vertex weight + edge weight
				thePaths[currEdge.destVertex->Value]->From = currVertex;				//Assigns current vertex as the From
			}
			else if((thePaths[currVertex->Value]->weight + currEdge.weight) < thePaths[currEdge.destVertex->Value]->weight) { //Checks if the weight of this curr. vertex + edge weight is smaller than the dest. weight
				thePaths[currEdge.destVertex->Value]->weight = currEdge.weight + thePaths[currVertex->Value]->weight;	//Assigns the dest. vertex weight to the curr. vertex weight + edge weight
				thePaths[currEdge.destVertex->Value]->From = currVertex;				//Assigns current vertex as the From
			}
		}

		thePaths[currVertex->Value]->visited = true; //Sets the curr. vertex to be visited

		minWeight = -1; //resets minWeight

		for(int j = 0; j < STARTSIZE; j++) { //Loops through thePaths to find the vertex that has the smallest weight
			if(thePaths[j]->Vertex == nullptr || thePaths[j]->visited || thePaths[j]->weight == -1) { //Checks none of these are true
				continue;
			}

			if(thePaths[j]->weight < minWeight || minWeight == -1) { //checks to see if the current path weight is smaller or automatically sets first weight if minWeight is still -1
				minWeight = thePaths[j]->weight;
				currVertex = thePaths[j]->Vertex;
			}
		}
	}

	while(true) {			//Pushes the path into the return vector using the thePaths and the "From" variable
		returnVector.push_back(thePaths[currVertex->Value]->Vertex);
		if(thePaths[currVertex->Value]->Vertex == weightArray[start].first) {
			break;
		}
		currVertex = thePaths[currVertex->Value]->From;
	}

	for(int o = 0; o < returnVector.size() / 2; o++) {			//This for loop is used to reorder the vertex so that first element in returnVector is the starting vector and last element is the destination vector
		tempVertex = returnVector[o];
		returnVector[o] = returnVector[returnVector.size() - 1 - o];
		returnVector[returnVector.size() - 1 - o] = tempVertex;
	}

	for(int m = 0; m < STARTSIZE; m++) { //Deletes all the new Paths created
		delete thePaths[m];
	}

	return returnVector; //returns the vector in order
}

void Graph::initWeightGraph(void) {
    for (int i=0; i<STARTSIZE; i++) {
        weightArray[i].first = nullptr;
        weightArray[i].second = new vector<Edge>;
    }//for
}
