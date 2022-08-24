```

Lecture 10.5 : TEST-2 START HERE

```

# ##Lecture 10.5 : TEST-2

### Next Number

```
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL.
Input Constraints:
1 <= Length of Linked List <=10^6.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Output Format :
Line 1: Updated linked list elements 
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 
```

```cpp
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

////////////////////=============>>>>>>>>>>>>>>>Next Number

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// This function mainly uses addOneUtil().
Node *NextLargeNumber(Node *head)
{
//-------------------------------------------------------------------------
    // Reverse linked list
    head = reverse(head);
    
//-------------------------------------------------------------------
////// Adds one to a linked lists
    // Add one from left to right of reversed list
    Node *ptr=head, *prev = NULL;

    int carry = 1, sum=0;

    while (ptr != NULL) // while both lists exist
    {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i) Carry
        // (ii) Next digit of head list (if there is a next digit)
        sum = carry + ptr->data;

        // update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;

        // update sum if it is greater than 10
        sum = sum % 10;

        // Create a new node with sum as data
        ptr->data = sum;

        // Move head and second pointers to next nodes
        prev = ptr;
        ptr = ptr->next;
    }

    // if some carry is still there, add a new node to result list.
    if (carry > 0)
        prev->next = new Node(carry);
//-------------------------------------------------------------------------

    // Reverse the modified list
    return reverse(head);
//-------------------------------------------------------------------------
}


Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}
```


### Dequeue
![image](https://user-images.githubusercontent.com/57065763/186504896-c350022c-8966-45ef-a7db-9ce4f25cb3be.png)

```
You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.
You don't need to double the capacity.
You need to implement the following functions -
1. constructor
You need to create the appropriate constructor. Size for the queue passed is 10.
2. insertFront -
This function takes an element as input and insert the element at the front of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
3. insertRear -
This function takes an element as input and insert the element at the end of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
4. deleteFront -
This function removes an element from the front of queue. Print -1 if queue is empty.
5. deleteRear -
This function removes an element from the end of queue. Print -1 if queue is empty.
6. getFront -
Returns the element which is at front of the queue. Return -1 if queue is empty.
7. getRear -
Returns the element which is at end of the queue. Return -1 if queue is empty.
Input Format:
For C++ and Java, input is already managed for you. You just have to implement given functions.

For Python:
The choice codes and corresponding input for each choice are given in a new line. The input is terminated by integer -1. The following table elaborately describes the function, their choice codes and their corresponding input - 
Alt Text

Output Format:
For C++ and Java, output is already managed for you. You just have to implement given functions.

For Python: 
The output format for each function has been mentioned in the problem description itself. 
Sample Input 1:
5 1 49 1 64 2 99 5 6 -1
Sample Output 1:
-1
64
99
Explanation:
The first choice code corresponds to getFront. Since the queue is empty, hence the output is -1. 
The following input adds 49 at the top and the resultant queue becomes: 49.
The following input adds 64 at the top and the resultant queue becomes: 64 -> 49
The following input add 99 at the end and the resultant queue becomes: 64 -> 49 -> 99
The following input corresponds to getFront. Hence the output is 64.
The following input corresponds to getRear. Hence the output is 99.

```

```cpp
// C++ implementation of De-queue using circular
// array
#include<iostream>
using namespace std;

class Deque { 
    int arr[10]; 
    int front=-1; 
    int rear=-1; 
    int size; 
    
    public : Deque(int size) { 
        front = -1; 
        rear = 0; 
        this->size = size; 
    } 
    //Checks whether deque is full or not. 
    bool isFull() { 
        // used % operator is insertion and deletion is in circular manner 
        return (front == (rear+1)%size); 
    } 
    
    //Checks whether Deque is empty or not. 
    bool isEmpty () { 
        return (front == -1); 
    } 
    
    // Inserts an element at front 
    void insertFront(int input) { 
        if (isFull()) { 
            cout << "-1\n"; return; 
        } 
        if (front == -1) { 
            front = 0; 
            rear = 0; 
        }else{ 
            // used % operator is insertion is in circular manner 
            front = ((front-1)%size+size)%size; 
        } 
        arr[front] = input ; 
    } 
    // function to inset element at rear end of Deque. 
    void insertRear(int input) { 
        if (isFull()) { 
            cout << "-1\n "; return; 
        } 
        if (front == -1) { 
            front = 0; 
            rear = 0; 
        }else{ 
            // used % operator is insertion is in circular manner 
            rear = ((rear+1)%size+size)%size; ; 
        } 
        
        arr[rear] = input; 
    } 
    // Deletes element at front end of Deque 
    void deleteFront() { 
        if (isEmpty()) { 
            cout << "-1\n"; return ; 
        } 
        if (front == rear) { 
            front = -1; 
            rear = -1; 
        } else{ 
            // used % operator is deletion is in circular manner 
            front = ((front+1)%size+size)%size; ; 
        } 
    } 
    
    // Delete element at rear end of Deque 
    void deleteRear() { 
        if (isEmpty()) { 
            cout << "-1\n"; 
            return ; 
        } 
        
        if (front == rear) { 
            front = -1; 
            rear = -1; 
        }else{ 
            // used % operator is deletion is in circular manner 
            rear = ((rear-1)%size+size)%size; 
        } 
    } 
    
    // Returns front element of Deque 
    int getFront() { 
        if (isEmpty()) { 
            return -1 ; 
        } 
        return arr[front]; 
    } 
    // function return rear element of Deque 
    int getRear() { 
        if(isEmpty() || rear < 0) { 
            return -1 ; 
        } 
        return arr[rear]; 
    } 
};

int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}

```

### Delete Alternate Nodes

```
Given a Singly Linked List of integers, delete all the alternate nodes in the list.
Example:
List: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> null
Alternate nodes will be:  20, 40, and 60.

Hence after deleting, the list will be:
Output: 10 -> 30 -> 50 -> null
Note :
The head of the list will remain the same. Don't need to print or return anything.
Input format :
The first and the only line of input will contain the elements of the Singly Linked List separated by a single space and terminated by -1.
Output Format :
The only line of output will contain the updated list elements.
Input Constraints:
1 <= N <= 10 ^ 6.
Where N is the size of the Singly Linked List

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 -1
Sample Output 1:
1 3 5
Explanation of Sample Input 1:
2, 4 are alternate nodes so we need to delete them 
Sample Input 2:
10 20 30 40 50 60 70 -1
Sample Output 2:
10 30 50 70 
```

```cpp
//delete alternate Node in a linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        if(next) {
            delete next;
        }
    }
};

////////////=============>>>>>>>>>>>>>Delete Alternate Nodes

/*
Time complexity: O(N) 
Space complexity: O(1) 
where N is the size of the linked list
*/

void deleteAlternateNodes(Node *head) { 
    Node *currentNode = head; 
    
    while (currentNode != NULL && currentNode->next != NULL) { 
        Node *temp = currentNode->next; 
        currentNode->next = currentNode->next->next; 
        temp->next = NULL; 
        delete temp; 
        currentNode = currentNode->next; 
    } 
}

Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}
```

```

Lecture 10.5 : TEST-2 END HERE

```
