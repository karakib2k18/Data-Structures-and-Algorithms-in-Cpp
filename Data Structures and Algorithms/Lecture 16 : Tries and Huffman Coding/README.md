```

Lecture 16 : Tries and Huffman Coding START HERE

```
# ##Lecture 16 : Tries and Huffman Coding

---

//============>>>>>>>>>>Tries and Huffman Coding Notes
[Lecture 16 : Tries and Huffman Coding notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/9134367/Lecture.16.Tries.and.Huffman.Coding.notes.pdf)


---

### Introduction to Tries
![image](https://user-images.githubusercontent.com/57065763/186527412-f6d7a9f8-0de3-4439-aa71-47073e5139a0.png)

### TrieNode class
![image](https://user-images.githubusercontent.com/57065763/186527808-77115712-b7f3-4df3-9df3-20fa9d95cd37.png)

```cpp
class TrieNode {
	public :
	char data;
	TreeNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		isTerminal = false;
	}


};
```

### Tries Implementation - Insert

```cpp
//TrieNode
class TrieNode {
	public :
	char data;
	TreeNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}


};
```

```cpp
class Trie {
	TrieNode *root;

	public :

	Trie() {
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = true;
			return;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}
		
		// Recursive call
		insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		insertWord(root, word);
	}
};
```

### Search in Tries and Code

```
Implement the function SearchWord for the Trie class.
For a Trie, write the function for searching a word. Return true if the word is found successfully, otherwise return false.
Note : main function is given for your reference which we are using internally to test the code.
```
```cpp
/*
#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main() {
    int choice;
    cin >> choice;
    Trie t;

    while (choice != -1) {
        string word;
        bool ans;
        switch (choice) {
            case 1:  // insert
                cin >> word;
                t.insertWord(word);
                break;
            case 2:  // search
                cin >> word;
                cout << (t.search(word) ? "true\n" : "false\n");
                break;
            default:
                return 0;
        }
        cin >> choice;
    }

    return 0;
}
*/
/*
Time complexity: O(N) 
Space complexity: O(N) 
where N is the length of the word to be searched 
*/
class TrieNode {
    
  public: 
    char data;
    TrieNode ** children;
    bool isTerminal;
    
    TrieNode(char data) {
    this -> data = data;
    children = new TrieNode * [26];
        
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isTerminal = false;
        
    }
};

class Trie {
    
  TrieNode * root;
    
  public:  
    Trie() {
    root = new TrieNode('\0');
  }
    
  void insertWord(TrieNode * root, string word) {
      
    // Base case 
    if (word.size() == 0) {
      root -> isTerminal = true;
      return;
    }
      
    // Small calculation 
    int index = word[0] - 'a';
    TrieNode * child;
      
    if (root -> children[index] != NULL) {
      child = root -> children[index];
    } else {
      child = new TrieNode(word[0]);
      root -> children[index] = child; // inserting child in a array
    }
      
    // Recursive call 
    insertWord(child, word.substr(1));
  }
    
  void insertWord(string word) {
    insertWord(root, word);
  }
    
  bool search(TrieNode * root, string word) {
      
    // Base case 
    if (word.size() == 0) {
      return root -> isTerminal;
    }
      
    // Small calculation 
    int index = word[0] - 'a';
    TrieNode * child;
      
    if (root -> children[index] != NULL) {
      child = root -> children[index];
    } else {
      return false;
    }
      
    // Recursive call 
    return search(child, word.substr(1));
  }
    
  bool search(string word) {
    return search(root, word);
  }
    
};
```

### Tries Implement - Remove

```cpp
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

#include <string>

class Trie {
	TrieNode *root;

	public :

	Trie() {
		root = new TrieNode('\0');
	}

	bool search(TrieNode *root, string word) {
		if(word.size() == 0) {
			return root -> isTerminal;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			return false;
		}

		// Recursive call
		return search(child, word.substr(1));
	}

	bool search(string word) {
		return search(root, word);
	}


	void insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = true;
			return;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		insertWord(root, word);
	}

	void removeWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = false;
			return;
		}

		// Small calculation
		TrieNode *child;
		int index =  word[0] - 'a';
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			// Word not found
			return;
		}

		removeWord(child, word.substr(1));

		// Remove child Node if it is useless
		if(child -> isTerminal == false) {
			for(int i = 0; i < 26; i++) {
				if(child -> children[i] != NULL) {
					return;
				}
			}
			delete child;
			root -> children[index] = NULL;
		}
	}


	void removeWord(string word) {
		removeWord(root, word);
	}


};

#include <iostream>
using namespace std;
#include "Trie.h"


int main() {
	Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");

	cout << t.search("and") << endl;

	t.removeWord("and");
	cout << t.search("and") << endl;
}
```

### Types of Tries
![image](https://user-images.githubusercontent.com/57065763/186528156-c018f9cf-f0f3-4329-825f-cfbae43dbd6d.png)

### Huffman Coding
![image](https://user-images.githubusercontent.com/57065763/186528488-ba7ba781-163c-4187-a25c-f3ea75d7f0c7.png)

### Pattern Matching
![image](https://user-images.githubusercontent.com/57065763/179860211-a3e0bdab-33fd-4b72-811c-1078e00b2487.png)

```
Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains a string, that denotes the value of the pattern p.
Output Format :
The first and only line of output contains true if the pattern is present and false otherwise.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
de
Sample Output 2 :
true
Sample Input 2 :
4
abc def ghi hg
hi
Sample Output 2 :
true
Sample Input 3 :
4
abc def ghi hg
hif
Sample Output 3 :
false
```

```cpp
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}
*/
/*Time complexity: O(N *M) 
Space complexity: O(N *M) 
where N is the number of words in the Trie and M is the average word length 
*/
class TrieNode
{
	public: 
    char data;
	TrieNode **children;
	bool isTerminal;
    
	TrieNode(char data)
	{
		this->data = data;
		children = new TrieNode *[26];
		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie
{
	TrieNode *root;
	public: 
    int count;
    
	Trie()
	{
		this->count = 0;
		root = new TrieNode('\0');
	}
    
	bool insertWord(TrieNode *root, string word)
	{
		// Base case 
		if (word.size() == 0)
		{
			if (!root->isTerminal)
			{
				root->isTerminal = true;
				return true;
			}
			else
			{
				return false;
			}
		}
		// Small calculation 
		int index = word[0] - 'a';
		TrieNode *child;
		if (root->children[index] != NULL)
		{
			child = root->children[index];
		}
		else
		{
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}
		// Recursive call 
		return insertWord(child, word.substr(1));
	}
    
	// For user 
	void insertWord(string word)
	{
		if (insertWord(root, word))
		{
			this->count++;
		}
	}
    
//------------------------------------------------
//-------------Pattern Matching-------------------

    bool search(TrieNode *root, string word)
	{
		if (word.size() == 0)
		{
			return true;
		}
        
		// Small calculation 
		int index = word[0] - 'a';
		TrieNode *child;
        
		if (root->children[index] != NULL)
		{
			child = root->children[index];
		}
		else
		{
			return false;
		}
		// Recursive call 
		return search(child, word.substr(1));
	}
    
	bool search(string word)
	{
		return search(root, word);
	}
    
	bool patternMatching(vector<string> vect, string pattern)
	{
		for (int i = 0; i < vect.size(); i++)
		{
			string word = vect[i];
			for (int j = 0; j < word.length(); j++)
			{
				insertWord(word.substr(j));
			}
		}
		return search(pattern);
	}
};
```

### Palindrome Pair => [HARD]

```
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.
Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.
Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome
Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
```

```cpp
/*
#include <bits/stdc++.h>
using namespace std;
#include "solution.h"

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}
*/
/*
---- The Approach We Have Taken To Implement This Problem ---- 

The approach we have taken to solve this problem is to store the reverse of each of the words in the Trie. 
We then iterate over the words and search that does the Trie contains the same word or not. It may happen 
that some parts of the word or a substring exist in the Trie. We check for the remaining part of the string 
to be a palindrome or not. Vise versa of the above will also be true, that means, it may happen that the word 
in the Trie may extend further over different number of branches, hence we check all the branches one by one 
to see if any of the branches make a palindrome. 
*/

/*
---- Another Possible Solution Could Be ---- 

There's another way of solving this problem. It goes like this. First add the reverse of every word in the trie. 
Then for every word, search it in the trie. If you find it, then that means the word was a palindrome itself and 
you can return true. If you don't find it, you need the length of the part that you did find. For example, 
you're searching for "abcdd" in the trie, you didn't find a match for "abcdd" but you found the word "abc" 
in the trie. Finding "abc" in the trie means that the actual word was "cba" since we inserted the reverse 
of every word in the list. Now, you have the word "abcdd", you found the word "abc" in the trie. If you can 
find whether the part of "abcdd" that comes after "abc", i.e. "dd" is a palindrome, you can conclude that 
concatenating "abcdd" and "cba" will also give a palindrome. So you can return true. If the part isn't a 
palindrome, you move to check for the next word. If you traverse through all words without finding a pair of 
words that combine to form a palindrome or a word that's a palindrome by itself, then you can return false. 
*/

/*Time complexity: O(N *M) 
Space complexity: O(N *M) 
where N is the number of words in the Trie and M is the average word length 
*/
#include <string>
#include <vector>

class TrieNode
{
	public: char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;
	TrieNode(char data)
	{
		this->data = data;
		children = new TrieNode *[26];
		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
	}
};

class Trie
{
	TrieNode * root;
	public: int count;
	Trie()
	{
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool add(TrieNode *root, string word)
	{
		// Base case 
		if (word.size() == 0)
		{
			if (!root->isTerminal)
			{
				root->isTerminal = true;
				return true;
			}
			else
			{
				return false;
			}
		}
		// Small calculation 
		int index = word[0] - 'a';
		TrieNode *child;
		if (root->children[index] != NULL)
		{
			child = root->children[index];
		}
		else
		{
			child = new TrieNode(word[0]);
			root->children[index] = child;
			root->childCount++;
		}
		// Recursive call 
		return add(child, word.substr(1));
	}

	// For user 
	void add(string word)
	{
		if (add(root, word))
		{
			this->count++;
		}
	}

	/*..................... Palindrome Pair................... */
	bool searchPalindrome(TrieNode *root, string words)
	{
		if (root->isTerminal || words.size() == 0)
		{
			return true;
		}
		if (root->children[words[0] - 'a'] != NULL)
		{
			return searchPalindrome(root->children[words[0] - 'a'], words.substr(1));
		}
		else
		{
			return false;
		}
	}

	bool searchPalindrome(vector<string> words)
	{
		for (int i = 0; i < words.size(); i++)
		{
			if (searchPalindrome(root, words[i]))
			{
				return true;
			}
		}
		return false;
	}

	bool isPalindromePair(vector<string> words)
	{
		// Write your code here
		for (int i = 0; i < words.size(); i++)
		{
			string ReverseWord = words[i];
			reverse(ReverseWord.begin(), ReverseWord.end());
			add(ReverseWord);
		}
		return searchPalindrome(words);
	}
};
```

### Auto complete
![image](https://user-images.githubusercontent.com/57065763/179859863-84b4236e-766a-4b36-9fa2-9b7b0bece175.png)
![image](https://user-images.githubusercontent.com/57065763/179859932-a022f9d8-4c11-4c4f-986b-7e280cc7f299.png)

```
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains the word w, that has to be auto-completed.
Output Format :
Print all possible words in separate lines.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 2 :
no
not
note
notes
Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den
Sample Input 3 :
7
do dont no not note notes den
nom
Sample Output 3 :
(Empty) There is no word which starts with "nom"
```

```cpp
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}
*/
/*
Time complexity: O(N *M) 
Space complexity: O(N *M) 
where N is the number of words in the Trie and 
M is the average word length 
*/

class TrieNode
{
	public: 
    char data;
	TrieNode **children;
	bool isTerminal;
	TrieNode(char data)
	{
		this->data = data;
		children = new TrieNode *[26];
		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;
		}
		isTerminal = false;
	}
};
class Trie
{
	TrieNode * root;
	public: 
    int count;
	Trie()
	{
		this->count = 0;
		root = new TrieNode('\0');
	}
	bool insertWord(TrieNode *root, string word)
	{
		// Base case 
		if (word.size() == 0)
		{
			if (!root->isTerminal)
			{
				root->isTerminal = true;
				return true;
			}
			else
			{
				return false;
			}
		}
		// Small calculation 
		int index = word[0] - 'a';
		TrieNode *child;
		if (root->children[index] != NULL)
		{
			child = root->children[index];
		}
		else
		{
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}
		// Recursive call 
		return insertWord(child, word.substr(1));
	}
	void insertWord(string word)
	{
		if (insertWord(root, word))
		{
			this->count++;
		}
	}
    
/* -------------------BY CN START-----------------*/
    
    void autoCompleteSingleHelper(TrieNode *root, string output)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->isTerminal)
        {
            cout << output << endl;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (root->children[i])
            {
				autoCompleteSingleHelper(root->children[i],  output + (root->children[i]->data));
            }
        }
    }
    void autoCompleteHelper(TrieNode *root, string pattern, string output)
    {
        if (root == NULL)
        {
            return;
        }
        if (pattern.size() == 0)
        {
            if (root->isTerminal)
            {
                cout << output << endl;
            }
            for (int i = 0; i < 26; ++i)
            {
                if (root->children[i] != NULL)
                {
                    autoCompleteSingleHelper(root->children[i],  output + (root->children[i]->data));
                }
            }
            return;
        }
        int index = pattern[0] - 'a';
        autoCompleteHelper(root->children[index], pattern.substr(1), output+ pattern[0]);
    }

    void autoComplete(vector<string> input, string pattern)
    {
        for (int i = 0; i < input.size(); ++i)
        {
            insertWord(input[i]);
        }
        string output = "";
        autoCompleteHelper(root, pattern, output);
    }
    
/* -------------------BY CN END-----------------*/
    
    
/* -------------------BY KAZI ABDUR RAKIB START-----------------*/ 
/*
    
    void autoCompleteHelper(TrieNode *root, string pattern, string output)
    {
        if (root == NULL)
        {
            return;
        }
        if (pattern.size() == 0)
        {
            if (root->isTerminal)
            {
                cout << output << endl;
            }
            for (int i = 0; i < 26; ++i)
            {
                if (root->children[i] != NULL)
                {
                    autoCompleteHelper(root->children[i], pattern, output + (root->children[i]->data));
                }
            }
        }
        else
        {
            autoCompleteHelper(root->children[pattern[0] - 'a'], pattern.substr(1), output + pattern[0]);
        }
    }

    void autoComplete(vector<string> input, string pattern)
    {
        for (int i = 0; i < input.size(); ++i)
        {
            insertWord(input[i]);
        }
        string output = "";
        autoCompleteHelper(root, pattern, output);
    }
*/
/* -------------------BY KAZI ABDUR RAKIB END-----------------*/
};
```

```

Lecture 16 : Tries and Huffman Coding END HERE

```
