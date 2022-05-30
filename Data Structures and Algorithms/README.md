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

### Introduction to OOPS

```cpp

// Class for Product
class Product {
	int id;
	int weight;
	char name[100];
};

//Class for Student
class Student {
	int rollNumber;
	int age;
};

```
### Creating Objects

```cpp

#include <iostream>
using namespace std;

//Class for Student
class Student {

	public :

	int rollNumber;
	
	private :
	int age;
};

int main() {
	// Create objects statically
	Student s1;
	Student s2;

	Student s3, s4, s5;

	s1.age = 24;
	s1.rollNumber = 101;

	cout << s1.age << endl;
	cout << s1.rollNumber << endl;

	s2.age = 30;


	// Create objects dynamicaaly
	Student *s6 = new Student;
	(*s6).age = 23;
	(*s6).rollNumber = 104;

	s6 -> age = 23;
	s6 -> rollNumber = 104;
}

```


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

### Getters and Setters

```cpp

// Student.cpp code
class Student {

	public :
	int rollNumber;
	
	private :
	int age;


	public :

	void display() {
		cout << age << " " << rollNumber << endl;
	}

	int getAge() {
		return age;
	}

	void setAge(int a, int password) {
		if(password != 123) {
			return;
		}
		if(a < 0) {
			return;
		}
		age = a;
	}

};


// StudentUse.cpp code
#include <iostream>
using namespace std;
#include "Student.cpp"


int main() {
	// Create objects statically
	Student s1;
	Student s2;

	Student s3, s4, s5;

	//s1.age = 24;
	s1.rollNumber = 101;

	cout << "S1 age : " << s1.getAge() << endl;
	cout << "S1 Roll number : " << s1.rollNumber << endl;

	s1.display();
	s2.display();


	//s2.age = 30;


	// Create objects dynamicaaly
	Student *s6 = new Student;
	//(*s6).age = 23;
	(*s6).rollNumber = 104;

	(*s6).display();

	cout << "S6 age : " << s6 -> getAge() << endl;

	//s6 -> age = 23;
	s6 -> rollNumber = 104;
	s6 -> display();
}


// StudentNew.cpp code
#include <iostream>
using namespace std;
#include "Student.cpp"

int main() {
	Student s1;

	Student *s2 = new Student;

	s1.setAge(20);
	s2 -> setAge(24);

	s1.display();
	s2 -> display();
}

```

### Constructors and this keyword

```cpp
#include <iostream>
using namespace std;


class Student {

	public :
	int rollNumber;
	
	private :
	int age;

	public :

	// Default constructor
	Student() {
		cout << "Constreuctor called ! "<< endl;
	}

	// Parameterized constructor
	Student(int rollNumber) {
		cout << "Constructor 2 called !" << endl;
	
		this -> rollNumber = rollNumber;
	}

	Student(int a, int r) {
		cout << "this : " << this << endl;
		cout << "Constructor 3 called ! " << endl;
		this -> age = a;
		this -> rollNumber = r;
	}

	void display() {
		cout << age << " " << rollNumber << endl;
	}

	int getAge() {
		return age;
	}

	void setAge(int a, int password) {
		if(password != 123) {
			return;
		}
		if(a < 0) {
			return;
		}
		age = a;
	}
};

int main() {

	Student s1(10, 1001);
	cout << "Address of s1 : " << &s1 << endl;

	Student s2(20);
	s2.display();


	Student s1;

	s1.display();

	Student s2;

	Student *s3 = new Student;
	s3 -> display();


	cout << "Parametrized constructors Demo" << endl;
	Student s4(10);

	s4.display();

	Student *s5 = new Student(101);
	s5 -> display();

	Student s6(20, 1002);
	s6.display()
	
}

```

### Inbuilt Constructors and Destructor

