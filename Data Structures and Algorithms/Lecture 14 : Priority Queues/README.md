```

Lecture 14 : Priority Queues START HERE

```

# ##Lecture 14 : Priority Queues

---

//============>>>>>>>>>> Lecture 14 : Priority Queues
[Lecture 14 : Priority Queues Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp/files/9422909/Lecture.14.Priority.Queues.Notes.pdf)

---

### What is Priority Queue
![image](https://user-images.githubusercontent.com/57065763/186587430-14daa0f9-b976-46e5-8190-c1f7210ae5cb.png)

### Ways to implement Priority Queues
![image](https://user-images.githubusercontent.com/57065763/186587873-47daf473-aceb-4b1f-a3ce-cb674f2e4cee.png)

### Heaps Introduction
![image](https://user-images.githubusercontent.com/57065763/186588182-559d4657-d77b-4696-85fd-a4f93b330d1d.png)

### CBT and its implementaion
![image](https://user-images.githubusercontent.com/57065763/186590527-e90510b9-fc83-439d-bdda-46c57f8ce508.png)

### Insert and Delete in Heaps
![image](https://user-images.githubusercontent.com/57065763/186594080-8e43172e-8c54-4428-9164-66816d66dd1e.png)

### Example Solution and Max heap
![image](https://user-images.githubusercontent.com/57065763/186594572-a75ced62-d68d-4c1a-b7ab-c2effe13b6cc.png)

### Implementation of Priority Queues - 1
![image](https://user-images.githubusercontent.com/57065763/186596833-cbe757ca-7f7c-48b1-b56c-643a681cddf2.png)

```cpp
#include <vector>

class PriorityQueue {
	vector<int> pq;

	public :

	PriorityQueue() {

	}

	bool isEmpty() {
		return pq.size() == 0;
	}

	// Return the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}

	int getMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		return pq[0];
	}
};
```

### Implementation - Insert
![image](https://user-images.githubusercontent.com/57065763/186598450-eb0ce22d-ec77-4587-99f7-bd65966cd0bd.png)

```cpp
#include <vector>

class PriorityQueue {
	vector<int> pq;

	public :

	PriorityQueue() {

	}

	bool isEmpty() {
		return pq.size() == 0;
	}

	// Return the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}

	int getMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		return pq[0];
	}

	void insert(int element) {
		pq.push_back(element);
		
		int childIndex = pq.size() - 1;

		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}

	}
};
```

### Remove Min - Explanation AND Code : Remove Min

```
Code : Remove Min
Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.

```

```cpp
/*
#include <iostream>
#include <climits>
using namespace std;

#include "solution.h"

int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
*/
/*-------------------------------CODE------------------------*/
/*
Time complexity: O(log(N)) 
Space complexity: O(1) 
where N is the size of the Priority Queue 
*/ 

#include <vector> 

class PriorityQueue { 
    vector<int> pq; 
    public: 
    bool isEmpty() { 
        return pq.size() == 0; 
    } 
    
    int getSize() { 
        return pq.size(); 
    } 
    
    int getMin() { 
        if (isEmpty()) { 
            return INT_MIN; 
        } 
        return pq[0]; 
    } 
    
    void insert(int element) { 
        pq.push_back(element); 
        int childIndex = pq.size() - 1; 
        while (childIndex > 0) { 
            int parentIndex = (childIndex - 1) / 2; 
            
            if (pq[childIndex] < pq[parentIndex]) { 
                int temp = pq[childIndex]; 
                pq[childIndex] = pq[parentIndex]; 
                pq[parentIndex] = temp; 
            } else { 
                break; 
            } 
            childIndex = parentIndex; 
        } 
    } 
    
    int removeMin() { 
        
        if (isEmpty()) { 
            return INT_MIN; 
        } 
        
        int ans = pq[0]; 
        pq[0] = pq[pq.size() - 1]; 
        pq.pop_back(); 
        
        // Down-heapify 
        int parentIndex = 0; 
        int leftChildIndex = 2 * parentIndex + 1; 
        int rightChildIndx = 2 * parentIndex + 2;
        
        while (leftChildIndex < pq.size()) { 
            int minIndex = parentIndex; 
            
            if (pq[minIndex] > pq[leftChildIndex]) { 
                minIndex = leftChildIndex; 
            } 
            
            if (rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) { 
                minIndex = rightChildIndx; 
            } 
            
            if (minIndex == parentIndex) { 
                break; 
            } 
            
            int temp = pq[minIndex]; 
            pq[minIndex] = pq[parentIndex]; 
            pq[parentIndex] = temp; 
            parentIndex = minIndex; 
            
            leftChildIndex = 2 * parentIndex + 1; 
            rightChildIndx = 2 * parentIndex + 2; 
        } 
        return ans; 
    } 
};
```

### Remove Min Solution and Complexity Analysis
![image](https://user-images.githubusercontent.com/57065763/186600684-86bdaeea-509b-4014-890a-2c0f2b58e918.png)

```cpp
#include <iostream>
using namespace std;
#include <vector>

class PriorityQueue {
	vector<int> pq;

	public :

	PriorityQueue() {

	}

	bool isEmpty() {
		return pq.size() == 0;
	}

	// Return the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}

	int getMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		return pq[0];
	}

	void insert(int element) {
		pq.push_back(element);
		
		int childIndex = pq.size() - 1;

		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}

	}

	int removeMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// down-heapify

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
	
		while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}

		return ans;
	}
};


int main() {
	PriorityQueue p;

	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);

	cout << p.getSize() << endl;
	cout << p.getMin() << endl;

	while(!p.isEmpty()) {
		cout << p.removeMin() << " " ;

	}
	cout << endl
}

```
### Code : Max Priority Queue

```
Code : Max Priority Queue

Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.

```

```cpp
/*
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(log(N)) [for insert and removeMax functions] : O(1) [for all other functions] 
Space complexity : O(1) [for all functions] 
where N is the size of the Priority Queue 
*/ 

#include <climits> 
#include <vector> 

class PriorityQueue { 
    vector<int> data; 
    
    public: 
    
    void insert(int element) { 
        data.push_back(element); 
        int childIndex = data.size() - 1; 
        
        while (childIndex > 0) { 
            int parentIndex = (childIndex - 1) / 2; 
            if (data[parentIndex] > data[childIndex]) { 
                return; 
            }  
            int temp = data[childIndex]; 
            data[childIndex] = data[parentIndex]; 
            data[parentIndex] = temp; 
            
            childIndex = parentIndex; 
        } 
    } 
    
    int getMax() { 
        if (data.size() == 0) { 
            return INT_MIN; 
        } 
        return data[0]; 
    } 
    
    int removeMax() { 
        if (data.size() == 0) { 
            return INT_MIN; 
        } 
        
        int ans = data[0]; 
        data[0] = data[data.size() - 1]; 
        data.pop_back(); 
        
        int parentIndex = 0; 
        int leftIndex  = parentIndex * 2 + 1; 
        int rightIndex = parentIndex * 2 + 2; 
        
        while (leftIndex < data.size()) { 
            int maxIndex = parentIndex; 
            if (data[leftIndex] > data[maxIndex]) { 
                maxIndex = leftIndex; 
            } 
            
            if (rightIndex < data.size() && data[rightIndex] > data[maxIndex]) { 
                maxIndex = rightIndex; 
            } 
            
            if (maxIndex == parentIndex) { 
                break; 
            } 
            
            int temp = data[maxIndex]; 
            data[maxIndex] = data[parentIndex]; 
            data[parentIndex] = temp; 
            
            parentIndex = maxIndex; 
            leftIndex = parentIndex * 2 + 1; 
            rightIndex = leftIndex + 1; 
        } 
        
        return ans; 
    } 
    
    int getSize() { 
        return data.size(); 
    } 
    
    bool isEmpty() { 
        return data.size() == 0; 
    } 
};
```

### Inplace Heap Sort
![image](https://user-images.githubusercontent.com/57065763/186605353-99246cff-56b4-436e-8a3e-0ec5bdb87ac4.png)

### Code : In-place heap sort
![image](https://user-images.githubusercontent.com/57065763/186606243-bf5c8504-b95c-4d28-b51c-19d0ce591876.png)

```
Code : In-place heap sort

Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
```

```cpp
/*
#include <iostream>
#include "solution.h"

using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(log(N))
Space complexity: O(1)
where N is the size of the input array 
*/ 

void heapSort(int arr[], int n) { 
    
    // Build the heap in input array 
    for (int i = 1; i < n; i++) { 
        
        int childIndex = i; 
        
        while (childIndex > 0) { 
            
            int parentIndex = (childIndex - 1) / 2; 
            
            if (arr[childIndex] < arr[parentIndex]) { 
                int temp = arr[childIndex]; 
                arr[childIndex] = arr[parentIndex]; 
                arr[parentIndex] = temp; 
            } else {
                break; 
            } 
            
            childIndex = parentIndex; 
        } 
    } 
    
    // Remove elements 
    int size = n; 
    
    while (size > 1) { 
        
        int temp = arr[0]; 
        arr[0] = arr[size - 1]; 
        arr[size - 1] = temp;
        size--; 
        
        int parentIndex = 0; 
        int leftChildIndex = 2 * parentIndex + 1; 
        int rightChildIndx = 2 * parentIndex + 2; 
        
        while (leftChildIndex < size) { 
            
            int minIndex = parentIndex; 
            if (arr[minIndex] > arr[leftChildIndex]) { 
                minIndex = leftChildIndex; 
            } 
            
            if (rightChildIndx < size && arr[rightChildIndx] < arr[minIndex]) { 
                minIndex = rightChildIndx; 
            } 
            
            if (minIndex == parentIndex) { 
                break; 
            } 
            
            int temp = arr[minIndex]; 
            arr[minIndex] = arr[parentIndex]; 
            arr[parentIndex] = temp; 
            
            parentIndex = minIndex;
            
            leftChildIndex = 2 * parentIndex + 1; 
            rightChildIndx = 2 * parentIndex + 2; 
        } 
    } 
}
```

### Inplace heap sort : Solution
![image](https://user-images.githubusercontent.com/57065763/186609396-ec06b9d3-ddce-4599-a96c-477334664bb1.png)

```cpp
#include <iostream>
using namespace std;

void inplaceHeapSort(int pq[], int n) {
	// Build the heap in input array
	for(int i = 1; i < n; i++) {
		
		int childIndex = i;
		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}
	}

	// Remove elements

	int size = n;

	while(size > 1) {
		int temp = pq[0];
		pq[0] = pq[size - 1];
		pq[size-1] = temp;

		size--;

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;

		while(leftChildIndex < size) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < size && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}
	}
}


int main() {
	int input[] = {5, 1, 2, 0, 8};
	inplaceHeapSort(input, 5);
	for(int i = 0; i < 5; i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;
}

```

### Inbuilt Priority Queue
![image](https://user-images.githubusercontent.com/57065763/186609956-6f131ef7-853d-48b8-9711-154dc3cf65ef.png)

```cpp
#include <iostream>
using namespace std;
#include <queue>

int main() {
	priority_queue<int> p;

	p.push(100);
	p.push(21);
	p.push(7);
	p.push(165);
	p.push(78);
	p.push(4);

	cout << p.size() << endl;
	cout << p.empty() << endl;
	cout << p.top() << endl;

	while(!p.empty()) {
		cout << p.top() << endl;
		p.pop();
	}
}

```

### K Sorted Array
![image](https://user-images.githubusercontent.com/57065763/186612056-c9cbe279-1198-4d19-a61b-217c34e426bc.png)
![image](https://user-images.githubusercontent.com/57065763/186613486-f3446a89-e839-43fd-a9b3-4b7180401bb7.png)

```cpp
#include <iostream>
using namespace std;
#include <queue>

void kSortedArray(int input[], int n, int k) {
	priority_queue<int> pq;
	for(int i = 0; i < k; i++) {
		pq.push(input[i]);
	}

	int j = 0;
	for(int i = k; i < n; i++) {
		input[j] = pq.top();
		pq.pop();
		pq.push(input[i]);
		j++;
	}


	while(!pq.empty()) {
		input[j] = pq.top();
		pq.pop();
                j++;
	}
}
	
int main() {
	int input[] = {10, 12, 6, 7, 9};
	int k = 3;
	kSortedArray(input, 5, k);
	for(int i = 0; i < 5; i++) {
		cout << input[i] << " ";
	}
}

```

### K smallest Elements AND Code : K smallest Elements
![image](https://user-images.githubusercontent.com/57065763/186613944-15967fa9-fbef-40ac-ae01-1a39e378996a.png)

```
Code : K smallest Elements

You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Note: Order of elements in the output is not important.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of k.
Output Format :
The first and only line of output print k smallest elements. The elements in the output are separated by a single space. 
Constraints:
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
1 2 3 5 
```

```cpp
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "solution.h"

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(N * log(K)) 
Space complexity: O(K)
where N is the size of the input array and 
K is the number of smallest elements that are to be found 
*/ 

#include <queue> 
vector<int> kSmallest(int arr[], int n, int k) { 
    
    priority_queue<int> maxHeap;
    
    for (int i = 0; i < k; i++) { 
        maxHeap.push(arr[i]); 
    } 
    
    for (int i = k; i < n; i++) { 
        if (arr[i] < maxHeap.top()) { 
            maxHeap.pop(); 
            maxHeap.push(arr[i]); 
        } 
    } 
    
    vector<int> output; 
    
    while (!maxHeap.empty()) { 
        output.push_back(maxHeap.top()); 
        maxHeap.pop(); 
    } 
    return output; 
}
```

### Inbuilt Min Priority Queue
![image](https://user-images.githubusercontent.com/57065763/186614530-7f0f8355-8b43-4c3f-9c2c-753f835a88cd.png)

### Code : K largest elements

```
Code : K largest elements

You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k largest elements
Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output :
12
16
20
25
```

```cpp
/*
#include <iostream>
using namespace std;
#include "Solution.h"

int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
	
	return 0;
}
*/

/*-------------------------------CODE------------------------*/
#include <vector> 
#include <queue> 

vector<int> kLargest(int input[], int n, int k){ 
    
    priority_queue<int, vector<int>, greater<int> > pq; 
    for(int i = 0; i < k; i++) { 
        pq.push(input[i]);
    } 
    
    for(int i = k; i < n; i++) { 
        if(input[i] > pq.top()) { 
            pq.pop(); 
            pq.push(input[i]); 
        } 
    } 
    
    vector<int> output; 
    while(!pq.empty()) { 
        output.push_back(pq.top()); 
        pq.pop(); 
    } 
    
    return output; 
}
```

### Check Max-Heap

```
Check Max-Heap

Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.
Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5
Time Limit: 1 sec
Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true
```

```cpp
/*
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(N) 
Space complexity: O(1) 
where N is the size of the input array 
*/ 

bool isMaxHeap(int arr[], int n) { 
    //code start
    for (int i = 0; 2*i+1< n; i++) { 
        
        int leftChildIndex = 2 * i + 1; 
        int rightChildIndex = leftChildIndex + 1; 
        
        if (arr[i] < arr[leftChildIndex]) { 
            return false; 
        } 
        
        if (arr[i] < arr[rightChildIndex]) { 
            return false; 
        } 
    } 
    
    return true; 
}
```

### Kth largest element

```
Kth largest element

Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Note: Try to do this question in less than O(N * logN) time.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following contains an integer, that denotes the value of k.
Output Format :
The first and only line of output contains the kth largest element
Constraints :
1 <= N, Ai, k <= 10^5
Time Limit: 1 sec
Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9
Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10
```

```cpp
/*
#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(N * log(K)) 
Space complexity: O(K) 
where K is the position (ordered by increasing value) of the element you need to find 
*/

#include <queue> 

int kthLargest(int* arr, int n, int k) { 
    priority_queue<int, vector<int>, greater<int> > minHeap; 
    for (int i = 0; i < k; ++i) { 
        minHeap.push(arr[i]); 
    } 
    
    for (int i = k; i < n; ++i) { 
        if (arr[i] > minHeap.top()) { 
            minHeap.pop(); 
            minHeap.push(arr[i]); 
        } 
    } 
    return minHeap.top(); 
}
```

### Merge K sorted arrays

```
Merge K sorted arrays

Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format:
The first line of input contains an integer, that denotes value of k.
The following lines of input represent k sorted arrays. Each sorted array uses two lines of input. The first line contains an integer, that denotes the size of the array. The following line contains elements of the array.
Output Format:
The first and only line of output contains space separated elements of the merged and sorted array, as described in the task.
Constraints:
0 <= k <= 1000
0 <= n1, n2 <= 10000
Time Limit: 1 second
Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234
```

```cpp
/*
#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(K * N * log(K * N)) 
Space complexity: O(K * N) 
where K is the number of arrays to merge and N is the average length of the arrays 
*/ 

#include <queue> 
vector<int> mergeKSortedArrays(vector<vector<int>*> input) { 
    
    vector<int> mergedArray; 
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    
    for (int i = 0; i < input.size(); i++) { 
        for (int j = 0; j < input[i]->size(); j++) { 
            minHeap.push(input[i]->at(j)); 
        } 
    } 
    
    while (!minHeap.empty()) { 
        mergedArray.push_back(minHeap.top()); 
        minHeap.pop(); 
    } 
    
    return mergedArray; 
}

```

### Running Median

```
Running Median

You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer 'N', denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list in one line (space-separated).
Input Constraints
0 <= N <= 10 ^ 5
1 <= ARR[i] <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
```

```cpp
/*
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}

*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(N * log(N)) ==>>bcz divide and insert element in 2 heap. that's why LogN
Space complexity: O(N) 
where N is the number of elements in the array 
*/ 

#include <queue> 

void findMedian(int* arr, int n) { 
    
    priority_queue<int, vector<int>, greater<int> > minHeap; 
    priority_queue<int> maxHeap; 
    
    // For each element in the data stream 
    for (int i = 0; i < n; i++) { 
        
        // minimun value gula MaxHeap a rakhle min er max top value pabo. 
        //temini max value minHeap a rakhle min top value pabo.
        if (maxHeap.size() && arr[i] > maxHeap.top()) {
            minHeap.push(arr[i]); 
        } else { 
            maxHeap.push(arr[i]); 
        } 
        
        if (abs((int)maxHeap.size() - (int)minHeap.size()) > 1) { 
            if (maxHeap.size() > minHeap.size()) { 
                int temp = maxHeap.top(); 
                maxHeap.pop(); 
                minHeap.push(temp); 
            } else { 
                int temp = minHeap.top(); 
                minHeap.pop(); 
                maxHeap.push(temp); 
            } 
        } 
        
        int median; 
        int totalSize = maxHeap.size() + minHeap.size();
        
        // When number of elements is odd 
        if (totalSize % 2 == 1) { 
            if (maxHeap.size() > minHeap.size()) { 
                median = maxHeap.top(); 
            } else { 
                median = minHeap.top(); 
            } 
        } 
        // When number of elements is even 
        else { 
            median = 0; 
            if (!maxHeap.empty()) {
                median += maxHeap.top(); 
            }
            if (!minHeap.empty()) {
                median += minHeap.top(); 
            }
            median /= 2; 
        } 
        cout << median << " "; 
    } 
}
```


### Buy the ticket

```
Buy the ticket

You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.
A queue is maintained for buying the tickets and every person is attached with a priority (an integer, 1 being the lowest priority).
The tickets are sold in the following manner -
1. The first person (pi) in the queue requests for the ticket.
2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
3. Otherwise, give him the ticket (and don't make him stand in queue again).
Giving a ticket to a person takes exactly 1 minute and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.
Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.
Input Format:
The first line of input contains an integer, that denotes the value of total number of people standing in queue or the size of the array of priorities. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array of priorities.
The following contains an integer, that denotes the value of index of your priority. Let us denote it with symbol k.
Output Format :
The first and only line of output contains the time required for you to get the ticket.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
3
3 9 4
2
Sample Output 1 :
2
Sample Output 1 Explanation :
Person with priority 3 comes out. But there is a person with higher priority than him. So he goes and then stands in the queue at the end. Queue's status :  {9, 4, 3}. Time : 0 secs.
Next, the person with priority 9 comes out. And there is no person with higher priority than him. So he'll get the ticket. Queue's status :  {4, 3}. Time : 1 secs.
Next, the person with priority 4 comes out (which is you). And there is no person with higher priority than you. So you'll get the ticket. Time : 2 secs.
Sample Input 2 :
5
2 3 2 2 4
3
Sample Output 2 :
4
```

```cpp
/*
#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(N * log(N)) 
Space complexity: O(N) 
where N is the number of people in the queue 
*/ 

#include <queue> 
int buyTicket(int *arr, int n, int k) { 
    queue<int> peopleQueue; 
    priority_queue<int> maxHeap; 
    for (int i = 0; i < n; i++) { 
        peopleQueue.push(arr[i]); 
        maxHeap.push(arr[i]); 
    } 
    
    int count = 0; 
    while (!maxHeap.empty()) { 
        if (peopleQueue.front() == maxHeap.top()) { 
            if (k == 0) { 
                return count + 1; 
            } else { 
                count++; 
                peopleQueue.pop(); 
                maxHeap.pop(); 
                k--; 
            } 
        } else { 
            peopleQueue.push(peopleQueue.front()); 
            peopleQueue.pop(); 
            if (k == 0) { 
                k = peopleQueue.size() - 1; 
            } else { 
                k--; 
            } 
        } 
    } 
    return count; 
}

```


```

Lecture 14 : Priority Queues END HERE

```
