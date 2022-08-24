```

Lecture 11 : Trees START HERE

```

# ##Lecture 11 : Trees

---

//============>>>>>>>>>>Trees Notes
[Lecture 11.1 : Trees Notes .pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/9001527/Lecture.11.1.Trees.Notes.pdf)

//============>>>>>>>>>>Vectors Notes
[Lecture 11.12: Vectors Notes .pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/9001528/Lecture.11.12.Vectors.Notes.pdf)

---

### Trees Introduction
![image](https://user-images.githubusercontent.com/57065763/174455605-526edb11-6927-4a0f-971e-23a289fe08c7.png)

### Vectors
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//vector<int> * vp = new vector<int>();
	vector<int> v;

	for (int i = 0; i < 100; i++) {
		cout << "cap:" << v.capacity() << endl;
		cout << "size:" << v.size() << endl;
		v.push_back(i + 1);
	}

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	v[1] = 100;

	// dont use [] for inserting elements
	//v[3] = 1002;
	//v[4] = 1234;

	v.push_back(23);
	v.push_back(234);

	v.pop_back();

	/*
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}


	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;
	cout << v[3] << endl;
	cout << v[4] << endl;
	cout << v[5] << endl;
	cout << v[6] << endl;

	cout << "Size: " << v.size() << endl;

	cout << v.at(2) << endl;
	cout << v.at(6) << endl;
	*/
}
```

### TreeNode class
```cpp

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode{
public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode (T data){
		this->data = data;
	}
}

int main(){
	TreeNode<int>* root = new TreeNode<int> (1);
	TreeNode<int>* node1 = new TreeNode<int> (2);
	TreeNode<int>* node2  = new TreeNode<int> (3);

	TreeNode->children.push_back(node1);
	TreeNode->children.push_back(node2);
}

```

### Take input and print Recursive
![image](https://user-images.githubusercontent.com/57065763/176167509-8b49f1e6-4489-4445-8b52-48d293fff838.png)

```cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class TreeNode{
public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode (T data){
		this->data = data;
	}
};

TreeNode<int>* takeinput(){
	int rootData;
	cout<<"Enter root data"<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
    
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin>>n;
	for(int i=0; i<n; i++){
		TreeNode<int>* child = takeinput();
		root->children.push_back(child);

	}
	return root;
}


void printTrees(TreeNode<int>* root){
	if(root == NULL){
		return;
	}

	cout<< root->data <<":";

	for(int i=0; i<root->children.size(); i++){
		cout<< root->children[i]->data<<",";
	}	
	cout<<endl;
	for(int i=0; i<root->children.size(); i++){
		printTrees(root->children[i]);
	}
}

int main(){
	// TreeNode<int>* root = new TreeNode<int> (1);
	// TreeNode<int>* node1 = new TreeNode<int> (2);
	// TreeNode<int>* node2  = new TreeNode<int> (3);

	// root->children.push_back(node1);
	// root->children.push_back(node2);
	TreeNode<int>* root = takeinput();
	printTrees(root);
	// TODO delete the tree
}
```

### Take input level wise
![image](https://user-images.githubusercontent.com/57065763/176171403-410d5544-335a-467f-8f70-49ca08b1ae1a.png)

```cpp
#include <iostream>
#include <queue>
using namespace std;

#include <vector>
using namespace std;

template <typename T>
class TreeNode {
	public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T data) {
		this->data = data;
	}
};

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}

