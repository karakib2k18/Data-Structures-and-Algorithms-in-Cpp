/*****************************************************************

### Code: Merge Sort - QUESTION-3

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



****************************************************************/

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
/*
Time Complexity : O(n* log(n)) Space Complexity : O(n) where n is the size of singly linked list
*/
Node* findMid(Node *head)
{
	if (head == NULL)
	{
		return head;
	}
	Node *slow = head, *fast = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
Node* merge(Node *head1, Node *head2)
{
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	Node *head = NULL, *tail = NULL;
	if (head1->data < head2->data)
	{
		head = head1;
		tail = head1;
		head1 = head1->next;
	}
	else
	{
		head = head2;
		tail = head2;
		head2 = head2->next;
	}
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->data < head2->data)
		{
			tail->next = head1;
			tail = head1;
			head1 = head1->next;
		}
		else
		{
			tail->next = head2;
			tail = head2;
			head2 = head2->next;
		}
	}
	if (head1 != NULL)
	{
		tail->next = head1;
	}
	if (head2 != NULL)
	{
		tail->next = head2;
	}
	return head;
}
Node* mergeSort(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Node *mid = findMid(head);
	Node *half1 = head;
	Node *half2 = mid->next;
	mid->next = NULL;
	half1 = mergeSort(half1);
	half2 = mergeSort(half2);
	Node *finalHead = merge(half1, half2);
	return finalHead;
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
