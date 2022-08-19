```

Lecture 08 : Linked List 1 START HERE

```
# ##Lecture 8 : Linked List 1

---

[Lecture 8 : Linked List 1.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/8843858/Lecture.8.Linked.List.1.pdf)

---

### What is Linked List
![image](https://user-images.githubusercontent.com/57065763/185605624-8b5d9753-3b26-41b2-a89a-37ad0123de9b.png)

```
==> Each Linked List Node stores his own data and store next node address.
==> Head & Tail. Head== FIrst node AND Tail=Last node.

```

```cpp
#include <iostream>
using namespace std;

class Node {
	public :
	int data;
	Node *next;

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

int main() {
	// Statically
	Node n1(1);
	Node *head = &n1;

	Node n2(2);

	n1.next = &n2;

	cout << n1.data << " " << n2.data << endl;
}
```


### Print the Linked List
![image](https://user-images.githubusercontent.com/57065763/185606120-39fbc427-a0ef-4d9d-82a5-4a49ec32af02.png)

```cpp
==> Print using [Head] Pointer.
--------------------------------------------------------------
void print(Node *head) {
  
  while(head != NULL) {
    cout << head -> data << " ";
    head = head -> next;
  }
}
```

```cpp
==> Print using [NULL] Pointer.
--------------------------------------------------------------
void print(Node *head) {
  Node *temp = head;
  temp = head;
    while(temp != NULL) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
}

```

```cpp
==> Creating Linked List Dynamically. ==>> best practice. becuase it will not delete untill er make it delete.
--------------------------------------------------------------

// Dynamically
Node *n1 = new Node(10);
Node *head = n1;

Node *n2 = new Node(20);
n1 -> next = n2;
print(head);

```

```cpp
==> Creating Linked List Statically. ==> it automatically delete when it complete the work in for or while loop. we can
lost the data in Linked List if we use static memory allowcation.
--------------------------------------------------------------
// Statically
Node n1(1);
Node *head = &n1;

Node n2(2);

Node n3(3);
Node n4(4);
Node n5(5);

n1.next = &n2;
n2.next = &n3;
n3.next = &n4;
n4.next = &n5;

print(head);
print(head);

```

```cpp
#include <iostream>
using namespace std;

class Node {
  public :
  int data;
  Node *next;

  Node(int data) {
    this -> data = data;
    next = NULL;
  }
};

void print(Node *head) {
  //Node *temp = head;
  
  while(head != NULL) {
    cout << head -> data << " ";
    head = head -> next;
  }

  /*
  temp = head;
    while(temp != NULL) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }*/
}

int main() {
  // Statically
  Node n1(1);
  Node *head = &n1;

  Node n2(2);

  Node n3(3);
  Node n4(4);
  Node n5(5);

  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  print(head);

  print(head);
  /*
  n1.next = &n2;

  cout << n1.data << " " << n2.data << endl;

  // Dynamically
  Node *n3 = new Node(10);
  Node *head = n3;
  
  Node *n4 = new Node(20);
  n3 -> next = n4;

  */
}

```
![image](https://user-images.githubusercontent.com/57065763/185608843-c9ab9556-9970-4807-a856-41cf4c346f86.png)

### Take Input - 1 => O(n^2)

```cpp
ONLY SUDO CODE BELLOW ==> Time Complexity O(n^2), because temp is going head to till (n-1) element of the following
linked List. So (1_________n-1) = (n*(n-1))/2 = O(n^2) . Optimized code added in the Take Input-2.
```
```cpp
==>> Sudo Code for Taking input in the Linked List.
------------------------------------------------------------------------------------------------
Node* takeInput() {
	int data;
	cin >> data;
	Node *head = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
		}
		else {
			Node *temp = head;
			while(temp -> next != NULL) {
				temp = temp -> next;
			}
			temp -> next = newNode;
		}

		cin >> data;
	}
	return head;
}

----------------------------------------------------------------------------------------------------

int main() {

	Node *head = takeInput();
	print(head);
}

```

### Take Input - 2 => O(N)

```cpp
Node *tail = NULL;
tail = newNode;
tail = tail -> next;
// OR
// tail = newNode;
```
```cpp
Node* takeInpu_Better() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}

		cin >> data;
	}
	return head;
}
----------------------------------------------------------------------------------------------------
int main() {

	Node *head = takeInpu_Better();
	print(head);
}

```

### Length of LL - QUESTION-1

```
Length of LL

For a given singly linked list of integers, find and return its length. Do it using an iterative method.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains elements of the singly linked list separated by a single space. 

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case, print the length of the linked list.

Output for every test case will be printed in a separate line.
 Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec


Sample Input 1 :
1
3 4 5 2 6 1 9 -1
Sample Output 1 :
7


Sample Input 2 :
2
10 76 39 -3 2 9 -23 9 -1
-1
Sample Output 2 :
8
0

```

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data){
    this->data = data;
    this->next=NULL;
  }
};

Node* inputNode(){

  int data;
  cin>>data;
  Node *head = NULL;
  Node *tail = NULL;
  while(data != -1){
    Node *newNode = new Node(data);
    if(head == NULL){
      head = newNode;
      tail = newNode;
    }else{
      tail->next = newNode;
      tail = newNode;
    }
  cin>> data;
  }
  return head;
}

////////////================================================================================>> Length of LL
/*
Time Complexity : O(n) Space Complexity : O(1) where n is size of singly linked list
*/
int length(Node *head)
{
	int len = 0;
	Node *temp = head;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return len;
}

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while(T--){

    Node *head = inputNode();
    cout<< length(head) <<endl;
  }
  return 0;
}

