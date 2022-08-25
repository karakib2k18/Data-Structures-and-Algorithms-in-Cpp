```

Lecture 15 : Hashmaps START HERE

```

# ##Lecture 15 : Hashmaps

---

//============>>>>>>>>>> Lecture 15 : Hashmaps Notes
[Lecture 15 : Hashmaps Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp/files/9424456/Lecture.15.Hashmaps.Notes.pdf)

---

### Introduction to Hashmaps
![image](https://user-images.githubusercontent.com/57065763/186646790-ddc32389-6947-4884-bbb0-fada779b984a.png)

### Inbuilt Hashmap
![image](https://user-images.githubusercontent.com/57065763/186647448-01a0eae1-d34e-409e-ad9e-5f324f75d296.png)
![image](https://user-images.githubusercontent.com/57065763/186647509-b22efb88-ab9e-418a-bdc1-bb4128d9f5f8.png)

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	unordered_map<string, int> ourmap;
	
	// insert
	pair<string, int> p("abc", 1);
	ourmap.insert(p);
	ourmap["def"] = 2;

	// find or access
	cout << ourmap["abc"] << endl;
	cout << ourmap.at("abc") << endl;
	
	//cout << ourmap.at("ghi") << endl;
	cout << "size : " << ourmap.size() << endl;
	cout << ourmap["ghi"] << endl;
	cout << "size : " << ourmap.size() << endl;

	// check Presense
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

	// erase
	ourmap.erase("ghi");
	cout << "size : " << ourmap.size() << endl;
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

}

```

### Remove Duplicates
![image](https://user-images.githubusercontent.com/57065763/186648257-f5e13bc9-b6db-4c0e-8d8d-692f00ba916b.png)

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicates(int* a, int size) {
	vector<int> output;
	unordered_map<int, bool> seen;
	for (int i = 0; i < size; i++) {
		if (seen.count(a[i]) > 0) {
			continue;
		}
		seen[a[i]] = true;
		output.push_back(a[i]);
	}
	return output;
}

int main() {
	int a[] = {1,2,3,3,2,1,4,3,6,5,5};
	vector<int> output = removeDuplicates(a, 11);
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
}
```

### Code : Maximum Frequency Number

```
Code : Maximum Frequency Number
Send Feedback
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
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

    cout << highestFrequency(arr, n);

    delete[] arr;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(N) 
Space complexity: O(N) 
where N is the size of input array 
*/

#include <unordered_map> 
int highestFrequency(int arr[], int n) {
    unordered_map<int, int> freq; 
    
    int maxFreq = 0; 
    for (int i = 0; i < n; ++i) { 
        ++freq[arr[i]]; 
        maxFreq = max(maxFreq, freq[arr[i]]); 
    } 
    
    int maxFreqElement; 
    for (int i = 0; i < n; ++i) { 
        if (freq[arr[i]] == maxFreq) { 
            maxFreqElement = arr[i]; 
            break; 
        } 
    } 
    
    return maxFreqElement; 
}
```

### Code : Print Intersection

```
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}
```

```cpp
/*
Code : Print Intersection
Send Feedback
You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the first sorted array/list (ARR1).


Input format :
The first line of input contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
Print the intersection elements. Each element is printed in a separate line.
Constraints :
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2
3 
4
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 
2 
2
*/
/*-------------------------------CODE------------------------*/
/* 
Time complexity: O(N) 
Space complexity: O(N)
where N is the size of input array 
*/

#include <unordered_map> 
void printIntersection(int arr1[], int arr2[], int n, int m) { 
    
    unordered_map<int, int> freq; 
    for (int i = 0; i < n; ++i) { 
        ++freq[arr1[i]]; 
    } 
    
    for (int i = 0; i < m; ++i) { 
        if (freq.find(arr2[i]) != freq.end()) { 
            cout << arr2[i] << "\n"; 
            if (freq[arr2[i]] > 1) { 
                --freq[arr2[i]]; 
            } else { 
                freq.erase(arr2[i]); 
            } 
        } 
    } 
}

```

### Code : Pair Sum to 0

```
Code : Pair Sum to 0
Send Feedback
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
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

    cout << pairSum(arr, n);

    delete[] arr;
}
*/
/*-------------------------------CODE------------------------*/
/*
Time complexity: O(N) 
Space complexity: O(N) 
where N is the size of input array 
*/ 

#include <unordered_map> 
int pairSum(int *arr, int n) { 
    
    unordered_map<int, int> freq; 
    int pairCount = 0; 

    for (int i = 0; i < n; ++i) { 
        int complement = -arr[i]; 
        if (freq.find(complement) != freq.end()) { 
            pairCount += freq[complement]; 
        } 
        ++freq[arr[i]]; 
    }
    
    return pairCount; 
}

```

### Iterators
![image](https://user-images.githubusercontent.com/57065763/186649779-f032809c-f215-4a1f-9bbf-3fca98917ac9.png)

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
	unordered_map<string, int> ourmap;
	ourmap["abc"] = 1;
	ourmap["abc1"] = 2;
	ourmap["abc2"] = 3;
	ourmap["abc3"] = 4;
	ourmap["abc4"] = 5;
	ourmap["abc5"] = 6;

	unordered_map<string, int>::iterator it = ourmap.begin();
	while (it != ourmap.end()) {
		cout << "Key : " << it->first << " Value: " << it->second << endl;
		it++;
	}

	// find
	unordered_map<string, int>::iterator it2 = ourmap.find("abc");
	ourmap.erase(it2, it2 + 4);
	

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it1 = v.begin();
	while (it1 != v.end()) {
		cout << *it1 << endl;
		it1++;
	}
}
```
### Bucket Array and hash function
![image](https://user-images.githubusercontent.com/57065763/186651116-ba5d8acf-700a-42a1-9e33-2f64dce00cee.png)

### Collision Handling
![image](https://user-images.githubusercontent.com/57065763/186651841-33ca205b-b484-4c18-ada5-1ef3f5bb5329.png)

### Hashmap Implementation - Insert
![image](https://user-images.githubusercontent.com/57065763/186652875-89f6c9f0-a931-4789-91b0-17772c0826cc.png)

```cpp
#include <string>
using namespace std;

template <typename V>
class MapNode {
	public:
		string key;
		V value;
		MapNode* next;

		MapNode(string key, V value) {
			this->key = key;
			this->value = value;
			next = NULL;
		}

		~MapNode() {
			delete next;
		}
};

template <typename V>
class ourmap {
	MapNode<V>** buckets;
	int count;
	int numBuckets;

	public:
	ourmap() {
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];
		for (int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}
	}

	~ourmap() {
		for (int i = 0; i < numBuckets; i++) {
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size() {
		return count;
	}

	V getValue(string key) {
		
	}

	private:
	int getBucketIndex(string key) {
		int hashCode = 0;

		int currentCoeff = 1;
		for (int i = key.length() - 1; i >= 0; i--) {
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff % numBuckets;
		}

		return hashCode % numBuckets;
	}

	public:
	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(string key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V>(key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;
	}

};
```

### Hashmap Implementation - Delete and Search

![image](https://user-images.githubusercontent.com/57065763/186654606-4a931ee2-1585-4437-bb4e-c1f4959ccbea.png)

```cpp
#include <string>
using namespace std;

template <typename V>
class MapNode {
	public:
		string key;
		V value;
		MapNode* next;

		MapNode(string key, V value) {
			this->key = key;
			this->value = value;
			next = NULL;
		}

		~MapNode() {
			delete next;
		}
};

template <typename V>
class ourmap {
	MapNode<V>** buckets;
	int count;
	int numBuckets;

	public:
	ourmap() {
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];
		for (int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}
	}

	~ourmap() {
		for (int i = 0; i < numBuckets; i++) {
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size() {
		return count;
	}

	V getValue(string key) {
		int bucketIndex = getBucketIndex(string key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				return head->value;
			}
			head = head->next;
		}
		return 0;
	}

	private:
	int getBucketIndex(string key) {
		int hashCode = 0;

		int currentCoeff = 1;
		for (int i = key.length() - 1; i >= 0; i--) {
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff % numBuckets;
		}

		return hashCode % numBuckets;
	}

	public:
	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(string key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V>(key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;
	}

	V remove(string key) {
		int bucketIndex = getBucketIndex(string key);
		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V>* prev = NULL;
		while (head != NULL) {
			if (head->key == key) {
				if (prev == NULL) {
					buckets[bucketIndex] = head->next;
				} else {
					prev->next = head->next;
				}
				V value = head->value;
				head->next = NULL;
				delete head;
				count--;
				return value;
			}
			prev = head;
			head = head->next;
		}
		return 0;
	}

};
```

### Time complexity and Load factor
![image](https://user-images.githubusercontent.com/57065763/186655341-fb1102e5-7782-4e84-96b9-5c9e3b12a729.png)

### Rehashing
![image](https://user-images.githubusercontent.com/57065763/186659397-6e872671-ebbf-40c3-adfa-53a1c6b88ed3.png)

```cpp
void rehash()
{
	MapNode<V> **temp = buckets;	// To store the old bucket
	buckets = new MapNode<V> *[2 *numBuckets];	// doubling the size
	for (int i = 0; i < 2 * numBuckets; i++)
	{
		buckets[i] = NULL;	// initialising each head pointer to NULL
	}
	int oldBucketCount = numBuckets;
	numBuckets *= 2;	// updating new size
	count = 0;
	for (int i = 0; i < oldBucketCount; i++)
	{
		MapNode<V> *head = temp[i];
		while (head != NULL)
		{
			string key = head->key;
			V value = head->value;
			insert(key, value);	// inserting each value of old bucket
			// into the new one
			head = head->next;
		}
	}
	// deleting the old bucket
	for (int i = 0; i < oldBucketCount; i++)
	{
		MapNode<V> *head = temp[i];
		delete head;
	}
	delete[] temp;
}
void insert(string key, V value)
{
	int bucketIndex = getBucketIndex(key);
	MapNode<V> *head = buckets[bucketIndex];
	while (head != NULL)
	{
		if (head->key == key)
		{
			head->value = value;
			return;
		}
		head = head->next;
	}
	head = buckets[bucketIndex];
	MapNode<V> *node = new MapNode<V> (key, value);
	node->next = head;
	buckets[bucketIndex] = node;
	count++;
	// Now we will check the load factor after insertion.
	double loadFactor = (1.0 *count) / numBuckets;
	if (loadFactor > 0.7)
	{
		rehash();	// We will rehash.
	}
}

```


### Extract Unique characters

```
Extract Unique characters
Send Feedback
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
Input format:
The first and only line of input contains a string, that denotes the value of S.
Output format :
The first and only line of output contains the updated string, as described in the task.
Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
```

```cpp
/*
#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
*/

/*-------------------------------CODE------------------------*/

/*
Time complexity: O(N) 
Space complexity: O(1)
where N is the length of the input string 
*/

#include <unordered_set> 
string uniqueChar(string str) { 
    string answer; 
    unordered_set<char> charSet; 
    for (char ch : str) { 
        if (charSet.find(ch) == charSet.end()) { 
            answer.push_back(ch); 
            charSet.insert(ch); 
        } 
    } 
    return answer; 
}
```

### Longest Consecutive Sequence

```
Longest Consecutive Sequence
Send Feedback
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of longest consecutive sequence, then just print the starting element.
Constraints :
0 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16
```

```cpp
/*
#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}

*/

/*-------------------------------CODE------------------------*/
// https://www.youtube.com/watch?v=YWXbu5uyGXs
/*
Time complexity: O(N) 
Space complexity: O(N) 
where N is the length of the input array 
*/ 
// EASY SOLUTION
#include <vector>
#include<unordered_map>

vector < int > longestConsecutiveIncreasingSequence(int * arr, int n) {
  
  unordered_map < int, bool > p;
  
  for (int i = 0; i < n; i++) {
    p[arr[i]] = true;
  }
  
  for (int i = 0; i < n; i++) {
    if (p.count(arr[i] - 1) > 0) {
      p[arr[i]] = false;
    }
  }
  
  int max = 0;
  int start;
  
  for (int i = 0; i < n; i++) {
    
    if (p[arr[i]] = true) {
      int incrementByOne = 1;
      int length = 1;
     
     while (p.count(arr[i] + incrementByOne) > 0) {
        incrementByOne++;
        length++;
      }
      
      if (length > max) {
        max = length;
        start = arr[i];
      }
    }

  }
  
  vector < int > v;
  v.push_back(start);
  v.push_back(start + max - 1);
  return v;

}
//============>>>>>>>>>>>>>>>>>solution by CN
/*
#include <unordered_map> 
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) { 
    unordered_map<int, bool> visitedElements; 
    unordered_map<int, int> elementToIndexMapping; 
    for (int i = 0; i < n; i++) { 
        elementToIndexMapping[arr[i]] = i; 
        if (visitedElements.count(arr[i]) == 0) { 
            visitedElements[arr[i]] = true; 
        } 
    } 
    
    vector<int> longestSequence; 
    int globalMaxSequenceLength = 1; 
    int globalMinStartIndex = 0; 
    for (int i = 0; i < n; i++) { 
        int num = arr[i]; 
        int currentMinStartIndex = i; 
        int count = 0; 
        int tempNum = num; 
        // Forward 
        
        while (visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true) { 
            visitedElements[tempNum] = false; 
            count++; 
            tempNum++; 
        } 
        // Backward 
        tempNum = num - 1; 
        while (visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true) { 
            visitedElements[tempNum] = false; 
            count++; 
            currentMinStartIndex = elementToIndexMapping[tempNum]; 
            tempNum--; 
        } 
        
        if (count > globalMaxSequenceLength) { 
            globalMaxSequenceLength = count; 
            globalMinStartIndex = currentMinStartIndex; 
        } else if (count == globalMaxSequenceLength) { 
            if (currentMinStartIndex < globalMinStartIndex) { 
                globalMinStartIndex = currentMinStartIndex; 
            } 
        } 
    } 
    
    int globalStartNum = arr[globalMinStartIndex]; 
    longestSequence.push_back(globalStartNum); 
    if (globalMaxSequenceLength > 1) { 
        longestSequence.push_back(globalStartNum + globalMaxSequenceLength - 1); 
    } 
    
    return longestSequence; 
}
*/
```

### Pairs with difference K

```
Pairs with difference K
Send Feedback
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.
Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6
```

```cpp
/*
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(N)
Space complexity: O(N)
where N is the size of the input array 
*/ 

#include <unordered_map> 
int getPairsWithDifferenceK(int *arr, int n, int k) {
    
    unordered_map<int, int> freq; 
    int pairCount = 0; 
    for (int i = 0; i < n; ++i) { 
        
        int complement = arr[i] + k; 
        pairCount += freq[complement]; 
        
        if (k != 0) { 
            complement = arr[i] - k; 
            pairCount += freq[complement]; 
        } 
        ++freq[arr[i]]; 
    } 
    return pairCount; 
}
```

### Longest subset zero sum

```
Longest subset zero sum
Send Feedback
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
```

```cpp
/*
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(N) 
Space complexity: O(N) 
where N is the size of the input array 
*/ 

#include <unordered_map> 
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) { 
    
    unordered_map<int, int> freq; 
    
    for (int i = 1; i < n; i++) { 
        arr[i] += arr[i - 1]; 
    } 
    
    int m = 0; 
    for (int i = 0; i < n; i++) { 
        if (arr[i] == 0) { 
            if (m < i + 1) { 
                m = i + 1; 
            } 
        } else if (freq.count(arr[i]) > 0) { 
            if (m < i - freq[arr[i]]) { 
                m = i - freq[arr[i]]; 
            } 
        } else { 
            freq[arr[i]] = i; 
        } 
    } 
    return m; 
}

```

```

Lecture 15 : Hashmaps END HERE

```
