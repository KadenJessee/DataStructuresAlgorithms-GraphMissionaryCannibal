# Graphs
Graphs are used for many different applications.
From pathfinding to artificial intelligence, finding a route from one vertex to
another can solve many different types of problems.
In this assignment you will create a templated graph.
You will use the graph to solve the missionaries vs cannibals problem.

## Goals:
The purpose of this project is to practice using graphs, graph algorithms,
and templated classes.

## Requirements:
Graph class

This class creates and manages a Graph.
You are welcome to create and add whatever variables you see fit to implement
the graph.
At minimum, you must implement the following public methods:

+ Graph(); //Constructs an empty graph with a max number of verticies
+ Graph(int); //creates a graph with the given max number of verticies
+ void addVertex(T vertex);//Adds a vertex to the graph with the given value
+ void addEdge(T source, T target); //Adds an edge to the graph from vertex "Source" going towards "target"
+ vector<T> getPath(T source, T dest); //Returns the shortest path from Vertex source to dest.  It includes all the verticies in the path with source at position 0 and dest at the end.
+ int findVertexPos(T item); //Returns the index position in list where the given vertext is found
+ int getNumVertices(); //returns the current number of verticies
+ friend ostream& operator << <>(ostream & out, Graph<T> g); //Returns the output stream of the nodes in a display of your choice.  This method is for debugging and will not be tested
