# ##Lecture 8 : Linked List 1

---

[Lecture 8 : Linked List 1.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/8843858/Lecture.8.Linked.List.1.pdf)

---

### What is Linked List

![image](https://user-images.githubusercontent.com/57065763/172052769-fe2a7281-33f2-4d06-b544-53075b897374.png)
![image](https://user-images.githubusercontent.com/57065763/172053195-ea4508bf-811f-4b49-9f82-2bf8ad4f9b48.png)
![image](https://user-images.githubusercontent.com/57065763/172053327-8fefb139-afb9-4d05-b994-cac6877f0525.png)

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

![image](https://user-images.githubusercontent.com/57065763/172054923-dfc9f741-cce3-48f2-91fe-7d4ff74b2945.png)
![image](https://user-images.githubusercontent.com/57065763/172055699-4b6aa8e9-6279-4f2c-9f94-89bb1294bf11.png)
![image](https://user-images.githubusercontent.com/57065763/172056937-6d52acb0-1a15-49e7-b572-8883f1ab76d6.png)
![image](https://user-images.githubusercontent.com/57065763/172057155-5cbff13e-6f77-43b8-9377-fa3025fc91ac.png)


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
![image](https://user-images.githubusercontent.com/57065763/172212881-45e3fecd-2aa8-4e44-a888-99abc19df0ee.png)
![image](https://user-images.githubusercontent.com/57065763/172216557-8c11e797-44d0-4b14-8297-5ef1776b0c6e.png)
![image](https://user-images.githubusercontent.com/57065763/172217130-6651831b-eeae-4db8-b9b5-715f9948fc64.png)
![image](https://user-images.githubusercontent.com/57065763/172217629-d1e25590-e812-406c-a9b1-1a662d9ff55f.png)

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
<table>
  <tr>
    <td>QUESTION</td>
     <td>CODE</td>
  </tr> 
  <tr> 
    <!-- <td><img src="https://user-images.githubusercontent.com/57065763/172363895-7558d2c4-6f40-4e92-a8ac-466a8eef54a8.png" width=400 height=480></td> -->
    <td><img src="https://user-images.githubusercontent.com/57065763/172363183-777a5441-14d3-41f3-8b18-ee0ff8d50a1c.png" width=400 height=480></td>
    <td><img src="https://user-images.githubusercontent.com/57065763/172363928-97a2ae26-d542-4847-ac8d-74408a97424e.png" width=400 height=480></td>
    <td>
    
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

int length(Node *head){
  int count = 0;
  Node *temp = NULL;
  temp = head;
  while(temp !=NULL){
    count +=1;
    temp = temp->next;
  }
  return count;
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
    </td>
  </tr>
 </table>

### Length of LL

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

int length(Node *head){
  int count = 0;
  Node *temp = NULL;
  temp = head;
  while(temp !=NULL){
    count +=1;
    temp = temp->next;
  }
  return count;
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

### Insert node at ith position
![image](https://user-images.githubusercontent.com/57065763/172123040-2ade74ed-3e98-435f-9904-6e745dc2a451.png)
![image](https://user-images.githubusercontent.com/57065763/172125534-5e2bd1fb-f4fb-449c-bd19-6b24babd21be.png)
![image](https://user-images.githubusercontent.com/57065763/172131756-8fe477e4-412d-47b7-bf20-61cfd741424c.png)
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

### Delete Node at ith position with QUESTION
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

### Insert node recursively

![image](https://user-images.githubusercontent.com/57065763/172144909-82d61218-d11e-4ffe-b579-78936dd1d564.png)
![image](https://user-images.githubusercontent.com/57065763/172146236-884bd0f6-846e-48ec-94fe-5c9a978830b7.png)


```cpp

----------------------------------------------------------------------------------------------------


```

### Insert node recursively

![image](https://user-images.githubusercontent.com/57065763/172146763-4aee9cde-8e81-44e0-8169-30e0b8ff0979.png)

```cpp

----------------------------------------------------------------------------------------------------


```
