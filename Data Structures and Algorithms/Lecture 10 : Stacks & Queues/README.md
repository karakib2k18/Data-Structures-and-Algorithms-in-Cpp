# ##Lecture 9 : Linked List 2

---



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






### Code: Midpoint of LL - QUESTION-1