```cpp
#include <iostream>
using namespace std;

class Student {

	public :
	int rollNumber;
	
	private :
	int age;

	public :

	~Student() {
		cout << "Destructor called ! " << endl;
	}

	// Default constructor
	/*Student() {
		cout << "Constreuctor called ! "<< endl;
	}*/

	// Parameterized constructor
	Student(int rollNumber) {
		cout << "Constructor 2 called !" << endl;
	
		this -> rollNumber = rollNumber;
	}

	Student(int a, int r) {
		cout << "this : " << this << endl;
		cout << "Constructor 3 called ! " << endl;
		this -> age = a;
		this -> rollNumber = r;
	}

	void display() {
		cout << age << " " << rollNumber << endl;
	}

	int getAge() {
		return age;
	}

	void setAge(int a, int password) {
		if(password != 123) {
			return;
		}
		if(a < 0) {
			return;
		}
		age = a;
	}

};


int main() {
	
	Student s1(10, 1001);
	Student s2(20, 2001);
	Student *s3 = new Student(30, 3001);

	s2 = s1;
	*s3 = s1;
	s2 = *s3;
	delete s3;


    // FOr another example:
	/*
	Student s1(10, 1001);
	cout << "S1 : ";
	s1.display();

	Student s2(s1);
	cout << "S2 : ";
	s2.display();

	Student *s3 = new Student(20, 2001);
	cout << "S3 : ";
	s3 -> display();

	Student s4(*s3);

	Student *s5 = new Student(*s3);
	Student *s6 = new Student(s1);
	*/

}


```

### Inbuilt Constructors and Destructor

```cpp
#include <iostream>
using namespace std;

class Student {

	public :
	int rollNumber;
	
	private :
	int age;

	public :

	~Student() {
		cout << "Destructor called ! " << endl;
	}

	// Default constructor
	/*Student() {
		cout << "Constreuctor called ! "<< endl;
	}*/

	// Parameterized constructor
	Student(int rollNumber) {
		cout << "Constructor 2 called !" << endl;
	
		this -> rollNumber = rollNumber;
	}

	Student(int a, int r) {
		cout << "this : " << this << endl;
		cout << "Constructor 3 called ! " << endl;
		this -> age = a;
		this -> rollNumber = r;
	}

	void display() {
		cout << age << " " << rollNumber << endl;
	}

	int getAge() {
		return age;
	}

	void setAge(int a, int password) {
		if(password != 123) {
			return;
		}
		if(a < 0) {
			return;
		}
		age = a;
	}

};


int main() {
	
	Student s1(10, 1001);
	Student s2(20, 2001);
	Student *s3 = new Student(30, 3001);

	s2 = s1;
	*s3 = s1;
	s2 = *s3;
	delete s3;


    // FOr another example:
	/*
	Student s1(10, 1001);
	cout << "S1 : ";
	s1.display();

	Student s2(s1);
	cout << "S2 : ";
	s2.display();

	Student *s3 = new Student(20, 2001);
	cout << "S3 : ";
	s3 -> display();

	Student s4(*s3);

	Student *s5 = new Student(*s3);
	Student *s6 = new Student(s1);
	*/

}


```

### Fraction Class

```cpp

#include <iostream>
using namespace std;

class Fraction {
	private :

		int numerator;
		int denominator;

	public :

		Fraction(int numerator, int denominator) {
			this -> numerator = numerator;
			this -> denominator = denominator;
		}

		void print() {
			cout << this -> numerator << " / " << denominator << endl;
		}


		void simplify() {
			int gcd = 1;
			int j = min(this -> numerator, this -> denominator);
			for(int i = 1; i <= j; i++) {
				if(this -> numerator % i == 0 && this -> denominator % i == 0) {
					gcd = i;
				}
			}
			this -> numerator = this -> numerator / gcd;
			this -> denominator = this -> denominator / gcd;
		}

		void add(Fraction f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			numerator = num;
			denominator = lcm;

			simplify();	

		}
};

int main() {
	Fraction f1(10, 2);
	Fraction f2(15, 4);

	f1.add(f2);

	f1.print();
	f2.print();
}

ANSWER: 35/4
        15/4

```


### xxxxxxxxx

```cpp


```

