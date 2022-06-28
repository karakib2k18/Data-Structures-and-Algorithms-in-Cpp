# ##Lecture 11 : Trees

---

//============>>>>>>>>>>ADT Notes

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
int numNodes(TreeNode<int>*root){
  int ans=1;
  for(inti=0;i<root->children.size();i++){
    ans+=numNodes(root->children[i]);
 }
  return ans;
}
```

### Code : Find sum of nodes
```cpp
=================================================>>>>>>>>>>>>>>>>>>.QUESTION.root
```

### Code : Max data node
0/480

### Find Height
02:39

### Code : Find height
0/240

### Depth of node
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

### Count leaf nodes
01:41

### Code : Count leaf nodes
0/240

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
0/240

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
