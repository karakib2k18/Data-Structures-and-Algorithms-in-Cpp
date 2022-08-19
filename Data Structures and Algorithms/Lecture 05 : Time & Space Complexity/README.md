```

Lecture 5 : Time and Space Complexity Analysis START HERE

```

# ##Lecture 5 : Time and Space Complexity Analysis

---

//============>>>>>>>>>>Lecture 5 : Time and Space Complexity Analysis Notes
[Lecture 5 : Time and Space Complexity Analysis Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp/files/9376820/Lecture.5.Time.and.Space.Complexity.Analysis.Notes.pdf)

---

### Order Complexity Analysis AND Theoretical Analysis
![image](https://user-images.githubusercontent.com/57065763/185409295-01ac3771-35cd-4ca5-8a88-d30b164e960f.png)

### Linear Search time complexity
![image](https://user-images.githubusercontent.com/57065763/185416158-800f28ab-dff0-49e0-ba04-c382144d7cc8.png)

### Insertion Sort time complexity
![image](https://user-images.githubusercontent.com/57065763/185444047-4704a962-e53f-493d-b48f-d5f4367f6901.png)

### Selection Sort time complexity
![image](https://user-images.githubusercontent.com/57065763/185445002-8fe338a5-a2a7-4312-b17e-e4d1dfd4f3e5.png)
![image](https://user-images.githubusercontent.com/57065763/185419651-7ea4ff05-92f4-475e-8f01-f4a05597098b.png)

### Theoretical Analysis - Recursive Algorithms
![image](https://user-images.githubusercontent.com/57065763/185461951-8a53d455-3974-4b36-bced-4d173d3086d7.png)

### Merge Sort Space Time complexity
![image](https://user-images.githubusercontent.com/57065763/185467100-6ceeba8c-7108-43bc-a629-b0259f3ed41e.png)

### Fibonacci Time Complexity Analysis
![image](https://user-images.githubusercontent.com/57065763/185468615-ad7c91db-4efc-44b3-a879-aa4a8d40a8e3.png)
![image](https://user-images.githubusercontent.com/57065763/185470273-39f0846f-f8d6-4674-88db-2de11829e1f1.png)

### Space Complexity Analysis
![image](https://user-images.githubusercontent.com/57065763/185472100-88bc6206-8264-4335-be48-bce8a9d1510d.png)

### Merge Sort Space Complexity Analysis
![image](https://user-images.githubusercontent.com/57065763/185474401-5095443f-6460-453c-b1e2-775f1fa759b1.png)

### Fibonacci Space Complexity Analysis
![image](https://user-images.githubusercontent.com/57065763/185474812-7ef1fc9b-605a-4edd-b92f-965be0a548ab.png)

### ###QUIZ:
![image](https://user-images.githubusercontent.com/57065763/185410111-635fa62e-39dc-4983-b1d9-8a2718f3359a.png)
![image](https://user-images.githubusercontent.com/57065763/185458586-291150ed-9c11-4d52-9ce7-134a8510480f.png)

### Find the Unique Element
![image](https://user-images.githubusercontent.com/57065763/185476488-7d93e3de-c8b8-485c-9496-56cf9cf6e6a2.png)

```
Find the Unique Element
Send Feedback
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
 Note:
Unique element is always present in the array/list according to the given condition.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the unique element present in the array.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec
Sample Input 1:
1
7
2 3 1 6 3 6 2
Sample Output 1:
1
Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7
Sample Output 2:
4
10
```

```cpp
/*
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n) Space Complexity : O(1) where n is size of input array */
int findUnique(int *arr, int n)
{
	int XOR = 0;
	for (int i = 0; i < n; ++i)
	{
		XOR ^= arr[i];
	}
	return XOR;
}

/*
    XOR Use korte hobe
    
    1 ^ 1=0;
    1 ^ !1 = 1;
    a^0 = 1;
    
    res =>  first elements indicate, then compare with first elements.
    then sote output in res. then compre with the next element until i<n;
    
    N;B: WATCH THE HINTS VIDEOS AGAIN
*/
```

### Duplicate in array
![image](https://user-images.githubusercontent.com/57065763/185477835-f1058a9a-aab8-4d1c-bffc-d39196ae83c7.png)

```
Duplicate in array
Send Feedback
You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.
Note :
Duplicate number is always present in the given array/list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the duplicate element in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec
Sample Input 1:
1
9
0 7 2 5 4 7 1 3 6
Sample Output 1:
7
Sample Input 2:
2
5
0 2 1 3 1
7
0 3 1 5 4 3 2
Sample Output 2:
1
3
```

```cpp
/*
#include <iostream>
using namespace std;

#include "solution.h"

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n) Space Complexity : O(1) where n is size of input array
*/
/*
There is another way of solving this using XOR. Time and Complexity remains the same as above.
*/

int findDuplicate(int *arr, int n){

    /*
    Hints: (1) count the some of sum of whole Array N.
    (2) Then count the the sum of N-1, because one number is duplicate. 
    SO, till N-1; we can use formula tor sum o to <N-1;
    Finally, minus sumOfAray to <N-1;
    */
    
    /*
    MATH FORMULA=>
    1 to n = (n*( n+1))/2
    so 1 to n-1 = ((n)*(n-1))/2;
    */
    
	int sumOfNminusTwoNaturalNumbers = 0;
	for (int i = 0; i < n - 1; i++){
		sumOfNminusTwoNaturalNumbers += i;
	}
    
	//OR int sumOfNminusTwoNaturalNumbers = ((n-2)*(n-1))/2;
	int sumOfElements = 0;
	for (int i = 0; i < n; i++) {
		sumOfElements += arr[i];
	}

	return (sumOfElements - sumOfNminusTwoNaturalNumbers);
}
```

### Array Intersection
![image](https://user-images.githubusercontent.com/57065763/185479053-f6bf14e9-f863-4c8a-a542-148a908c1d32.png)

```
Array Intersection
Send Feedback
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in ascending order.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 
Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10
Sample Output 1 :
2 3 4
10
Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 2 2
Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array.
```

```cpp
/*
#include <iostream>
#include <algorithm>
using namespace std;

#include "solution.h"

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time Complexity : O((n* log(n)) + (m* log(m))) 
Space Complexity : O(1) 
A more optimized solution to this problem is possible using HashMaps which will have: 
Time Complexity: O(n + m) 
Space Complexity : O(min(n, m)) where 'n' and 'm' are sizes of the input arrays/lists 
*/
void intersection(int *arr1, int *arr2, int n, int m)
{
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);
	int i = 0;	//Pointer to iterate over 
	int j = 0;	//Pointer to iterate over 

	while (i < n && j < m)
	{
		if (arr1[i] == arr2[j])
		{
			cout << arr1[i] << " ";
			i++;
			j++;
		}
		else if (arr1[i] < arr2[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
}
```
### Pair sum in array
![image](https://user-images.githubusercontent.com/57065763/185481171-bffa4adc-d7a5-4ce4-9a8a-c58bee46c724.png)

```
Pair sum in array
Send Feedback
You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
Note:
Given array/list can contain duplicate elements. 
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'num'.
Output format :
For each test case, print the total number of pairs present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7
Sample Output 1:
7
Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10
Sample Output 2:
0
2


 Explanation for Input 2:
Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).
```

```cpp
/*
#include <iostream>
#include <algorithm>
using namespace std;

#include "solution.h"

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n* log(n))
Space Complexity : O(1)
A more optimized solution to this problem is possible using HashMaps 
which will have: Time Complexity: O(n) 
Space Complexity : O(n) 
where n is size of input Array/List
*/

/*---------------------- easy approach-----------------------*/
int pairSum(int *arr, int n, int num) 
{ 
    
    sort(arr, arr + n); 
    int count=0;
        int i=0;
        int j=n-1;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum==num)
            {
                if(arr[i]==arr[i+1] || arr[j]==arr[j-1])
                {
                    int p=j-1;
                    while(arr[p]==arr[j] && p>i)
                    {
                        count++;
                        p--;
                    }
                    count++;
                    i++;
                }
                else
                {
                    count++;
                    i++;
                    j--;
                }
            }
            else if(sum<num)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
    return count;
}


/*---------------------- HARD approach-----------------------*/
int pairSum(int *arr, int n, int num) 
{ 
    
    // befor sort=>  example: 1 5 2 1 7 2 3 2
    
    /* We can sort using Merge Sort or using inbuilt Algorithm */
    
    //Algorithm
    sort(arr, arr + n); 
    
    
    int startIndex = 0; 
    int endIndex = n - 1; 
    int numPairs = 0; 
    //after sort=> example: 1 1 2 2 2 3 5 7
    /*
        1 1 2 2 2 3 3 5 7
        1 1 2 2 2 3 3 5
        1 1 2 2 2 3 3 => 1+3 & 1+3 (2 times 1* 2 times 3= 4)
    */
    while (startIndex < endIndex) 
    { 
        if (arr[startIndex] + arr[endIndex] < num) // 1+2 < 4 hole start++
        { 
            startIndex++; 
        } 
        else if (arr[startIndex] + arr[endIndex] > num)// 1+7>4 hole end --
        {
            endIndex--; 
        } 
        else
        { 
    /*
        1 1 2 2 2 3 3 5 7
        1 1 2 2 2 3 3 5
        1 1 2 2 2 3 3 => 1+3 & 1+3 (2 times 1* 2 times 3= 4)
        
        next step code for 2 2 2
    */
            int elementAtStart = arr[startIndex];  // 0=> 1
            int elementAtEnd = arr[endIndex]; // 5=> 3
            
            if (elementAtStart == elementAtEnd) // example: 2 2 2
            { int totalElementsFromStartToEnd = (endIndex - startIndex) + 1; 
             numPairs += (totalElementsFromStartToEnd * (totalElementsFromStartToEnd - 1) / 2); //so 15 pairs
             return numPairs; 
            } 
            
    /*
        1 1 2 2 2 3 3 5 7
        1 1 2 2 2 3 3 5
        1 1 2 2 2 3 3 => 1+3 & 1+3 (2 times 1* 2 times 3= 4)
        
        next code for 1 1 3 3
    */
            
            int tempStartIndex = startIndex + 1; //1
            int tempEndIndex = endIndex - 1; // 4
            
            // index 1 value = index 0 value hole (same then tempStartIndex increase untill not same and make the elementAtStart=tempStartIndex)
            while (tempStartIndex <= tempEndIndex && arr[tempStartIndex] == elementAtStart) 
            {
                tempStartIndex += 1; 
            } 
                //index 4 value = index 5 value hole (same then tempEndIndex decrease untill not same and make the elementAtEnd=tempEndIndex)
            while (tempStartIndex <= tempEndIndex && arr[tempEndIndex] == elementAtEnd) 
            { 
                tempEndIndex -= 1; 
            } 
            int totalElementsFromStart = (tempStartIndex - startIndex); 
            int totalElementsFromEnd = (endIndex - tempEndIndex); 
            numPairs += (totalElementsFromStart * totalElementsFromEnd); 
            startIndex = tempStartIndex; endIndex = tempEndIndex; 
        } 
    } 
    return numPairs; 
}
```

### Triplet sum

```
Triplet sum
Send Feedback
You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'X'.
Output format :
For each test case, print the total number of triplets present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5

 Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)
```

```cpp
/*
#include <iostream>
#include <algorithm>
using namespace std;

#include "solution.h"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}
*/

/*-------------------------------CODE------------------------*/

/*
Time Complexity : O(n^2)
Space Complexity : O(1)
where n is size of Array/List 
*/

/*---------------------- EASY approach-----------------------*/

int tripletSum(int *arr, int n, int num)
{

    sort(arr, arr + n); 
    int count=0;
    for(int l=0;l<n-2;l++)
    {
        int i=l+1;
        int j=n-1;
        while(i<j)
        {
            int sum=arr[i]+arr[j]+arr[l];
            if(sum==num)
            {
                if(arr[i]==arr[i+1] || arr[j]==arr[j-1])
                {
                    int p=j-1;
                    while(arr[p]==arr[j] && p>=i+1)
                    {
                        count++;
                        p--;
                    }
                    count++;
                    i++;
                }
                else
                {
                    count++;
                    i++;
                    j--;
                }
            }
            else if(sum<num)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
    }
    return count;
}

/*---------------------- HARD approach-----------------------*/

int pairSum(int *arr, int startIndex, int endIndex, int num)
{
	int numPair = 0;
	while (startIndex < endIndex)
	{
		if (arr[startIndex] + arr[endIndex] < num)
		{
			startIndex++;
		}
		else if (arr[startIndex] + arr[endIndex] > num)
		{
			endIndex--;
		}
		else
		{
			int elementAtStart = arr[startIndex];
			int elementAtEnd = arr[endIndex];
			if (elementAtStart == elementAtEnd)
			{
				int totalElementsFromStartToEnd = (endIndex - startIndex) + 1;
				numPair += (totalElementsFromStartToEnd *(totalElementsFromStartToEnd - 1) / 2);
				return numPair;
			}
			int tempStartIndex = startIndex + 1;
			int tempEndIndex = endIndex - 1;
			while (tempStartIndex <= tempEndIndex && arr[tempStartIndex] == elementAtStart)
			{
				tempStartIndex += 1;
			}
			while (tempEndIndex >= tempStartIndex && arr[tempEndIndex] == elementAtEnd)
			{
				tempEndIndex -= 1;
			}
			int totalElementsFromStart = (tempStartIndex - startIndex);
			int totalElementsFromEnd = (endIndex - tempEndIndex);
			numPair += (totalElementsFromStart *totalElementsFromEnd);
			startIndex = tempStartIndex;
			endIndex = tempEndIndex;
		}
	}
	return numPair;
}
int tripletSum(int *arr, int n, int num)
{
	sort(arr, arr + n);
	int numTriplets = 0;
	for (int i = 0; i < n; i++)
	{
		int pairSumFor = num - arr[i];
		int numPairs = pairSum(arr, (i + 1), (n - 1), pairSumFor);
		numTriplets += numPairs;
	}
	return numTriplets;
}
```

### Rotate array

```
Rotate array
Send Feedback
You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
 Note:
Change in the input array/list itself. You don't need to return or print the elements.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains the value of 'D' by which the array/list needs to be rotated.
Output Format :
For each test case, print the rotated array/list in a row separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^4
0 <= N <= 10^6
0 <= D <= N
Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2
Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2
Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2
```

```cpp
/*
#include <iostream>
using namespace std;

#include "solution.h"

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
*/

/*-------------------------------CODE------------------------*/
/*---------------------- EASY approach-----------------------*/

void rotate(int *input,int k, int n)
{
 int b[n],i;

 //Moving each element by k positions
 for(i=0;i<n;i++)
  b[i]=input[(i+k)%n];

 //Display Rotated Array
 for(i=0;i<n;i++)
  input[i] = b[i];

}


/*---------------------- HARD approach-----------------------*/

// // SWAP WAY
void swapElements(int *input, int i, int j) { 
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp; 
} 
void reverse(int *input, int start, int end) { 
    int i = start, j = end; 
    while (i < j) { 
        swapElements(input, i, j); 
        i++; 
        j--; 
    } 
} 
void rotate(int *input, int d, int n) { 
    if (d >= n && n != 0) { 
        d = d % n;
    } else if (n == 0) {
        return; 
    } 
    reverse(input, 0, n - 1); 
    reverse(input, 0, n - d - 1); 
    reverse(input, n - d, n - 1); 
}
```

### Check Array Rotation
![image](https://user-images.githubusercontent.com/57065763/185483575-835a7a21-a096-4f73-bd64-636eefb86a91.png)

```
Check Array Rotation
Send Feedback
You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the right hand direction.
Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the value of 'K' or the index from which which the array/list has been rotated.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
6
5 6 1 2 3 4
Sample Output 1:
2
Sample Input 2:
2
5
3 6 8 9 10
4
10 20 30 1
Sample Output 2:
0
3
```

```cpp
/*
#include <iostream>
using namespace std;

#include "solution.h"

int main()
{

	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}
*/

/*-------------------------------CODE------------------------*/
/*---------------------- EASY approach-----------------------*/
int arrayRotateCheck(int *input, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		if (input[i] > input[i + 1])
		{
			return i + 1;
		}
	}
	return 0;
}

/*---------------------- Binary search approach-----------------------*/
int arrayRotateCheck(int *arr, int n)
{
    //simply: ager ta boro and porer ta choto holei ai index ta hobe answer.
        int low = 0, high = n - 1;
       while (low <= high) {
 
        // if first element is mid or
        // last element is mid
        // then simply use modulo so it
        // never goes out of bound.
        int mid = low + (high - low) / 2;
        int prev = (mid - 1 + n) % n; // OR  int prev = (mid - 1); 
        int next = (mid + 1 + n) % n; // Or int next = (mid + 1); 
 
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) // for 4 5 6 1 2 3 bcz 1 is mid and  
            return mid;								  		// biger than prev and smaller than next; 
        else if (arr[mid] <= arr[high]) // 5 6 1 2 3 4. 2 is mid here
            high = mid - 1;
        else if (arr[mid] >= arr[low])
            low = mid + 1;
    }
    return 0;
}
```

```

Lecture 5 : Time and Space Complexity Analysis END HERE

```