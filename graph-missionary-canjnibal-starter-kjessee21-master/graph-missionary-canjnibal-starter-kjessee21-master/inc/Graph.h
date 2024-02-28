#ifndef GRAPH_H
#define GRAPH_H
#include <stack>
#include <list>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using std::endl;
using std::cout;
using std::ostream;
using std::stack;
using std::vector;
using namespace std;

template <typename T>
class Graph;

template <typename T>
ostream& operator << (ostream & out, Graph<T> g);

template <typename T>
class Graph{
    private:
      //Declare any variables needed for your graph
      int max_vertices;
      int num_vertices;
      std::list<T>* adjList;

    public:
      Graph();
      Graph(int);
      void addVertex(T vertex);
      void addEdge(T source, T target);
      vector<T> getPath(T, T);
      int findVertexPos(T item);
      int getNumVertices();
      friend ostream& operator << <>(ostream & out, Graph<T> g);
};



/*********************************************
* Constructs an empty graph with a max number of verticies of 100
* 
*********************************************/
template<typename T>
Graph<T>::Graph(){
    max_vertices = 100;
    num_vertices = 0;
    adjList = new list<T>[max_vertices];
}


/*********************************************
* Constructs an empty graph with a given max number of verticies
* 
*********************************************/
template<typename T>
Graph<T>::Graph(int maxVerticies){
    max_vertices = maxVerticies;
    num_vertices = 0;
    adjList = new list<T>[max_vertices];
}




/*********************************************
* Adds a Vertex to the GraphIf number of verticies is less than the 
* Max Possible number of verticies.  
*********************************************/
template <typename T>
void Graph<T>::addVertex(T vertex){
    adjList[num_vertices].push_back(vertex);
    num_vertices++;
}

/*********************************************
* Returns the current number of vertices
* 
*********************************************/
template<typename T>
int Graph<T>::getNumVertices(){
  return num_vertices;
}



/*********************************************
* Returns the position in the verticies list where the given vertex is located, -1 if not found.
* 
*********************************************/
template <typename T>
int Graph<T>::findVertexPos(T item){
   for(int i = 0; i < num_vertices; i++){
       if(item == *adjList[i].begin()){
           return i;
       }
   }
    return -1; //return negative one
}//End findVertexPos

/*********************************************
* Adds an edge going in the direction of source going to target
* 
*********************************************/
template <typename T>
void Graph<T>::addEdge(T source, T target){
    int sp = findVertexPos(source);
    int tg = findVertexPos(target);
    adjList[sp].push_back(target);
    adjList[tg].push_back(source);
}


/*********************************************
* Returns a display of the graph in the format
* vertex: edge edge
Your display will look something like the following
    9: 8 5
    2: 7 0
    1: 4 0
    7: 6 2
    5: 6 8 9 4
    4: 5 1
    8: 6 5 9
    3: 6 0
    6: 7 8 5 3
    0: 1 2 3
*********************************************/
template <typename T>
ostream& operator << (ostream & out, Graph<T> g){
    return out;
}




/*
  getPath will return the shortest path from source to dest.  
  You may use any traversal/search algorithm you want including
  breadth first, depth first, dijkstra's algorithm, or any
  other graph algorithm.
  You will return a vector with the solution.  The source will be in position 1
  the destination is in the last position of the solution, and each node in between 
  are the verticies it will travel to get to the destination.  There will not be any
  other verticies in the list.

  Given the test graph:
  
[0]-----------[2]
|  \            \
|   \            \
[1]  [3]----[6]---[7]   
|          /  \
|         /    \
|        /      \
|     [5]--------[8]
|    /   \       /
|   /     \     /
|  /       \   /
[4]         [9]

getPath(0, 5) should return 
0 -> 1 -> 4 -> 5   or   0 -> 3 -> 6 -> 5
    
  Hint: As you find the solution store it in a stack, pop all the items of the stack 
  into a vector so it will be in the correct order.

*/
template <typename T>
vector<T> Graph<T>::getPath(T source, T dest){
  vector<T> solution;
  //create stack
  list<T> stack;
  //create visited/parents array
  bool *visited = new bool[num_vertices];
  int *parents = new int[num_vertices];
  bool found = false;
  for(int i = 0; i < num_vertices; i++){
      visited[i] = false;
      parents[i] = -1;
  }

  //push startV to stack
  stack.push_front(source);

  //while(stack is not empty)
  while(!stack.empty()){
      //currentV = popStack
      auto currentV = stack.front();
      int curPos = findVertexPos(currentV);
      stack.pop_front();
      //for debugging
      //cout << currentV << endl;
      //if (currentV is not in visited set)
      if(visited[curPos] == false){
          //visit and add to visitedSet
          visited[curPos] = true;
          //for each vertex adjacent to currentV
          //push adjV to stack
          for(auto it = adjList[curPos].begin(); it != adjList[curPos].end(); it++){
              int itPos = findVertexPos(*it);
              if(visited[itPos] == false){
                  stack.push_back(*it);
                  if(parents[itPos] < 0){
                      parents[itPos] = curPos;
                  }
                  if(*it == dest){
                      found = true;
                  }
              }
          }
      }
  }

cout << endl;
for(int i = 0; i < getNumVertices(); i++){
    cout << i << ": " << parents[i] << endl;
}
//curr = dest
auto curr = dest;
//while curr != start
while(curr != source){
    //push curr on solution
    solution.push_back(curr);
    //set curr = to it's parent
    int parentPos = findVertexPos(curr);
    parentPos = parents[parentPos];
    curr = *adjList[parentPos].begin();
}

//add start node
solution.push_back(source);
//reverse solution
reverse(solution.begin(), solution.end());
  return solution;
}

#endif
