```

Lecture 4: Recursion 2 START HERE

```

# ##Lecture 4: Recursion 2

---

//============>>>>>>>>>> Lecture 4: Recursion 2 Notes
[Lecture 4: Recursion 2 Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp/files/9354657/Lecture.4.Recursion.2.Notes.pdf)

---
### Recursion and Strings

```cpp
#include <iostream>
using namespace std;

void removeX(char s[]) {
	if (s[0] == '\0') {
		return;
	}

	if (s[0] != 'x') {
		removeX(s + 1);
	} else {
		int i = 1;
		for (; s[i] != '\0'; i++) {
			s[i - 1] = s[i];
		}
		s[i - 1] = s[i];
		removeX(s);
	}
}

int length(char s[]) {
	if (s[0] == '\0') {
		return 0;
	}
	int smallStringLength = length(s + 1);
	return 1 + smallStringLength;
}

int main() {
	char str[100];
	cin >> str;

	int l = length(str);
	cout << l << endl;
	removeX(str);
	cout << str << endl;
	l = length(str);
	cout << l << endl;
}
```

### Replace Character Recursively

```
Replace Character Recursively
Send Feedback
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :
Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)
Output Format :
Updated string
Constraints :
1 <= Length of String S <= 10^6
Sample Input :
abacd
a x
Sample Output :
xbxcd
```

```cpp
/*
#include <iostream>
using namespace std;
#include "Solution.h"

int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}

*/

/*-------------------------------CODE------------------------*/
void replaceCharacter(char input[], char c1, char c2) {
    if(input[0]=='\0'){
        return;
    }
    if(input[0]==c1){
       input[0]=c2;
    }
    
    replaceCharacter(input+1, c1, c2);
}
```


### Remove Duplicates Recursively

```
Remove Duplicates Recursively
Send Feedback
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
```

```cpp
/*
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n) Space Complexity : O(n) where n is size of input array */
void remove(char *input, int newIndex, int index)
{
	if (input[index] == '\0')
	{
		input[newIndex] = input[index - 1];
		input[newIndex + 1] = '\0';
		return;
	}
	if (input[index] == input[index - 1])
	{
		remove(input, newIndex, index + 1);
		return;
	}
	else
	{
		input[newIndex] = input[index - 1];
	}
	remove(input, newIndex + 1, index + 1);
}
void removeConsecutiveDuplicates(char *input)
{
	remove(input, 0, 1);
}
```

### Merge Sort Algo AND Merge Sort Code