int main() {
	/*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	TreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	// TODO delete the tree
}


```

### Print Level Wise

```
Given a generic tree, print the input tree in level wise order.
For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn
where, N is data of any node present in the generic tree. x1, x2, x3, ...., xn are the children of node N. Note that there is no space in between.
You need to print all nodes in the level order form in different lines.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains the elements of the tree in level wise order, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
10:20,30,40
20:40,50
30:
40:
40:
50:

```

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/////////////////================>>>>>>>>>>>>>>>>>>>> Print Level Wise
/************************************************************
Time complexity: O(N) 
Space complexity: O(M) 
where N is the number of nodes in the tree and 
M is the maximum number of nodes in a level
************************************************************/

void printLevelWise(TreeNode<int>* root) { 
    queue<TreeNode<int>*> pendingNodes; 
    pendingNodes.push(root); 
    
    while (!pendingNodes.empty()) { 
        TreeNode<int>* front = pendingNodes.front(); 
        pendingNodes.pop(); 
        cout << front->data << ":"; 
        for (int i = 0; i < front->children.size(); i++) { 
            if (i < ((front->children.size()) - 1)) { 
                cout << front->children[i]->data << ","; 
            } else { 
                cout << front->children[i]->data; 
            } 
            
            pendingNodes.push(front->children[i]); 
        } 
        
        cout << "\n"; 
    } 
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}
```

### Count Nodes
![image](https://user-images.githubusercontent.com/57065763/174493322-4fe009f5-f16f-4f24-856e-330580009ea7.png)

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
	public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T data) {
		this->data = data;
	}

};

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}
/*-----------------------Count Nodes---------------------*/
int numNodes(TreeNode<int>* root) {
	int ans = 1;
	for (int i = 0; i < root->children.size(); i++) {
		ans += numNodes(root->children[i]);
	}
	return ans;
}

int main() {
	/*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	TreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	// TODO delete the tree
}

```

### Code : Find sum of nodes
```
Given a generic tree, find and return the sum of all nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.   
Output Format :
The first and only line of output prints the sum of all nodes of the given generic tree.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
190
```
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
 
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the tree and 
H is the height/depth of the tree

************************************************************/
int sumOfNodes(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return 0;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++){
        sum += sumOfNodes(root->children[i]);    
    }
    
    return sum;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << sumOfNodes(root);
}
```

### Code : Max data node

```
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
Return null if tree is empty.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains the data of the node with largest data in the given tree.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
50
```

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the tree and 
H is the height/depth of the tree
************************************************************/
// https://youtu.be/eJnf0QBg64g
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if (root == NULL) { 
        return root; 
    } 
    
    TreeNode<int>* max = root; 
    
    for (int i = 0; i < root->children.size(); i++) { 
        
        TreeNode<int>* maxChild = maxDataNode(root->children[i]); 
        
        if (maxChild->data > max->data) { 
            max = maxChild; 
        } 
    } 
    return max;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxDataNode(root);

    if (root != NULL) {
        cout << ans->data;
    }
}
```


### Find Height && ### Code : Find height

```
Given a generic tree, find and return the height of given tree.
Input Format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
Output Format :
The first and only line of output prints the height of the given generic tree.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
3
```

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the tree and 
H is the height/depth of the tree
************************************************************/
//////// https://youtu.be/duRYlVs72js
///////// https://youtu.be/HJy6kGGlAWQ

int getHeight(TreeNode<int>* root) { 
    if(root == NULL) { 
        return 0; 
    } 
    
// for (TreeNode<int>* child : root->children) { |
//												 |=>> AUTO WAY
// int childHeight = getHeight(child); 			 |

    int ans = 0; 
    for (int i = 0; i < root->children.size(); i++) { 
        int childHeight = getHeight(root->children[i]); 
        ans = max(ans,childHeight );
        // if (childHeight > ans) { 
        //     ans = childHeight; 
        // } 
    }
    ans++;
    return ans; 
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << getHeight(root);
}
```

### Depth of node
![image](https://user-images.githubusercontent.com/57065763/176179218-35b4a723-1a45-4a34-9259-101a76fe7814.png)

```cpp
void printAtLevelK(TreeNode<int>*root,intk){
  if(root == NULL){
    return;
 }
  if(k==0){
    cout << root->data << endl;
    return;
  }
  for(inti=0;i<root->children.size();i++){
    printAtLevelK(root->children[i],k-1);
 }
}
```

### Count leaf nodes && ### Code : Count leaf nodes

```
Given a generic tree, count and return the number of leaf nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
Output Format :
The first and only line of output prints the count of leaf nodes present in the given tree.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
4
```

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the tree and 
H is the height/depth of the tree
************************************************************/

int getLeafNodeCount(TreeNode<int>* root) {
// Write your code here
    if (root == NULL){
        return 0;
    }
    int count = 0;
    if (root->children.size() == 0){
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++){
        count = count + getLeafNodeCount(root->children[i]);
    }
    return count;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << getLeafNodeCount(root);
}
```

