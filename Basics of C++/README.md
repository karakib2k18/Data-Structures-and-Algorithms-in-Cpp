# C++ Course for Beginners to Experienced Learners

## TEST-1
### Does s contain t ?

```cpp

/*
Does s contain t ?
Given two string s and t, write a function to check if s contains all characters of t (in the
same order as they are in string t). Return true or false. Do it recursively. 
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. 
So function will return true.

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

*/

// Counting from from 1st char
bool checksequenece(char large[] , char*small) {
    
    if(large[0]=='\0'){
        return false;
    }
        if(small[0]=='\0'){
        return true;
    }
    
    // small er word jodi large a thake tahole small & large next elements a jabe.
    if(large[0]==small[0]){
       return  checksequenece(large+1 , small+1);
    }
    
    // na soman hole only large ++ hobe. and large jodi age '\0' hoy tahole flase
    return checksequenece(large+1 , small);
}

#include<iostream>
using namespace std;
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

```