![image](https://user-images.githubusercontent.com/57065763/185201763-1207331c-1669-4df0-9070-1801d4873f27.png)
![image](https://user-images.githubusercontent.com/57065763/185201806-60ae5c06-d96f-46d2-ac54-c78ca1add7a8.png)

```
Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
*/

/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n* log(n)) Space Complexity : O(n) where n is size of input array 
*/

void mergeSortMain(int input[],int start, int mid, int end){

    int len = (end-start)+1;
    int *out = new int[len];
    
    int i=start;
    int j=mid+1;
    int k=0;
    input[mid]
    
    while(i<=mid && j<=end){
        if(input[i]<input[j]){
            out[k++] = input[i++];
        }else{
            out[k++] = input[j++];
        }
    }
    
    while(i<=mid){
            out[k++] = input[i++];
    }
    while(j<=end){
            out[k++] = input[j++];
    }
    
    for(int m=0, i=start; i<=end; m++,i++){
        input[i] = out[m];
    }
    
    delete []out;
}



void mergeSortHelper(int input[],int start,  int end){
    
    if(start>=end){
        return;
    }
    int mid = start + (end-start)/2;
    
    mergeSortHelper(input,start,mid);
    mergeSortHelper(input,mid+1,end);
    mergeSortMain(input,start,mid,end);
}

void mergeSort(int input[], int size){
    if(size==0|| size==1){return;}
    mergeSortHelper(input, 0, size-1);
}
```

### Quick Sort Algo AND Quick Sort - Dry Run AND Quick Sort Code
![image](https://user-images.githubusercontent.com/57065763/185202019-86625de3-4387-4d2b-aa3e-4b826df32245.png)
![image](https://user-images.githubusercontent.com/57065763/185214381-d92f495a-97d8-454c-ac80-31b4e5a86838.png)

```
Quick Sort Code
Send Feedback
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
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
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n* log(n)) Space Complexity : O(n) where n is size of input array */
#include <iostream>
using namespace std;
int partitionArray(int input[], int start, int end)
{
	// Chose pivot 
	int pivot = input[start];
	// Count elements smaller than pivot and swap 
	int count = 0;
	for (int i = start + 1; i <= end; i++)
	{
		if (input[i] <= pivot)
		{
			count++;
		}
	}
	int pivotIndex = start + count;
	int temp = input[start];
	input[start] = input[pivotIndex];
	input[pivotIndex] = temp;
	// ensure left half contains elements smaller than pivot 
	// and right half larger 
	int i = start, j = end;
	while (i <= pivotIndex && j >= pivotIndex)
	{
		while (input[i] <= pivot)
		{
			i++;
		}
		while (input[j] > pivot)
		{
			j--;
		}
		if (i < pivotIndex && j > pivotIndex)
		{
			int temp = input[i];
			input[i] = input[j];
			input[j] = temp;
			i++;
			j--;
		}
	}
	return pivotIndex;
}
void quickSort(int input[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivotIndex = partitionArray(input, start, end);
	quickSort(input, start, pivotIndex - 1);
	quickSort(input, pivotIndex + 1, end);
}
void quickSort(int input[], int n)
{
	quickSort(input, 0, n - 1);
}
```

### Strings

```cpp
#include <iostream>
using namespace std;

int main() {

	string* sp = new string;
	*sp = "def";
	cout << sp << endl;
	cout << *sp << endl;

	string s = "abc";
	//getline(cin, s);
	cout << s << endl;
	
	s = "defdef";
	cout << s[0] << endl;
	s[0] = 'a';
	string s1;
	s1 = "def";

	string s2 = s + s1;
	cout << s2 << endl;

	s += s1;

	cout << s1 << endl;
	cout << s << endl;

	cout << s.size() << endl;
	cout << s.substr(3) << endl;	
	cout << s.substr(3, 3) << endl;	

	cout << s.find("def") << endl;
}
```

### Return Subsequences of a String

```cpp
#include <iostream>
using namespace std;

int subs(string input, string output[]) {
	if (input.empty()) {
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1);
	int smallOutputSize = subs(smallString, output);
	for (int i = 0; i < smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}
	return 2 * smallOutputSize;
}

int main() {
	string input;
	cin >> input;
	string* output = new string[1000];
	int count = subs(input, output);
	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
}
```

### Return Keypad Approach  AND  Return Keypad Code

```
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
```

```cpp
/*
#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
*/

/*-------------------------------CODE------------------------*/
#include <string>
using namespace std;

int keypad(int num, string output[]){

    if(num==0){
        output[0]= "" ;
        return 1;
    }
    string mapping[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    int smallsize = keypad(num/10, output);
    string digitstr= mapping[num%10];
    string temp[10000];
    int k=0;
    
    for(int i=0; i<smallsize; i++){
        for(int j=0; j<digitstr.size(); j++){
            temp[k] = output[i] + digitstr[j];
            k++;
        }
    }
    
    for(int i=0; i<10000; i++){
        output[i] = temp[i];
    }
    
    return (digitstr.size()) * smallsize ; 
}
```

### Print Subsequences of a String

```cpp
#include <iostream>
using namespace std;

void print_subs(string input, string output) {
	if (input.length() == 0) {
		cout << output << endl;
		return;
	}

	print_subs(input.substr(1), output);
	print_subs(input.substr(1), output + input[0]);
}

int main() {
	string input;
	cin >> input;
	string output = "";
	print_subs(input, output);
}

```

### Print Keypad Combinations Approach AND Print Keypad Combinations Code

![image](https://user-images.githubusercontent.com/57065763/185250875-dd0c3975-a926-46ea-8912-75699975b33a.png)

```
Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
```

```cpp
/*
#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

*/

/*-------------------------------CODE------------------------*/

//----------------------------------My way-------------------------------

#include <iostream>
#include <string>
using namespace std;

// WELL DONE
void keypad(int num, string output){
    if(num==0){
        cout<< output <<endl;
        return;
    }
    string mapping[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    string value = mapping[num%10];
    
    for(int i=0; i<value.length(); i++){
        keypad(num/10, value[i]+output );
    }
    
}

void printKeypad(int num){
    keypad(num, "");
    
}

//--------------------------------Another Way-------------------------
#include <iostream>
#include <string>
using namespace std;
void printKeypadHelper(int num, string output, string options[10])
{
	if (num == 0)
	{
		cout << output << endl;
		return;
	}
	int digit = num % 10;
	int i = 0;
	while (i < options[digit].length())
	{
		printKeypadHelper(num / 10, options[digit][i] + output, options);
		i++;
	}
	return;
}
void printKeypad(int num)
{
	string options[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	printKeypadHelper(num, "", options);
	return;
}
```

### Check AB

```
Check AB
Send Feedback
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Input format :
String S
Output format :
'true' or 'false'
Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
abb
Sample Output 1 :
true
Sample Input 2 :
abababa
Sample Output 2 :
false
Explanation for Sample Input 2
In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
*/

/*-------------------------------CODE------------------------*/
/*Time Complexity : O(n) Space Complexity : O(n) where n is size of input array */
bool check_ab(char input[], int startIndex)
{
	if (input[startIndex] == '\0')
	{
		return true;
	}
	if (input[startIndex] != 'a')
	{
		return false;
	}
	if (input[startIndex + 1] != '\0' && input[startIndex + 2] != '\0')
	{
		if (input[startIndex + 1] == 'b' && input[startIndex + 2] == 'b')
		{
			return check_ab(input, startIndex + 3);
		}
	}
	return check_ab(input, startIndex + 1);
}
bool checkAB(char input[])
{
	bool ans;
	ans = check_ab(input, 0);
	return ans;
}
```

### Staircase

```
Staircase
Send Feedback
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
Input format :
Integer N
Output Format :
Integer W
Constraints :
1 <= N <= 30
Sample Input 1 :
4
Sample Output 1 :
7
Sample Input 2 :
5
Sample Output 2 :
13
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
*/

/*-------------------------------CODE------------------------*/
/*Time Complexity : O(3^n) Space Complexity : O(n) where n is size of input array */
int staircase(int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}
	return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}
```

### Binary Search (Recursive)

```
Binary Search (Recursive)
Send Feedback
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
*/

/*-------------------------------CODE------------------------*/
int binarySearchHelper(int input[], int start, int end, int element)
{
	if (start > end)
	{
		return -1;
	}
	int mid = (start + end) / 2;
	if (input[mid] == element)
	{
		return mid;
	}
	else if (input[mid] > element)
	{
		return binarySearchHelper(input, start, mid - 1, element);
	}
	else
	{
		return binarySearchHelper(input, mid + 1, end, element);
	}
}
int binarySearch(int input[], int size, int element)
{
	return binarySearchHelper(input, 0, size - 1, element);
}
```

### Return subset of an array

```
Return subset of an array
Send Feedback
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
*/

/*-------------------------------CODE------------------------*/
/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

don't print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20])
{
	if (n == 0)
	{
		output[0][0] = 0;
		return 1;
	}
	int smalloutput = subset(input + 1, n - 1, output);
	for (int i = 0; i < smalloutput; i++)
	{
		int nocol = output[i][0];
		output[i + smalloutput][0] = 1 + nocol;
		output[i + smalloutput][1] = input[0];
		for (int j = 1; j <= nocol; j++)
		{
			output[i + smalloutput][j + 1] = output[i][j];
		}
	}
	return (2 *smalloutput);
}
```

### Print Subsets of Array

```
Print Subsets of Array
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
```

```cpp
/*
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
*/

/*-------------------------------CODE------------------------*/
///-------------------------------HARD WAY---------------------------------------
void printSubsetsOfArrayHelper(int input[], int size, int output[], int outputSize){
    
    if(size==0){
        for(int i=0; i<outputSize; i++){
            cout<< output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printSubsetsOfArrayHelper(input+1, size-1, output, outputSize);
    
    //including
    int newOutput[outputSize];
    for(int i=0; i<outputSize; i++){
        newOutput[i]= output[i];  // store data in the newOutput because we don't want to lose previous data
    }
    
    newOutput[outputSize]= input[0];
    printSubsetsOfArrayHelper(input+1, size-1, newOutput, outputSize+1);
    
    
}

void printSubsetsOfArray(int input[], int size) {
    
    int output[size];
    printSubsetsOfArrayHelper(input,size,output,0); 
    
}


/*

-------------------------------EASY WAY---------------------------------------
void printSubsetsOfArrayHelper(int input[], int size, int output[], int outputSize){
    
    if(size==0){
        for(int i=0; i<outputSize; i++){
            cout<< output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    //excluding
    printSubsetsOfArrayHelper(input+1, size-1, output, outputSize);
    
    
    //including
    output[outputSize]= input[0];
    printSubsetsOfArrayHelper(input+1, size-1, output, outputSize+1);
    
    
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    
    int output[size+12];
    printSubsetsOfArrayHelper(input,size,output,0); 
    
}

*/
```

### Return subsets sum to K

```
Return subsets sum to K
Send Feedback
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
*/

/*-------------------------------CODE------------------------*/
/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

don't print the subsets, just save them in output.
***/

 /*
int subsetSumToK(int input[], int n, int startIndex, int output[][50], int k) { 
    if(startIndex == n) {
        if(k == 0) { 
           output[0][0] = 0;
          return 1; 
        } 
       return 0;
    }
    int smallOutput1[1000][50], smallOutput2[1000][50];
    int size1 = subsetSumToK(input, n, startIndex+1, smallOutput1, k); 
    int size2 = subsetSumToK(input, n, startIndex+1, smallOutput2, k - input[startIndex]);
    
    int row = 0; 
    
    for(int i = 0; i < size1; i++) { 
      for(int j = 0; j <= smallOutput1[i][0]; j++) { 
        output[row][j] = smallOutput1[i][j]; // smalloutput value kitna he??????????????
      }
      row++; 
    }

    for(int i = 0; i < size2; i++) {
      output[row][0] = smallOutput2[i][0] + 1; 
      output[row][1] = input[startIndex];
      for(int j = 1; j <= smallOutput2[i][0]; j++) { 
        output[row][j+1] = smallOutput2[i][j]; 
      }
      row++; 
    }
    
  return row; 
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
  return subsetSumToK(input, n, 0, output, k);
}
*/


#include<bits/stdc++.h>
int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(n==0){
        if(k==0){
        output[0][0]=0;
        return 1;
        }else{
            return 0;
        }
    }
    int size1=subsetSumToK(input+1,n-1,output,k);
    int size2=subsetSumToK(input+1,n-1,output+size1,k-input[0]);
    for(int i=size1;i<(size1+size2);i++){
        for(int j=output[i][0]+1;j>1;j--){
            output[i][j]=output[i][j-1];
        }
        output[i][0]+=1;
        output[i][1]=input[0];
    }
    return size1+size2;
}

/*
---------------------------ANOTHER WAY---------------------------

int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(k < 0) return 0;
    if(n == 0) {
        if(k == 0) {
            output[0][0] = 0;
            return 1;
        }
        else 
            return 0;
    }
    
	int a = subsetSumToK(input+1,n-1,output,k);
    int tempOut[1000][50];
    int b = subsetSumToK(input+1,n-1,tempOut, k - input[0]);
   
    for(int i=0; i<b; i++) {        
		output[a+i][0] = tempOut[i][0]+1;
        output[a+i][1] = input[0];
        for(int j=1; j<=tempOut[i][0]; j++)
            output[a+i][j+1] = tempOut[i][j];
    }
    return a+b;
}*/

```

### Print Subset Sum to K

```
Print Subset Sum to K
Send Feedback
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
```

```cpp
/*
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
*/

/*-------------------------------CODE------------------------*/
void printSubsetSumToKHelper(int input[],int size,int k,int output[],int outputSize)
{
    if(size==0)
    {
        if(k==0)
        {
            for(int i=0;i<outputSize;i++)
            {
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    //excluding
    printSubsetSumToKHelper(input+1,size-1,k,output,outputSize);
    
    //including
    int newOutput[outputSize];
    int i;
    for(i=0;i<outputSize;i++)
    {
        newOutput[i]=output[i];
    }
    newOutput[outputSize]=input[0];
    printSubsetSumToKHelper(input+1,size-1,k-input[0],newOutput,outputSize+1);
}

void printSubsetSumToK(int input[], int size, int k) {
    int output[size];
    printSubsetSumToKHelper(input,size,k,output,0);
}
```

### Return all codes - String

```
Return all codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
*/

/*-------------------------------CODE------------------------*/

/*--------------------- 1st Approach----------------------*/
#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {

    if(input[0] == '\0'){ 
        output[0] = ""; 
        return 1;  
    }
    
    int first = input[0] - 48; // string to int a convert. >> '2'-48 = 2 ;
    char firstChar = first + 'a' - 1; // 2 + 'a' - 1 = b;
    char secondChar = '\0';
    string smallOutput1[500];
    string smallOutput2[500]; 
    int size1 = getCodes(input.substr(1), output+firstChar);
    int size2 = 0;
    if(input[1] != '\0'){ 
        int second = first * 10 + input[1] - 48;
        if(second >= 10 && second <= 26){ 
            secondChar = second + 'a' - 1; 
            size2 = getCodes(input.substr(2), output+secondChar);  
            
        }
    }
    return size1+size2;
}

/*--------------------- 2nd Approach----------------------*/
#include <string.h>
using namespace std;

int getCodes(string input, string output[])
{
	if (input[0] == '\0')
	{
		output[0] = "";
		return 1;
	}
	int first = input[0] - 48;
	char firstChar = first + 'a' - 1;
	char secondChar = '\0';
	string smallOutput1[500];
	string smallOutput2[500];
	int size1 = getCodes(input.substr(1), smallOutput1);
	int size2 = 0;
	if (input[1] != '\0')
	{
		int second = first *10 + input[1] - 48;
		if (second >= 10 && second <= 26)
		{
			secondChar = second + 'a' - 1;
			size2 = getCodes(input.substr(2), smallOutput2);
		}
	}
	int k = 0;
	for (int i = 0; i < size1; i++)
	{
		output[k] = firstChar + smallOutput1[i];
		k++;
	}
	for (int i = 0; i < size2; i++)
	{
		output[k] = secondChar + smallOutput2[i];
		k++;
	}
	return k;
}
```

### Print all Codes - String

```
Print all Codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
*/

/*-------------------------------CODE------------------------*/
#include <string.h>
using namespace std;
void printAllPossibleCodesHelper(string input, string output)
{
	if (input[0] == '\0')
	{
		cout << output << endl;
		return;
	}
	int num = input[0] - 48;
	char ch = num - 1 + 'a';
	printAllPossibleCodesHelper(input.substr(1), output + ch);
	if (input[1] != '\0')
	{
		num = num *10 + input[1] - 48;
		ch = num - 1 + 'a';
		if (num >= 10 && num <= 26)
		{
			printAllPossibleCodesHelper(input.substr(2), output + ch);
		}
	}
}
void printAllPossibleCodes(string input)
{
	printAllPossibleCodesHelper(input, "");
}
```

### Return Permutations - String

```
Return Permutations - String
Send Feedback
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
```

```cpp
/*
#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
*/

/*-------------------------------CODE------------------------*/

#include <string>
using namespace std;
int returnPermutations(string input, string output[])
{
	if (input.length() == 0)
	{
		output[0] = "";
		return 1;
	}
	string smallOutput[10000];
	int smallSize = returnPermutations(input.substr(1), smallOutput);
	int k = 0;
	for (int i = 0; i < smallSize; i++)
	{
		for (int j = 0; j <= smallOutput[i].length(); j++)
		{
			output[k++] = smallOutput[i].substr(0, j) + input[0] + smallOutput[i].substr(j);
		}
	}
	return k;
}
```

### Print Permutations

```
Print Permutations
Send Feedback
Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line
Constraint:
1<=length of STR<=8
Time Limit: 1sec
Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba
```

```cpp
/*
#include <iostream>
#include <string>
using namespace std;
#include "solution.h"

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
*/

/*-------------------------------CODE------------------------*/
/*
Time complexity: O(N!) Space complexity: O(N) where N is the size of the input string 
*/

void printPermutationsHelper(string input, string output)
{
	if (input.length() == 0)
	{
		cout << output << endl;
		return;
	}
	for (int i = 0; i <= output.length(); i++)
	{
		printPermutationsHelper(input.substr(1), output.substr(0, i) + input[0] + output.substr(i));
	}
}
void printPermutations(string input)
{
	printPermutationsHelper(input, "");
	return;
}
```

```

Lecture 4: Recursion 2 END HERE

```
