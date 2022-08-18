```

Lecture 19 : DP - 2 START HERE

```

# ##Lecture 19 : DP - 2

---

//============>>>>>>>>>> Lecture 19 : DP - 2 NOTE
[Lecture 19 : DP - 2 Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/9176816/Lecture.19.DP.-.2.Notes.pdf)

---

---------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------


### Min Cost Path
![image](https://user-images.githubusercontent.com/57065763/180771105-53203e38-7670-4755-9af3-40e319ffaf2f.png)

### Code : Min Cost Path
```
Code : Min Cost Path

An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
 Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format :
Print the minimum cost to reach the destination.
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76
Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18
```

```cpp
/*
#include <bits/stdc++.h>
using namespace std;

#include "solution.h"

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}
*/
/*Time Complexity : O(3^P) where P = (M *N) 
Space Complexity : O(max(M, N))
Where M and N are the rows and columns of the input matrix 
*/
#include <climits>

int minCostPathHelper(int **input, int m, int n, int i, int j)
{
	if (i >= m || j >= n)
	{
		return INT_MAX;
	}
	else if (i == m - 1 && j == n - 1)
	{
		return input[i][j];
	}
	int downCost = minCostPathHelper(input, m, n, i + 1, j);
	int diagonalCost = minCostPathHelper(input, m, n, i + 1, j + 1);
	int leftCost = minCostPathHelper(input, m, n, i, j + 1);
	return input[i][j] + min(diagonalCost, min(downCost, leftCost));
}
int minCostPath(int **input, int m, int n)
{
	return minCostPathHelper(input, m, n, 0, 0);
}
```

### Solution : Min Cost Path (Brute Force)

![image](https://user-images.githubusercontent.com/57065763/180780265-d6e3ec63-7757-43de-a896-141b10fdb974.png)

```cpp
#include <iostream>
using namespace std;

int minCostPath(int **input, int m, int n, int i, int j) {
	// Base case
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}

	if(i >= m || j >= n) {
		return INT_MAX;
	}

	// Recursive calls
	int x = minCostPath(input, m, n, i, j+1);
	int y = minCostPath(input, m, n, i+1, j+1);
	int z = minCostPath(input, m, n, i+1, j);

	// Small Calculation
	int ans = min(x, min(y, z)) + input[i][j];
	return ans;
}

int minCostPath(int **input, int m, int n) {
	return minCostPath(input, m, n, 0, 0);
}

int main() {
	int m, n;
	cin >> m >> n;
	int **input = new int*[m];
	for(int i = 0; i < m; i++) {
		input[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}	
	}
	cout << minCostPath(input, m, n) << endl;
}
```

### Min Cost Path - Memoization

![image](https://user-images.githubusercontent.com/57065763/180773289-e9f0b98b-3444-412c-9809-2ea54de1d3bf.png)

![image](https://user-images.githubusercontent.com/57065763/180792362-b2deee13-daf1-4318-978d-ade1a61ffe2b.png)

```cpp
//Min Cost Path - Memoization
#include <iostream>
using namespace std;
#include <climits>

/*----------------------------------minCostPath_Mem----------------------------------*/
int minCostPath_Mem(int **input, int m, int n, int i, int j, int **output) {
    if(i == m- 1 && j == n- 1) {
        return input[i][j];
    }
    
    if(i >= m || j >= n) {
        return INT_MAX;
    }
    
    // Check if ans already exists
    if(output[i][j] != -1) {
        return output[i][j];
    }
    
    // Recursive calls
    int x = minCostPath_Mem(input, m, n, i, j+1, output);
    int y = minCostPath_Mem(input, m, n, i+1, j+1, output);
    int z = minCostPath_Mem(input, m, n, i+1, j, output);
    
    // Small Calculation
    int a = min(x, min(y, z)) + input[i][j];
    
    // Save the answer for future use
    output[i][j] = a;
    
    return a;
}

int minCostPath_Mem(int **input, int m, int n, int i, int j) {
    int **output = new int*[m];
    for(int i = 0; i < m; i++) {
        output[i] = new int[n];
        for(int j = 0; j < n; j++) {
            output[i][j] = -1;
        }
    }
    return minCostPath_Mem(input, m, n, i, j, output);
}

/*------------------------------------minCostPath_Mem End----------------------*/

/*------------------------------------minCostPath_Better----------------------*/
int minCostPath_Better(int **input, int m, int n, int i, int j, int **ans) {
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}

	if(i >= m || j >= n) {
		return INT_MAX;
	}

	if(ans[i][j] != -1) {
		return ans[i][j];
	}

	int x = minCostPath_Better(input, m, n, i+1, j, ans);
	if(x < INT_MAX) {
		ans[i+1][j] = x;
	}
	int y = minCostPath_Better(input, m, n, i+1, j+1, ans);
	if(y < INT_MAX) {
		ans[i+1][j+1] = y;
	}
	int z = minCostPath_Better(input, m, n, i, j+1, ans);
	if(z < INT_MAX) {
		ans[i][j+1] = z;
	}
	ans[i][j] = min(x, min(y, z)) + input[i][j];
	return ans[i][j];
}

int minCostPath_Better(int **input, int m, int n) {
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
		for(int j = 0; j < n; j++) {
			ans[i][j] = -1;
		}
	}
	return minCostPath_Better(input, m, n, 0, 0, ans);
}
/*------------------------------------minCostPath_Better  End----------------------*/

int main() {
    int m, n;
    cin >> m >> n;
    int **input = new int*[m];
    for(int i = 0; i < m; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }	
    }
    cout << minCostPath_Mem(input, m, n, 0, 0) << endl;
    cout << minCostPath_Better(input, m, n) << endl;
}
```

### Min Cost Path - DP

![image](https://user-images.githubusercontent.com/57065763/180821031-88888881-5e42-4aa8-8f1a-673a4a5c8330.png)

```cpp
// Min Cost Path - DP
#include <iostream>
using namespace std;
#include <climits>

int minCOst_DP(int **input, int m, int n) {
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
	}

	ans[m-1][n-1] = input[m-1][n-1];

	// Last row
	for(int j = n - 2; j >= 0; j--) {
		ans[m-1][j] = input[m-1][j] + ans[m-1][j+1];
	}

	// Last col
	for(int i = m-2; i >= 0; i--) {
		ans[i][n-1] = input[i][n-1] + ans[i+1][n-1];
	}

	for(int i = m-2; i >= 0; i--) {
		for(int j = n-2; j >= 0; j--) {
			ans[i][j] = input[i][j] + min(ans[i][j+1], min(ans[i+1][j+1], ans[i+1][j]));
		}
	}
	return ans[0][0];
}


int main() {
	int m, n;
	cin >> m >> n;
	int **input = new int*[m];
	for(int i = 0; i < m; i++) {
		input[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}	
	}
	cout << minCOst_DP(input, m, n) << endl;
}
```

### LCS

```cpp
#include <iostream>
using namespace std;

int lcs_DP(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];

	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}

	// Fill 1st row
	for(int j = 0; j <= n; j++) {
		output[0][j] = 0;
	}

	// Fill 1st col
	for(int i = 1; i <= m; i++) {
		output[i][0] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			// Check if 1st char matches
			if(s[m-i] == t[n-j]) {
				output[i][j] = 1 + output[i-1][j-1];
			}
			else {
				int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = max(a, max(b, c));
			}
		}
	}

	return output[m][n];
}


int main() {
	string s, t;
	cin >> s >> t;

	cout << lcs_DP(s, t) << endl;
	cout << lcs_mem(s, t) << endl;
	cout << lcs(s, t) << endl;
}
```

### LCS - Memoization

![image](https://user-images.githubusercontent.com/57065763/180944927-bfa85073-6145-4441-8f02-f9052e4ba095.png)

```cpp
#include <iostream>
using namespace std;

int lcs_mem(string s, string t, int **output) {
	int m = s.size();
	int n = t.size();
	
	// Base case
	if(s.size() == 0 || t.size() == 0) {
		return 0;
	}

	// Check if ans already exists
	if(output[m][n] != -1) {
		return output[m][n];
	}

	int ans;
	// Recursive calls
	if(s[0] == t[0]) {
		ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
	}
	else {
		int a = lcs_mem(s.substr(1), t, output);
		int b = lcs_mem(s, t.substr(1), output);
		int c = lcs_mem(s.substr(1), t.substr(1), output);
		ans = max(a, max(b, c));
	}

	// Save your calculation
	output[m][n] = ans;

	// Return ans
	return ans;
}

int lcs_mem(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			output[i][j] = -1;
		}
	}

	return lcs_mem(s, t, output);
}

int main() {
	string s, t;
	cin >> s >> t;
	cout << lcs_mem(s, t) << endl;
}
```

### LCS - DP

![image](https://user-images.githubusercontent.com/57065763/180937595-c1cdee96-1aae-47e1-91ab-f9a07be0f521.png)

```cpp
#include <iostream>
using namespace std;

int lcs_DP(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];

	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}

	// Fill 1st row
	for(int j = 0; j <= n; j++) {
		output[0][j] = 0;
	}

	// Fill 1st col
	for(int i = 1; i <= m; i++) {
		output[i][0] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			// Check if 1st char matches
			if(s[m-i] == t[n-j]) {
				output[i][j] = 1 + output[i-1][j-1];
			}
			else {
				int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = max(a, max(b, c));
			}
		}
	}

	return output[m][n];
}


int main() {
	string s, t;
	cin >> s >> t;

	cout << lcs_DP(s, t) << endl;
	cout << lcs_mem(s, t) << endl;
	cout << lcs(s, t) << endl;
}
```

### Edit Distance  && ### Code : Edit Distance

![image](https://user-images.githubusercontent.com/57065763/180962234-16a75edd-33bc-4b67-85f8-601bae19d11c.png)

```
Code : Edit Distance

Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
Output Format :
The first and only line of output contains the edit distance value between the given strings.
Constraints :
1<= m,n <= 10
Time Limit: 1 second
Sample Input 1 :
abc
dc
Sample Output 1 :
2
```

```cpp
#include <cstring>
#include <iostream>
using namespace std;

/*Time complexity: O(3 ^ min(N, M)) 
Space complexity: O(min(N, M)) 
where N and M are the lengths of the two strings 
*/
int editDistance(string s1, string s2)
{
	// Base case
	if (s1.size() == 0 || s2.size() == 0)
	{
		return max(s1.size(), s2.size());
	}

	if (s1[0] == s2[0])
	{
		return editDistance(s1.substr(1), s2.substr(1));
	}
	else
	{
               /*
		int Insert = editDistance(s1.substr(1), s2);
		int Delete = editDistance(s1, s2.substr(1));
		int Replace = editDistance(s1.substr(1), s2.substr(1));
		return 1 +( min(Insert, min(Delete, Replace)));
		*/
        
		// Insert
		int Insert = editDistance(s1.substr(1), s2) + 1;
		// Delete
		int Delete = editDistance(s1, s2.substr(1)) + 1;
		// Replace
		int Replace = editDistance(s1.substr(1), s2.substr(1)) + 1;

        //Final return
		return min(Insert, min(Delete, Replace));
	}
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}
```
### Solution : Edit Distance (Brute Force)

```cpp
#include <iostream>
using namespace std;

int editDistance(string s, string t) {
	// Base case
	if(s.size() == 0 || t.size() == 0) {
		return max(s.size(), t.size());
	}


	if(s[0] == t[0]) {
		return editDistance(s.substr(1), t.substr(1));
	}
	else {
		// Insert
		int x = editDistance(s.substr(1), t) + 1;
		// Delete
		int y = editDistance(s, t.substr(1)) + 1;
		// Replace
		int z = editDistance(s.substr(1), t.substr(1)) + 1;

		return min(x, min(y, z));
	}
}

int main() {
	string s = "abcdf";
	string t = "afd";
	
	cout << editDistance(s, t) << endl;
}
```

### Code : Edit Distance (Memoization and DP)

```
Code : Edit Distance (Memoization and DP)

You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
 Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9
```

```cpp
#include <iostream>
#include <cstring>
using namespace std;

/*-----------------------------------Memoization------------------------------*/
int editDistance(string s1, string s2, int **output)
{
    int m = s1.size(), n = s2.size();
    if (m == 0 || n == 0)
        return max(m, n);

    if (output[m][n] != -1)
        return output[m][n];

    int ans;
    if (s1[0] == s2[0])
        ans = editDistance(s1.substr(1), s2.substr(1), output);
    else
    {
        int x = editDistance(s1.substr(1), s2, output) + 1;
        int y = editDistance(s1, s2.substr(1), output) + 1;
        int z = editDistance(s1.substr(1), s2.substr(1), output) + 1;
        ans = min(x, min(y, z));
    }

    output[m][n] = ans;

    return output[m][n];
}
int editDistance(string s1, string s2)
{
    // Write your code here
    int m = s1.size(), n = s2.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
            output[i][j] = -1;
    }
    return editDistance(s1, s2, output);
}

/*-----------------------------------DP------------------------------*/
int editDistanceHelper(string s1, string s2, int **dp)
{
	int m = s1.size(), n = s2.size();
	if (m <= 0 || n <= 0)
	{
		return max(m, n);
	}
	if (dp[m][n] != -1)
	{
		return dp[m][n];
	}
	else
	{
		if (s1[0] == s2[0])
		{
			int x = editDistanceHelper(s1.substr(1), s2.substr(1), dp);
			dp[m - 1][n - 1] = x;
			dp[m][n] = x;
		}
		else
		{
			dp[m][n - 1] = editDistanceHelper(s1, s2.substr(1), dp);
			dp[m - 1][n - 1] = editDistanceHelper(s1.substr(1), s2.substr(1), dp);
			dp[m - 1][n] = editDistanceHelper(s1.substr(1), s2, dp);
			dp[m][n] = min(dp[m][n - 1], min(dp[m - 1][n - 1], dp[m - 1][n])) + 1;
		}
	}
	return dp[m][n];
}
int editDistance(string s1, string s2)
{
	int m = s1.size() + 1, n = s2.size() + 1;
	int **dp = new int *[m];
	for (int i = 0; i < m; i++)
	{
		dp[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
	}
	return editDistanceHelper(s1, s2, dp);
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}
```

### Solution : Edit Distance (Memoization) && ## Solution : Edit Distance (DP)

![image](https://user-images.githubusercontent.com/57065763/181906626-30918e97-bd37-455e-8673-740f4cbd52e3.png)

```cpp
#include <iostream>
using namespace std;

int editDistance_DP(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}

	// Fill 1st row
	for(int j = 0; j <= n; j++) {
		output[0][j] = j;
	}

	// Fill 1st col
	for(int i = 1; i <= m; i++) {
		output[i][0] = i;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[m-i] == t[n-j]) {
				output[i][j] = output[i-1][j-1];
			}
			else {
				int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = min(a, min(b, c)) + 1;
			}
		}
	}

	return output[m][n];
}

int editDistance_mem(string s, string t, int **output) {
	int m = s.size();
	int n = t.size();
	
	if(s.size() == 0 || t.size() == 0) {
		return max(s.size(), t.size());
	}

	// Check if ans already exists
	if(output[m][n] != -1) {
		return output[m][n];
	}

	int ans;
	if(s[0] == t[0]) {
		ans = editDistance_mem(s.substr(1), t.substr(1), output);
	}
	else {
		// Insert
		int x = editDistance_mem(s.substr(1), t, output) + 1;
		// Delete
		int y = editDistance_mem(s, t.substr(1), output) + 1;
		// Replace
		int z = editDistance_mem(s.substr(1), t.substr(1), output) + 1;

		ans =  min(x, min(y, z));
	}

	// Save the ans
	output[m][n] = ans;

	// Return the ans
	return ans;
}

int editDistance_mem(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **ans = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		ans[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			ans[i][j] = -1;
		}
	}
	return editDistance_mem(s, t, ans);

}

int editDistance(string s, string t) {
	// Base case
	if(s.size() == 0 || t.size() == 0) {
		return max(s.size(), t.size());
	}

	if(s[0] == t[0]) {
		return editDistance(s.substr(1), t.substr(1));
	}
	else {
		// Insert
		int x = editDistance(s.substr(1), t) + 1;
		// Delete
		int y = editDistance(s, t.substr(1)) + 1;
		// Replace
		int z = editDistance(s.substr(1), t.substr(1)) + 1;

		return min(x, min(y, z));
	}
}

int main() {
	string s = "abcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdf";
	string t = "afdiafdafdafdafd";

	cout << editDistance_DP(s, t) << endl;
	cout << editDistance_mem(s, t) << endl;
	cout << editDistance(s, t) << endl;
}
```

### Code : Knapsack AND ### Solution : Knapsack (Brute Force)

![image](https://user-images.githubusercontent.com/57065763/181905066-c9245909-9663-4082-afc8-24092854ffca.png)

```
Code : Knapsack

A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
Input Format :
The first line of the input contains an integer value N, which denotes the total number of items.

The second line of input contains the N number of weights separated by a single space.

The third line of input contains the N number of values separated by a single space.

The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
Output Format :
Print the maximum value of V that the thief can steal.
Constraints :
1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
Sample Input 2 :
5
12 7 11 8 9
24 13 23 15 16
26
Sample Output 2 :
51
```

```cpp
#include <iostream>
using namespace std;

/*-----------------Start from First index-----------------*/

int knapsack(int *weight, int *values, int n, int maxWeight) {
	// Base case
	if(n == 0 || maxWeight == 0) {
		return 0;
	}

	if(weight[0] > maxWeight) {
		return knapsack(weight + 1, values + 1, n - 1, maxWeight);
	}

	// Recursive calls
	int includeItem = knapsack(weight + 1, values + 1, n - 1, maxWeight - weight[0]) + values[0];
	int excludeItem = knapsack(weight + 1, values + 1, n - 1, maxWeight);

	return max(includeItem, excludeItem);
}
/*------------------------------------------------*/

/*-----------------Start from Last index-----------------*/

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	if (n == 0 || maxWeight == 0)
	{
		return 0;
	}
	if (weights[n - 1] > maxWeight)
	{
		return knapsack(weights, values, n - 1, maxWeight);
	}
	int includeItem = values[n - 1] + knapsack(weights, values, n - 1, maxWeight - weights[n - 1]);
	int excludeItem = knapsack(weights, values, n - 1, maxWeight);
	return max(includeItem, excludeItem);
}
/*------------------------------------------------*/

int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}
```

### Code: Knapsack (Memoization and DP)

 https://youtu.be/bUSaenttI24

![image](https://user-images.githubusercontent.com/57065763/181905178-510d5df5-2196-4f49-98b2-ea832c80df2f.png)

```cpp
Code: Knapsack (Memoization and DP)

A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
```

```cpp
#include <cstring>
#include <iostream>
using namespace std;

// https://youtu.be/bUSaenttI24

/*-------------------------Memoization--------------------*/
int knapsack(int *weights, int *values, int n, int maxWeight, int **dp)
{
	if (maxWeight == 0 || n == 0)
	{
		return 0;
	}
	if (dp[n][maxWeight] != -1)
	{
		return dp[n][maxWeight];
	}
	int ans;
	if (maxWeight < weights[0])
	{
		ans = knapsack(weights + 1, values + 1, n - 1, maxWeight, dp);
	}
	else
	{
		int a = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0], dp) + values[0];
		int b = knapsack(weights + 1, values + 1, n - 1, maxWeight, dp);
		ans = max(a, b);
	}
	dp[n][maxWeight] = ans;
	return dp[n][maxWeight];
}
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	int **dp = new int *[n + 1];
	for (int i = 0; i <= n; i++)
	{
		dp[i] = new int[maxWeight + 1];
		for (int j = 0; j <= maxWeight; j++)
		{
			dp[i][j] = -1;
		}
	}
	return knapsack(weights, values, n, maxWeight, dp);
}
/*------------------------------------------------*/


// https://youtu.be/bUSaenttI24

/*----------------- dynamic programming-----------------------*/
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	int **dp = new int *[n + 1];
    
	for (int i = 0; i <= n; i++)
	{
		dp[i] = new int[maxWeight + 1];
	}

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
	}

	for (int i = 0; i <= maxWeight; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= maxWeight; j++)
		{
			if (j < weights[i-1])
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - weights[i-1]] + values[i-1], dp[i - 1][j]);
			}
		}
	}
	return dp[n][maxWeight];
}
/*------------------------------------------------*/

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}
```

### Loot Houses

```
Loot Houses

A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
```

```cpp
#include <iostream>
using namespace std;

/*Time complexity : O(n)
Space complexity : O(n)
where n is the total number of houses 
*/

int maxMoneyLooted(int *houses, int n)
{
	/*We are assuming that the n houses are numbered from 0 to n - 1. maxMoney[i] stores the 
    maximum amount of money that can be looted from houses numbered 0 to i (both inclusive). */
	int *maxMoney = new int[n];
	maxMoney[0] = houses[0];
	if (n > 1)
	{
		maxMoney[1] = max(houses[1], maxMoney[0]);
	}
	for (int i = 2; i < n; i++)
	{
		//maxMoney[i-2] + houses[i] : In case we are including current element	
		//maxMoney[i-1] : In case we are excluding current element
		maxMoney[i] = max(maxMoney[i - 2] + houses[i], maxMoney[i - 1]);
	}
	int result = maxMoney[n - 1];
	delete[] maxMoney;
	return result;
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}
```

### Longest Increasing Subsequence

![image](https://user-images.githubusercontent.com/57065763/181813611-77a8a7f8-d849-4a6f-ab96-54b23e18a533.png)

```
Longest Increasing Subsequence

Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.
Input Format
The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.
Output Format
The first and only line of output contains the length of longest subsequence.
Constraints
1 <= N <= 10^3
Time Limit: 1 second
Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2 :
3
1 2 2
Sample Output 2 :
2
```

```cpp
#include <iostream>
using namespace std;

// O(n^2)
int longestIncreasingSubsequence(int *arr, int n)
{
	int *output = new int[n];
	int res = 0;
    
    for(int i=0; i<n; i++){
        output[i]= 1;
    }
    
	for (int i = 1; i < n; i++){
		int ans = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] < arr[i])
			{
				output[i] = max(output[j] + 1,  output[i]);
			}
		}
	}
    
	for (int i = 0; i < n; i++){
		res = max(output[i], res);
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << longestIncreasingSubsequence(arr, n);
}
```

### All possible ways

```
All possible ways

Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
Input Format:
The first line of input contains two space separated integers, that denote the value of a and b.
Output Format:
The first and only line of output contains count of ways in which a can be represented as sum of unique integers raised to power b.
Constraints :
1 <= a <= 10^4
1 < b <= 20
Time Limit: 1 second
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
Explanation:
Following are the three ways: 
1. 100 = 10^2
2. 100 = 8^2 + 6^2
3. 100 = 7^2+5^2+4^2+3^2+1^2
```

```cpp
#include <iostream>
using namespace std;

/*
Time complexity: O(A ^ (1 / B)) 
Space complexity: O(A ^ (1 / B)) 
where A and B are the two given integers
*/
#include <cmath>

int dp(int a, int b, int base, int *output)
{
	if (a < pow(base, b))
	{
		return 0;
	}
	if (a == pow(base, b))
	{
		return 1;
	}

	output[a] = dp(a - pow(base, b), b, base + 1, output) + dp(a, b, base + 1, output);

	return output[a];
}

int getAllWays(int a, int b)
{
	int *output = new int[10000];
	for (int i = 0; i < 10000; i++)
	{
		output[i] = -1;
	}
	return dp(a, b, 1, output);
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << getAllWays(a, b);
}
```

### Ways To Make Coin Change

//	// https://youtu.be/zmXevdv5nuc
//	//https://youtu.be/l_nR5X9VmaI

![image](https://user-images.githubusercontent.com/57065763/181779036-474a6c79-4bf2-400e-966c-5b5498cb4232.png)


```
Ways To Make Coin Change

For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
```

```cpp
#include <iostream>
using namespace std;

//	// https://youtu.be/zmXevdv5nuc
//	//https://youtu.be/l_nR5X9VmaI
int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
	//Write your code here
	long long dp[value + 1];
	for (int i = 0; i <= value; i++)
	{
		dp[i] = 0;
	}

	//base case
	dp[0] = 1;

    //Calculaiton
	for (int i = 0; i < numDenominations; i++)
	{
		for (int j = 0; j <= value; j++)
		{
			if (j >= denominations[i])
				dp[j] += dp[j - denominations[i]];
		}
	}
	// delete[] dp;
	return dp[value];
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}
```

### Matrix Chain Multiplication

![image](https://user-images.githubusercontent.com/57065763/181771835-6573bca5-8c61-4e0f-8640-e138d316c536.png)

```
Matrix Chain Multiplication

Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format:
The first line of input contains an integer, that denotes the value of n. The following line contains n+1 integers, that denote the value of elements of array p[].
Output Format:
The first and only line of output prints the minimum number of multiplication needed.
Constraints :
1 <= n <= 100
Time limit: 1 second
Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000
Sample Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 
```
```cpp
#include <iostream>
using namespace std;

#include <climits>
#include <vector>

int matrixChainMultiplication(vector<vector < int>> &dp, int *p, int s, int e)
{
	if ((e - s) == 1)
	{
		return 0;
	}

	if (dp[s][e])
	{
		return dp[s][e];
	}

	int ans = INT_MAX;
	for (int k = s + 1; k < e; k++)
	{
		int temp = matrixChainMultiplication(dp, p, s, k) + matrixChainMultiplication(dp, p, k, e) + p[s] *p[k] *p[e];
		ans = min(ans, temp);
	}
	dp[s][e] = ans;
	return ans;

}
int matrixChainMultiplication(int *arr, int n)
{
	// Write your code here
	vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));
	int ans = matrixChainMultiplication(dp, arr, 0, n);
	return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}
```

### Coin Tower

https://youtu.be/pDr7wDufgVc

![image](https://user-images.githubusercontent.com/57065763/181757256-77c8419e-ddba-477b-8cfb-0ddd71c9cc06.png)

![image](https://user-images.githubusercontent.com/57065763/181759901-a1db1233-cb11-45ef-bbac-8723c0ebabb4.png)

```
Coin Tower

Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
Explanation to Sample Input 1:
Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins in all three cases, Whis can win by removing all the remaining coins. 
```

```cpp
#include <iostream>
#include <string>
using namespace std;

/*Time complexity : O(n) 
Space complextiy : O(n) 
where n is the initial number of coins 
*/

string findWinner(int n, int x, int y)
{

  // To store results
  bool *dp = new bool[n + 1];

  // Initial values
  dp[0] = false;
  dp[1] = true;

  // Computing other values.
  for (int i = 2; i <= n; i++){
    // If A losses any of i-1 or i-x
    // or i-y game then he will
    // definitely win game i
    if (i - 1 >= 0 and !dp[i - 1]){
      dp[i] = true;
    }
    else if (i - x >= 0 and !dp[i - x]){
      dp[i] = true;
    }
    else if (i - y >= 0 and !dp[i - y]){
      dp[i] = true;
    }
    // Else A loses game.
    else{
      dp[i] = false;
    }
  }

  // If dp[n] is true then A will
  // game otherwise  he losses

  if (dp[n]){
    return "Beerus";
  }
  else{
    return "Whis";
  }
  delete[] dp;
}

int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  cout << findWinner(n, x, y);
}
```

### Maximum Square Matrix With All Zeros

![image](https://user-images.githubusercontent.com/57065763/181758651-5fbf87c7-ff24-40b7-b80f-484b79ca2bc3.png)

https://youtu.be/UagRoA3C5VQ
https://youtu.be/6CjGeHizyOg

```
Maximum Square Matrix With All Zeros

Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
Output Format:
Print the size of maximum square sub-matrix.
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4
```
```cpp
#include <iostream>
using namespace std;

//https://youtu.be/UagRoA3C5VQ
//https://youtu.be/6CjGeHizyOg

/*Time Complexity: O(N *M) 
Space Complexity: O(N *M) 
where N and M are the number of rows and columns in the input matrix 
*/

/*--------------------------Abul type logic--------------------------*/
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
  int **dp = new int *[n + 1];
  for (int i = 0; i <= n; i++)
  {
    dp[i] = new int[m + 1];
    for (int j = 0; j <= m; j++)
    {
      dp[i][j] = 0;
    }
  }
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 0; j--)
    {
      dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      if (min(n - i, m - j) <= dp[i][j])
      {
        continue;
      }
      bool foundOne = false;
      for (int p = 0; p <= dp[i][j]; p++)
      {
        for (int q = 0; q <= dp[i][j]; q++)
        {
          if (arr[i + p][j + q] == 1)
          {
            foundOne = true;
            p = q = dp[i][j] + 1;
          }
        }
      }
      if (foundOne == false)
      {
        dp[i][j] += 1;
      }
    }
  }
  int ans = dp[0][0];
  for (int i = 0; i <= n; i++)
  {
    delete[] dp[i];
  }
  delete[] dp;
  return ans;
}
*/
/*-----------------------------------------------------*/

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	int **dp = new int *[n];
	for (int i = 0; i < n; i++){
		dp[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			dp[i][j] = 0;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++){
		dp[i][0] = (arr[i][0] == 1) ? 0 : 1;
		ans = max(ans, dp[i][0]);
	}
    
	for (int j = 1; j < m; j++){
		dp[0][j] = (arr[0][j] == 1) ? 0 : 1;
		ans = max(ans, dp[0][j]);
	}

	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			if (arr[i][j] == 1){
				dp[i][j] = 0;
			}else{
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			}
			ans = max(ans, dp[i][j]);
		}
	}
	for (int i = 0; i < n; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}
/*------------------------------------------------------*/

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}
```
### Shortest Subsequence

https://youtu.be/tGlSd-hCCl8

![image](https://user-images.githubusercontent.com/57065763/181752543-4b8abd3a-2e08-4b6c-b4ed-817d454c9f92.png)

![image](https://user-images.githubusercontent.com/57065763/181904835-ba5d3da3-46a7-4869-9fa7-12c340ebf628.png)

```
Shortest Subsequence

Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= |S| <= 1000 (|x| implies the length of the string x)
1 <= |V| <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
```

```cpp
//https://youtu.be/tGlSd-hCCl8

#include <iostream>
#include <string>
using namespace std;

/* ----------(3rd Approach) Optimized with DP and STL-----------*/
/*Time complexity: O(N *M) 
Space compleity: O(N *M) 
where N and M are the lengths of the two input strings 
*/

#include <vector> 

int solve(string s, string v) {

/*We establish the relationship between the sub problems and the problem at hand. Let dp(i, j) be the length 
of the shortest subsequence that is in s[1..i] that is not in v[1..j]. Here we have the following relationship:
dp(i, j) = ... 1) If letter s[i] is nowhere to be found in v[1..j], then dp(i,j) = 1 2) Otherwise, we have two 
case: 2a) s[i] is in the shortest subsequence. We find k, the most immediate index in v[1..j] where v[k] == s[i].
Then dp(i, j) = 1 + dp(i-1, k-1) 2b) s[i] is not in the shortest subsequence. Then dp(i, j) = dp(i-1, j) 
We pick whichever is lower. */

int slen = s.length();
int vlen = v.length();
    
vector<vector < int>> dp(slen + 1, vector<int> (vlen + 1));
vector<vector < int>> next(slen + 1, vector<int> (vlen + 1));
    
for (int i = 0; i < slen; i++){
	int prev = -1;
	for (int j = 0; j < vlen; j++){
		if (s[i] == v[j]){
			prev = j;
		}
		next[i + 1][j + 1] = prev;
	}
}
    
for (int i = 1; i <= slen; i++){
	dp[i][0] = 1;
}
    
for (int i = 0; i <= vlen; i++){
	dp[0][i] = 1e9;
}
    
for (int i = 1; i <= slen; i++){
	for (int j = 1; j <= vlen; j++){
		if (next[i][j] == -1){
			dp[i][j] = 1;
		}else{
			dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][next[i][j]]);
		}
	}
}
    
return dp[slen][vlen];
}
/* ----------(3rd Approach) Optimized with DP and STL-----------*/

/* ----------(2nd Approach) Memoization And Dp (easy to understand)-----------*/
int solve(string s, string v, int si, int vi, int** dp) {
    
    /// O(m*n*n)
    int slen = s.length();
    int vlen = v.length();
    
    if(vlen==vi){
        return 1;
    }
    
    if(slen==si){
        return 1001;
    }

    if(dp[si][vi] != -1){
        return dp[si][vi];
    }
    
    int dpExclude = solve(s,v,si+1,vi, dp);
    
    int indexV = -1;
    for(int i=vi; i<vlen; i++){
        if(v[i]==s[si]){
            indexV=i;
            break;
        }
    }
    if(indexV == -1){
       return 1; 
    }
    
    int dpInclude = solve(s,v,si+1,indexV+1, dp) +1;
    
    int dpResult = min(dpExclude, dpInclude);
    dp[si][vi]=dpResult;
    return dpResult;
    
}

int solve(string s, string v) {
    int slen =s.length();
    int vlen = v.length();
    
    int **dp = new int*[slen];
    for(int i=0; i<slen; i++){
        dp[i]=new int[vlen];
        for(int j=0; j<vlen; j++){
            dp[i][j] = -1;
        }
    }
    int ans = solve(s,v,0,0,dp);
    
    for(int i=0; i<slen; i++){
        delete[]dp[i];
    }
    delete dp;
    return ans;
}
/* ----------(2nd Approach) Memoization And Dp (easy to understand)-----------*/

/* -------------(1st Approach ) Bruite force --------------*/
int solve(string s, string v, int si = 0, int vi = 0)
{
	// O(2^n)
	// total univque call s*v

	if (vi == v.length()){
		return 1;
	}

	if (si == s.length()){
		return 1001;
	}

	int dp1 = solve(s, v, si + 1, vi);

	int indexV = -1;
    for (int i = vi; i < v.length(); i++){
		if (v[i] == s[si])
		{
			indexV = i;
			break;
		}
	}

	if (indexB == -1){
		return 1;
	}

	int dp2 = 1 + solve(s, v, si + 1, indexV + 1);
	return min(dp1, dp2);
}
/* -------------(1st Approach ) Bruite force --------------*/

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}
```

```

Lecture 19 : DP - 2 END HERE

```
