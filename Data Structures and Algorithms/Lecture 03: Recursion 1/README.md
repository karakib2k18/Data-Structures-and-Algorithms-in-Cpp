```

Lecture 3: Recursion 1 START HERE

```

# ##Lecture 3: Recursion 1

---

//============>>>>>>>>>> Lecture 3: Recursion 1 Notes
[Lecture 3: Recursion 1 Notes First .pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp/files/9353479/Lecture.3.Recursion.1.Notes.First.pdf)
[Lecture 3: Recursion 1 Notes Second .pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp/files/9353480/Lecture.3.Recursion.1.Notes.Second.pdf)


---

### Introduction to Recursion

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
	cout << n << endl;
	if (n == 0) {
		return 1;
	}
	int smallOutput = factorial(n - 1);
	return n * smallOutput;
}

int main() {
	int n;
	cin >> n;
	int output = factorial(n);
	cout << output << endl;
}

```

### Recursion and PMI

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	int smallOutput = factorial(n - 1);
	int output = n * smallOutput;
	return output;
}

int main() {
	cout << factorial(4) << endl;
}

```

### Power
```
Power

Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.
Input format :
Two integers x and n (separated by space)
Output Format :
x^n (i.e. x raise to the power n)
Constraints :
0 <= x <= 30
0 <= n <= 30
Sample Input 1 :
 3 4
Sample Output 1 :
81
Sample Input 2 :
 2 5
Sample Output 2 :
32
```

```cpp
/*
#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int x, n;
    cin >> x >> n;
  
    cout << power(x, n) << endl;
}
*/
/* 
Time Complexity : O(n) 
Space Complexity : O(n)
where n is the exponent 
*/

int power(int x, int n) { 
    if(n == 0) { 
        return 1; 
    } 
    return x * power(x, n - 1); 
}

```

### Print Numbers
```
Print Numbers

Given the number 'n', write a code to print numbers from 1 to n in increasing order recursively.
Input Format :
Integer n
Output Format :
Numbers from 1 to n (separated by space)
Constraints :
1 <= n <= 10000
Sample Input 1 :
 6
Sample Output 1 :
1 2 3 4 5 6
Sample Input 2 :
 4
Sample Output 2 :
1 2 3 4
```

```cpp
/*
#include<iostream>
using namespace std;
#include "Solution.h"

int main(){
    int n;
    cin >> n;
  
    print(n);
}

*/
/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n) Space Complexity : O(n)
*/
void print(int n)
{
	if (n == 1)
	{
		cout << n << " ";
		return;
	}
	print(n - 1);
	cout << n << " ";
}
```

### Number of Digits
```
Number of Digits

Given the number 'n', find out and return the number of digits present in a number recursively.
Input Format :
Integer n
Output Format :
Count of digits
Constraints :
1 <= n <= 10^6
Sample Input 1 :
 156
Sample Output 1 :
3
Sample Input 2 :
 7
Sample Output 2 :
1
```

```cpp
/*
#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}
*/
/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(log(n)) Space Complexity : O(log(n)) where n is the number */
int count(int n)
{
	if (n < 10)
	{
		return 1;
	}
	return 1 + count(n / 10);
}
```

