```

Lecture 3.5: Assignment: Recursion 1b  START HERE

```

# ##Lecture 3.5: Assignment: Recursion 1b 

---

### Replace pi (recursive)

```
Replace pi (recursive)
Send Feedback
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
*/
/*-------------------------------CODE------------------------*/
#include <cstring>

void replacePi(char input[], int start)
{
	if (input[start] == '\0' || input[start + 1] == '\0')
	{
		return;
	}
	replacePi(input, start + 1);
	if (input[start] == 'p' && input[start + 1] == 'i')
	{
		int len = strlen(input);
		input[len + 2] = '\0';
		for (int i = len - 1; i >= start + 2; i--)
		{
			input[i + 2] = input[i];
		}
		input[start] = '3';
		input[start + 1] = '.';
		input[start + 2] = '1';
		input[start + 3] = '4';
	}
}

void replacePi(char input[])
{
	replacePi(input, 0);
}
```

### Remove X

```
Remove X
Send Feedback
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
*/
/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n^2) Space Complexity : O(n^2) where n is size of input array */
int length(char input[])
{
	int len = 0;
	for (int i = 0; input[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}
void removeX(char input[], int start)
{
	if (input[start] == '\0')
	{
		return;
	}
	removeX(input, start + 1);
	if (input[start] == 'x')
	{
		int len = length(input);
		int i;
		for (i = start + 1; i < len; i++)
		{
			input[i - 1] = input[i];
		}
		input[i - 1] = '\0';
	}
}
void removeX(char input[])
{
	removeX(input, 0);
}
```

### String to Integer

```
String to Integer
Send Feedback
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 < |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
*/
/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n) Space Complexity : O(n) where n is size of input array */
int length(char input[])
{
	int len = 0;
	for (int i = 0; input[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}
int stringToNumber(char input[], int last)
{
	if (last == 0)
	{
		return input[last] - '0';
	}
	int smallAns = stringToNumber(input, last - 1);
	int a = input[last] - '0';
	return smallAns *10 + a;
}
int stringToNumber(char input[])
{
	int len = length(input);
	return stringToNumber(input, len - 1);
}
```

### Pair Star

```
Pair Star
Send Feedback
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
```

```cpp
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

*/
/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(n) Space Complexity : O(n) where n is size of input array */
int length(char input[])
{
	int len = 0;
	for (int i = 0; input[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}
void pairStar(char input[], int start)
{
	if (input[start] == '\0')
	{
		return;
	}
	pairStar(input, start + 1);
	if (input[start] == input[start + 1])
	{
		int l = length(input);
		input[l + 1] = '\0';
		int i;
		for (i = l - 1; i >= start + 1; i--)
		{
			input[i + 1] = input[i];
		}
		input[i + 1] = '*';
	}
}
void pairStar(char input[])
{
	pairStar(input, 0);
}
```

### Tower of Hanoi

```
Tower of Hanoi
Send Feedback
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move all disks from source rod to destination rod using third rod (say auxiliary). The rules are :
1) Only one disk can be moved at a time.
2) A disk can be moved only if it is on the top of a rod.
3) No disk can be placed on the top of a smaller disk.
Print the steps required to move n disks from source rod to destination rod.
Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.
Input Format :
Integer n
Output Format :
Steps in different lines (in one line print source and destination rod name separated by space)
Constraints :
0 <= n <= 20
Sample Input 1 :
2
Sample Output 1 :
a b
a c
b c
Sample Input 2 :
3
Sample Output 2 :
a c
a b
c b
a c
b a
b c
a c
```

```cpp
/*
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}
*/
/*-------------------------------CODE------------------------*/
/*
Time Complexity : O(2^n) Space Complexity : O(n) where n is size of input array */
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
	if (n == 0)
	{
		return;
	}
	towerOfHanoi(n - 1, source, destination, auxiliary);
	cout << source << " " << destination << endl;
	towerOfHanoi(n - 1, auxiliary, source, destination);
}
```


```

Lecture 3.5: Assignment: Recursion 1b  END HERE

```