### Traversals-PreOrder + PostOrder
![image](https://user-images.githubusercontent.com/57065763/176180114-00e10fff-b826-4f16-89bb-24a05123c160.png)

![image](https://user-images.githubusercontent.com/57065763/176180218-ec6f3de0-4536-4cfb-9e99-2cf13a3197e6.png)


### Traversals-PreOrder
```cpp
void preorder(TreeNode<int>*root){
  if(root == NULL){
    return;
  }
  cout << root->data <<
  for(inti=0;i<root->children.size();i++){
    preorder(root->children[i]);
  }
}
```
### Code : PostOrder Traversal

```
Given a generic tree, print the post-order traversal of given tree.
The post-order traversal is: visit child nodes first and then root node.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains the elements printed in post-order traversal. The elements in the output must be separated by a single space.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 400 50 0 0 0 0 
Sample Output 1:
400 50 20 30 40 10
```

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the tree and 
H is the height/depth of the tree
************************************************************/

void printPostOrder(TreeNode<int>* root) { 
    if (root == NULL) { 
        return; 
    } 
    
    for (int i = 0; i < root->children.size(); i++) { 
        printPostOrder(root->children[i]); 
    } 
    
    cout << root->data << " "; 
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printPostOrder(root);
}
```

### Destructor
```cpp
/// Delete TreeNode using postOrder
void deleteTree(TreeNode<int>*root){
  for(inti=0;i<root->children.size();i++){
    deleteTree(root->children[i]);
  }
  delete root;
}
```
```cpp
/// Delete TreeNode using dectructor
~TreeNode(){
for(inti=0;i<children.size();i++){
	delete children[i];
}
```


### Contains x
```
Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of x.
Output format :
The first and only line of output contains true, if x is present and false, otherwise.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
40 
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
4 
Sample Output 2:
false
```

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the tree and 
H is the height/depth of the tree
************************************************************/
bool isPresent(TreeNode<int>* root, int x) {
    
    if (root == NULL){
    	return false;
    }
    if (root->data == x) { 
        return true; 
    } 
    
    for (int i = 0; i < root->children.size(); i++) { 
        bool ans = isPresent(root->children[i], x); 
        if (ans == true) { 
            return true; 
        } 
    } 
    
    return false; 
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    cout << (isPresent(root, x) ? "true" : "false");
}
```

### Count nodes

```
Given a tree and an integer x, find and return the number of nodes which contains data greater than x.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of x. 
Output Format :
The first and only line of output prints the count of nodes greater than x.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
35 
Sample Output 1 :
3
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
10 
Sample Output 2:
5
```

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the tree and 
H is the height/depth of the tree
************************************************************/

int getLargeNodeCount(TreeNode<int> *root, int x) { 
    
    int count = 0; 
    
    if (root->data > x) { 
        count = 1; 
    }else{ 
        count = 0; 
    } 
    
    for (int i = 0; i < root->children.size(); ++i) { 
        count += getLargeNodeCount(root->children[i], x); 
    } 
    
    return count; 
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    cout << getLargeNodeCount(root, x);
}
```

### Node with maximum child sum

```
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 
Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
```

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
EASY WAY WITHOUT CREATING A NODE
************************************************************/
/*
void maxSum(TreeNode<int>* root, TreeNode<int>* *maxNode, int* max)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
        sum += root->children[i]->data;
    if (sum > *max)
    {
        *max = sum;
        *maxNode = root;
    }
    for (int i = 0; i < root->children.size(); i++)
        maxSum(root->children[i], maxNode, max);
}
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return NULL;
    TreeNode<int> *maxNode;
    int max = 0;
    maxSum(root, &maxNode, &max);
    return maxNode;
}
*/
/*-------------BY CREATING A CUSTOM NODE--------------*/
#include <climits> 

template <typename T> 

class MaxNodePair {
    public: 
    
    TreeNode<T>* node; 
    int sum; 
}; 

MaxNodePair<int>* maxSumNodeHelper(TreeNode<int>* root) { 
    if (root == NULL) { 
        MaxNodePair<int>* pair = new MaxNodePair<int>(); 
        pair->node = NULL; 
        pair->sum = INT_MIN; 
        return pair; 
    } 
    
    int sum = root->data; 
    for (int i = 0; i < root->children.size(); i++) { 
        sum += root->children[i]->data; 
    } 
    
    MaxNodePair<int>* ans = new MaxNodePair<int>(); 
    ans->node = root; 
    ans->sum = sum; 
    
    for (int i = 0; i < root->children.size(); i++) { 
        MaxNodePair<int>* childAns = maxSumNodeHelper(root->children[i]); 
        if (childAns->sum > ans->sum) { 
            ans = childAns; 
        } 
    } 
    return ans; 
} 

TreeNode<int>* maxSumNode(TreeNode<int>* root) { 
    return maxSumNodeHelper(root)->node; 
}
//************************************************************

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}
```

### Structurally identical

```
Given two generic trees, return true if they are structurally identical. Otherwise return false.
Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.  
Input format :
The first line of input contains data of the nodes of the first tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line of input contains data of the nodes of the second tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output format :
The first and only line of output contains true, if the given trees are structurally identical and false, otherwise.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0
Sample Output 2:
false
```

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the smaller tree and 
H is the height/depth of the smaller tree
************************************************************/

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2) { 
    if (root1 == NULL && root2 == NULL) { 
        return true; 
    } 
    
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) { 
        return false; 
    } 
    
    if ((root1->data != root2->data) || (root1->children.size() != root2->children.size())) { 
        return false; 
    } 
    
    for (int i = 0; i < root1->children.size(); ++i) { 
        TreeNode<int> *child1 = root1->children[i]; 
        TreeNode<int> *child2 = root2->children[i]; 
        if (!areIdentical(child1, child2)) { 
            return false; 
        } 
    } 
    return true; 
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}
```

### Next larger

```
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of n.
Output format :
The first and only line of output contains data of the node, whose data is just greater than n.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
18
Sample Output 1 :
20
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
21
Sample Output 2:
30
```

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the tree and 
H is the height/depth of the tree
************************************************************/

#include <climits> 
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int n) { 
    if (root == NULL) { 
        return root; 
    } 
    bool flag = false; 
    TreeNode<int> *nextLarger = NULL; 
    if (root->data > n) { 
        flag = true; 
        nextLarger = root; 
    } 
    for (int i = 0; i < root->children.size(); i++) { 
        TreeNode<int> *temp = getNextLargerElement(root->children[i], n); 
        if (nextLarger == NULL) { 
            nextLarger = temp; 
        }else if (temp != NULL && temp->data < nextLarger->data) { 
            flag = true; 
            nextLarger = temp; 
        } 
    } 
    return nextLarger; 
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}
```

### Second Largest Element In Tree

```
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
```

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the tree and 
H is the height/depth of the tree
************************************************************/
/************************************************************
////////==========>>>>>>>>>>> normal way
void getSecondLargest(TreeNode<int> *root, TreeNode<int> **secondLargestNode, TreeNode<int> **largestNode)
{
    if (*largestNode == NULL)
        *largestNode = root;
    else if (*secondLargestNode == NULL && (root->data) < ((*largestNode)->data))
        *secondLargestNode = root;
    else if ((root->data) > ((*largestNode)->data))
    {
        *secondLargestNode = *largestNode;
        *largestNode = root;
    }
    else if ((root->data) < ((*largestNode)->data) && (root->data) > ((*secondLargestNode)->data))
        *secondLargestNode = root;
    for (int i = 0; i < root->children.size(); i++)
        getSecondLargest(root->children[i], secondLargestNode, largestNode);
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL || root->children.size() == 0)
        return NULL;
    TreeNode<int> *secondLargestNode = NULL;
    TreeNode<int> *largestNode = NULL;
    getSecondLargest(root, &secondLargestNode, &largestNode);
    return secondLargestNode;
}
************************************************************/
/////////////==========>>>>>>>>. creating a class way
template <typename T> 
class SecondLargestReturnType { 
    public: 
    TreeNode<T> *largest; 
    TreeNode<T> *secondLargest; 
    SecondLargestReturnType(TreeNode<T> *first, TreeNode<T> *second) { 
        this->largest = first; 
        this->secondLargest = second; 
    } 
}; 

SecondLargestReturnType<int> *getSecondLargestNodeHelper(TreeNode<int> *root) { 
    if (root == NULL) { 
        return new SecondLargestReturnType<int>(NULL, NULL); 
    } 
    
    // 1st template
    SecondLargestReturnType<int> *ans = new SecondLargestReturnType<int>(root, NULL); 
    for (int i = 0; i < root->children.size(); i++) { 
        //2nd template
        SecondLargestReturnType<int> *childAns = getSecondLargestNodeHelper(root->children[i]); 
        
        //now compare with both 1st and 2nd template
        if (childAns->largest->data > ans->largest->data) { 
            if (childAns->secondLargest == NULL) { 
                ans->secondLargest = ans->largest; 
                ans->largest = childAns->largest; 
            } else { 
                if (childAns->secondLargest->data > ans->largest->data) { 
                    ans->secondLargest = childAns->secondLargest; 
                    ans->largest = childAns->largest; 
                } else { 
                    ans->secondLargest = ans->largest; 
                    ans->largest = childAns->largest; 
                } 
            } 
        } else { 
            if (ans->largest->data != childAns->largest->data && (ans->secondLargest == NULL || childAns->largest->data > ans->secondLargest->data)) { 
                ans->secondLargest = childAns->largest; 
            } 
        } 
    } 
    return ans; 
} 

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root) { 
    return getSecondLargestNodeHelper(root)->secondLargest; 
}

/*----------------------------------------------------------------
*/

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}
```

### Replace with depth

```
You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
Output format:
The updated tree is printed level wise. Each level is printed in a new line. Please refer to sample output 1 for more details. 
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
0 
1 1 1 
2 2
```

```cpp
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};


/************************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the tree and 
H is the height/depth of the tree  
************************************************************/

void replaceWithDepthValueHelper(TreeNode<int> *root, int depth) { 
    root->data = depth; 
    for (int i = 0; i < root->children.size(); i++) { 
        replaceWithDepthValueHelper(root->children[i], depth + 1);   
    } 
} 

void replaceWithDepthValue(TreeNode<int> *root) { 
    if (root == NULL) { 
        return; 
    } 
    replaceWithDepthValueHelper(root, 0); 
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printLevelATNewLine(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        for (int i = 0; i < first->children.size(); i++) {
            q.push(first->children[i]);
        }
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}
```

```

Lecture 11 : Trees END HERE

```
