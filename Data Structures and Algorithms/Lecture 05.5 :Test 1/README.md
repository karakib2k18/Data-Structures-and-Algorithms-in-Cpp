```

Lecture 5.5 : Test 1  START HERE

```

# ##Lecture 5.5 : Test 1 

###QUIZ
![image](https://user-images.githubusercontent.com/57065763/185486550-3a34eded-18d8-4535-8a14-168ff27541bb.png)

### Does s contain t ?

```
Does s contain t ?
Send Feedback
Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
true or false
Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding
Sample Output 1 :
true
Sample Input 2 :
abcde
aeb
Sample Output 2 :
false
```

```cpp
/*
#include<iostream>
using namespace std;
#include "solution.h"

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
*/

/*-------------------------------CODE------------------------*/
bool checksequenece(char large[], char *small)
{
	if (small[0] == '\0')
	{
		return true;
	}
	if (large[0] == '\0')
	{
		return false;
	}
    
    // small er word jodi large a thake tahole small & large next elements a jabe.
	if (large[0] == small[0])
	{
		bool a = checksequenece(++large, ++small);
		return a;
	}
    
    // na soman hole only large ++ hobe. and large jodi age '\0' hoy tahole flase
	else
	{
		return checksequenece(++large, small);
	}
}
```

### Maximum Profit on App

```
Maximum Profit on App
Send Feedback
You have made a smartphone app and want to set its subscription price such that the profit earned is maximised. There are certain users who will subscribe to your app only if their budget is greater than or equal to your price.
You will be provided with a list of size N having budgets of subscribers and you need to return the maximum profit that you can earn.
Lets say you decide that price of your app is Rs. x and there are N number of subscribers. So maximum profit you can earn is :
 m * x
where m is total number of subscribers whose budget is greater than or equal to x.
Input format :
Line 1 : N (No. of subscribers)
Line 2 : Budget of subscribers (separated by space)
Output Format :
 Maximum profit
Constraints :
1 <= N <= 10^6
1 <=budget[i]<=9999
Sample Input 1 :
4
30 20 53 14
Sample Output 1 :
60
Sample Output 1 Explanation :
Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.
Sample Input 2 :
5
34 78 90 15 67
Sample Output 2 :
201
Sample Output 2 Explanation :
Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).
```

```cpp
/*
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
*/

/*-------------------------------CODE------------------------*/
#include <algorithm>

int maximumProfit(int budget[], int n)
{
	sort(budget, budget + n);
	int *cost = new int[n];
	for (int i = 0; i < n; i++) cost[i] = budget[i] *(n - i);
	int max = 0;
	for (int i = 0; i < n; i++)
		if (cost[i] > max) max = cost[i];
	return max;
}
```

### Split Array

```
Split Array
Send Feedback
Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.
Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.
Return true, if array can be split according to the above rules, else return false.
Note : You will get marks only if all the test cases are passed.
Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)
Output Format :
true or false
Constraints :
1 <= N <= 50
Sample Input 1 :
2
1 2
Sample Output 1 :
false
Sample Input 2 :
3
1 4 3
Sample Output 2 :
true
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
*/

/*-------------------------------CODE------------------------*/
bool check(int *input, int size, int startIndex, int lSum, int rSum)
{
	if (startIndex == size)
	{
		return lSum == rSum;
	}
	if (input[startIndex] % 5 == 0)
	{
		lSum += input[startIndex];
	}
	else if (input[startIndex] % 3 == 0)
	{
		rSum += input[startIndex];
	}
	else
	{
		bool leftAns = check(input, size, startIndex + 1, lSum + input[startIndex], rSum);
		bool rightAns = check(input, size, startIndex + 1, lSum, rSum + input[startIndex]);
		return leftAns || rightAns;
	}
	return check(input, size, startIndex + 1, lSum, rSum);
}
bool splitArray(int *input, int size)
{
	return check(input, size, 0, 0, 0);
}
```


```

Lecture 5.5 : Test 1 END HERE

```