/*

LinkedIn: https://www.linkedin.com/in/karakib2k18/

*/

```
### Print ith node - QUESTION-2

```
Print ith node ===>>>>
For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.
 
Note :
Assume that the Indexing for the singly linked list always starts from 0.

If the given position 'i',  is greater than the length of the given singly linked list, then don't print anything.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line contains the value of 'i'. It denotes the position in the given singly linked list.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Output format :
For each test case, print the node data at the 'i-th' position of the linked list(if exists).

Output for every test case will be printed in a seperate line.
 
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
i  >= 0
Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
2
Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
9 8 4 0 7 8 -1
3
Sample Output 2 :
3
0

```

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

////////////=============================================================>>>> Printing Node Node

/*
//--------------- not good way-----------------
void printIthNode(Node *head, int i)
{
  Node *current = head;
  int count = 0;
  while(current != NULL){
      if(count==i){
          cout<< current->data <<endl;
          break;
      }
      current = current->next;
      count +=1;
  }
}
*/

/*
Time Complexity : O(min(i, n)) 
Space Complexity : O(1) 
where i is the position of the element to be printed and n is the size of singly linked list 
*/
void printIthNode(Node *head, int i)
{
	int position = 0;
	Node *temp = head;
	while (temp != NULL && position < i)
	{
		position++;
		temp = temp->next;
	}
	if (temp != NULL)
	{
		cout << temp->data;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}
```

