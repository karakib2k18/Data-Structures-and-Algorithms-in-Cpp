# ##Lecture 8 : Linked List 1

---

pdf link here

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
using namespace std;class Node {
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
### Insert node at ith position

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
Node* insertNode(Node *head, int i, int data) {
	Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;

	if(i == 0) { ==>> when i=index is 0 or we can say new node is first node.
		newNode -> next = head;
		head = newNode;
		return head; ==> if we do not return head, then main head will store previous head addres not new head address.
	}

	while(temp != NULL && count < i-1) { ==>Here we start from head=temp then moving temp till previous index of (i).
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