### Fibonacci Number
![image](https://user-images.githubusercontent.com/57065763/184953982-3b107078-21cc-4c8a-b4e5-bdbe074b62e7.png)

```cpp
#include <iostream>
using namespace std;

int fib(int n) {
	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}

	int smallOutput1 = fib(n - 1);
	int smallOutput2 = fib(n - 2);
	return smallOutput1 + smallOutput2;
}

int main() {
	cout << fib(3) << endl;
}

```

### QUIZ-1

```cpp
//What will be the output of the following code ?
#include <iostream>
using namespace std;

int func(int num){
    return func(num- 1);
}

int main() {
    int num = 5;
    int ans = func(num - 1);
    cout << ans;
}
```
```
Answer:  Runtime Error . bcz Since the base case is missing in the code, therefore there will be infinite recursion calls and hence runtime error will occur.
```

### What is the output

```cpp
//What will be the output ?
#include <iostream>
using namespace std;

void print(int n){
    if(n < 0){
        return;
    }
    cout << n << " ";
    print(n - 2);
}

int main() {
    int num = 5;
    print(num);
}
// Answer: 5 3 1
```

### What is the output

```cpp
What will be the output of the following code ?
#include <iostream>
using namespace std;

void print(int n){
    if(n < 0){
        return;
    }
    if(n == 0){
        cout << n << “ “;
        return;
    }
    print(n --);
    cout << n << “ “;
}

int main() {
    int num = 3;
    print(num);
}
// Answer:  Runtime Error . Solution Description :: In function print when recursion call is being made  n-- is being passed as //input. Here we are using post decrement operator, so argument passed to next function call is n and not n - 1. Thus there will //be infinite recursion calls and runtime error will come.
```

### Recursion and Arrays

```cpp
#include <iostream>
using namespace std;

bool is_sorted2(int a[], int size) {
	if (size == 0 || size ==1) {
		return true;
	}

	bool isSmallerOutput = is_sorted2(a + 1, size -1);
	if (!isSmallerOutput) {
		return false;
	}
	if (a[0] > a[1]) {
		return false;
	} else {
		return true;
	}

}

bool is_sorted(int a[], int size) {
	if (size == 0 || size ==1) {
		return true;
	}

	if (a[0] > a[1]) {
		return false;
	}
	bool isSmallerSorted = is_sorted(a + 1, size - 1);
	return isSmallerSorted;
	/*if (isSmallerSorted) {
		return true;
	} else {
		return false;
	}*/
}

int main() {
	
}
```

### Sum of Array
```
Sum of Array

Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Sum
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 9
Sample Output 1 :
26
Sample Input 2 :
3
4 2 1
Sample Output 2 :
7    
```

```cpp
/*
#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << sum(input, n) << endl;
}
*/

/*-------------------------------CODE------------------------*/

/*
Time Complexity : O(n) Space Complexity : O(n) where n is size of input array */
int sum(int input[], int n)
{
	if (n == 0)
	{
		return 0;
	}
	return input[0] + sum(input + 1, n - 1);
}
```

### Check Number
```
Check Number

Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
'true' or 'false'
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 10
8
Sample Output 1 :
true
Sample Input 2 :
3
9 8 10
2
Sample Output 2 :
false
```

```cpp
/*
#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
*/

/*-------------------------------CODE------------------------*/

/*
Time Complexity : O(n) Space Complexity : O(n) where n is size of input array */

bool checkNumber(int input[], int size, int x)
{
	if (size == 0)
	{
		return false;
	}
	else if (input[0] == x)
	{
		return true;
	}
	return checkNumber(input + 1, size - 1, x);
}
```

### First Index of Number AND Hint : First index

![image](https://user-images.githubusercontent.com/57065763/184963981-b15bbf41-88a0-4fe3-8bb4-38f51367862d.png)

```
First Index of Number

Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
first index or -1
Constraints :
1 <= N <= 10^3
Sample Input :
4
9 8 10 8
8
Sample Output :
1
```

```cpp
/*
#include<iostream>
#include "Solution.h"
using namespace std;

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    cin >> x;
    cout << firstIndex(input, n, x) << endl;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n) Space Complexity : O(n) where n is size of input array */

int firstIndex(int input[], int size, int x)
{
	if (size == 0)
	{
		return -1;
	}
	if (input[0] == x)
	{
		return 0;
	}
	int ans = firstIndex(input + 1, size - 1, x);
	if (ans != -1)
	{
		return ans + 1;
	}
	else
	{
		return ans;
	}
}
```

### Last Index of Number and Hint : Last Index

![image](https://user-images.githubusercontent.com/57065763/184965001-eff500a8-db4b-46e4-a32c-37e0329dbada.png)

```
Last Index of Number

Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
last index or -1
Constraints :
1 <= N <= 10^3
Sample Input :
4
9 8 10 8
8
Sample Output :
3
```

```cpp
/*
#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}
*/
/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n) Space Complexity : O(n) where n is size of input array */

int lastIndex(int input[], int size, int x)
{
	if (size == 0)
	{
		return -1;
	}
	int smallAns = lastIndex(input + 1, size - 1, x);
	if (smallAns != -1)
	{
		return smallAns + 1;
	}
	if (input[0] == x)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
```

### Hint 1 : All Indices of a number
![image](https://user-images.githubusercontent.com/57065763/184967965-3a16fe61-0654-4432-89a1-7eeb08146904.png)

### Hint 2 : All Indices of a number
![image](https://user-images.githubusercontent.com/57065763/184968634-18cc8f8b-055f-4406-8193-354932d6fb77.png)

### All Indices of Number
```
All Indices of Number

Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
```

```cpp
/*
#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    delete [] output;
}
*/
/*-------------------------------CODE------------------------*/
/*
//using index
#include <bits/stdc++.h>
using namespace std;
void findIndexes(int input[], int currIndex, int size, int x, int output[], int &k)
{
	if (currIndex == size) return;
	if (input[currIndex] == x)
	{
		output[k] = currIndex;
		k++;
	}
	findIndexes(input, currIndex + 1, size, x, output, k);
}
int allIndexes(int input[], int size, int x, int output[])
{
	int k = 0;
	findIndexes(input, 0, size, x, output, k);
	return k;
}
*/
int allIndexes(int input[], int size, int x, int output[]) {
    if(size==0){
        return 0;
    }
    
    int smallans=allIndexes(input,size-1,x,output);
    
    if(input[size-1]==x){
        output[smallans]=size-1;
        smallans++;
        return smallans;
    }else{
        return smallans;
    }
    
} 
    
/*
  index==> 0 1 2  3 4    

           9 8 10 8 8   size=5;    output[2]=4;   smallans=3;
           9 8 10 8     size=4;    output[1]=3;   smallans=2;
           9 8 10       size=3;                   smallans=1;    
           9 8          size=2;    output[0]=1;   smallans=1;
           9            size=1;                   smallans=0;

*/

```

### Multiplication (Recursive)
```
Multiplication (Recursive)

Given two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.
Input format :
Line 1 : Integer M
Line 2 : Integer N
Output format :
M x N
Constraints :
0 <= M <= 1000
0 <= N <= 1000
Sample Input 1 :
3 
5
Sample Output 1 :
15
Sample Input 2 :
4 
0
Sample Output 2 :
0
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n) 
Space Complexity : O(n)
where n is the smaller of the two numbers we need to multiply
*/ 
    
int multiplyNumbers(int m, int n) { 
    if(n > m) { 
        return multiplyNumbers(n, m); 
    } 
    
    if (m == 0 || n == 0) { 
        return 0; 
    } 
    return m + multiplyNumbers(m, n - 1);
}
```

### Count Zeros
```
Count Zeros

Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
Input Format :
Integer N
Output Format :
Number of zeros in N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
0
Sample Output 1 :
1
Sample Input 2 :
00010204
Sample Output 2 :
2
Explanation for Sample Output 2 :
Even though "00010204" has 5 zeros, the output would still be 2 because when you convert it to an integer, it becomes 10204.
Sample Input 3 :
708000
Sample Output 3 :
4
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
*/
/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(log(n)) 
Space Complexity : O(log(n))
*/
int countZeros(int n) { 
    if (n <= 9) { 
        if (n == 0) { 
            return 1;
        } else { 
            return 0; 
        } 
    } 
    
    int count = 0; 
    if (n % 10 == 0) { 
        count = 1; 
    } 
    return count + countZeros(n / 10); 
}
```

### Geometric Sum
```
Geometric Sum

Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion.
Input format :
Integer k
Output format :
Geometric sum (upto 5 decimal places)
Constraints :
0 <= k <= 1000
Sample Input 1 :
3
Sample Output 1 :
1.87500
Sample Input 2 :
4
Sample Output 2 :
1.93750
Explanation for Sample Input 1:
1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500
```

```cpp
/*
#include <iostream>
#include <math.h>
#include <iomanip>
#include "solution.h"
using namespace std;

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
*/
/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(k) 
Space Complexity : O(k) 
*/ 

double geometricSum(int k) { 
    if (k == 0) { 
        return 1; 
    } 
    return (1 / pow(2, k)) + geometricSum(k - 1); 
}
```

### Check Palindrome (recursive)
```
Check Palindrome (recursive)

Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
*/
/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n) 
Space Complexity : O(n) 
where n is size of input array 
*/ 

#include <cstring>
int checkPalindrome_helper(char input[], int start, int end) { 
    if (input[0] == '\0' || input[1] == '\0') { 
        return 1; 
    } 
    if (start >= end) { 
        return 1; 
    } 
    if (input[start] == input[end]) { 
        return checkPalindrome_helper(input, start + 1, end - 1); 
    } else { 
        return 0; 
    } 
} 

int checkPalindrome(char input[]) { 
    int len = strlen(input); 
    return checkPalindrome_helper(input, 0, len - 1); 
}
```

### Sum of digits (recursive)
```
Sum of digits (recursive)

Write a recursive function that returns the sum of the digits of a given integer.
Input format :
Integer N
Output format :
Sum of digits of N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
12345
Sample Output 1 :
15
Sample Input 2 :
9
Sample Output 2 :
9
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
*/
/*-------------------------------CODE------------------------*/
int sumOfDigits(int n) {
    
    /*--------------- FIRST APPROACH ---------------*/

    /*
    Time Complexity : O(log(n)) 
    Space Complexity : O(log(n)) 
    */ 
    
    if (n <= 9) { 
        return n; 
    } 
    return n % 10 + sumOfDigits(n / 10); 
    
    /*--------------- SECOND APPROACH ---------------*/
    /*  
    if(n==0){
        return 0;
    }else if(n<10){
        return n;
    }
    
    int ans= n%10;
    return ans + sumOfDigits(n/10);
    */

    /*--------------- THIRD APPROACH ---------------*/
    /*  
    if(n<10){
        if(n==0){
            return 0;
        }else{
            return n;
        }
    }
    
    int ans= n%10;
    return ans + sumOfDigits(n/10);
    */
}
```

```

Lecture 3: Recursion 1 END HERE

```
