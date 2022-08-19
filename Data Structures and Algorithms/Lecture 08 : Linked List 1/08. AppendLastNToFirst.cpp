
/****************************************************************** 
### AppendLastNToFirst - QUESTION-8

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

*****************************************************************/

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


/*---------------------------CODE------------------------*/

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




