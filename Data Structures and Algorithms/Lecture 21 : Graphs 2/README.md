```

Lecture 21 : Graphs 2  START HERE

```

# ##Lecture 21 : Graphs 2

---

//============>>>>>>>>>> Lecture 21 : Graphs 2 Notes

[Lecture 21 : Graphs 2 Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp/files/9333711/Lecture.21.Graphs.2.Notes.pdf)

---

### MST & Kruskals Introduction

![image](https://user-images.githubusercontent.com/57065763/183262350-74039e3e-a54f-4cf5-b57f-2c1c4c9055d4.png)

### Cycle Detection

![image](https://user-images.githubusercontent.com/57065763/183263023-b35eccf4-3a90-4907-a81e-09b09238b437.png)

### Kruskal's Algorithm

![image](https://user-images.githubusercontent.com/57065763/184533628-2f50db31-884b-431a-8968-bb0b1152e6dc.png)

### Code : Kruskal's Algorithm - Solution

```
Code : Kruskal's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
```

```cpp
/*
Time complexity: O(E* log(E)) 
Space complexity: O(V + E) 
where E is the number of edges in the graph and 
V is the number of vertices in the graph 
*/
#include <algorithm>
#include <iostream>
using namespace std;

class Edge
{
	public:
    int source;
	int dest;
	int weight;
	void printEdge()
	{
		cout << min(source, dest) << " " << max(source, dest) << " " << weight;
	}
};
bool compare(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}
int findParent(int v, int *parent)
{
	if (parent[v] == v)
	{
		return v;
	}
	return findParent(parent[v], parent);
}
void printMST(Edge *input, int v, int e)
{
	// Sort the input array in ascending order based on weights 
	sort(input, input + e, compare);
	Edge *output = new Edge[v - 1];
	int *parent = new int[v];
	for (int i = 0; i < v; i++)
	{
		parent[i] = i;
	}
	int count = 0;
	int i = 0;
	while (count != v - 1)
	{
		Edge currentEdge = input[i];
		// Check if we can add the currentEdge in MST or not 
		int sourceParent = findParent(currentEdge.source, parent);
		int destParent = findParent(currentEdge.dest, parent);
		if (sourceParent != destParent)
		{
			output[count] = currentEdge;
			count++;
            parent[destParent] = sourceParent;
			// parent[sourceParent] = destParent;
		}
		i++;
	}
	for (int i = 0; i < v - 1; i++)
	{
		output[i].printEdge();
		cout << "\n";
	}
}
int main()
{
	int v, e;
	cin >> v >> e;
	Edge *input = new Edge[e];
	for (int i = 0; i < e; i++)
	{
		int s, d, w;
		cin >> s >> d >> w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	printMST(input, v, e);
}
```

### Time Complexity of Kruskal's Algorithm

![image](https://user-images.githubusercontent.com/57065763/184539310-d98dee3b-c861-44b6-a17f-d27de30cadef.png)

### Prim's Algorithm AND Code : Prim's Algorithm + Solution

![image](https://user-images.githubusercontent.com/57065763/184542443-08bc3be6-ec73-4bd6-a3d6-77a647fd6903.png)

![image](https://user-images.githubusercontent.com/57065763/184544254-fff7eeea-047d-4ffe-833e-861d9732655e.png)

```
Code : Prim's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
1 <= Wi <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
```

```cpp
/*
Time complexity: O(E* log(V)) 
Space compleity: O(V^2) 
where E is the number of edges in the graph and V is the number of vertices in the graph
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int> &weights, vector<bool> &visited, int v)
{
	int minVertex = -1;
	for (int i = 0; i < v; ++i)
	{
		if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
		{
			minVertex = i;
		}
	}
	return minVertex;
}
void printMST(vector<vector < int>> &graph, int v)
{
	vector<int> parent(v, -1);
	vector<int> weights(v, INT_MAX);
	vector<bool> visited(v, false);
	parent[0] = -1;
	weights[0] = 0;
	for (int i = 0; i < v - 1; ++i)
	{
		// Find Min Vertex 
		int minVertex = findMinVertex(weights, visited, v);
		visited[minVertex] = true;
		// Explore unvisted neighbours 
		for (int j = 0; j < v; ++j)
		{
			if (graph[minVertex][j] != 0 && !visited[j])
			{
				if (graph[minVertex][j] < weights[j])
				{
					weights[j] = graph[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}
	for (int i = 1; i < v; ++i)
	{
		cout << min(parent[i], i) << " " << max(parent[i], i) << " " << weights[i] << "\n";
	}
}

int main()
{
	int v, e;
	cin >> v >> e;
	vector<vector < int>> graph(v, vector<int> (v, 0));
	for (int i = 0, s, d, weight; i < e; ++i)
	{
		cin >> s >> d >> weight;
		graph[s][d] = weight;
		graph[d][s] = weight;
	}
	printMST(graph, v);
}
```

### Time Complexity of Prim's Algorithm

![image](https://user-images.githubusercontent.com/57065763/184544720-b4c4c35c-ca71-4d4f-b14a-b6454bf00ef0.png)

### Dijkstra’s Algorithm AND Code : Dijkstra's Algorithm  && Solution + Time Complexity

![image](https://user-images.githubusercontent.com/57065763/184545977-aa2fc594-d73b-444c-bd79-0138c486525a.png)

![image](https://user-images.githubusercontent.com/57065763/184545699-90ab99f1-7721-488d-a01c-979dead2d48a.png)

```
Code : Dijkstra's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
```

```cpp
/*
Time complexity: O(E* log(V)) 
Space compleity: O(V^2)
where E is the number of edges in the graph and V is the number of vertices in the graph 
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findMinVertex(vector<int> &distance, vector<int> &visited, int v)
{
	int minVertex = -1;
	for (int i = 0; i < v; ++i)
	{
		if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
		{
			minVertex = i;
		}
	}
	return minVertex;
}
void printShortestDistance(vector<vector < int>> &edges, int v)
{
	vector<int> distance(v, INT_MAX);
	vector<int> visited(v, false);
	distance[0] = 0;
	for (int i = 0; i < v - 1; ++i)
	{
		int minVertex = findMinVertex(distance, visited, v);
		visited[minVertex] = true;
		for (int j = 0; j < v; ++j)
		{
			if (edges[minVertex][j] != 0 && !visited[j])
			{
				int dist = distance[minVertex] + edges[minVertex][j];
				if (dist < distance[j])
				{
					distance[j] = dist;
				}
			}
		}
	}
	for (int i = 0; i < v; ++i)
	{
		cout << i << " " << distance[i] << "\n";
	}
}
int main()
{
	int v, e;
	cin >> v >> e;
	vector<vector < int>> edges(v, vector<int> (v, 0));
	for (int i = 0, s, d, weight; i < e; ++i)
	{
		cin >> s >> d >> weight;
		edges[s][d] = weight;
		edges[d][s] = weight;
	}
	printShortestDistance(edges, v);
}
```

```

Lecture 21 : Graphs 2 END HERE

```
