```

Lecture 20 : Graphs 1 START HERE

```

# ##Lecture 20 : Graphs 1

---

//============>>>>>>>>>> Lecture 20 : Graphs 1 Notes
[Lecture 20 : Graphs 1 Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/9270341/Lecture.20.Graphs.1.Notes.pdf)

---

### Graphs Introduction && ### Graphs Terminology

![image](https://user-images.githubusercontent.com/57065763/182013562-7ae5a705-804e-4ea6-8f75-8ea5f516e5d8.png)

### Graphs Implementation

![image](https://user-images.githubusercontent.com/57065763/182017299-05401176-ffd1-46b1-9291-0caa0211da38.png)

### DFS - Adjacency Matrix
20:42

### BFS Traversal

![image](https://user-images.githubusercontent.com/57065763/182028076-d1ba8ebc-fefa-400d-ad50-e7dfa2ba2da6.png)

```cpp
#include <iostream>
#include <queue>
using namespace std;

void singleComponentDFS(int **eadge, int n, bool *visited, int sv){
	cout << sv << endl;
	visited[sv] = true;
	for (int i = 0; i < n; i++){
		// if(i==sv){
		//   continue;
		// }

		if (eadge[sv][i] == 1){
			if (visited[i]){
				continue;
			}
		}
	}
}

void DFS(int **eadge, int v){
	bool *visited = new bool[v]();	// () function use
	for (int i = 0; i < v; ++i){
		if (!visited[i]){
			singleComponentDFS(eadge, v, visited, i);
		}
	}
	delete[] visited;
}

int main()
{
	int v, e;
	cin >> v >> e;
	int **eadge = new int *[v];
	for (int i = 0; i < v; ++i){
		eadge[i] = new int[v]();	// () => automatically make false or 0, if we run this funciton.
		// for (int j = 0; j < v; j++)
		// {
		//   eadge[i][j] = 0;
		// }
	}

	for (int i = 0, a, b; i < e; ++i){
		cin >> a >> b;
		eadge[a][b] = 1;
		eadge[b][a] = 1;
	}

	DFS(eadge, v);
	for (int i = 0; i < v; ++i){
		delete[] eadge[i];
	}

	delete[] eadge;
}
```

### Code : BFS Traversal && Solution : BFS Traversal

![image](https://user-images.githubusercontent.com/57065763/182030523-1300036b-4c3c-40ad-b9d8-b9e69b6ade52.png)

```
Code : BFS Traversal
Send Feedback
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print the BFS Traversal, as described in the task.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
```

```cpp
/*
Time complexity: O(V + E) 
Space complexity: O(V^2) 
where V is the number of vertices in the input eadge and 
E is the number of edges in the input eadge 
*/
#include <iostream>
#include <queue>
using namespace std;
void singleComponentBFS(int** eadge, int v, bool *visited, int vertex)
{
	queue<int> pendingVertices;
	pendingVertices.push(vertex);
	visited[vertex] = true;
	while (!pendingVertices.empty()){
		int frontVertex = pendingVertices.front();
		pendingVertices.pop();
		cout << frontVertex << " ";
		for (int i = 0; i < v; ++i){
			// if (i == frontVertex){
			// continue; //=> this (if) function not so important. 
                        ////because we are doing true and won't came again.
			// }
			if (eadge[frontVertex][i]==1 && !visited[i]){
				pendingVertices.push(i);
				visited[i] = true;
			}
		}
	}
}
void BFS(int** eadge, int v)
{
	bool *visited = new bool[v](); // () function use
	for (int i = 0; i < v; ++i){
		if (!visited[i]){
			singleComponentBFS(eadge, v, visited, i);
		}
	}
	delete[] visited;
}
int main()
{
	int v, e;
	cin >> v >> e;
	int **eadge = new int*[v];
	for (int i = 0; i < v; ++i){
		eadge[i] = new int[v](); // () => automatically make false or 0 , if we run this funciton.
		// for (int j = 0; j < v; j++)
		// {
		//   eadge[i][j] = 0;
		// }
	}
    
	for (int i = 0, a, b; i < e; ++i){
		cin >> a >> b;
		eadge[a][b] = 1;
		eadge[b][a] = 1;
	}
	
    BFS(eadge, v);
	for (int i = 0; i < v; ++i){
		delete[] eadge[i];
	}
	delete[] eadge;
}
```

### BFS & DFS for disconnected graph

![image](https://user-images.githubusercontent.com/57065763/182042330-92511062-20c8-4691-8bf9-64fbab811c34.png)

### Has path && Code : Has Path  #DFS Approach(USING RECURSION) && #BFS Approach(USING QUEUE )

```
Code : Has Path
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= V - 1
0 <= v2 <= V - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
```

```cpp
/*---------------------DFS Approach(USING RECURSION)------------------*/
/*
Time complexity: O(V + E) 
Space complexity: O(V^2) 
where V is the number of vertices in the input graph and
E is the number of edges in the input graph 
*/
#include <iostream>
#include <queue>
using namespace std;

bool hasPathHelper(bool **edges, int v, int start, int end, bool *visited){
    
	if (start == end){
		return true;
	}
    
	if (end >= v || start >= v){
		return false;
	}
    
	if (edges[start][end] || edges[end][start]){
		return true;
	}
    
	queue < long long > pendingVertices;
	pendingVertices.push(start);
	visited[start] = true;
    //  --------------1st WAY---------------
	while (!pendingVertices.empty()){
		int front = pendingVertices.front();
		pendingVertices.pop();
		for (long long i = 0; i < v; i++){
			if (edges[front][i] && !visited[i]){
				pendingVertices.push(i);
				visited[i] = true;
			}
		}
        
		if (visited[end]){
			return true;
		}
	}
	return false;
    
    /*
    //--------------2ND WAY---------------
	bool pathFound = false;
	while (!pendingVertices.empty()){
		int front = pendingVertices.front();
		pendingVertices.pop();
		for (long long i = 0; i < v; i++){
			if (edges[front][i] && !visited[i]){
				pendingVertices.push(i);
				visited[i] = true;
                if (i == end){
                    pathFound = true;
                    break;
                }
			}
		}
	}
	if (pathFound){
		return true;
	}else{
		return false;
	}
    */
}

bool hasPath(bool **edges, int v, int start, int end){
	bool *visited = new bool[v]();
	return hasPathHelper(edges, v, start, end, visited);
	delete[] visited;
}

int main(){
	int v, e;
	cin >> v >> e;
	bool **edges = new bool *[v];
	for (int i = 0; i < v; ++i){
		edges[i] = new bool[v]();
	}
	for (int i = 0, a, b; i < e; ++i){
		cin >> a >> b;
		edges[a][b] = true;
		edges[b][a] = true;
	}
	int start, end;
	cin >> start >> end;
	cout << (hasPath(edges, v, start, end) ? "true" : "false");
	for (int i = 0; i < v; ++i){
		delete[] edges[i];
	}
	delete[] edges;
}

/*-----------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/

/*--------------------- BFS Approach(USING QUEUE )------------------*/

/*
Time complexity: O(V + E) 
Space complexity: O(V^2) 
where V is the number of vertices in the input graph and
E is the number of edges in the input graph 
*/
#include <iostream>
using namespace std;
bool hasPathHelper(bool **graph, int v, int start, int end, bool *visited)
{
	if (start == end){
		return true;
	}
    
	visited[start] = true;
	for (int i = 0; i < v; ++i){
		if (graph[start][i] && !visited[i]){
			if (hasPathHelper(graph, v, i, end, visited)){
				return true;
			}
		}
	}
	return false;
}
bool hasPath(bool **graph, int v, int start, int end)
{
	bool *visited = new bool[v]();
	return hasPathHelper(graph, v, start, end, visited);
	delete[] visited;
}
int main()
{
	int v, e;
	cin >> v >> e;
	bool **graph = new bool *[v];
	for (int i = 0; i < v; ++i){
		graph[i] = new bool[v]();
	}
	for (int i = 0, a, b; i < e; ++i){
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	int start, end;
	cin >> start >> end;
	cout << (hasPath(graph, v, start, end) ? "true" : "false");
	for (int i = 0; i < v; ++i){
		delete[] graph[i];
	}
	delete[] graph;
}
```
### Get Path - DFS && Code : Get Path - DFS

```
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
(print blank space)
```

```cpp
/*Time complexity: O(V + E) 
Space complexity: O(V^2)
where V is the number of vertices in the input edges and 
E is the number of edges in the input edges 
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> *getDFSPathHelper(bool **edges, int v, int start, int end, bool *visited)
{
	if (start == end)
	{
		vector<int> *output = new vector<int> ();
		output->push_back(end);
		return output;
	}
	visited[start] = true;
	for (int i = 0; i < v; ++i)
	{
		if (edges[start][i] && !visited[i])
		{
			vector<int> *smallOutput = getDFSPathHelper(edges, v, i, end, visited);
			if (smallOutput != NULL)
			{
				smallOutput->push_back(start);
				return smallOutput;
			}
		}
	}
	return NULL;
}
vector<int> *getDFSPath(bool **edges, int v, int start, int end)
{
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	vector<int> *output = getDFSPathHelper(edges, v, start, end, visited);
	delete[] visited;
	return output;
}
int main()
{
	int v, e;
	cin >> v >> e;
	bool **edges = new bool *[v];
	for (int i = 0; i < v; ++i)
	{
		edges[i] = new bool[v]();
	}
	for (int i = 0, a, b; i < e; ++i)
	{
		cin >> a >> b;
		edges[a][b] = true;
		edges[b][a] = true;
	}
	int start, end;
	cin >> start >> end;
	vector<int> *output = getDFSPath(edges, v, start, end);
	if (output != NULL)
	{
		for (int i = 0; i < output->size(); ++i)
		{
			cout << output->at(i) << " ";
		}
		delete output;
	}
	for (int i = 0; i < v; ++i)
	{
		delete[] edges[i];
	}
	delete[] edges;
}
```

### Get Path - BFS &&Code : Get Path - BFS

```
Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
(print blank space)
```

```cpp
/*Time complexity: O(V + E) 
Space complexity: O(V^2) 
where V is the number of vertices in the input graph and 
E is the number of edges in the input graph 
*/

#include <iostream>
#include <queue>
#include <vector> 
#include<map>
using namespace std;

vector<int> *getBFSPath(bool **graph, int v, int start, int end)
{
	queue<int> pendingVertices;
	bool *visited = new bool[v]();
	pendingVertices.push(start);
	visited[start] = true;
    
	bool pathFound = false;
    
	// vector<int> parent(v, -1); // using Vector
    map<int, int> parent; // using map , vector or map jekono 1ta use korlei hoy

    
	while (!pendingVertices.empty() && !pathFound)
	{
		int front = pendingVertices.front();
		pendingVertices.pop();
		for (int i = 0; i < v; i++)
		{
			if (graph[front][i] && !visited[i])
			{
            // front holo 1st value. 1st is indicating to the i(th) value. so i(th) value=front add kore pellam.
            // suppost front=0 and i=3, then i=3 ber korte parle 0 peye jabo.
				parent[i] = front; // parent[0]=3
				pendingVertices.push(i);
				visited[i] = true;
                
				if (i == end)
				{
					pathFound = true;
					break;
				}
			}
		}
	}
	delete[] visited;
	if (!pathFound)
	{
		return NULL;
	}
	vector<int> *output = new vector<int> ();
	int current = end; // supost end=3
	output->push_back(end);
	while (current != start)
	{
		current = parent[current]; // so parent[3] = 0, finish.
		output->push_back(current);
	}
	return output;
}
int main()
{
	int v, e;
	cin >> v >> e;
	bool **graph = new bool *[v];
	for (int i = 0; i < v; ++i)
	{
		graph[i] = new bool[v]();
	}
	for (int i = 0, a, b; i < e; ++i)
	{
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	int start, end;
	cin >> start >> end;
	vector<int> *output = getBFSPath(graph, v, start, end);
	if (output != NULL)
	{
		for (int i = 0; i < output->size(); ++i)
		{
			cout << output->at(i) << " ";
		}
		delete output;
	}
	for (int i = 0; i < v; ++i)
	{
		delete[] graph[i];
	}
	delete[] graph;
}
```

### Is Connected ? AND ### Code : Is Connected ?
![image](https://user-images.githubusercontent.com/57065763/183135079-3a2ceb64-4385-4314-ac08-e9b2db613c5b.png)

```
Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
```

```cpp
/*Time complexity: O(V + E) 
Space complexity: O(V^2) 
where V is the number of vertices in the input edges and 
E is the number of edges in the input edges 
*/

#include <iostream>
#include <queue>
using namespace std;

bool BFS(bool **edges, int v, bool *visited, int currentVertex){
    queue<int> vertices;
    vertices.push(currentVertex);
    visited[currentVertex] = true;

    while (!vertices.empty()){
        int current = vertices.front();
        vertices.pop();
        for (int i = 0; i < v; i++){
            if (edges[current][i] && !visited[i]){
                vertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(bool **edges, int v, bool *visited, int currentVertex){
	visited[currentVertex] = true;
	for (int i = 0; i < v; ++i){
		if (edges[currentVertex][i] && !visited[i]){
			DFS(edges, v, visited, i);
		}
	}
}

bool isConnected(bool **edges, int v){
	bool *visited = new bool[v]();
	// DFS(edges, v, visited, 0);
    BFS(edges, v, visited, 0);
    
	for (int i = 0; i < v; ++i){
		if (!visited[i]){
			return false;
		}
	}
	return true;
}
int main(){
	int v, e;
	cin >> v >> e;
	bool **edges = new bool *[v];
	for (int i = 0; i < v; ++i){
		edges[i] = new bool[v]();
	}
	for (int i = 0, a, b; i < e; ++i){
		cin >> a >> b;
		edges[a][b] = true;
		edges[b][a] = true;
	}
	cout << (isConnected(edges, v) ? "true" : "false");
	for (int i = 0; i < v; ++i){
		delete[] edges[i];
	}
	delete[] edges;
}
```

### Return all connected components AND ### Code : All connected components

![image](https://user-images.githubusercontent.com/57065763/183131268-8bf8675c-359d-474f-9eda-fdefc2e5da80.png)

```
Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
```

```cpp
/*
Time complexity: O(V + E) 
Space complexity: O(V^2) 
where V is the number of vertices in the input graph and 
E is the number of edges in the input graph 
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> getOneComponent(bool **graph, int startingVertex, int v, bool *visited){
	vector<int> component;
	queue<int> pendingNodes;
	pendingNodes.push(startingVertex);
	visited[startingVertex] = true;
	while (!pendingNodes.empty()){
		int current = pendingNodes.front();
		pendingNodes.pop();
		component.push_back(current);
		for (int i = 0; i < v; ++i){
			if (graph[current][i] && !visited[i]){
				pendingNodes.push(i);
				visited[i] = true;
			}
		}
	}
	return component;
}
vector<vector < int>> getAllComponents(bool **graph, int v){
	vector<vector < int>> result;
	bool *visited = new bool[v]();
	for (int i = 0; i < v; ++i){
		if (!visited[i]){
			vector<int> component = getOneComponent(graph, i, v, visited);
			result.push_back(component);
		}
	}
	delete[] visited;
	return result;
}

int main(){
	int v, e;
	cin >> v >> e;
	bool **graph = new bool *[v];
	for (int i = 0; i < v; i++){
		graph[i] = new bool[v]();
	}
	for (int i = 0, a, b; i < e; ++i){
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	vector<vector < int>> connectedComponenents = getAllComponents(graph, v);
	for (int i = 0; i < connectedComponenents.size(); i++){
		sort(connectedComponenents[i].begin(), connectedComponenents[i].end());
		for (int j = 0; j < connectedComponenents[i].size(); j++){
			cout << connectedComponenents[i][j] << " ";
		}
		cout << "\n";
	}
}
```

### Weighted & Directed Graphs

![image](https://user-images.githubusercontent.com/57065763/183123586-81ae2ab4-5102-4d96-8f27-ef1925092949.png)

### Islands

```
Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 
```

```cpp
/*
Time complexity: O(V + E)
Space complexity: O(V^2)
where V is the number of vertices in the input graph and
E is the number of edges in the input graph 
*/
#include <iostream>
#include <queue>
using namespace std;


bool BFS(bool **edges, int v, bool *visited, int currentVertex){
    queue<int> vertices;
    vertices.push(currentVertex);
    visited[currentVertex] = true;

    while (!vertices.empty()){
        int current = vertices.front();
        vertices.pop();
        for (int i = 0; i < v; i++){
            if (edges[current][i] && !visited[i]){
                vertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(bool **graph, int v, bool *visited, int currentVertex){
	visited[currentVertex] = true;
	for (int i = 0; i < v; ++i){
		if (graph[currentVertex][i] && !visited[i]){
			DFS(graph, v, visited, i);
		}
	}
}
int getIslandGroups(bool **graph, int v){
	bool *visited = new bool[v]();
	int groupCount = 0;
	for (int i = 0; i < v; ++i){
		if (!visited[i]){
            /*------------- // using DFS ------------------*/
			DFS(graph, v, visited, i); 
            
            /*------------- // using BFS ------------------*/
			BFS(graph, v, visited, i);
			++groupCount;
		}
	}
	return groupCount;
}
int main(){
	int v, e;
	cin >> v >> e;
	bool **graph = new bool *[v];
	for (int i = 0; i < v; ++i){
		graph[i] = new bool[v]();
	}
	for (int i = 0, a, b; i < e; ++i){
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	cout << getIslandGroups(graph, v);
	for (int i = 0; i < v; ++i){
		delete[] graph[i];
	}
	delete[] graph;
}
```

### Coding Ninjas

```
Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
```

```cpp
#include <iostream>
#include <vector>
using namespace std;


/*
Time complexity: O(N *M) 
Space complexity: O(N *M) 
where N and M are the rows and columns respectively of the board 
*/

int validPoint(int x, int y, int n, int m){
	return (x >= 0 && x < n && y >= 0 && y < m);
}

bool dfs(vector<vector < char>> &board, vector< vector< bool>> &used, string &word, int x, int y, int wordIndex, int n, int m){
    
	if (wordIndex == 11){ // OR wordIndex= word.length()
		return true;
	}
    
	used[x][y] = true;
	bool found = false;
	int dXdY[8][2] = {{ -1, -1},{-1, 0},{-1, 1},{ 0, -1 },{ 0, 1 },{ 1, -1 },{ 1, 0 },{ 1, 1 }};
    
    for (int i = 0; i < 8; ++i){
        int newX = x + dXdY[i][0];
        int newY = y + dXdY[i][1];
        if (validPoint(newX, newY, n, m) && board[newX][newY] == word[wordIndex] && !used[newX][newY]){
        	found = found | dfs(board, used, word, newX, newY, wordIndex + 1, n, m);
        }
    }
	used[x][y] = false;
	return found;
}

bool hasPath(vector<vector < char>> &board, int n, int m)
{
	bool foundPath = false;
	string word = "CODINGNINJA";
	vector<vector < bool>> used(n, vector<bool> (m, false));
    
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (board[i][j] == word[0]){
				foundPath = dfs(board, used, word, i, j, 1, n, m);
				if (foundPath) break;
			}
		}
		if (foundPath) break;
	}
	return foundPath;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}
```

### Connecting Dots

```
Connecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.
Output Format :
Print true if there is a cycle in the board, else print false.
Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

/*Time complexity: O(N *M) 
Space complexity: O(N *M) 
where N and M are the rows and columns respectively of the board
*/

void dfs(vector<vector < char>> &board, vector< vector< bool>> &visited, int x, int y, int fromX, int fromY, char sameChar, bool &foundCycle, int n, int m){
	if (board[x][y] != sameChar){
		return;
	}
    
	if (visited[x][y]){
		foundCycle = true;
		return;
	}
    
	visited[x][y] = true;
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };
    
	for (int i = 0; i < 4; ++i){
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX == fromX && nextY == fromY){
			continue;
		}
        
		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n){
			dfs(board, visited, nextX, nextY, x, y, sameChar, foundCycle, n, m);
		}	
	}
}

bool hasCycle(vector<vector < char>> &board, int n, int m){
	bool foundCycle = false;
	vector<vector < bool>> visited(n, vector<bool> (m, false));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (!visited[i][j]){
				dfs(board, visited, i, j, -1, -1, board[i][j], foundCycle, n, m);
			}
		}
	}
	return foundCycle;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}
```

### Largest Piece

```
Largest Piece
Send Feedback
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

/*Time complexity: O(N^2) 
Space complexity: O(N^2) 
where N by N are the dimensions of the cake
*/
// Consider the cake to be connected graph with every vertex connected to its nearby 4 vertices 
int dfs(vector<vector < int>> &cake, vector< vector< bool>> &visited, int x, int y, int n){
	if (visited[x][y]){
		return 0;
	}
	visited[x][y] = true;
	int count = 1;
	int dx[] = { 0, 0, -1, 1 }; // Change in x while taking four moves 
	int dy[] = { 1, -1, 0, 0 }; // Change in y while taking four moves 
    
	for (int i = 0; i < 4; ++i){
		int X = x + dx[i];
		int Y = y + dy[i];
		if (X >= 0 && X < n && Y >= 0 && Y < n && cake[X][Y] == 1){
			count += dfs(cake, visited, X, Y, n);
		}
	}
	return count;
}

int getBiggestPieceSize(vector<vector < int>> &cake, int n)
{
	int biggestPieceSize = 0;
	vector<vector < bool>> visited(n, vector<bool> (n, false));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (cake[i][j] == 1 && !visited[i][j]){
				biggestPieceSize = max(biggestPieceSize, dfs(cake, visited, i, j, n));
			}
		}
	}
	return biggestPieceSize;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}
```

### 3 Cycle

```
3 Cycle

Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
Output Format :
Print the count the number of 3-cycles in the given graph
Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1
```

```cpp
/*Time complexity: O(V^3) 
Space complexity: O(V^2) 
where V is the number of vertices in the input graph and 
E is the number of edges in the input graph 
*/

#include <iostream>
using namespace std;

int getCycles(bool **graph, int v)
{
	int cycleCount = 0;
	for (int i = 0; i < v - 2; ++i){
		for (int j = i + 1; j < v - 1; ++j){
			for (int k = j + 1; k < v; ++k){
				if (graph[i][j] && graph[j][k] && graph[k][i]){
                    ++cycleCount;
				}
			}
		}
	}
	return cycleCount;
}

/*-------------2nd Approach-----------------
int countCycles(bool **arr, long long n){
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j && arr[i][j] == 1){
                for (int k = 0; k < n; k++){
                    if (j != k && k != i && arr[j][k] == 1){
                        if (arr[i][k] == 1){
                            count += 1;
                        }
                    }
                }
            }
        }
    }
    return count;
}
*/

int main()
{
	int v, e;
	cin >> v >> e;
	bool **graph = new bool *[v];
	for (int i = 0; i < v; ++i){
		graph[i] = new bool[v]();
	}
    
	for (int i = 0, a, b; i < e; ++i){
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
    
	cout << getCycles(graph, v);
    
	//(For only 2nd Approach  only) divide by 6, bcz i  will get 3 elements circle 6 times.
	for (int i = 0; i < v; ++i){
    // cout << getCycles(graph, v)/6; 
		delete[] graph[i];
	}
	delete[] graph;
}
```

```

Lecture 20 : Graphs 1 END HERE

```
