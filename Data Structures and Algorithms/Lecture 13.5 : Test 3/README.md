```

Lecture 13.5 : Test 3 START HERE

```

# ##Lecture 13.5 : Test 3

### Check cousins

```
Check cousins

Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
Do it in O(n).
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Line 2 : integer value of p 
Line 3 : Integer value of q
Output format :
true or false
Constraints :
1 <= N <= 10^5
Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4
Sample Output :
true
```

```cpp
/*
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}

*/

/*-------------------------------CODE------------------------*/
int depth(BinaryTreeNode<int> *root, int node){ 
    
    if(root == NULL){ return -1; }
    
    if(node == root->data){ return 0; }
    
    int left = depth(root->left, node);
    
    if(left != -1){
        return left + 1; 
    }
    else { 
        int right = depth(root->right, node); 
        if(right != -1){
            return right + 1;
        }else{ 
            return -1;
        } 
    } 
} 

bool isSibling(BinaryTreeNode<int> *root, int p, int q){ 
    
    if(root==NULL){ return false; }
    
    if(root -> left!=NULL && root -> right !=NULL){ 
        
        if(root->left->data == p && root->right->data == q){ 
            return true;
        }else if(root->left->data == q && root->right->data == p) {
            return true;
        }else{
            return isSibling(root->left, p, q) || isSibling(root->right, p, q);
        }
    }
    
    if(root->right != NULL) {
    	return isSibling(root->right, p, q); 
    }else{
        return isSibling(root->left, p, q);
    }
} 

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    if(root==NULL){ return false; }
    return ((depth(root, p) == depth(root, q)) && (isSibling(root, p, q)==false)); 
}

```

### Longest Leaf to root path

```
Longest Leaf to root path

Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.
Input format :

Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 1 : Binary Tree 1 (separated by space)

Sample Input 1 :
 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
9
3
6
5
```

```cpp
/*
#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}

*/

/*-------------------------------CODE------------------------*/
vector<int>* longestPath(BinaryTreeNode<int>* root) { 
    
    if (root == NULL) { 
        return NULL; 
    } 
    
    if (root->left == NULL  && root->right == NULL) { 
        vector<int>* output = new vector<int>(); 
        output->push_back(root -> data); 
        return output; 
    }
    
    vector<int>* leftAns = longestPath(root->left); 
    vector<int>* rightAns = longestPath(root->right); 
    
    if (leftAns == NULL ) { 
        rightAns->push_back(root->data); 
        return rightAns; 
    }
    else if (rightAns == NULL ) { 
        leftAns->push_back(root->data); 
        return leftAns; 
    } 
    else { 
         if (leftAns->size() >= rightAns->size()) {
            leftAns->push_back(root->data); 
            delete rightAns; 
            return leftAns; 
        } 
        if (leftAns->size() < rightAns->size()) { 
            rightAns->push_back(root->data); 
            delete leftAns; 
            return rightAns; 
        }
    } 
}
```

### Remove leaf nodes in Tree

```
Remove leaf nodes in Tree

Remove all leaf nodes from a given generic Tree. Leaf nodes are those nodes, which don't have any children.
Note : Root will also be a leaf node if it doesn't have any child. You don't need to print the tree, just remove all leaf nodes and return the updated root.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is - `

Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element `
Output Format :
Elements are printed level wise, each level in new line (separated by space)
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 : (Level wise, each level in new line)
10
20
```

