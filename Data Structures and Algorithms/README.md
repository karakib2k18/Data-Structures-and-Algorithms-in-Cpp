# Data Structures and Algorithms for Beginners and Experienced Learners

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

---

---

# OOPS-1

---

---

#### Q-1. Which of these statements is used to allocate memory for an object dynamically ?

```cpp

==>ANSWER: new

```
#### Q-2. Which of the following is/are a valid statement(s) to create an object of class Bird in C++ ?

```cpp

==>ANSWER: 1) Bird *b = new Bird;
        2) Bird b;

```

#### Q-3. Figure out the correct statement ?

```cpp

Figure out the correct statement
class Car{
    public : 
    int price;
};

int main() {
    Car c; 
    //Figure out the correct statement to set the price of the car object referred to by c to “10000”
}

==>ANSWER: c.price = 10000; 

```
#### Q-4. What is the output -  ?

```cpp

#include <iostream>
using namespace std;

class Student {
    int rollNumber;
};

int main() {
    Student s;
    cout << s.rollNumber;
}

==>ANSWER: Compilation Error | becuase question a public and private didn't write.

```
#### Q-5.What will be the output of the following program ?  ?

```cpp
#include <iostream>
using namespace std;

class Shape{
    public : 
    int height;
    int width;
};

int main() {
    Shape *s = new Shape();
    s -> height = 1;
    cout << s -> height;
}

==>ANSWER: 1; 

```


#### Q-6. Which statement is not true in C++ language ?

```cpp

==>ANSWER: A private member of a class cannot be accessed by the functions of the same class. 

```

#### Q-7.  ?

```cpp

/* 

*/


==>ANSWER: c.price = 10000; 

```

