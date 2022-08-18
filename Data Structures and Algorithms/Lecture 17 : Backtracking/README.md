```

Lecture 17 : Backtracking START HERE

```

# ## Lecture 17 : Backtracking

---

//============>>>>>>>>>> NOTE-NAME
PDF


---

### Backtracking ( N-Queen Explain) and Blog link

https://www.codesdope.com/course/algorithms-backtracking/

https://codecrucks.com/n-queen-problem/

![image](https://user-images.githubusercontent.com/57065763/180084181-2aa7e822-daff-405c-b66b-21f2d6d9490b.png)

![image](https://user-images.githubusercontent.com/57065763/180083444-205b3756-3b53-4fc7-b920-93466f19f42e.png)

![image](https://user-images.githubusercontent.com/57065763/180083606-973e1fca-53c4-4052-8c09-41b21ffb8f41.png)

![image](https://user-images.githubusercontent.com/57065763/180084649-dc666ca9-1626-4463-be84-9b78a406b66b.png)

![image](https://www.codesdope.com/staticroot/images/algorithm/queen.gif)

###  N-Queen Problem AND N-Queen Code

```
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Note: Don't print anything if there isn't any valid configuration.
Input Format:
The first line of input contains an integer, that denotes the value of N.     
Output Format :
In the output, you have to print every board configuration in a new line. Every configuration will have N*N board elements printed row wise and are separated by space. The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. Please refer to sample test cases for more clarity.
Constraints :
1 <= N <= 10
Time Limit: 1 second
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
Explanation:
The first and second configuration are shown in the image below. Here, 1 denotes the placement of a queen and 0 denotes an empty cell. Please note that in both the configurations, no pair of queens can kill each other. 
```
![image](https://user-images.githubusercontent.com/57065763/180084833-e685a177-aea3-4fed-96ed-b3ae838d0860.png)

```cpp
// BEST VIDEO ==>>> https://youtu.be/05y82cP3bJo?t=1465
/*
Time complexity : O(N*2^N) 
Space complexity : O(N*N) 
Where N is the input size of chess board 
*/
#include <bits/stdc++.h>
using namespace std;

bool isBoardSafe(vector<vector < int>> &board, int row, int col)
{
	int n = board.size();
    
    // Same Column
	for (int i = row - 1; i >= 0; i--)
	{
		if (board[i][col] == 1)
		{
			return false;
		}
	}
    
    //Upper Left Diagonal
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j] == 1)
		{
			return false;
		}
	}

	// Upper Right Diagonal
	for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
	{
		if (board[i][j] == 1)
		{
			return false;
		}
	}
	return true;
}
void placeQueen(vector<vector < int>> &board, int row, int n)
{
	if (row == n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << board[i][j] << " ";
			}
		}
		cout << endl;
	}
	for (int j = 0; j < n; j++)
	{
		if (isBoardSafe(board, row, j))
		{
			board[row][j] = 1;
			placeQueen(board, row + 1, n);
			board[row][j] = 0;
		}
	}
}
void placeNQueens(int n)
{
	vector<vector < int>> board(n, vector<int> (n, 0));
	placeQueen(board, 0, n);
}
int main()
{
	int n;
	cin >> n;
	placeNQueens(n);
}
```

### Rat In A Maze Problem - Explain &&& Rat In A Maze - Code

![image](https://user-images.githubusercontent.com/57065763/180374175-043b67d4-443d-47b0-a05e-f8c59f541ba5.png)

![image](https://user-images.githubusercontent.com/57065763/180374210-c097d088-21a4-4e64-a3d1-3ae600ed1ea0.png)

![image](https://user-images.githubusercontent.com/57065763/180291977-d565759f-bc89-43f6-8072-f596de6d0585.png)

![image](https://user-images.githubusercontent.com/57065763/180293735-cf7a2336-22da-4308-964d-b7edcb890c64.png)

[![Rat In A Maze](https://yt-embed.herokuapp.com/embed?v=PwxGTHraMNg&t=106s)](https://www.youtube.com/watch?v=PwxGTHraMNg&t=106s
 "Rat In A Maze")

```
Rat In A Maze Problem

You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
Input Format
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 
Output Format :
Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.   
Constraints
1 <= N <= 18
0 <= Number of cells with value 1 <= 15
Time Limit: 1 second
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Explanation :
Only 1 path is possible. The path is shown in the image below.
Alt Text

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Explanation:
 As described in the Sample Output 2, four paths are possible.

```

```cpp
/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/

/*
Time complexity : O(2^k) 
Space complexity : O(N^2) 
where N is the size of maze and 
K is the numer of cells in maze with value equal to one(1) 
*/

#include <bits/stdc++.h>
using namespace std;

void printSolution(int** solution,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << solution[i][j] << " ";
		}
	}
	cout<<endl;
}
void mazeHelp(int maze[][20],int n,int** solution,int x,int y){


	if(x == n-1 && y == n-1){
		solution[x][y] =1;
		printSolution(solution,n);
      	solution[x][y] =0;
		return;
	}
	if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || solution[x][y] ==1){
		return;
	}
	solution[x][y] = 1;
	mazeHelp(maze,n,solution,x-1,y);
	mazeHelp(maze,n,solution,x+1,y);
	mazeHelp(maze,n,solution,x,y-1);
	mazeHelp(maze,n,solution,x,y+1);
	solution[x][y] = 0;
}

void ratInAMaze(int maze[][20], int n){

  int** solution = new int*[n];
  for(int i=0;i<n;i++){
  	solution[i] = new int[n];
  }
  mazeHelp(maze,n,solution,0,0);
}

int main()
{
	int n;
	cin >> n;
	int maze[20][20];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
		}
	}
	ratInAMaze(maze, n);
}
```

### Crossword Problem

![image](https://user-images.githubusercontent.com/57065763/180393349-fae423db-c8c2-4aa5-adc0-9ce63d8f9f83.png)



```
Crossword Problem

Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Constraints
The number of words in the word list lie in the range of: [1,6]
The length of words in the word list lie in the range: [1, 10]
Time Limit: 1 second
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
```

```cpp
/*
Time complexity : O(2^K) 
Space complexity : O(N*N) 
where N is the size of cross word and K is the number of words 
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> crossword(10);
vector<string> words;

bool flag;

void puzzle(int index)
{
	if (!flag)
	{
		return;
	}
	if (index == words.size())
	{
		if (flag)
		{
			for (auto word: crossword)
			{
				cout << word << endl;
			}
			flag = false;
		}
		return;
	}
	int i, j, k;
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			for (k = 0; k < words[index].size() && i + k < 10; ++k)
			{
				if (crossword[i + k][j] != '-' && crossword[i + k][j] != words[index][k])
				{
					break;
				}
			}
			if (k == words[index].size())
			{
				vector<string> temp = crossword;
				for (k = 0; k < words[index].size(); ++k)
				{
					crossword[i + k][j] = words[index][k];
				}
				puzzle(index + 1);
				crossword = temp;
			}
			for (k = 0; k < words[index].size() && j + k < 10; ++k)
			{
				if (crossword[i][j + k] != '-' && crossword[i][j + k] != words[index][k])
				{
					break;
				}
			}
			if (k == words[index].size())
			{
				vector<string> temp = crossword;
				for (k = 0; k < words[index].size(); ++k)
				{
					crossword[i][j + k] = words[index][k];
				}
				puzzle(index + 1);
				crossword = temp;
			}
		}
	}
}
int main()
{
	flag = true;
	int i, j;
	for (i = 0; i < 10; ++i)
	{
		cin >> crossword[i];
	}
	string word, sentenceWithColon;
	cin >> sentenceWithColon;
	for (auto singleAlpa : sentenceWithColon)
	{
		if (singleAlpa == ';')
		{
			words.push_back(word);
			word = "";
		}
		else{
			word += singleAlpa;
        }
	}
	words.push_back(word);
	puzzle(0);
	return 0;
}
```


### Sudoku Solver
![image](https://user-images.githubusercontent.com/57065763/180598185-5e15dc20-1a43-4283-a478-5ac25603ce57.png)

```
Sudoku Solver

Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.
Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 
Note:
Input are given in a way that backtracking solution will work in the provided time limit.
Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
true
```

```cpp
//https://youtu.be/uyetDh-DyDg
/*
Time complexity : O(9^k) 
Space complexity : O(m^2) 
where K is the number of cell with value equal to zero and m is the 9 (as 9 * 9 suduko) 
*/

#include <bits/stdc++.h>
using namespace std;

bool check(int board[][9], int row, int col, int val)
{
	for (int k = 0; k < 9; k++)
	{
		if (board[row][k] == val) {
            return false;
        }
		if (board[k][col] == val) {
            return false;
        }
	}
    
	int TopRowIndice = row - row % 3;
	int TopColIndice = col - col % 3;
	for (int c = TopRowIndice; c < TopRowIndice + 3; c++)
	{
		for (int d = TopColIndice; d < TopColIndice + 3; d++)
		{
			if (board[c][d] == val)
			{
				return false;
			}
		}
	}
	return true;
}
bool helper(int board[][9], int row, int col)
{
	if (row == 9)
	{
		return true;
	}
	if (col == 9){
		return helper(board, row + 1, 0);
    }
	if (board[row][col] != 0)
	{
		return helper(board, row, col + 1);
	}else{
        for (int k = 1; k <= 9; k++)
        {
            if (check(board, row, col, k))
            {
                board[row][col] = k;
                if (helper(board, row, col + 1)){ 
                     return true;
                }
            }
            board[row][col] = 0;
        }
    }
	return false;
}
bool sudokuSolver(int board[][9])
{
	return helper(board, 0, 0);
}
int main()
{
	int board[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
		}
	}
	if (sudokuSolver(board))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}
```

### Subset Sum

![image](https://user-images.githubusercontent.com/57065763/180603894-5401d20b-0c07-4f1e-b847-057e55725509.png)

```
Subset Sum

You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.
Note:
1. Subset can have duplicate values.
2. Empty subset is a valid subset and has sum equal to zero.
Input Format:
The first line of input will contain an integer T, that denotes the value of number of test cases.
Each test case contains two lines. The first line of each test case will contain two space-separated integers N and K, where N is the size of the given array and K is the target value. 
The second line of each test case will contain N space separated integers denoting the elements of the input array.
Output Format ;
For each test case, print the number of subsets that sum upto K in a separate line.
Constraints
1 <= T <= 50
2 <= N <= 15
0 <= array[i] <= 10^9
0 <= K <= 10^9
Time Limit: 1 second
Sample Input 1:
1
5 6
2 4 4 3 1
Sample Output 1:
3
Explanation:
Following are the three subsets, that sum upto K=6:
1. [2, 4], Element 4 in this subset is the one at index 1
2. [2, 4], Element 4 in this subset is the one at index 2
3. [2, 3, 1]  
Sample Input 2:
2
8 8
1 4 1 3 1 1 2 3 
8 2
4 1 4 4 2 4 1 1
Sample Output 2:
30
4
```

```cpp
/*
Time complexity : O(2^N) 
Space complexity : O(N) 
where N is the size of input array 
*/

#include <bits/stdc++.h>
using namespace std;

int subsetCount(int arr[], int n, int index, int target)
{
	if (index == n)
	{
		if (target == 0)
		{
			return 1;
		}
		else return 0;
	}
	int count = 0;
// including
	if (target - arr[index] >= 0)
	{
		count += subsetCount(arr, n, index + 1, target - arr[index]);
	}
// excluding
	count += subsetCount(arr, n, index + 1, target);
	return count;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << subsetCount(arr, n, 0, k) << endl;
	}
}
```

```

Lecture 17 : Backtracking END HERE

```