```cpp
/*
template <typename T>
class TreeNode {
	TreeNode<T>** children;
	int childCount;
    	int maxChildCount;
	public:
		T data;
		
		TreeNode(T data) {
			this->data = data;
			childCount = 0;
			children = new TreeNode<T>*[10];
		   	maxChildCount = 10;
        }	

		int numChildren() {
			return childCount;
		}

		void addChild(TreeNode<T>* child) {
			children[childCount] = child;
			childCount++;
            if(childCount == maxChildCount) {
	            TreeNode<T>** childrenNew = new TreeNode<T>*[2*maxChildCount];
        	    for(int i = 0; i < maxChildCount; i++) {
	                childrenNew[i] = children[i];
        	     }
	        	 maxChildCount *= 2;
        	        children = childrenNew;
	        }
		}

		TreeNode<T>* getChild(int index) {
			return children[index];
		}

		void setChild(int index, TreeNode<T>* child) {
			children[index] = child;
		}
    
    void removeChild(int i) {
        for(int j = i + 1; j < childCount; j++) {
            children[j - 1] = children[j];
        }
        childCount--;
    }
};

template <typename T>
class Queue {
	T* data;
	int capacity;
	int nextIndex;
	int firstIndex;
	int length;

	public:
		Queue() {
			capacity = 10;
			data = new T[capacity];
			length = 0;
			nextIndex = 0;
			firstIndex = -1;
		}
		
		int size() {
			return length;
		}

		bool isEmpty() {
			return length == 0;
		}

		T front() {
			if (length == 0) {
				return 0;
			}
			return data[firstIndex];
		}
		
		T dequeue() {
			if (length == 0) {
				return 0;
			}

			T output = data[firstIndex];
			length--;
			firstIndex = (firstIndex + 1)%capacity;
			if (length == 0) {
				firstIndex = -1;
				nextIndex = 0;
			}
			return output;
		}

		void enqueue(T element) {
			if (length == capacity) {
				T* temp = data;
				capacity = 2* capacity;
				data = new T[capacity];
				int k = 0;
				for (int i = firstIndex; i < length; i++) {
					data[k] = temp[i];
					k++;
				}
				for (int i = 0; i < firstIndex; i++) {
					data[k] = temp[i];
					k++;
				}
				delete [] temp;
				firstIndex = 0;
				nextIndex = length;
			}
			data[nextIndex] = element;
			length++;
			nextIndex = (nextIndex + 1) % capacity;
			if (firstIndex == -1) {
				firstIndex = 0;
			}
		}

		~Queue() {
			delete [] data;
		}


};

#include <iostream>
using namespace std;
#include "solution.h"

TreeNode<int>* takeInputLevelWise() {
	Queue<TreeNode<int>*> q;
	int rootData;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	q.enqueue(root);
	while (!q.isEmpty()) {
		TreeNode<int>* frontNode = q.dequeue();
		int numChildren;
		cin >> numChildren;
		for (int i = 0; i < numChildren; i++) {
			int childData;
			cin >> childData;
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			q.enqueue(childNode);
			frontNode->addChild(childNode);
		}
	}
	return root;
}

void printLevelATNewLine(TreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    Queue<TreeNode<int>*> q;
    q.enqueue(root);
    q.enqueue(NULL);
    while(!q.isEmpty()) {
        TreeNode<int> *first = q.dequeue();
        if(first == NULL) {
            if(q.isEmpty()) {
                break;
            }
            cout << endl;
            q.enqueue(NULL);
            continue;
        }
        cout << first -> data << " ";
        for(int i = 0; i < first -> numChildren(); i++) {
            q.enqueue(first -> getChild(i));
        }
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    root = removeLeafNodes(root);
    printLevelATNewLine(root);
}

*/

/*-------------------------------CODE------------------------*/
#include <vector> 

TreeNode<int>* removeLeafNodes(TreeNode<int> *root) { 
    if(root == NULL || root -> numChildren() == 0) { 
        return NULL; 
    } 
    
    vector<int> indexes; 
    for(int i = 0; i < root -> numChildren(); i++) { 
        TreeNode<int> *child = root -> getChild(i); 
        if(child -> numChildren() == 0) { 
            indexes.push_back(i); 
        } 
    } 
    
    for(int i = indexes.size()-1; i >= 0; i--) { 
        int j = indexes[i]; 
        root -> removeChild(j); 
    } 
    
    for(int i = 0; i < root -> numChildren(); i++) { 
        TreeNode<int> *child = removeLeafNodes(root -> getChild(i)); 
        if(child == NULL) { 
            root -> removeChild(i); 
        } 
    } 
    return root; 
}
```

```

Lecture 13.5 : Test 3 END HERE

```