# ##Lecture 13 : BST

---

//============>>>>>>>>>>BST Notes
[Lecture 13 : BST  Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/9022831/Lecture.13.BST.Notes.pdf)



---

### BST Introduction
![image](https://user-images.githubusercontent.com/57065763/176425811-b88cfcb2-e293-4bb6-b465-551d53b79239.png)


### Search in BST
```cpp
BinaryTreeNode<int>* findNode(BinaryTreeNode<int>* root, int data) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == data) {
		return root;
	} else if (data < root->data) {
		return findNode(root->left, data);
	} else {
		return findNode(root->right, data);
	}
}
```

### Code: Search in BST

```
Given a BST and an integer k. Find if the integer k is present in given BST or not. You have to return true, if node with data k is present, return false otherwise.
Note: Assume that BST contains all unique elements.
Input Format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.
Output Format:
The first and only line of output contains a boolean value. Print true, if node with data k is present, print false otherwise. 
Constraints:
Time Limit: 1 second
Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1 :
true
Sample Input 2 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 2 :
false
```

```cpp
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;
/**********************************************************
Time complexity: O(H) 
Space complexity: O(H) 
where H is the height of the input BST 
***********************************************************/

bool searchInBST(BinaryTreeNode<int>* root, int k) { 
    if (root == NULL) { 
        return false; 
    } 
    
    if (root->data == k) { 
        return true; 
    } else if (k < root->data) { 
        return searchInBST(root->left, k); 
    } else { 
        return searchInBST(root->right, k); 
    } 
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    cout << ((searchInBST(root, k)) ? "true" : "false");
    delete root;
}
```

### Print Elements in Range

```cpp
void printBetweenK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if (root == NULL) {
		return;
	}

	if (root->data >= k1 && root->data <= k2) {
		cout << root->data << endl;
	}
	if (root->data > k1) {
		printBetweenK1K2(root->left, k1, k2);
	}

	if (root->data <= k2) {
		printBetweenK1K2(root->right, k1, k2);
	}
}
```

### Code: Print Elements in Range

```
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line contains two integers, that denote the value of k1 and k2.
Output Format:
 The first and only line of output prints the elements which are in range k1 and k2 (both inclusive). Print the elements in increasing order.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
Sample Output 1:
6 7 8 10
```

```cpp
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
/**********************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the input BST and 
H is the height of the input BST 
***********************************************************/

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) { 
    if (root == NULL) { 
        return; 
    } 
    
    if (root->data >= k1 && root->data <= k2) { 
        elementsInRangeK1K2(root->left, k1, k2); 
        cout << root->data << " "; 
        elementsInRangeK1K2(root->right, k1, k2); 
    } else if (root->data < k1) { 
        elementsInRangeK1K2(root->right, k1, k2); 
    } else if (root->data > k2) { 
        elementsInRangeK1K2(root->left, k1, k2); 
    } 
}


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
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
}
```

### Check if a Binary Tree is BST

```
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
The first and only line of output contains either true or false.
Constraints :
Time Limit: 1 second
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false
```

```cpp
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
/**********************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the input tree and 
H is the height of the input tree

***********************************************************/

#include <climits> 
bool isBSTHelper(BinaryTreeNode<int> *root, int min, int max) { 
    if (root == NULL) { 
        return true; 
    } 
    
    if (root->data < min || root->data > max) { 
        return false; 
    } 
    bool leftAns = isBSTHelper(root->left, min, root->data); 
    bool rightAns = isBSTHelper(root->right, root->data, max); 
    return leftAns && rightAns; 
} 

bool isBST(BinaryTreeNode<int> *root) { 
    return isBSTHelper(root, INT_MIN, INT_MAX); 
}

/*
// END APPROAACH
int maximum(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return INT_MIN;
	}
	return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return INT_MAX;
	}
	return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return true;
	}

	int leftMax = maximum(root->left);
	int rightMin = minimum(root->right);
	bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
	return output;
}
*/

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}
```

### Check BST - 1
![image](https://user-images.githubusercontent.com/57065763/176509868-0102c2de-f2d2-4138-bdbe-ba7f9bbeac12.png)

![image](https://user-images.githubusercontent.com/57065763/176510081-f4bae013-d7ca-42c8-8be6-9fe2e164ca89.png)

```cpp
int maximum(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return INT_MIN;
	}
	return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return INT_MAX;
	}
	return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return true;
	}

	int leftMax = maximum(root->left);
	int rightMin = minimum(root->right);
	bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
	return output;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << isBST(root) << endl;
	delete root;
}

```

### Check BST - 2

![image](https://user-images.githubusercontent.com/57065763/176520688-df49fd1a-865d-4bfb-bab2-bdda95d0b4b1.png)

```cpp
class IsBSTReturn {
	public:
		bool isBST;
		int minimum;
		int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		IsBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	IsBSTReturn leftOutput = isBST2(root->left);
	IsBSTReturn rightOutput = isBST2(root->right);
	int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
	int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
	bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) &&
		leftOutput.isBST && rightOutput.isBST;
	IsBSTReturn output;
	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTFinal;
	return output;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << isBST(root) << endl;
	delete root;
}
```

### Check BST - 3
```cpp
bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
	if (root == NULL) {
		return true;
	}
	if (root->data < min || root->data > max) {
		return false;
	}
	bool isLeftOk = isBST3(root->left, min, root->data - 1);
	bool isRightOk = isBST3(root->right, root->data, max);
	return isLeftOk && isRightOk;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << isBST(root) << endl;
}
```

### Construct BST from a Sorted Array ||  Code: Construct BST from a Sorted Array:

```
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.
Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, that denote the values of array.
Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.
Constraints:
Time Limit: 1 second
Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4 2 1 3 6 5 7 
```

```cpp
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
/**********************************************************
Time complexity: O(N) 
Space complexity: O(N) 
where N is the number of nodes in the input BST

***********************************************************/
BinaryTreeNode<int>* constructTreeHelper(int* input, int start, int end) { 
    if (start > end) { 
        return NULL; 
    } 
    
    int mid = start + (end-start) / 2; 
    int rootData = input[mid];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData); 
    root->left = constructTreeHelper(input, start, mid - 1); 
    root->right = constructTreeHelper(input, mid + 1, end); 
    return root; 
} 

BinaryTreeNode<int>* constructTree(int* input, int n) { 
    return constructTreeHelper(input, 0, n - 1); 
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void preOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int size;
    cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    delete[] input;
}
```

### BST to Sorted LL || ### Code: BST to Sorted LL

```
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
```

```cpp
#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
/**********************************************************
Time complexity: O(N) 
Space complexity: O(H) 
where N is the number of nodes in the input BST and 
H is the height of the input BST
***********************************************************/
/*
// USING Pair template
pair<Node<int>*,Node<int>*> helper(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<Node<int>*,Node<int>*> p={NULL,NULL};	
    	
        return p;
	}
    pair<Node<int>*,Node<int>*> leftPair=helper(root->left);
    pair<Node<int>*,Node<int>*> rightPair=helper(root->right);
    Node<int>* temp =new Node<int>(root->data);
    
    if(root->left==NULL && root->right==NULL){
        Node<int>* temp=new Node<int>(root->data);
        pair<Node<int>*,Node<int>*> p={temp,temp};	
    	
        return p;
    }
    
    if(rightPair.first==NULL){
        leftPair.second->next=temp;
        pair<Node<int>*,Node<int>*> a={leftPair.first,temp};
        return a;
    }
    if(leftPair.first==NULL){
        temp->next=rightPair.first;
        pair<Node<int>*,Node<int>*> a={temp,rightPair.second};
        return a;
    }
    else{
        leftPair.second->next=temp;
        temp->next=rightPair.first;
    }
    pair<Node<int>*,Node<int>*> ans;
    ans.first=leftPair.first;
    ans.second=rightPair.second;
    return ans;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    pair<Node<int>*,Node<int>*> finaNode;
    finaNode=helper(root);
    return finaNode.first;
}
*/
// creating own Pair Class

class Pair{
public:
    Node<int> *head;
    Node<int> *tail;
};

Pair BST(BinaryTreeNode<int> *root){
    if (root == NULL)
    {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    Node<int> *node = new Node<int>(root->data);

    Pair leftans = BST(root->left);
    Pair rightans = BST(root->right);

    Pair ans;
    if (leftans.head != NULL && rightans.head != NULL){
        ans.head = leftans.head;
        leftans.tail->next = node;
        node->next = rightans.head;
        ans.tail = rightans.tail;
    }else if (leftans.head == NULL && rightans.head == NULL){
        ans.head = node;
        ans.tail = node;
        
    }else if (leftans.head==NULL){
        ans.head = node;
        node->next = rightans.head;
        ans.tail = rightans.tail;
        
    }else if (rightans.head == NULL){
        ans.head = leftans.head;
        leftans.tail->next = node;
        ans.tail = node;
        
    }
    return ans;
}
Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    return BST(root).head;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
```

### Root to Node Path in Binary Tree
```cpp
// jodi na pai tahole root return hobe and left right null hole null er insert hobe
// jodi data peye jai tahole vector a insert kore return kore dibo. 
// then jehetu null nah, tai back jaite jaie ja value pabe sob push kore nibe.
// that's it.
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	
	if (root->data == data) {
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	
	vector<int>* leftOutput = getRootToNodePath(root->left, data);
	if (leftOutput != NULL) {
		leftOutput->push_back(root->data);
		return leftOutput;
	}

	vector<int>* rightOutput = getRootToNodePath(root->right, data);
	if (rightOutput != NULL) {
			rightOutput->push_back(root->data);
			return rightOutput;
	} else {
		return NULL;
	}

}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << isBST(root) << endl;
    delete root;
}
```

### Find Path in BST

```
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.
Output Format :
The first line and only line of output prints the data of the nodes in the path from node k to root. The data of the nodes is separated by single space.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1:
2 5 8
```

```cpp
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;
#include <vector>
/**********************************************************
Time complexity: O(H) 
Space complexity: O(H) 
where H is the height of the input BST
***********************************************************/

vector<int> *getPath(BinaryTreeNode<int> *root, int data) { 
    if (root == NULL) { 
        return NULL; 
    } 
    
    if (root->data == data) { 
        vector<int> *output = new vector<int>; 
        output->push_back(root->data); 
        return output; 
        
    } 
    
    if (data < root->data) { 
        vector<int> *output = getPath(root->left, data); 
        if (output != NULL) { 
            output->push_back(root->data); 
        } 
        return output; 
        
    }else if (data > root->data) {
        vector<int> *output = getPath(root->right, data); 
        if (output != NULL) { 
        	output->push_back(root->data); 
        } 
        return output; 
    }

}


BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if (output != NULL) {
        for (int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}
```

### BST Class

```cpp
#include <iostream>
using namespace std;
class BST {
	BinaryTreeNode<int>* root;

	public:

	BST() {
		root = NULL;
	}

	~BST() {
		delete root;
	}

	private:
	bool hasData(int data, BinaryTreeNode<int>* node) {
		if (node == NULL) {
			return false;
		}

		if (node->data == data) {
			return true;
		} else if (data < node->data) {
			return hasData(data, node->left);
		} else {
			return hasData(data, node->right);
		}
	}

	public:
	bool hasData(int data) {
		return hasData(data, root);
	}
};
```

### BST Class - How to Insert and Delete node ? || ### Code: BST Class || ### BST Class - Insert Delete Solution

```
Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BST or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
```

```cpp
#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


/*
Time complexity: O(H) [for all operations]
Space complexity: O(N)
where N is the number of nodes in the input BST
and H is the height of the input BST
*/

class BST {
    BinaryTreeNode<int>* root; 
    
    public:
    BST() { 
        root = NULL; 
    } 
    
    ~BST() { 
        delete root; 
    } 
    
    private: 
    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* node, int data) { 
        if (node == NULL) { 
            return NULL; 
        } 
        if (data > node->data) { 
            node->right = remove(node->right, data); 
            return node; 
        } else if (data < node->data) { 
            node->left = remove(node->left, data); 
            return node; 
        } else { 
            if (node->left == NULL && node->right == NULL) { 
                delete node; 
                return NULL; 
            } else if (node->left == NULL) { 
                BinaryTreeNode<int>* temp = node->right; 
                node->right = NULL; 
                delete node; 
                return temp; 
            } else if (node->right == NULL) { 
                BinaryTreeNode<int>* temp = node->left; 
                node->left = NULL; 
                delete node; 
                return temp; 
            } else { BinaryTreeNode<int>* minNode = node->right; 
                    while (minNode->left != NULL) { 
                        minNode = minNode->left; 
                    } 
                    int rightMin = minNode->data; 
                    node->data = rightMin; 
                    node->right = remove(node->right, rightMin); return node; 
                   } 
        } 
    } 
    
    void print(BinaryTreeNode<int>* root) { 
        if (root == NULL) { 
            return; 
        } 
        
        cout << root->data << ":"; 
        if (root->left != NULL) { 
            cout << "L:" << root->left->data << ","; 
        } 
        
        if (root->right != NULL) { 
            cout << "R:" << root->right->data; 
        } 
        
        cout << endl; print(root->left); 
        print(root->right); 
    } 
    
    public: 
    void remove(int data) { 
        root = remove(root, data); 
    } 
    
    void print() { 
        print(root); 
    } 
    
    private: 
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int data) { 
        if (node == NULL) { 
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data); 
            return newNode; 
        } if (data <= node->data) { 
            node->left = insert(node->left, data); 
        } else { 
            node->right = insert(node->right, data); 
        } 
        return node; 
    
    } 
    
    public: 
    void insert(int data) { 
        this->root = insert(this->root, data); 
    } 
    
    private: 
    bool search(BinaryTreeNode<int>* node, int data) { 
        if (node == NULL) { 
            return false; 
        } 
        
        if (node->data == data) { 
            return true; 
        } else if (data < node->data) { 
            return search(node->left, data); 
        } 
        return search(node->right, data); 
    } 
    
    public: 
    bool search(int data) { 
        return search(root, data); 
    } 
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}
```

### Types of Balanced BSTs

![image](https://user-images.githubusercontent.com/57065763/176761769-2a757597-deb0-41e8-a5db-f12f28fb583a.png)
![image](https://user-images.githubusercontent.com/57065763/176761896-5948502c-f295-4be5-97f0-0a85b0b04e5e.png)
![image](https://user-images.githubusercontent.com/57065763/176762108-e4e6be16-83d6-457e-af9b-da091f19bf4d.png)


### Create & Insert Duplicate Node
```

```

```cpp

```

### Pair Sum Binary Tree
![image](https://user-images.githubusercontent.com/57065763/176825886-0fc8bb25-9fa9-47ef-8843-1bbed95ab95c.png)
```

```

```cpp

```

### LCA of Binary Tree
![image](https://user-images.githubusercontent.com/57065763/176829400-c81307e7-d501-4f39-b0ca-5f7149beb62c.png)

```

```

```cpp

```

### LCA of BST
```

```

```cpp

```

### Largest BST
```

```

```cpp

```

### Replace with Sum of greater nodes
![image](https://user-images.githubusercontent.com/57065763/176966421-da73e09f-d468-4ea0-a9aa-9e0124b636e0.png)

```

```

```cpp

```

### Path Sum Root to Leaf
![image](https://user-images.githubusercontent.com/57065763/176969005-6060ab76-3b04-4dba-95c9-d94ccfa02f34.png)

```

```

```cpp

```

### Print nodes at distance k from node
![image](https://user-images.githubusercontent.com/57065763/176997151-7fb88bd5-c912-4652-b239-162dda850cd9.png)

```

```

```cpp

```

### Pair sum in a BST
```

```

```cpp

```





