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