### Insert node at ith position
![image](https://user-images.githubusercontent.com/57065763/185606554-54e355e1-c1b2-4622-8ee8-92ede1b453b6.png)
```cpp
//First way
Node *a = temp -> next;
temp -> next = newNode;
newNode -> next = a;

//2nd way
newNode -> next = temp -> next ;
temp -> next = newNode;
```
```cpp
Node* insertNode(Node *head, int i, int data) { ==> As we are return head node so reutrn type Node.
	Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;

	if(i == 0) { ==>> when i=index is 0 or we can say new node is first node.
		newNode -> next = head;
		head = newNode;
		return head; ==>if we donot return head,then main head will store prev head address not new head address
	}

	while(temp != NULL && count < i-1) { ==>Here we start from head=temp then moving temp till previous index (i).
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		Node *a = temp -> next;
		temp -> next = newNode;
		newNode -> next = a;
	}
	return head;
}
----------------------------------------------------------------------------------------------------
	int i, data;
	cin >> i >> data;
	head = insertNode(head, i, data);
	print(head);

```

### Delete Node at ith position
![image](https://user-images.githubusercontent.com/57065763/172142068-8146495e-17fd-47ac-a8fc-40b677726ae0.png)

```cpp
Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    int i = 0;
    Node *current = head;
    if (head == NULL)
        return head;
    if (pos == 0)
    {
        head = current->next;
        delete current;
        return head;
    }
    while (i < pos - 1 && current->next != NULL)
    {
        current = current->next;
        i++;
    }
    if (current->next != NULL)
    {
        Node *temp = current->next->next;
        delete current->next;
        current->next = temp;
    }
    return head;
}
----------------------------------------------------------------------------------------------------
  Node *head = takeinput();
  int pos;
  cin >> pos;
  head = deleteNode(head, pos);
  print(head);

```

### Delete node - QUESTION-3

```
Delete node===>

You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.

Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.

Illustration :
The following images depict how the deletion has been performed.

Image-I :
Alt txt

Image-II :
Alt txt

Input format :
The first line contains an Integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space. 

The second line of each test case contains the integer value of 'POS'. It denotes the position in the linked list from where the node has to be deleted.

 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.

Note:
You are not required to print the output, it has already been taken care of. Just implement the function. 
Constraints :
1 <= T <= 10^2
0 <= N <= 10^5
POS >= 0

Time Limit: 1sec
Sample Input 1 :
1 
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
10 20 30 40 50 60 -1
7
Sample Output 2 :
4 5 2 6 1 9
10 20 30 40 50 60

```

```cpp

#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};



Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

////////////=============================================================>>>> Delete Node
/*
Time Complexity : O(min(I, N))
Space Complexity : O(1)
where I is the position of the node to be deleted and 
N is the size of singly linked list 
*/
Node *deleteNode(Node *head, int pos)
{
    Node *current = head;
    int newPos = 0;
    if(current == NULL){
        return head;
    }
    if(pos==0){
        head = current->next;
        delete current;
        return head;
    }
    while(newPos<pos-1 && current->next != NULL){
        current = current->next;
        newPos++;
    }
    
    if(current->next != NULL){
        Node *temp = current->next->next;
        delete current->next;
        current->next =temp;
    }
    return head;
}


void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}
```

### Length of LL (recursive) - QUESTION-4

```
Length of LL (recursive)

Given a linked list, find and return the length of the given linked list recursively.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains elements of the singly linked list separated by a single space. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Output format :
For each test case, print the length of the linked list.

Output for every test case will be printed in a separate line.
 Constraints :
1 <= t <= 20
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
1 
3 4 5 2 6 1 9 -1
Sample Output 1:
7

```
```cpp
#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
////=================================================================> Length of LL (recursive)
/*
Time complexity: O(N) 
Space complexity: O(N)
where N is the length of the singly linked list
*/
int length(Node *head)
{
	if (head == NULL)
	{
		return 0;
	}
	return 1 + length(head->next);
}
void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        Node *head = takeinput();
        cout << length(head) << "\n";
    }
}

```
### Insert node (recursive) - QUESTION-5
![image](https://user-images.githubusercontent.com/57065763/185607030-6f9c6f1e-44b8-4c9a-8793-c94374531dad.png)

```
Insert node (recursive)

You have been given a linked list of integers. Your task is to write a function that inserts a node at a given position, 'pos'.
Note:
Assume that the Indexing for the linked list always starts from 0.

If the given position 'pos' is greater than length of linked list, then you should return the same linked list without any change. And if position 'pos' is equal to length of input linked list, then insert the node at the last position.
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space. 

The second line of each test case contains two space separated integers, that denote the value of 'pos' and the data to be inserted respectively. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format:
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.
You don't need to print explicitly, it has been taken care of.
Constraints:
1 <= t <= 20
0 <= length of linked list <= 10^4
0 <= pos, data to be inserted <= 2^31 - 1
Time Limit: 1 second
Sample Input 1:
1
3 4 5 2 6 1 9 -1
3 100
Sample Output 1:
3 4 5 100 2 6 1 9
Sample Input 2:
1 
3 4 5 2 6 1 9 -1
0 20
Sample Output 2:
20 3 4 5 2 6 1 9

```

```cpp
#include <iostream>
using namespace std;


class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

////////////////////////////================>> Recursive process
////////////////////////////================>> Recursive process
/*
Time complexity: O(N) 
Space complexity: O(N) 
where N is the length of the singly linked list
*/
Node* insertNode(Node *head, int pos, int data)
{
	if (head == NULL)
	{
		if (pos == 0)
		{
			Node *newnode = new Node(data);
			return newnode;
		}
		return head;
	}
	Node *newnode = new Node(data);
	if (pos == 0)
	{
		newnode->next = head;
		head = newnode;
		return head;
	}
	
    // Amra next line a khane position komaite komaite 0 te gia then 0th element add kore disi.
    // Then add korar porer LInked LIst ta [Node *afterRecursionLL] a store korsi.
    // then sheta ke head->next er sathe add kore disi. bas kaj sesh
    Node *afterRecursionLL = insertNode(head->next, pos - 1, data); 
    head->next = afterRecursionLL;
    return head;
}

////////////////////////////================>> Iterative process
/*
Node* insertNode(Node *head, int i, int data) {
    int currentPos = 0;
    Node *temp = head;
    Node *newNode = new Node(data); 
    if(i==0){
        newNode->next = head ;
        head = newNode;
        return head;
    }

    while(currentPos < i-1 && temp->next != NULL){
        temp = temp->next;
        currentPos++;
    }

    if(temp->next != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head; 
}
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}
```

### Delete node (recursive) - QUESTION-6

```
Delete node (recursive)

Given a singly linked list of integers and position 'i', delete the node present at the 'i-th' position in the linked list recursively.
 Note :
Assume that the Indexing for the linked list always starts from 0.

No need to print the list, it has already been taken care. Only return the new head to the list.
 input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'i'.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M

Time Limit:  1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Sample Input 2 :
2
30 -1
0
10 20 30 50 60 -1
4
Sample Output 2 :
10 20 30 50 

```

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

////////////// ========================================>> Recursive Process

/* Time Complexity : O(n)
Space Complexity : O(n)
where n is the size of singly linked list
*/ 

Node *deleteNodeRec(Node *head, int pos)
{
    if(head==NULL){
        return head;
    }
    if(pos==0){
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    // Amra next line a khane position komaite komaite 0 te gia then 0th element delete kore disi.
    // Then delete korar porer LInked LIst ta [Node *afterRecursionLL] a store korsi.
    // then sheta ke head->next er sathe add kore disi. bas kaj sesh
    Node *afterRecursionLL = deleteNodeRec(head->next, pos-1); 
    head->next = afterRecursionLL;
    return head;
}


/*****************************************************************

////////////// ========================================>> Iterative Process

Node *deleteNodeRec(Node *head, int pos)
{
    Node *current = head;
    int newPos = 0;
    if(current == NULL){
        return head;
    }
    if(pos==0){
        head = current->next;
        delete current;
        return head;
    }
    while(newPos<pos-1 && current->next != NULL){
        current = current->next;
        newPos++;
    }
    
    if(current->next != NULL){
        Node *temp = current->next->next;
        delete current->next;
        current->next =temp;
    }
    return head;
}

*****************************************************************/

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNodeRec(head, pos);
		print(head);
	}

	return 0;
}
```
### Find a Node in Linked List - QUESTION-7

```
Find a Node in Linked List

You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.
Note :
Assume that the Indexing for the singly linked list always starts from 0.
Input format :
The first line contains an Integer 'T' which denotes the number of test cases. 

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 

The second line contains the integer value 'N'. It denotes the data to be searched in the given singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence -1 would never be a list element.
Output format :
For each test case, return the index/position of 'N' in the singly linked list. Return -1, otherwise.

Output for every test case will be printed in a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
 Constraints :
1 <= T <= 10^2
0 <= M <= 10^5

Where 'M' is the size of the singly linked list.

Time Limit: 1 sec
Sample Input 1 :
2
3 4 5 2 6 1 9 -1
5
10 20 30 40 50 60 70 -1
6
Sample Output 1 :
2
-1
 Explanation for Sample Output 1:
In test case 1, 'N' = 5 appears at position 2 (0-based indexing) in the given linked list.

In test case 2, we can see that 'N' = 6 is not present in the given linked list.
Sample Input 2 :
2
1 -1
2
3 4 5 2 6 1 9 -1
6
Sample Output 2 :
-1
4
 Explanation for Sample Output 2:
In test case 1, we can see that 'N' = 2 is not present in the given linked list.

In test case 2, 'N' = 6 appears at position 4 (0-based indexing) in the given linked list.

```

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};



Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

////////////////================================>>>>>>>Find a Node in Linked List
/*
Time Complexity : O(N) 
Space Complexity : O(1) 
Where 'N' is the size of singly linked list. */
int findNode(Node *head, int n)
{
	// Variable to maintain the position in the list. 
	int pos = 0;
	while (head != NULL)
	{
		// If element found, return the position of the element. 
		if (head->data == n)
		{
			return pos;
		}
		pos++;
		head = head->next;
	}
	return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}
```

### AppendLastNToFirst - QUESTION-8

```
AppendLastNToFirst

You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 

The second line contains the integer value 'N'. It denotes the number of nodes to be moved from last to the front of the singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
0 <= N < M
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5
Sample Output 1 :
3 4 5 1 2
20 30 40 50 60 10
Sample Input 2 :
1
10 6 77 90 61 67 100 -1
4
Sample Output 2 :
90 61 67 100 10 6 77 
 Explanation to Sample Input 2 :
We have been required to move the last 4 nodes to the front of the list. Here, "90->61->67->100" is the list which represents the last 4 nodes. When we move this list to the front then the remaining part of the initial list which is, "10->6->77" is attached after 100. Hence, the new list formed with an updated head pointing to 90.

```

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
	
/*------------------------------------------CODE--------------------------------------*/

//////// VIDEO explain===============>>>>>>>>>>>.https://youtu.be/v6g1g4lNowM

// at first find the length then [length-ath] Node;
// then jet pabo oitar hobe tail and head head e thakbe.
// newNode create korbo at [ath] elements and NULL porjontoto jabo. 
// NULL Khuje pele Null er jaygay head ke add kore dibo and tail porjontoo add kore dibo.
// time=O(n) and space O(1)

// Using length techniquer 1st Approach
int nodeLength(Node *head){
    if(head==NULL){
        return 0;
    }
    return 1 + nodeLength(head->next);
}


Node *appendLastNToFirst(Node *head, int n)
{
    int length = nodeLength(head);
    Node *newTail;
    Node *newHead;
    Node *tail = head;
    int element = 1;
    if(n<length && n!=0){
        int skip = length - n;
        while(tail->next !=NULL){
            if(skip==element){
                newTail = tail;
            }
            if(skip+1==element){
                newHead = tail;
            }
            tail = tail->next;
            element++;
        }

        newTail->next = NULL;
        tail->next = head;
        head = newHead;
    }
    return head;
}

// using skiping technique 2nd Approach
/*
Time Complexity : O(n) 
Space Complexity : O(1) 
where n is the size of singly linked list 
*/
Node* appendLastNToFirst(Node *head, int n)
{
	if (n == 0 || head == NULL)
	{
		return head;
	}
	Node *fast = head;
	Node *slow = head;
	Node *initialhead = head;
	for (int i = 0; i < n; i++)
	{
		fast = fast->next;
	}
	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	Node *temp = slow->next;
	slow->next = NULL;
	fast->next = initialhead;
	head = temp;
	return head;
}	cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
```




### Eliminate duplicates from LL - QUESTION-9

```
Eliminate duplicates from LL

You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements(in ascending order) of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
 Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
1 2 3 3 3 3 4 4 4 5 5 7 -1
Sample Output 1 :
1 2 3 4 5 7 
Sample Input 2 :
2
10 20 30 40 50 -1
10 10 10 10 -1
Sample Output 2 :
10 20 30 40 50
10

```

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

////////////////////////////================>> Eliminate duplicates from LL
/*
Time Complexity : O(n) Space Complexity : O(1) where n is the size of singly linked list */
Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL){
    	return head;
    }
    
    Node *current = head;

    while(current->next != NULL){
        if(current->data == (current->next->data)){
            Node *temp = current->next->next;
            delete current->next;
            current->next = temp;
        }else{
            current= current->next;
        }
    }
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}
```


### Print Reverse LinkedList - QUESTION-10

```
Print Reverse LinkedList
Send Feedback
You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.
Note :
You can’t change any of the pointers in the linked list, just print it in the reverse order.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Constraints :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Output format :
For each test case, print the singly linked list of integers in a reverse fashion, in a row, separated by a single space.

Output for every test case will be printed in a seperate line.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^3
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
1 2 3 4 5 -1
Sample Output 1 :
5 4 3 2 1
Sample Input 2 :
2
1 2 3 -1
10 20 30 40 50 -1
Sample Output 2 :
3 2 1
50 40 30 20 10

```
/*-------------//////// =====>>>>>>>>>> Iterative Process---------------------------*/
![image](https://user-images.githubusercontent.com/57065763/185675184-b3b416c5-9844-4a1b-b5eb-1499268141d9.png)

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

////////////======>>>>>>>>>https://youtu.be/bjtMCwy_LMA


///////////// ==========>>>>>>>>>> Recursive Process
/*Time Complexity : O(n) Space Complexity : O(n) where n is the size of singly linked list */
void printReverse(Node *head)
{
    if(head == NULL){
        return;
    }
    printReverse(head->next);
    cout<< head->data <<" ";

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		printReverse(head);
		cout << endl;
	}
	return 0;
}

```


### Palindrome LinkedList - QUESTION-11

```
Palindrome LinkedList

You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
 Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.

```

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

///////////// ==========>>>>>>>>>>Palindrome LinkedList

/*----------------------------HARD AND LARGE WAY  USING REVERSE----------------------------*/
/*
Time Complexity : O(n) Space Complexity : O(1) where n is the size of singly linked list 
*/

Node* reverseLinkedList(Node *head)
{
	Node *curr = head;
	Node *prev = NULL;
	Node *fwd = NULL;
	while (curr != NULL)
	{
		fwd = curr->next;
		curr->next = prev;
		prev = curr;
		curr = fwd;
	}
	return prev;
}
bool isPalindrome(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	// Find center of list 
	Node *fast = head;
	Node *slow = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node *secondHead = slow->next;
	slow->next = NULL;
	secondHead = reverseLinkedList(secondHead);
	//Compare the two sublists 
	Node *firstSubList = head;
	Node *secondSubList = secondHead;
	bool ans = true;
	while (secondSubList != NULL)
	{
		if (firstSubList->data != secondSubList->data)
		{
			ans = false;
			break;
		}
		firstSubList = firstSubList->next;
		secondSubList = secondSubList->next;
	}
	//Rejoin the two sublists 
	firstSubList = head;
	secondSubList = reverseLinkedList(secondHead);
	while (firstSubList->next != NULL)
	{
		firstSubList = firstSubList->next;
	}
	firstSubList->next = secondSubList;
	return ans;
}

/*----------------------------EASY WAY(DELETE THE END AND MOVE HEAD TO NEXT)----------------------------*/
bool isPalindrome(Node *head)
{
   if(head == NULL || head->next== NULL){
       return true;
   }
    
    Node *cur = head;
    Node *prev = NULL;
    
    while(cur->next != NULL){
        prev = cur;
        cur = cur->next;
    }
    
    if(head->data == cur->data){
        prev->next = NULL;
        delete cur;
        isPalindrome(head->next);
    }else{
        return false;
    }

//https://youtu.be/ee-DuKtRNGw
// https://youtu.be/-DtNInqFUXs
    
}


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}

```

```

Lecture 08 : Linked List 1 END HERE

```