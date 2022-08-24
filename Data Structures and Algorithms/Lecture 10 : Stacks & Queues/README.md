```

Lecture 10 : Stacks & Queues START HERE

```

# ##Lecture 10 : Stacks & Queues

---

//============>>>>>>>>>>ADT Notes
[Lecture 10.1 : ADT Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/8926808/Lecture.10.1.ADT.Notes.pdf)

//============>>>>>>>>>>Templates Notes
[Lecture 10.2 : Templates Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/8926809/Lecture.10.2.Templates.Notes.pdf)

//============>>>>>>>>>>Stacks Notes
[Lecture 10.3 :  Stacks Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/8926812/Lecture.10.3.Stacks.Notes.pdf)

//============>>>>>>>>>>Queues Notes
[Lecture 10.4 :   Queues Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/8926813/Lecture.10.4.Queues.Notes.pdf)

---

### Stack Introduction
![image](https://user-images.githubusercontent.com/57065763/173322585-6f4fd52c-2af0-4a42-bcee-b529ca36cd7f.png)
### Stack in Recursion
![image](https://user-images.githubusercontent.com/57065763/173323082-847c804d-46f9-4299-b336-6ab09b2a289f.png)
### Stack Using Array
![image](https://user-images.githubusercontent.com/57065763/173324457-4298275b-3ef9-4d2c-bf1e-e08154c2e707.png)
![image](https://user-images.githubusercontent.com/57065763/173328643-9fb5a6f8-6f13-4cfb-b4a8-d7ae8f9aa17b.png)
![image](https://user-images.githubusercontent.com/57065763/173329979-56cc1d1c-b6ba-42ee-ad5b-99ba80f44bfa.png)
![image](https://user-images.githubusercontent.com/57065763/173342472-078ef80f-ad2c-486f-a454-4f7cff46cfcc.png)


```cpp
// insert element in static array
void push(int element) {
    if(nextIndex == capacity) {
        cout << "Stack full " << endl;
        return;
    }
    data[nextIndex] = element;
    nextIndex++;
}
```

```cpp
// return the number of elements present in my stack
int size() {
    return nextIndex;
}
```

```cpp
bool isEmpty() {
    /*
    if(nextIndex == 0) {
        return true;
    }
    else {
        return false;
    }
    */
    return nextIndex == 0; // index 0 hole empty and true return korbe. And empty e hobe.
}
```

```cpp
// delete element
int pop() {
    if(isEmpty()) {
        cout << "Stack is empty " << endl;
        return INT_MIN;	
    }
    nextIndex--;
    return data[nextIndex];
}

int top() {
    if(isEmpty()) {
        cout << "Stack is empty " << endl;
        return INT_MIN;	
    }
    return data[nextIndex - 1];
}
```
```cpp
//find top element
int top() {
    if(isEmpty()) {
        cout << "Stack is empty " << endl;
        return INT_MIN;	
    }
    return data[nextIndex - 1];
}
```

```cpp
#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray {
	int *data;
	int nextIndex;
	int capacity;	

	public :

	StackUsingArray(int totalSize) {
		data = new int[totalSize];
		nextIndex = 0;
		capacity = totalSize;
	}

	// return the number of elements present in my stack
	int size() {
		return nextIndex;
	}

	bool isEmpty() {
        /*
		if(nextIndex == 0) {
			return true;
		}
		else {
			return false;
		}
        */
		return nextIndex == 0;
	}

	// insert element
	void push(int element) {
		if(nextIndex == capacity) {
			cout << "Stack full " << endl;
			return;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	// delete element
	int pop() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		nextIndex--;
		return data[nextIndex];
	}

	int top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		return data[nextIndex - 1];
	}
};


int main() {
	StackUsingArray s(4);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << s.top() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.size() << endl;
	cout << s.isEmpty() << endl;
}

```

### Dynamic Stack
![image](https://user-images.githubusercontent.com/57065763/173344003-a3992ce2-cc6e-45c7-a5e6-3c4488b11476.png)



```cpp
// creating dynamically stack
public :

StackUsingArray() {
    data = new int[4];
    nextIndex = 0;
    capacity = 4;
}

```

```cpp
// insert element and increment size dynamically
void push(int element) {
    if(nextIndex == capacity) {
        int *newData = new int[2 * capacity];
        for(int i = 0; i < capacity; i++) {
            newData[i] = data[i];
        }
        capacity *= 2;
        delete [] data;
        data = newData;
        /*cout << "Stack full " << endl;
        return;*/
    }
    data[nextIndex] = element;
    nextIndex++;
}
```

```cpp
#include <iostream>
#include <climits>
using namespace std;


class StackUsingArray {
	int *data;
	int nextIndex;
	int capacity;	

	public :

	StackUsingArray() {
		data = new int[4];
		nextIndex = 0;
		capacity = 4;
	}

	// return the number of elements present in my stack
	int size() {
		return nextIndex;
	}

	bool isEmpty() {
		/*
		if(nextIndex == 0) {
			return true;
		}
		else {
			return false;
		}
		*/

		return nextIndex == 0;
	}

	// insert element
	void push(int element) {
		if(nextIndex == capacity) {
			int *newData = new int[2 * capacity];
			for(int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			capacity *= 2;
			delete [] data;
			data = newData;
			/*cout << "Stack full " << endl;
			return;*/
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	// delete element
	int pop() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		nextIndex--;
		return data[nextIndex];
	}
	int top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		return data[nextIndex - 1];
	}

};


int main() {
	StackUsingArray s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << s.top() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.size() << endl;
	cout << s.isEmpty() << endl;

}

```

# Some MCQ::
![image](https://user-images.githubusercontent.com/57065763/173502589-82b6d545-3ef1-4a73-a44a-17ca4ced45c3.png)
![image](https://user-images.githubusercontent.com/57065763/173502634-ab81644b-22f9-43de-a9b7-b501a4cd3ef4.png)
![image](https://user-images.githubusercontent.com/57065763/173502660-134c30ea-0783-4946-822c-e42e68ce6549.png)
![image](https://user-images.githubusercontent.com/57065763/173502682-915220f2-99c3-4e07-bda4-6b06c3ceda16.png)
![image](https://user-images.githubusercontent.com/57065763/173502717-279b2966-cdab-4373-8b1f-3dd063b93d1d.png)


### Templates

![image](https://user-images.githubusercontent.com/57065763/173515982-6c27daca-71a0-4b30-8430-ded8450d110f.png)
![image](https://user-images.githubusercontent.com/57065763/173524276-f7f915d1-17b5-45ee-a548-b42452f3a2ae.png)
![image](https://user-images.githubusercontent.com/57065763/173526170-ba8b2862-39d2-4f83-8b29-959c673bf2c8.png)
![image](https://user-images.githubusercontent.com/57065763/173526669-b0ba02ae-f632-43db-8087-e4acea223c80.png)
![image](https://user-images.githubusercontent.com/57065763/173526814-b7b95045-7da6-4b7f-ac55-9dd9968a45de.png)

```cpp
#include <iostream>
using namespace std;

template <typename T, typename V>

class Pair {
	T x;
	V y;

	public :

	void setX(T x) {
		this -> x = x;
	}

	T getX() {
		return x;
	}

	void setY(V y) {
		this -> y = y;
	}

	V getY() {
		return y;
	}
};


int main() {

	Pair<Pair<int, int>, int> p2;
	p2.setY(10);
	Pair<int, int> p4;
	p4.setX(5);
	p4.setY(16);

	p2.setX(p4);

	cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << endl;

	/*
	Pair<int, double> p1;
	p1.setX(100.34);
	p1.setY(100.34);

	cout << p1.getX() << " " << p1.getY() << endl;
	*/
	/*
	Pair<int> p1;
	p1.setX(10);
	p1.setY(20);

	cout << p1.getX() << " " << p1.getY() << endl;

	Pair<double> p2;

	p2.setX(100.34);
	p2.setY(34.21);
	cout << p2.getX() << " " << p2.getY() << endl;

	Pair<char> p3;
	*/

}

```


### Stack Using Templates
```cpp
#include <iostream>
using namespace std;


#include <climits>

template <typename T>
class StackUsingArray {
	T *data;
	int nextIndex;
	int capacity;	

	public :

	StackUsingArray() {
		data = new T[4];
		nextIndex = 0;
		capacity = 4;
	}

	// return the number of elements present in my stack
	int size() {
		return nextIndex;
	}

	bool isEmpty() {
		/*
		if(nextIndex == 0) {
			return true;
		}
		else {
			return false;
		}
		*/
		return nextIndex == 0;
	}

	// insert element
	void push(T element) {
		if(nextIndex == capacity) {
			T *newData = new T[2 * capacity];
			for(int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			capacity *= 2;
			delete [] data;
			data = newData;
			/*cout << "Stack full " << endl;
			return;*/
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	// delete element
	T pop() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return 0;	
		}
		nextIndex--;
		return data[nextIndex];
	}
	T top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return 0;	
		}
		return data[nextIndex - 1];
	}

};


int main() {
	StackUsingArray<char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);

	cout << s.top() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.size() << endl;
	cout << s.isEmpty() << endl;
}

```
### Stack Using LL Introduction
![image](https://user-images.githubusercontent.com/57065763/173547154-002b1b5b-d732-43c6-b404-fe73057b89df.png)
![image](https://user-images.githubusercontent.com/57065763/173548250-33645248-459e-48fc-a0a1-06b3f5a018e1.png)
![image](https://user-images.githubusercontent.com/57065763/173549820-a13563bd-aa1f-4c60-971f-c44776ff856e.png)
![image](https://user-images.githubusercontent.com/57065763/173550554-a637670e-e9a2-4388-8ae0-aee2f31607ad.png)
![image](https://user-images.githubusercontent.com/57065763/173551083-387a55c9-071b-47ae-816e-1076d9752594.png)
![image](https://user-images.githubusercontent.com/57065763/173553864-161a5a80-7ccf-43de-9ff5-c84670267854.png)
![image](https://user-images.githubusercontent.com/57065763/173553164-dbcdb822-8ca2-4af6-a1e8-df317b5a39ea.png)
![image](https://user-images.githubusercontent.com/57065763/173553898-9015167f-dc52-4a2c-a058-5265ee155d25.png)

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Node {
	public : 
		T data;
		Node<T> *next;

		Node(T data) {
			this -> data = data;
			next = NULL;
		}

		~Node() {
			delete next;
		}
};

template <typename T>
class Stack {
	Node<T> *head;
	int size;		// number of elements prsent in stack

	public :

	Stack() {

	}

	int getSize() {
		
	}

	bool isEmpty() {

	}

	void push(T element) {

	}

	T pop() {

	}

	T top() {

	}
};
```


###  Code : Stack Using LL

```
Implement a Stack Data Structure specifically to store integer data using a Singly Linked List.
The data members should be private.
You need to implement the following public functions :
1. Constructor:
It initialises the data members as required.
2. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.
3. pop() :
It pops the element from the top of the stack and in turn, returns the element being popped or deleted. In case the stack is empty, it returns -1.
4. top :
It returns the element being kept at the top of the stack. In case the stack is empty, it returns -1.
5. size() :
It returns the size of the stack at any given instance of time.
6. isEmpty() :
It returns a boolean value indicating whether the stack is empty or not.
Operations Performed on the Stack:
Query-1(Denoted by an integer 1): Pushes an integer data to the stack.

Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack and returns it to the caller.

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack but doesn't remove it, unlike the pop function.

Query-4(Denoted by an integer 4): Returns the current size of the stack.

Query-5(Denoted by an integer 5): Returns a boolean value denoting whether the stack is empty or not.
Input Format:
The first line contains an integer 'q' which denotes the number of queries to be run against each operation in the stack. 
Then the test cases follow.

Every 'q' lines represent an operation that needs to be performed.

For the push operation, the input line will contain two integers separated by a single space, representing the type of the operation in integer and the integer data being pushed into the stack.

For the rest of the operations on the stack, the input line will contain only one integer value, representing the query being performed on the stack.
 Output Format:
For Query-1, you do not need to return anything.
For Query-2, prints the data being popped from the stack.
For Query-3, prints the data kept on the top of the stack.
For Query-4, prints the current size of the stack.
For Query-5, prints 'true' or 'false'(without quotes).

Output for every query will be printed in a separate line.
Note:
You are not required to print anything explicitly. It has already been taken care of. Just implement the function.
 Constraints:
1 <= q <= 10^5
1 <= x <= 5
-2^31 <= data <= 2^31 - 1 and data != -1

Where 'q' is the total number of queries being performed on the stack, 'x' is the range for every query and data represents the integer pushed into the stack. 

Time Limit: 1 second
Sample Input 1:
6
1 13
1 47
4
5
2
3
Sample Output 1:
2
false
47
13
Sample Input 2:
4
5
2
1 10
5
Sample Output 2:
true
-1
false
 Explanation of Sample Input 2:
There are 4 queries in total.
The first one is Query-5: It tells whether the stack is empty or not. Since the stack is empty at this point, the output is  'true'.

The second one is Query-2: It pops the data from the stack. Since at this point in time, no data exist in the stack hence, it prints -1.

The third one is Query-1: It pushes the specified data 10 into the stack and since the function doesn't return anything, nothing is printed.

The fourth one is Query-5: It tells whether the stack is empty at this point or not. Since the stack has one element and hence it is not empty, false is printed.
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
        next = NULL;
    }
};

////////////////==============>>>>>>>>>>>>>>> Code : Stack Using LL
class Stack {
    Node *head;
    int size;
    
   public:
    Stack() {
        head = NULL;
        size = 0;
    }

	/*----Public Functions of Stack -----*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return (size == 0);
    }

    void push(int element) {
        Node *newNode = new Node(element);
        size++;
        if (head == NULL)
        {
            head = newNode;
        }
        newNode->next = head;
        head=newNode;
    }

    int pop() {
        if(isEmpty()){
            return -1;
        }
        Node *temp = head;
        int tempData = head->data;
        head = head->next;
        size--;
        return tempData;
        delete temp;
    }

    int top() {
        if(isEmpty()){
            return -1;
        }
        int topdata = head->data;
        return topdata;
        
    }
};

int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
```

###  Stack Using LL - Solution

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Node {
	public : 
		T data;
		Node<T> *next;

		Node(T data) {
			this -> data = data;
			next = NULL;
		}
};

template <typename T>
class Stack {
	Node<T> *head;
	int size;		// number of elements prsent in stack

	public :

	Stack() {
		head = NULL;
		size = 0;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void push(T element) {
		Node<T> *newNode = new Node<T>(element);
		newNode -> next = head;
		head = newNode;
		size++;
	}

	T pop() {
		if(isEmpty()) {
			return 0;		
		}
		T ans = head -> data;
		Node<T> *temp = head;
		head = head -> next;
		delete temp;
		size--;
		return ans;
	}

	T top() {
		if(isEmpty()) {
			return 0;		
		}
		return head -> data;
	}

};

int main() {
	Stack<char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);

	cout << s.top() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.getSize() << endl;
	cout << s.isEmpty() << endl;
}
```

###  Inbuilt Stack
```cpp
#include <iostream>
using namespace std;
#include <stack>

int main() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << s.size() << endl;
	cout << s.empty() << endl;
}
```
### Balanced Parenthesis
![image](https://user-images.githubusercontent.com/57065763/174234255-c72ec24a-6718-44df-a6af-db25866e3fa5.png)
![image](https://user-images.githubusercontent.com/57065763/174234527-12245af8-4bee-4b13-9ba8-ebb5673dfac8.png)

### Code : Balanced Parenthesis
```
Code : Balanced Parenthesis
Send Feedback
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.
Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.
Note:
The input expression will not contain spaces in between.
Input Format:
The first and the only line of input contains a string expression without any spaces in between.
 Output Format:
The only line of output prints 'true' or 'false'.
Note:
You don't have to print anything explicitly. It has been taken care of. Just implement the function. 
Constraints:
1 <= N <= 10^7
 Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1 :
(()()())
Sample Output 1 :
true
Sample Input 2 :
()()(()
Sample Output 2 :
false
Explanation to Sample Input 2:
The initial two pairs of brackets are balanced. But when you see, the opening bracket at the fourth index doesn't have its corresponding closing bracket which makes it imbalanced and in turn, making the whole expression imbalanced. Hence the output prints 'false'.
```

```cpp
#include <iostream>
#include <string>
using namespace std;

//////////////////============>>>>>>>>>>> Code : Balanced Parenthesis

#include <stack> 

bool isBalanced(string expression) { 
    stack<char> stk; 
    for (int i = 0; i < expression.length(); i++) { 
        if (expression[i] == '(') { 
            stk.push(expression[i]); 
        } else if (expression[i] == ')') { 
            if (stk.empty()) { 
                return false; 
            } 
            
            char topChar = stk.top(); 
            stk.pop(); 
            if (expression[i] == ')' && topChar == '(') { 
                continue; 
            } else { 
                return false; 
            } 
        } 
    } 
    
    return stk.empty(); 
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}

```

### Queues Introduction
![image](https://user-images.githubusercontent.com/57065763/174234700-c221b665-861d-4cca-a1e3-26c771cd9ee0.png)
![image](https://user-images.githubusercontent.com/57065763/174235380-599c5958-60e9-41c8-8138-f56d382be804.png)

### Queue using array - Introduction
![image](https://user-images.githubusercontent.com/57065763/174235268-b7e58849-97a4-4ec4-aa08-f55338cd3f55.png)
![image](https://user-images.githubusercontent.com/57065763/174237439-34cff050-ac56-42ce-aac5-b0fd40401aec.png)
![image](https://user-images.githubusercontent.com/57065763/174237777-449fbe39-c66d-4114-8b02-f9a313b340cb.png)
![image](https://user-images.githubusercontent.com/57065763/174240201-8ba051fe-321a-4be3-8cb1-b670ae2c4fa4.png)


### Queue using array - Code

```cpp
	data[nextIndex] = element;
	nextIndex = (nextIndex + 1) % capacity ;
```
```cpp
	T ans = data[firstIndex];
	firstIndex = (firstIndex + 1) % capacity;
```
```cpp
#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray {
	T *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;

	public :
	QueueUsingArray(int s) {
		data = new T[s];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	// insert element
	void enqueue(T element) {
		if(size == capacity) {
			cout << "Queue Full ! " << endl;
			return;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity ;
		if(firstIndex == -1) {
			firstIndex = 0;
		}
		size++;
	}
	
	T front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	T dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		T ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return ans;
	}
};


int main() {
	QueueUsingArray<int> q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);


	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;
}

```
### Dynamic Queue

```cpp
if(size == capacity) {
	T *newData = new T[2 * capacity];
	int j = 0;
	for(int i = firstIndex; i < capacity; i++) {
		newData[j] = data[i];
		j++;
	}
	for(int i = 0; i < firstIndex; i++) {
		newData[j] = data[i];
		j++;
	}
	delete [] data;
	data = newData;
	firstIndex = 0;
	nextIndex = capacity;
	capacity *= 2;
	//cout << "Queue Full ! " << endl;
	// return;
}
```

```cpp
#include <iostream>
using namespace std;

template <typename T>

class QueueUsingArray {
	T *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;

	public :
	QueueUsingArray(int s) {
		data = new T[s];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	// insert element
	void enqueue(T element) {
		if(size == capacity) {
			T *newData = new T[2 * capacity];
			int j = 0;
			for(int i = firstIndex; i < capacity; i++) {
				newData[j] = data[i];
				j++;
			}
			for(int i = 0; i < firstIndex; i++) {
				newData[j] = data[i];
				j++;
			}
			delete [] data;
			data = newData;
			firstIndex = 0;
			nextIndex = capacity;
			capacity *= 2;
			//cout << "Queue Full ! " << endl;
			// return;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity ;
		if(firstIndex == -1) {
			firstIndex = 0;
		}
		size++;
	}
	
	T front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	T dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		T ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return ans;
	}
};


int main() {
	QueueUsingArray<int> q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);


	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;
}

```
# Some MCQ::
![image](https://user-images.githubusercontent.com/57065763/174272003-2d96e1b5-d152-4f6a-9445-7bdc4ad424a1.png)
![image](https://user-images.githubusercontent.com/57065763/174272044-afffe668-b701-416c-a515-a522b0aa9422.png)
![image](https://user-images.githubusercontent.com/57065763/174272096-9d948054-7925-4f6c-bbef-b7f36dc5636e.png)
![image](https://user-images.githubusercontent.com/57065763/174272125-ca3b0545-2b2a-4eec-bf00-fb957ae7efc3.png)
![image](https://user-images.githubusercontent.com/57065763/174272164-4a311f82-ff3b-4104-8786-91897c590e76.png)

### Queue Using LL Introduction
![image](https://user-images.githubusercontent.com/57065763/174272527-d7cde9c2-5ea0-4e04-8c44-3858d8cfe9b7.png)
![image](https://user-images.githubusercontent.com/57065763/174273110-01ec501b-d9a5-4b1d-b07f-477e3866da2c.png)

###  Queue Using LL Introduction || Code : Queue Using LL || Queue using LL - Solution

```cpp

#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

/////////////============>>>>>>>>>>>>>>>>>> Code : Queue Using LL
class Queue {
    Node *head;
    Node *tail;
    int size;
   public:
    Queue() {
        head=NULL;
        tail = NULL;
        size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
        return size;
	}
    bool isEmpty() {
        return (size==0);
	}

    void enqueue(int data) {
        Node *newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        tail->next=newNode;
        tail = newNode;
        size++;
	}

    int dequeue() {
        if(isEmpty()){
            return -1;
        }
        int tempData = head->data;
        Node *temp = head;
        head= head->next;
        delete temp;
        size--;
        return tempData;
    }

    int front() {
        if(isEmpty()){
            return -1;
        }
        return head->data;
    }
};

int main() {

    Queue q;

    int t;
    cin >> t;
    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}

```
###  Inbuilt Queue
![image](https://user-images.githubusercontent.com/57065763/174282213-04ac1f04-4315-4448-b10e-735b50bf2cb0.png)

```cpp
#include <iostream>
using namespace std;
#include <queue>


template <typename T>

class QueueUsingArray {
	T *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;

	public :
	QueueUsingArray(int s) {
		data = new T[s];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	// insert element
	void enqueue(T element) {
		if(size == capacity) {
			T *newData = new T[2 * capacity];
			int j = 0;
			for(int i = firstIndex; i < capacity; i++) {
				newData[j] = data[i];
				j++;
			}
			for(int i = 0; i < firstIndex; i++) {
				newData[j] = data[i];
				j++;
			}
			delete [] data;
			data = newData;
			firstIndex = 0;
			nextIndex = capacity;
			capacity *= 2;
			//cout << "Queue Full ! " << endl;
			// return;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity ;
		if(firstIndex == -1) {
			firstIndex = 0;
		}
		size++;
	}
	
	T front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	T dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		T ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return ans;
	}
}

int main() {
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);

	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	cout << q.size() << endl;
	cout << q.empty() << endl;

	while(!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	
}

```

### Reverse a Stack

![image](https://user-images.githubusercontent.com/57065763/174354024-aa791028-53cd-49ff-aca6-24c6a7405646.png)
![image](https://user-images.githubusercontent.com/57065763/174383415-1c6c7ca1-0a97-442c-b09d-8acf418a59ad.png)

```
You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.
For Example:
Alt txt

Input Format :
The first line of input contains an integer N, denoting the total number of elements in the stack.

The second line of input contains N integers separated by a single space, representing the order in which the elements are pushed into the stack.
Output Format:
The only line of output prints the order in which the stack elements are popped, all of them separated by a single space. 
Note:
You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input stack itself.
Constraints:
1 <= N <= 10^3
-2^31 <= data <= 2^31 - 1

Time Limit: 1sec 
Sample Input 1:
6
1 2 3 4 5 10
Note:
Here, 10 is at the top of the stack.
Sample Output 1:
1 2 3 4 5 10
Note:
Here, 1 is at the top of the stack.
Sample Input 2:
5
2 8 15 1 10
Sample Output 2:
2 8 15 1 10
```

```cpp
#include <iostream>
#include <stack>
using namespace std;

// https://youtu.be/fEauTlo6J-w
void reverseStack(stack<int> &input, stack<int> &extra) { 
    if (input.size() <= 1) {
        return;               
    } 
    
    int lastElement = input.top(); 
    input.pop(); 
    
    reverseStack(input, extra); 
    
    while (!input.empty()) { 
        int top = input.top(); 
        input.pop(); 
        extra.push(top); 
    } 
    
    input.push(lastElement); 
    
    while (!extra.empty()) { 
        int top = extra.top(); 
        extra.pop(); 
        input.push(top); 
    } 
}


int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}
```

### Reverse Queue

```
You have been given a queue that can store integers as the data. You are required to write a function that reverses the populated queue itself without using any other data structures.
Example:
Alt txt

Alt txt

Input Format:
The first list of input contains an integer 't' denoting the number of test cases/queries to be run.
Then the test cases follow.

The first line input for each test case/query contains an integer N, denoting the total number of elements in the queue.

The second line of input contains N integers separated by a single space, representing the order in which the elements are enqueued into the queue.
Output Format:
For each test case/query, the only line of output prints the order in which the queue elements are dequeued, all of them separated by a single space.

Output for every test case/query will be printed on a new line. 
Note:
You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input queue itself.
Constraints:
1 <= t <= 100
1 <= N <= 10^4
-2^31 <= data <= 2^31 - 1

Time Limit: 1sec 
Sample Input 1:
1
6
1 2 3 4 5 10
Note:
Here, 1 is at the front and 10 is at the rear of the queue.
Sample Output 1:
10 5 4 3 2 1
Sample Input 2:
2
5
2 8 15 1 10
3
10 20 30
Sample Output 2:
10 1 15 8 2 
30 20 10 
```

```cpp
#include <iostream>
using namespace std;

/*****************
Time complexity: O(N)
Space complexity: O(N)
where N is the size of the input queue
****************/

#include <queue> 

void reverseQueue(queue<int> &input) { 
    if (input.size() <= 1) { 
        return; 
    } 
    
    int front = input.front(); 
    
    input.pop();
    
// amra ai  khane ekta recurison chalai dibo jate kore code er front ta last a pochai jay. then last theke push korte thakbo.
    reverseQueue(input);
    
    input.push(front); 
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}
```

### Check redundant brackets

```
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.
Note:
You will not get a partial score for this problem. You will get marks only if all the test cases are passed.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.
Note:
You are not required to print the expected result. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1 second
Sample Input 1:
a+(b)+c 
Sample Output 1:
true
Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.
Sample Input 2:
(a+b)
Sample Output 2:
false
```

```cpp
#include <iostream>
#include <string>
using namespace std;

/*****************
Time complexity: O(N)
Space complexity: O(N)
where N is the size of the input expression
****************/
#include <stack> 

bool checkRedundantBrackets(string expression) { 
    stack<char> stk; 
    string operators = "+-*/"; 
    for (int i = 0; i < expression.length(); ++i) { 
        if (expression[i] == '(' || operators.find(expression[i]) != string::npos) { 
            stk.push(expression[i]); 
        } 
        else if (expression[i] == ')') { 
            bool hasOperator = false; 
            while (!stk.empty() && stk.top() != '(') { 
                stk.pop(); 
                hasOperator = true; 
            } 
            
            if (hasOperator==false) {  // if hasOpertor equal to flase hoy then this is redundant true; mane kono operator na thekle to redundant hobei.
                return true; 
            } 
            
            if (!stk.empty()) { 
                stk.pop(); 
            } 
        } 
    } 
    return false; 
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}
```

### Stock Span
```
Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].
Explanation:
On the sixth day when the price of the stock was 75, the span came out to be 4, because the last 4 prices(including the current price of 75) were less than the current or the sixth day's price.

Similarly, we can deduce the remaining results.
Afzal has to return an array/list of spans corresponding to each day's stock's price. Help him to achieve the task.
Input Format:
The first line of input contains an integer N, denoting the total number of days.

The second line of input contains the stock prices of each day. A single space will separate them.
Output Format:
The only line of output will print the span for each day's stock price. A single space will separate them.
Note:
You are not required to print the expected output explicitly. It has already been taken care of. 
Constraints:
0 <= N <= 10^7
1 <= X <= 10^9
Where X denotes the stock's price for a day.

Time Limit: 1 second
Sample Input 1:
4
10 10 10 10
Sample Output 1:
1 1 1 1 
Sample Input 2:
8
60 70 80 100 90 75 80 120
Sample Output 2:
1 2 3 4 1 1 2 8 
```

```cpp
#include <iostream>
using namespace std;

// Time complexity: O(N) Space complexity: O(N) where N is the number of days
#include <stack> 
//https://youtu.be/XlD5VsOZsyA
int *stockSpan(int *price, int n) { 
    stack<int> stk; 
    int *output = new int[n]; 
    stk.push(0); 
    output[0] = 1; 
    
    for (int i = 1; i < n; ++i) { 
        while (!stk.empty() && price[stk.top()] < price[i]) { 
            stk.pop(); 
        }
		// output[i] = (stk.empty()) ? (i + 1) : (i - stk.top());
        if (stk.empty()) { 
            output[i] = i + 1; 
        } else { 
            output[i] = i - stk.top(); 
        } 
        stk.push(i); 
    } 
    return output; 
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
```

### Minimum bracket Reversal

```
For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.
Note:
You don't have to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1:
{{{
Sample Output 1:
-1
Sample Input 2:
{{{{}}
Sample Output 2:
1
```

```cpp

#include <iostream>
#include <string>
using namespace std;

//Time complexity: O(N) Space complexity: O(N) where N is the number of brackets
#include <stack> 
int countBracketReversals(string input) { 
    int len = input.length(); 
    if (len == 0) { 
        return 0; 
    } 
    
    if (len % 2 != 0) {
        return -1; // Only even number of brackets can be balanced 
    } 
    stack<char> stack; 
    for (int i = 0; i < len; i++) { 
        char currentChar = input[i]; 
        if (currentChar == '{') { 
            stack.push(currentChar); 
        } else if (currentChar == '}'){ // Pop if there is a balanced pair 
            if (!stack.empty() && stack.top() == '{') { 
                stack.pop(); 
            } else { 
                stack.push(currentChar); 
            } 
        } 
    } 
    
    int count = 0; // Only unbalanced brackets are there in stack now 
    while (!stack.empty()) { 
        char char1 = stack.top(); 
        stack.pop(); 
        char char2 = stack.top(); 
        stack.pop(); /* When char1 = } and char2 = {, then we need to reverse both of them so count will increase by 2 */ 
        if (char1 != char2) { 
            count += 2; 
        } else { 
            count += 1; 
        } 
    } 
    return count; 
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
```

```

Lecture 10 : Stacks & Queues END HERE

```
