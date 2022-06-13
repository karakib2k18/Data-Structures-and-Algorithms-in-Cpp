# ##Lecture 9 : Linked List 2

---

[Lecture 9 : Linked List 2.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/8872461/Lecture.9.Linked.List.2.pdf)


---

### Midpoint of LL

![image](https://user-images.githubusercontent.com/57065763/172657102-23fc6684-7219-436f-a7f2-12598c93f65b.png)
![image](https://user-images.githubusercontent.com/57065763/172658080-7a198d73-437e-4f50-8a81-8034f1764fd2.png)


### Code: Midpoint of LL - QUESTION-1


```
For a given singly linked list of integers, find and return the node present at the middle of the list.
Note :
If the length of the singly linked list is even, then return the first middle node.

Example: Consider, 10 -> 20 -> 30 -> 40 is the given list, then the nodes present at the middle with respective data values are, 20 and 30. We return the first node with data 20.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space. 
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
 Output Format :
For each test case/query, print the data value of the node at the middle of the given list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5 
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 -1
Sample Output 1 :
3
Sample Input 2 :
2 
-1
1 2 3 4 -1
Sample Output 2 :
2
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

//////////////////===================>>>>>>>>>> Code: Midpoint of LL
Node *midPoint(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *slow = head;
    Node *fast=head;
    
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}

```


### Merge Two Sorted Linked Lists

![image](https://user-images.githubusercontent.com/57065763/172669468-11980e76-f6d0-4dd9-b937-f756c37d449b.png)


### Code: Merge Two Sorted LL - QUESTION- 2


```
### Code: Merge Two Sorted LL - QUESTION- 2

You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
Note :
Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space. 

The second line of the input contains the elements of the second sorted singly linked list separated by a single space. 
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output :
For each test case/query, print the resulting sorted singly linked list, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t = 10^2
0 <= N <= 10 ^ 4
0 <= M <= 10 ^ 4
Where N and M denote the sizes of the singly linked lists. 

Time Limit: 1sec
Sample Input 1 :
1
2 5 8 12 -1
3 6 9 -1
Sample Output 1 :
2 3 5 6 8 9 12 
Sample Input 2 :
2
2 5 8 12 -1
3 6 9 -1
10 40 60 60 80 -1
10 20 30 40 50 60 90 100 -1
Sample Output 2 :
2 3 5 6 8 9 12 
10 10 20 30 40 40 50 60 60 60 80 90 100
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

/////////////=============>>>>>>>>> Code: Merge Two Sorted LL

Node *mergeTwoSortedLinkedLists(Node *h1, Node *h2)
{
    Node *fh = NULL;
    Node *ft = NULL;
    
    if(h1 == NULL && h2 == NULL){
        return fh;
    }
    if(h1 == NULL){
        return h2;
    }
    
    if(h2 == NULL){
        return h1;
    }
    
    if((h1->data) <= (h2->data)){
        fh=h1;
        ft=h1;
        h1=h1->next;
    }else if((h2->data)<(h1->data)){
        fh=h2;
        ft=h2;
        h2=h2->next;
    }
    
    while(h1 !=NULL && h2 != NULL){
        if((h1->data) <= (h2->data)){
            ft->next = h1;
            ft=h1;
            h1=h1->next;
        }else if((h2->data)<(h1->data)){
            ft->next = h2;
            ft=h2;
            h2=h2->next;
        }
    }
    
    if(h2 ==NULL && h1 != NULL){
        while(h1 != NULL){
            ft->next = h1;
            ft=h1;
            h1=h1->next;
        }
    } else if(h1 ==NULL && h2 != NULL){
        while(h2 != NULL){
            ft->next = h2;
            ft=h2;
            h2=h2->next;
        }
    }
    ft->next = NULL;
    return fh;
    
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
```


### Merge Sort in Linked List

![image](https://user-images.githubusercontent.com/57065763/172781064-b91e990f-ef7f-49f2-b8d9-caa2796fb248.png)
![image](https://user-images.githubusercontent.com/57065763/172781361-a484391e-0622-4bf1-b923-7887779e2c89.png)


### Code: Merge Sort - QUESTION-3


```
Code: Merge Sort
 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 

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

//////////=============>>>>>>>>>>>>>>>>> Code: Merge Sort LInked List

// finding the mid
Node *findMid(Node *head){
    Node *slow=head;
    Node *fast=head;
    
    while(fast->next !=NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

////merging two sorted LL
Node *mergeTwoSortedLinkedLists(Node *h1, Node *h2)
{
    Node *fh = NULL;
    Node *ft = NULL;
    
    if(h1 == NULL && h2 == NULL){
        return fh;
    }
    if(h1 == NULL){
        return h2;
    }
    
    if(h2 == NULL){
        return h1;
    }
    
    if((h1->data) <= (h2->data)){
        fh=h1;
        ft=h1;
        h1=h1->next;
    }else if((h2->data)<(h1->data)){
        fh=h2;
        ft=h2;
        h2=h2->next;
    }
    
    while(h1 !=NULL && h2 != NULL){
        if((h1->data) <= (h2->data)){
            ft->next = h1;
            ft=h1;
            h1=h1->next;
        }else if((h2->data)<(h1->data)){
            ft->next = h2;
            ft=h2;
            h2=h2->next;
        }
    }
    
    if(h2 ==NULL && h1 != NULL){
        while(h1 != NULL){
            ft->next = h1;
            ft=h1;
            h1=h1->next;
        }
    } else if(h1 ==NULL && h2 != NULL){
        while(h2 != NULL){
            ft->next = h2;
            ft=h2;
            h2=h2->next;
        }
    }

    ft->next = NULL;
    return fh;
}

//// everything is processing from here
Node *mergeSort(Node *head)
{
	if(head == NULL || head->next==NULL){
        return head;
    }
    
    // finding the mid
    Node *mid = findMid(head);
    //then naming the mid+1 to the head1
    Node *head1 = mid->next;
    //then making mid next equal to NULL
    mid->next=NULL;
    
    //doing recursion to divide
    head = mergeSort(head);
    head1 = mergeSort(head1);
    
    // then concor or merging to sorted LL
    return mergeTwoSortedLinkedLists(head, head1);
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}

```

### Code : Reverse LL (Recursive) - QUESTION-4

```
Code : Reverse LL (Recursive)

Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. You have to do this in O(N) time complexity where N is the size of the linked list.
 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^4
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
Sample Output 1 :
8 7 6 5 4 3 2 1
Sample Input 2 :
2
10 -1
10 20 30 40 50 -1
Sample Output 2 :
10 
50 40 30 20 10 

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

/////////////////////=================>>>>>>>>>>>>>Code : Reverse LL (Recursive)

/*
//////=======> Almost iterative process
Node* swiftHeadTail(Node *head, Node* tail){
    Node *current = head;
    
    if(current != tail){
        int temp = current-> data;
        current->data = tail-> data;
        tail->data = temp;

        while(current->next != tail){
            current= current->next;
        }
        if(head->next ==tail){
            return head;
        }
        swiftHeadTail(head->next, current);
        
    }else{
        return head;
    }
    
}

Node *reverseLinkedListRec(Node *head)
{
    if (head == NULL){
        return head;
    }
    
    Node *tail = head;
    while(tail->next !=NULL){
        tail = tail->next;
    }
    
    swiftHeadTail(head, tail);
    
    return head;
}
*/

///////==============>>>>>> Recursive Process
Node *reverseLinkedListRec(Node *head) {
    
    // O(N) ==>best approach
    if (head == NULL || head->next == NULL) { 
        return head; 
    } 
    
    Node *smallhead = reverseLinkedListRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallhead;
    
    /*
    // O(N^2) so not good
    if (head == NULL || head->next == NULL) { 
    	return head; 
    } 
    
	Node *smallAns = reverseLinkedListRec(head -> next);

	Node *temp = smallAns;
	while(temp -> next != NULL) {
		temp = temp -> next;
	}

	temp -> next = head;
	head -> next = NULL;
	return smallAns;
    */
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}
```

### Reverse LL (Recursive) => O(N^2)

![image](https://user-images.githubusercontent.com/57065763/172867183-c0954a79-9820-4710-8f86-1e5c2bd44dfd.png)
![image](https://user-images.githubusercontent.com/57065763/172875235-be477015-e732-4f09-9823-a94af18d0f5c.png)
![image](https://user-images.githubusercontent.com/57065763/172875803-73a33bb8-d80e-4ca6-824e-7779f059ee90.png)


```cpp
/////////==============>>>>>>>>>> This is O(N^2) ==>>>>> It's bad, will see the O(N) bellow.
Node* reverseLL(Node *head) {
	if(head == NULL || head -> next == NULL) {
		return head;
	}

	Node *smallAns = reverseLL(head -> next);

	Node *temp = smallAns;
	while(temp -> next != NULL) {
		temp = temp -> next;
	}

	temp -> next = head;
	head -> next = NULL;
	return smallAns;
}
```

### Reverse LL (Recursive) {boring Approach but effective for learning new things using Class+Objects} => O(N)

![image](https://user-images.githubusercontent.com/57065763/172878988-d19c03e1-f73a-4132-89f1-ddea8006a712.png)

```cpp
/////////==============>>>>>>>>>> This is O(N) ==>>>>> but better and easy approach is bellow.
class Pair {
	public :
		Node *head;
		Node *tail;
};

Pair reverseLL_2(Node *head) {
	if(head == NULL || head -> next == NULL) {
		Pair ans;
		ans.head = head;
		ans.tail = head;
		return ans;
	}

	Pair smallAns = reverseLL_2(head -> next);

	smallAns.tail -> next = head;
	head -> next = NULL;
	Pair ans;
	ans.head = smallAns.head;
	ans.tail = head;
	return ans;
}

Node* reverseLL_Better(Node *head) {
	return reverseLL_2(head).head;
}
```
### Reverse LL (Recursive) - O(n) =====>> Best and Easy approach

![image](https://user-images.githubusercontent.com/57065763/172882740-7e3ec351-d659-4275-9fd1-93ceb24045aa.png)


```cpp
/////////==============>>>>>>>>>> This is O(N) ==>>>>> Best and better approach

Node* reverseLL_3(Node *head) {
	if(head == NULL || head -> next == NULL) {
		return head;
	}

	Node *smallAns = reverseLL_3(head -> next);

	Node *tail = head -> next;
	tail -> next = head;
	head -> next = NULL;
	return smallAns;
}
```
### Reverse LL (Iterative)

![image](https://user-images.githubusercontent.com/57065763/172886651-dd825038-eca5-43f1-ab86-30c768a427e2.png)
![image](https://user-images.githubusercontent.com/57065763/172892462-31bfe4f1-90c2-47ec-87be-b9c2ac836392.png)


### Code : Reverse LL (Iterative)- QUESTION-5

```
Code: Reverse LL (Iterative)

Given a singly linked list of integers, reverse it iteratively and return the head to the modified list.
 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a separate line.
 Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
Where N is the size of the singly linked list.

Time Limit: 1 sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
Sample Output 1 :
8 7 6 5 4 3 2 1
Sample Input 2 :
2
10 -1
10 20 30 40 50 -1
Sample Output 2 :
10 
50 40 30 20 10 

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
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
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

/////////////===============>>>>>>>>>>>>>> Code: Reverse LL (Iterative)
Node* reverseLinkedList(Node* head) {
    Node *currentNode = head;
    Node *previousNode = NULL;
    
    while (currentNode != NULL) { 
        Node *nextNode = currentNode->next; 
        currentNode->next = previousNode; 
        previousNode = currentNode; 
        currentNode = nextNode; 
    } 
    
    head = previousNode;
    return head;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}

```

### Variations of LL

![image](https://user-images.githubusercontent.com/57065763/172900453-9823092a-219a-4670-b211-f9a2521828a2.png)
![image](https://user-images.githubusercontent.com/57065763/172900852-2f377af0-a172-4de9-af61-418387cdd1bc.png)
![image](https://user-images.githubusercontent.com/57065763/172901242-0e987754-30a5-4178-a39a-3e780b474884.png)
![image](https://user-images.githubusercontent.com/57065763/172901558-bb0d9f59-f99c-417c-b077-2316b2a909d8.png)


![image](https://user-images.githubusercontent.com/57065763/172903772-263c07ac-060c-42ba-9481-ec85eacef037.png)
![image](https://user-images.githubusercontent.com/57065763/172903652-a3db23f7-e93a-4512-a239-6203290ee302.png)
![image](https://user-images.githubusercontent.com/57065763/172903613-65111eda-d161-4aae-9ee6-1f5587be9e78.png)

![image](https://user-images.githubusercontent.com/57065763/172903566-fda17154-94e6-48f7-9579-ac9bcf4151eb.png)


### Code : ### Code : Reverse LL (Iterative)- QUESTION-6


```
Given a singly linked list of integers and an integer n, find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.
Follow a recursive approach to solve this.
Note :
Assume that the Indexing for the linked list always starts from 0.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'n'.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
 Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit:  1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
100
Sample Output 1 :
-1
Sample Input 2 :
2
10 20010 30 400 600 -1
20010
100 200 300 400 9000 -34 -1
-34
Sample Output 2 :
1
5

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


////////////////================>>>>>>>>>>> Find a node in LL (recursive)

int findNodeRec(Node *head, int n){
    if(head == NULL)
        return -1;
    
    if(head -> data == n)
        return 0;
    int smallAns = findNodeRec(head -> next, n);
    if(smallAns == -1)
        return smallAns;
    else
        return 1 + smallAns;
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
		cout << findNodeRec(head, val) << endl;
	}
}
```

### Code : Even after Odd LinkedList- QUESTION-7
![image](https://user-images.githubusercontent.com/57065763/173046196-fe700d17-5add-43a5-9ff9-02b1a25f479c.png)


```
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40

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
////////////////================>>>>>>>>>>> Even after Odd LinkedList

Node *evenAfterOdd(Node *head)
{
    if(head==NULL){
        return head;
    }
    
    Node *evenHead = NULL, *evenTail = NULL, *oddHead=NULL, *oddTail = NULL;

    while(head != NULL){
        
      if((head->data % 2 )==0 ){
          
        if(evenHead==NULL){
          evenHead = head;
          evenTail = head;
        }else{
          evenTail->next = head;
          evenTail = head;
        }
          
      }else{
          
        if(oddHead==NULL){
          oddHead = head;
          oddTail = head;
        }else{
          oddTail->next = head;
          oddTail = head;
        }
          
      }
    head = head->next;
    }

    if(oddTail != NULL){
      oddTail->next = evenHead;
    }

    if(evenTail != NULL){
      evenTail->next = NULL;
    }

    if(oddTail==NULL){
      return evenHead;
    }else{
      return oddHead;
    }

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}
```
### Code : Delete every N nodes- QUESTION-8
![image](https://user-images.githubusercontent.com/57065763/173051948-6c620194-efb1-4504-83ef-e06bca390633.png)


```
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= P <= 10^5
Where P is the size of the singly linked list.
0 <= M <= 10^5
0 <= N <= 10^5 

Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
2 2
Sample Output 1 :
1 2 5 6
Sample Input 2 :
2
10 20 30 40 50 60 -1
0 1
1 2 3 4 5 6 7 8 -1
2 3
Sample Output 2 :
1 2 6 7
Explanation of Sample Input 2 :
For the first query, we delete one node after every zero elements hence removing all the items of the list. Therefore, nothing got printed.

For the second query, we delete three nodes after every two nodes, resulting in the final list, 1 -> 2 -> 6 -> 7.
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

////////////////================>>>>>>>>>>> Delete every N nodes

Node *skipMdeleteN(Node *head, int M, int N)
{
	if(head==NULL || M==0){
        return NULL;
    }
    if(N==0){
        return head;
    }
    
    Node *currentNode = head;
    Node *newNode = NULL;
    Node *temp = NULL; //temp will keep a copy of currentNode as we modify the list
    
    while(currentNode != NULL){
        int skip = 0;
        int needToDelete = 0;
        
        while(currentNode != NULL && skip<M){
            if(temp == NULL){
                temp = currentNode;
            }else{
                temp->next = currentNode;
                temp = currentNode;
            }
            currentNode = currentNode->next;
            skip++;
        }
        
        while(currentNode != NULL && needToDelete<N){
            newNode = currentNode->next;
            delete currentNode;
            currentNode = newNode;
            needToDelete++;
        }
    }
    if(temp != NULL){
       temp->next = NULL;
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
```

### Code : Swap two Nodes of LL- QUESTION-9

![image](https://user-images.githubusercontent.com/57065763/173105771-edc385ea-497e-43b7-b370-16c7143b66a2.png)

```
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
 Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 

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

///////////////////-======================>>>>>>>>>> Swap two Nodes of LL
Node *swapNodes(Node *head, int i, int j) { 
    if(i == j) { 
        return head; 
    } 
    
    Node *currentNode = head, *prev = NULL; 
    Node *firstNode = NULL, *secondNode = NULL, *firstNodePrev = NULL, *secondNodePrev = NULL; 
    int pos = 0; 
    while (currentNode != NULL) { 
        if (pos == i) { 
            firstNodePrev = prev; 
            firstNode = currentNode; 
        } else if (pos == j) { 
            secondNodePrev = prev; 
            secondNode = currentNode; 
        } 
        prev = currentNode; 
        currentNode = currentNode->next; 
        pos++; 
    } 
    if (firstNodePrev != NULL) { 
        firstNodePrev->next = secondNode; 
    } else { 
        head = secondNode; 
    } 
    
    if (secondNodePrev != NULL) { 
        secondNodePrev->next = firstNode; 
    } else { 
        head = firstNode; 
    } 
    
    Node *currentFirstNode = secondNode->next; 
    secondNode->next = firstNode->next; 
    firstNode->next = currentFirstNode; 
    return head; 
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
```

### Code : kReverse- QUESTION-10


```
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'k'.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= k <= M

Time Limit:  1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 9 10 -1
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9
Sample Input 2 :
2
1 2 3 4 5 -1
0
10 20 30 40 -1
4
Sample Output 2 :
1 2 3 4 5 
40 30 20 10 
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

/////==============>>>>>>>>>.kReverse
///////////// https://www.youtube.com/watch?v=LCRGV8avvUY&t=227s
Node *kReverse(Node *head, int k) { 
    if (k == 0 || k == 1) { 
        return head; 
    } 
    
    Node* current = head; 
    Node* nextptr = NULL; 
    Node* prev = NULL; 
    int count = 0; /* Reverse first k nodes of linked list */ 
    
    /// 1 2 3 4 5 6
    //3
    //=>> ai khane  first 3tar jonno while loop a kortesi. baki 3 tar jonno amra recurison call kortesi.
    while (count < k && current != NULL) { 
        nextptr = current->next; 
        current->next = prev; 
        prev = current; 
        current = nextptr; 
        count++; 
    } 
    
    if (nextptr != NULL) { 
        head->next = kReverse(nextptr, k); 
    } 
    
    return prev;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}
```

### Code : Bubble Sort (Iterative) LinkedList - QUESTION-11

![image](https://user-images.githubusercontent.com/57065763/173136673-8c8a1495-ed52-4431-9552-7f58f05646dc.png)

```
Given a singly linked list of integers, sort it using 'Bubble Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Input 2 :
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
```

```cpp
//bubble sort iterative
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

////////////===================>>>>>>>>>> Bubble Sort (Iterative) LinkedList
// find length
int length(Node *head) { 
    if (head == NULL) { 
        return 0; 
    } 
    
    Node *temp = head; 
    int size = 1 + length(temp->next); 
    return size; 
} 
// functionality
Node *bubbleSort(Node *head) { 
    for (int i = 0; length(head) > i; i++) { 
        Node *prev = NULL, *curr = head; 
        while (curr->next != NULL) { 
            if (curr->data > curr->next->data) { 
                if (prev != NULL) { 
                    Node *temp = curr->next->next; 
                    curr->next->next = curr; 
                    prev->next = curr->next; 
                    curr->next = temp; 
                    prev = prev->next; 
                } else { 
                    head = curr->next; 
                    curr->next = head->next; 
                    head->next = curr; 
                    prev = head; 
                } 
            } else {
                prev = curr; 
                curr = curr->next; 
            } 
        } 
    } 
    return head; 
}

int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}
```

### Lecture 09 : Linked List 2

```cpp

Lecture 09 : Linked List 2

```