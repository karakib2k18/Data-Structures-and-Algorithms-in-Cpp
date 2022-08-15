<!-- # Data Structures & Algorithms for Beginners to Experienced Learners

## TEST-1

### Does s contain t ?

```cpp
------------------------------------------------------------------------------------------------
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

------------------------------------------------------------------------------------------------

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

# ##OOPS-1

---

[Lecture -6: OOPS-1.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/8837504/Lecture.-6.OOPS-1.pdf)

---

### Introduction to OOPS


```cpp
this ->  ==> this holds the address of the current object.
```

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

![image](https://user-images.githubusercontent.com/57065763/171986499-4d830aff-98ab-4c82-ae36-af328576a9fb.png)

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

![image](https://user-images.githubusercontent.com/57065763/171987232-a4112ebf-038e-4649-99e3-d09a55f9a741.png)
![image](https://user-images.githubusercontent.com/57065763/171987244-f8a043de-15bd-461e-9bb7-1f3ce2470311.png)
![image](https://user-images.githubusercontent.com/57065763/171987253-1d6d2688-9c1b-43b2-a40e-0c3ecebc8d21.png)
![image](https://user-images.githubusercontent.com/57065763/171987268-d25bce14-35ed-4b7b-b1d1-9c0ac788dfa3.png)
![image](https://user-images.githubusercontent.com/57065763/171987275-df94757e-a03b-4bda-8b5f-d55d7bcc5298.png)
![image](https://user-images.githubusercontent.com/57065763/171987328-d46ab789-0b5e-4f75-be6a-bdba65e3955a.png)


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

void display() {
	cout << age << " " << rollNumber << endl;
}
----------------------------------------------------------------------------------------------
void setAge(int a, int password) {
	if(password != 123) {
		return;
	}
	if(a < 0) {
		return;
	}
	age = a;
}

----------------------------------------------------------------------------------------------
int getAge() {
	return age;
}
----------------------------------------------------------------------------------------------
s1.display();
(*s6).display();
s6 -> display();
```
```cpp

#include <iostream>
using namespace std;

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
![image](https://user-images.githubusercontent.com/57065763/171987362-d5bfc657-a1a3-4120-8ee2-c7eb17ff261b.png)
![image](https://user-images.githubusercontent.com/57065763/171987434-e877ed8a-f916-40de-806b-491ae9a57042.png)
![image](https://user-images.githubusercontent.com/57065763/171987448-cd39ce14-ec57-4a18-91b2-425a29f0d639.png)

#### Q-7.  What is the output ?

What will be the Output ?

```cpp

#include <iostream>
using namespace std;

class Box{
    public :
    int width;
    int height;
    int length;
    void volume(){
        cout << length * width * height;
    }
};

int main() {
    Box b;
    b.height = 5;
    b.width = 4;
    b.volume();
}

==> ANSWER: Garbage value.

Solution Description:=>

####Height and width are initialised to 5 and 4 respectively but length is not initialised. Default value for an 
integer data member of a class is garbage value, hence length contains garbage value.Volume will thus be garbage value.

```


#### Q-8.  What will be the output of the following code ?

What will be the output of the following code ?

```cpp
#include <iostream>
using namespace std;

class Student{
    public :
    char *name;
    int rollNo;
    Student(int num){
        rollNo = num;
    }

    void print(){
        cout << rollNo;
    }
};

int main() {
    Student s(12);
    s.print();
}

==> ANSWER: 12

Solution Description=>

####Constructor is called when an object is created, here when we create a Student object, corresponding student 
object is created and rollNo is assigned to 12. So output is 12.

```

#### Q-9.  What will be the output of the following code ?

What will be the output of the following code ?

```cpp

#include <iostream>
using namespace std;

class Student{
    public :
    char name;
    int rollNo;

    Student(int num){
        rollNo = num;
    }

    void print(){
        cout << name << " "  <<  rollNo;
    }
};

int main() {
    Student *s = new Student();
    s -> name = 'A';
    s -> rollNo = 15;
    s -> print();
}

==> ANSWER: Compilation error | becuase Default constructor hole answer became [A 15], it was create a constructor,
			so, it can only take rollNo input. and name can not take input. 

Solution Description=>

There is Compilation error - “constructor Student() is undefined” because the default constructor is available only 
till the point we don’t create our own constructor. So Student class has only one constructor which require roll 
number as argument, hence we should pass integer as argument while creating any Student object.

```


### Inbuilt Constructors and Destructor

![image](https://user-images.githubusercontent.com/57065763/171994489-64118cb9-4625-41b6-b636-cb050f890581.png)
![image](https://user-images.githubusercontent.com/57065763/171994643-cb79a655-eb4f-4dd4-b15a-9f3deeb69c5b.png)


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

![image](https://user-images.githubusercontent.com/57065763/171987472-a2674a0e-cba8-4f98-bdd5-285fda4d4753.png)
![image](https://user-images.githubusercontent.com/57065763/171987484-171ae583-a65e-4c87-9971-903627ef49e4.png)
![image](https://user-images.githubusercontent.com/57065763/171987492-f7787f0d-0a90-49ba-a23c-afc320bcfeea.png)
![image](https://user-images.githubusercontent.com/57065763/171987498-3262b308-6cb9-4560-8e32-741702678239.png)

#### Q-10.  Find Incorrect Statement ?

```cpp

Which of the following statements are not true about destructor?
1. It is invoked when object goes out of the scope
2. Like constructor, it can also have parameters 
3. It can be declared in private section
4. It bears same name as that of the class and precedes tilde sign. 

==> ANSWER: 2. Like constructor, it can also have parameters 

```
#### Q-11.  Copy Constructor

```cpp

Assume class DEMO. Which of the following statement(s) responsible to invoke copy constructor?
1. DEMO D2(D1); //  Here D1 is an already created object of class  DEMO
2. D2 = D1; // Here D1, D2 are already created objects of class DEMO

==> ANSWER: 2. Like constructor, it can also have parameters 

```

#### Q-12.  Copy Assignment Operator

```cpp

//Consider following piece of code:
class Pair{
  public :
  int first;
  int second;
};

int main(){

  Pair *p1 = new Pair;
  Pair p2;
}

Which of the following statement is feasible ?

This problem has only one correct answer
1. p2 = p1;
2. p2 = *p1;
3. Both 1 and 2 are correct.
4. None of the above


==> ANSWER: 2. p2 = *p1;

```

#### Q-13.  Copy Assignment Operator

```cpp

//Consider following piece of code:
#include<iostream>
using namespace std;

class Pair{
      public :
      int first;
      int second;
};

int main(){

      Pair p1;
      p1.first = 10;
      p1.second = 20;
      Pair p2;
      p2 = p1;
      cout << p2.first << " " << p2.second << endl;
}

What will be the output ?

Options
This problem has only one correct answer
10 20
Error
Garbage_value Garbage_value


==> ANSWER: 10 20 
	because first and second was declare in public;

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

==>ANSWER : 35/4
         	15/4

```


### Fraction Class contd.

```cpp
#include <iostream>
using namespace std;
// #include "Fraction.cpp"

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

		void add(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			numerator = num;
			denominator = lcm;
			simplify();	
		}

		void multiply(Fraction const &f2) {
			numerator = numerator * f2.numerator;
			denominator = denominator * f2.denominator;
			
			simplify();
		}

};


int main() {
	Fraction f1(10, 2);
	Fraction f2(15, 4);

	f1.add(f2);

	f1.print();
	f2.print();

	f1.multiply(f2);
	f1.print();
	f2.print();


}

==>ANSWER : 
			35 / 4
			15 / 4
			525 / 16
			15 / 4

```
## Complex Number Class

```cpp
------------------------------------------------------------------------------------------------

Complex Number Class
A ComplexNumber class contains two data members: one is the real part(R) and the other is imaginary (I)(both integers).
Implement the Complex numbers class that contains following functions -
1. constructor
You need to create the appropriate constructor.
2. plus -
This function adds two given complex numbers and updates the first complex number.
e.g.
if C1 = 4 + i5 and C2 = 3 +i1
C1.plus(C2) results in: 
C1 = 7 + i6 and C2 = 3 + i1
3. multiply -
This function multiplies two given complex numbers and updates the first complex number.
e.g.
if C1 = 4 + i5 and C2 = 1 + i2
C1.multiply(C2) results in: 
C1 = -6 + i13 and C2 = 1 + i2
4. print -
This function prints the given complex number in the following format :
a + ib
Note : There is space before and after '+' (plus sign) and no space between 'i' (iota symbol) and b.
Input Format :
Line 1 : Two integers - real and imaginary part of 1st complex number
Line 2 : Two integers - real and imaginary part of 2nd complex number
Line 3 : An integer representing choice (1 or 2) (1 represents plus function will be called and 2 represents multiply
 function will be called)
Output format :
Check details of 'print' function given above.
Sample Input 1 :
4 5
6 7
1
Sample Output 1 :
10 + i12
Sample Input 2 :
4 5
6 7
2
Sample Output 2 :
-11 + i58

------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class ComplexNumbers {
    // Complete this class
    private:
    
     int real;
     int imaginary;
    
    public:
    
     ComplexNumbers(int real, int imaginary){
         this -> real = real;
         this -> imaginary = imaginary;
     }
    
    void print(){
        cout<< real <<" + "<<"i"<<imaginary<<endl;
    }
    
    void plus(ComplexNumbers const &c2){
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }
    
    /*
    //MAthematics rules
    // link:https://www.mathsisfun.com/algebra/complex-number-multiply.html
    Firsts: a × c
    Lasts: bi × di //i^2= -1;
    Inners: bi × c
    Outers: a × di
    real = first + last;
    imaginary = innter+outer
    */

    void multiply(ComplexNumbers const &c2){
        int first = real * c2.real;
        int last = (-1) * (imaginary * c2.imaginary); // i^2 = -1;
        int inner = imaginary * c2.real;
        int outer = real * c2.imaginary;
        
        real = first + last;
        imaginary = inner + outer;   
    }
};


int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}

```

### OPPS-1 END HERE

```cpp

OPPS-1 END HERE

```

# ##OOPS-2

---

[Lecture 7: OOPS-2.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp-AND-Competitive-Programming/files/8837505/Lecture.7.OOPS-2.pdf)

---

### Shallow and Deep Copy


```cpp
 strcpy(name, "abc"); ==>> here name is the destination & "abc" is source. It is mean abc is copied into name.
 int Student::totalStudents = 20;
```

```cpp

DynamicArray d2(d1);		// Copy constructor
DynamicArray d3;
d3 = d1; //  inbuilt copy assignment operator.

==> In shallow copy, it does not copy the value of the specified object value. it just copy object addess.so its 
bad practice.It also happen for inbuilt copy constructor.(ex:CN d1(d2)) && inbuilt copy assignment operator(d1=d2).
SO always we have to create a deep copy.

```

```cpp
==> copy assignment operator (ex: d1=d2) also do shallow copy.
==> shallow copy created by the system, but deep copy created by the progrmmer itself.
	this -> age = age;
	// Shallow copy
	// this -> name = name;

	// Deep copy
	this -> name = new char[strlen(name) + 1];
	strcpy(this -> name, name);

```

```cpp

#include <iostream>
using namespace std;

class Student {
	int age;
	char *name;

	public :

	Student(int age, char *name) {
		this -> age = age;
		// Shallow copy
		// this -> name = name;
	
		// Deep copy
		this -> name = new char[strlen(name) + 1];
		strcpy(this -> name, name);
	
	}

	void display() {
		cout << name << " " << age << endl;
	}
};

int main() {
	char name[] = "abcd";
	Student s1(20, name);
	s1.display();

	name[3] = 'e';
	Student s2(24, name);
	s2.display();

	s1.display();
}

```


### Copy Constructor

```cpp

this->name = new char[strlen(name) + 1]; ==>> create a new Array for the string length.

strcpy(this -> name, name); ==>> Now the string name is copying to the this->name array size.

```

```cpp
#include <iostream>
using namespace std;


class Student {
	int age;

	public :

	char *name;
	
	Student(int age, char *name) {
		this -> age = age;
		// Shallow copy
		// this -> name = name;
	
		// Deep copy
		this -> name = new char[strlen(name) + 1];
		strcpy(this -> name, name);
	
	}

	// Copy constructor
	Student(Student const &s) {
		this -> age = s.age;
		// this -> name = s.name;		// Shallo Copy
	
		// Deep copy
		this -> name = new char[strlen(s.name) + 1];
		strcpy(this -> name, s.name);
	}

	void display() {
		cout << name << " " << age << endl;
	}
};


int main() {
	char name[] = "abcd";
	Student s1(20, name);
	s1.display();

	Student s2(s1);

	s2.name[0] = 'x';
	s1.display();
	s2.display();
	/*
	name[3] = 'e';
	Student s2(24, name);
	s2.display();

	s1.display();
	*/

}

```
### Initialisation List | Passing value in the Const Data type.

```cpp

------------------------------------------------------------------------------------------------
int &x;	
x(this -> age)
------------------------------------------------------------------------------------------------

int age;
const int rollNumber;
int &x;		// age reference variable

==>  using Initialisation List we can pass value to the const variable or to the reference variable.
==>  here age(age), did n0t write this->age(age) because it automatically indicating the variable.
==> but here x(this -> age), if do not write (this->) then value will pass here but we want to indicate the age variable.
==>  x is referencing to the age variable.

Student(int r, int age) : rollNumber(r), age(age), x(this -> age) {  
	//rollNumber = r;	
}	
------------------------------------------------------------------------------------------------

```

```cpp

#include <iostream>
using namespace std;

class Student {
	public :
		int age;
		const int rollNumber;
		int &x;		// age reference variable

		Student(int r, int age) : rollNumber(r), age(age), x(this -> age) {
			//rollNumber = r;	
		}	
};

int main() {
	Student s1(101, 20);
	s1.age = 20;
	//s1.rollNumber = 101;
}

```

### Constant Functions | Const=> Obj can call only const Functions, they can't call the normal functions.

```
==> what is const function? ANSWER: which function does not change any property of current object. And we can make 
getvalue and print functions const. becuase we don't need to change them. And normal & const property also can access
const function. but we can't write const on setvalue or other calculation function where main variable's value of 
private class will be change, but we can use cons't where the function changing only their own variable value not 
private variable value. We should make every geting and printing function const becuase it's best way and we  don't 
need to do any inside of geting and printing function;
```

```cpp

//main function code
Fraction const f3; // it will work
cout << f3.getNumerator() << " " << f3.getDenominator() << endl; // it will work
f3.setNumerator(10); // it won't work, becuase const object. and inside of const function can't set new value;

//class function code
int getNumerator() const { // possible
	return numerator;
}

int getDenominator() const { // possible
	return denominator;
}

void setNumerator(int n) const { // not possible | impossible
	numerator = n;
}

void setDenominator(int d) const { // not possible | impossible
	denominator = d;
}

void print() const { // possible
	cout << this -> numerator << " / " << denominator << endl;
}

```

```cpp

#include <iostream>
using namespace std;

class Fraction {
	private :

		int numerator;
		int denominator;

	public :

		Fraction() {
			
		}

		Fraction(int numerator, int denominator) {
			this -> numerator = numerator;
			this -> denominator = denominator;
		}

		int getNumerator() const {
			return numerator;
		}
		
		int getDenominator() const {
			return denominator;
		}

		void setNumerator(int n) {
			numerator = n;
		}

		void setDenominator(int d) {
			denominator = d;
		}

		void print() const {
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

		void add(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			numerator = num;
			denominator = lcm;
			simplify();	
		}

		void multiply(Fraction const &f2) {
			numerator = numerator * f2.numerator;
			denominator = denominator * f2.denominator;
			
			simplify();
		}
};


int main() {
	Fraction f1(10, 2);
	Fraction f2(15, 4);

	Fraction const f3;

	cout << f3.getNumerator() << " " << f3.getDenominator() << endl;

	f3.setNumerator(10);
}

```
### Static Members

![image](https://user-images.githubusercontent.com/57065763/172006543-fd7f2a79-1178-4d5f-9df8-cb8a7bc0714f.png)

``` 
=>Static:  example> totalStudents isn't a property of Students class single object's property. SO we can make it static.
property is depending on CLASS not Objects.

=>(::)=> this is called scop resolution operator.

=>( this -> [it's called This pointer])=> Don't have for static function. or don't have access for static function.

==> CLASS::Property , example: int Student :: totalStudents = 0;

==> when create a new object then constructor will call automatically, so we can put [totalStudents] in the constructor
then [totalStudents] value will increate according to the code logic inside of constructor.

```

```cpp
 :: => this is called scop resolution operator.

// code in the class
static int totalStudents;	
Student() {
	totalStudents++;
}
static int getTotalStudent() { ====> This function depends on Class not Objects. SO we write static.
	return totalStudents;
}

// code outside of the Class or Main function
int Student :: totalStudents = 0;	// initialze static data members

// main function is accessing the static value from class 
cout << Student :: getTotalStudent() << endl; ==> using function
cout << Student :: totalStudents << endl; ===> using Variable

```

```cpp
#include <iostream>
using namespace std;

class Student {
	static int totalStudents; // total number of students present

	public :

	int rollNumber;
	int age;


	Student() {
		totalStudents++;
	}

	int getRollNumber() {
		return rollNumber;
	}

	static int getTotalStudent() {
		return totalStudents;
	}
};

int Student :: totalStudents = 0;	// initialze static data members

int main() {
	Student s1;

	Student s2;

	Student s3, s4, s5;

	// cout << Student :: totalStudents << endl;

	cout << Student :: getTotalStudent() << endl;

}

```

### Operator Overloading 1

``` 
replace return type void to CLASS name. becuase we are creating a object inside of function and set valu in it.
then it goes to the constructor as a new object value. then we can call the function for this object. we can write
(operator+) for F1+F2;

==> can use const in a function when its not chnaging in (this->) own property, by using own property can do some 
calculation and send it to other property using another function. thats why we can use const here. it won't affect 
in  our code; 

```

```cpp
--------------------------------------------------------------------------------------------
Fraction operator+(Fraction const &f2) const {
---------------------------------------------------------------------------------------------

Fraction operator+(Fraction const &f2) const {  
	-----------------------------------------------------
	==>can use const becuase its not chnaging in (this->) own property, by using own property we can do some 
	calculation and send it to other property. thats why we can use const here. 
	-----------------------------------------------------
	Fraction fNew(X, Y); ==> create new object and pass data inside the object.then alue will set using constructor.
	fNew.simplify(); ==> call simplify function for new fNew object.
	return fNew;
}
------------------------------------------------------------------------------------------------

bool operator==(Fraction const &f2) const {
	return (numerator == f2.numerator && denominator == f2.denominator);
}

------------------------------------------------------------------------------------------------
Fraction f3 = f1.add(f2);
Fraction f4 = f1 + f2;
------------------------------------------------------------------------------------------------

```

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

		Fraction add(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			Fraction fNew(num, lcm);
			fNew.simplify();
			return fNew;
		}

		Fraction operator+(Fraction const &f2) const {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			Fraction fNew(num, lcm); // create new object and pass data inside the object.
			fNew.simplify(); // call simplify function for fNew object.
			return fNew;
		}

		Fraction operator*(Fraction const &f2) const {
			int n = numerator * f2.numerator;
			int d = denominator * f2.denominator;
			Fraction fNew(n, d);
			fNew.simplify();
			return fNew;
		}

		bool operator==(Fraction const &f2) const {
			return (numerator == f2.numerator && denominator == f2.denominator);
		}


		void multiply(Fraction const &f2) {
			numerator = numerator * f2.numerator;
			denominator = denominator * f2.denominator;
			
			simplify();
		}
};


int main() {
	Fraction f1(10, 2);
	Fraction f2(15, 4);

	Fraction f3 = f1.add(f2);
	Fraction f4 = f1 + f2;
	f1.print();
	f2.print();
	f3.print();
	f4.print();

	Fraction f5 = f1 * f2;
	f5.print();

	if(f1 == f2) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not equal " << endl;
		
	}
}


```


### Operator Overloading 2

```cpp
------------------------------------------------------------------------------------------------

// Pre-increment
Fraction&  
==>> Here we are using ClassName insted of void becuase we want to store data in the ClassName Object. AND
in Pre-increment it will always create a new copy for storing the data if we use call by value. but we want to
increment more than once , for this reason we are using the refernce(&) key for passing the data/address. then
every time of increment the value will be change.  If don not use refernce(&) then f1= 6/1 AND f3= 7/1. using 
refernce(&) both are same.

------------------------------------------------------------------------------------------------

return *this; 
==>>  *this mean we are return the content of F1(in the code) or return the value to the same OBJECT. we do not
want to return the value of address, for this reason we use pointer(*) to get the value from this address.

------------------------------------------------------------------------------------------------

// Pre-increment
Fraction& operator++() {
	numerator = numerator + denominator;
	simplify();

	return *this;
}

------------------------------------------------------------------------------------------------

Fraction f3 = ++(++f1); ==>f1 Pre-increment then again Pre-increment the f1 Pre-incremented value.THEN store in F3.
f1.print();
f3.print();

------------------------------------------------------------------------------------------------
EXAMPLE--------1:
int i = 5;
int j = i++;
cout<< i << j <<endl; ==>ANSWER: i=6 & j=5, becuase we are firstly copying the value to the J then increment i;

EXAMPLE---------2:
int i = 5;
int j = ++i;
cout<< i << j <<endl; ==>ANSWER: i=6 & j=6,becuase we are firstly pre-increment i then copying the value to the J;

------------------------------------------------------------------------------------------------

```

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

		Fraction add(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			Fraction fNew(num, lcm);
			fNew.simplify();
			return fNew;
		}

		Fraction operator+(Fraction const &f2) const {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			Fraction fNew(num, lcm);
			fNew.simplify();
			return fNew;
		}

		Fraction operator*(Fraction const &f2) const {
			int n = numerator * f2.numerator;
			int d = denominator * f2.denominator;
			Fraction fNew(n, d);
			fNew.simplify();
			return fNew;
		}

		bool operator==(Fraction const &f2) const {
			return (numerator == f2.numerator && denominator == f2.denominator);
		}

		void multiply(Fraction const &f2) {
			numerator = numerator * f2.numerator;
			denominator = denominator * f2.denominator;
			
			simplify();
		}

		// Pre-increment
		Fraction& operator++() {
			numerator = numerator + denominator;
			simplify();

			return *this;
		}
};


int main() {
	Fraction f1(10, 2);
	Fraction f2(15, 4);

	f1.print();
	Fraction f3 = ++(++f1);
	f1.print();
	f3.print();

	//++f1;
	//f1.print();
}

```

### Operator Overloading 3

![image](https://user-images.githubusercontent.com/57065763/172013823-a8e247d5-e50a-4ec4-8aea-b685559e8aef.png)
![image](https://user-images.githubusercontent.com/57065763/172013897-9431b405-8582-423e-8573-f88430fb0770.png)


```cpp
------------------------------------------------------------------------------------------------
==>>The postfix version of the increment operator takes a dummy int parameter in order to disambiguate:

// prefix
CSample& operator++()
{
  // implement increment logic on this instance, return reference to it.
  return *this;
}

// postfix
CSample operator++(int)
{
  CSample tmp(*this);
  operator++(); // prefix-increment this instance
  return tmp;   // return value before increment
}
------------------------------------------------------------------------------------------------

(i++)++ ==>> its not possible, because nesting increment are not allow in post-increment.

(i += j) += j; ===> This is possible. SO we can do nested post-increment using this formula.

(+=) ==>> need to create overloading function for it.

int j= i++; ==> for this we need to crate new object. then pass i value to the Objects of J. becuase first copy
then increment the data of i Object.

int j= ++i; ==> Here i will increment then send data to the  J. So, we can use refernce and get value j to i.

int j= ++(++i); || (f1 += f2) += f2; ==> it is possible, return type should be ClassName. store (++i) value in a 
New object and return the object. then increment the object again. 

------------------------------------------------------------------------------------------------
Fraction fNew(n, d);|
fNew.simplify();	|==>>create a new object, then simplify AND return it with ClassName return type not void.
return fNew;		|

return *this; ==>> The all property of the (this) object will be return. 
------------------------------------------------------------------------------------------------

```

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

		Fraction add(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			Fraction fNew(num, lcm);
			fNew.simplify();
			return fNew;
		}

		Fraction operator+(Fraction const &f2) const {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			Fraction fNew(num, lcm);
			fNew.simplify();
			return fNew;
		}

		Fraction operator*(Fraction const &f2) const {
			int n = numerator * f2.numerator;
			int d = denominator * f2.denominator;
			Fraction fNew(n, d);
			fNew.simplify();
			return fNew;
		}

		bool operator==(Fraction const &f2) const {
			return (numerator == f2.numerator && denominator == f2.denominator);
		}

		void multiply(Fraction const &f2) {
			numerator = numerator * f2.numerator;
			denominator = denominator * f2.denominator;
			
			simplify();
		}

		// Pre-increment
		Fraction& operator++() {
			numerator = numerator + denominator;
			simplify();

			return *this;
		}

		// Post-increment
		Fraction operator++(int) {
			Fraction fNew(numerator, denominator);
			numerator = numerator + denominator;
			simplify();
			fNew.simplify();
			return fNew;
		}

		Fraction& operator+=(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			numerator = num;
		  	denominator = lcm;
			simplify();

			return *this;
		}
};

int main() {

	int i = 5, j = 3;
	(i += j) += j;

	cout << i << " " << j << endl;

	Fraction f1(10, 3);
	Fraction f2(5, 2);

	(f1 += f2) += f2;

	f1.print();
	f2.print();

}

```
### Dynamic Array Class

```cpp
------------------------------------------------------------------------------------------------
int *data; ==>> declare in private class Fraction
data = new int[5]; ==>> initialze in public class

this -> data = new int[d.capacity]; ==>> create array for deep copying
------------------------------------------------------------------------------------------------
// Deep copy
this -> data = new int[d.capacity]; | ==>> here is Deep copy, created a new array of inpyt size.

------------------------------------------------------------------------------------------------

this -> data = new int[d.capacity];   ==>> Then sending all data from old Array to a New Array.
for(int i = 0; i < d.nextIndex; i++) {
	this -> data[i] = d.data[i];
}
	
------------------------------------------------------------------------------------------------

int *newData = new int[2 * capacity];  ==> when input index become >capacity, then capacity make double. 2* gun. 
for(int i = 0; i < capacity; i++) {
	newData[i] = data[i]; ==>> store old data to newData
}

----------------------------------------------------------

delete [] data; ==>> Delete Old data & Array
data = newData; ==> data is pointing to the newData Address.
capacity *= 2;

------------------------------------------------------------------------------------------------

if(i < nextIndex) { ==>> if i< nextIndex then it will show the data. only valid i will work here.
	return data[i];
}

------------------------------------------------------------------------------------------------

if(i < nextIndex) {
	data[i] = element;
}
else if(i == nextIndex) { ==>> If i is become qual to nextIndex size then we will add the value in the array.
	add(element);
}
else {
	return; ==> If i > nextIndex, then it will not return anything.
}
------------------------------------------------------------------------------------------------
DynamicArray d2(d1);		// Copy constructor
DynamicArray d3;
d3 = d1; //  inbuilt copy assignment operator.
==> In shallow copy, it does not copy the value of the specified object value. it just copy object addess.so its 
bad practice.It also happen for inbuilt copy constructor.(ex:CN d1(d2)) && inbuilt copy assignment operator(d1=d2).
SO always we have to create a deep copy.
------------------------------------------------------------------------------------------------

```

```cpp
#include <iostream>
using namespace std;

class DynamicArray {
	int *data;
	int nextIndex;
	int capacity;			// total size

	public :

	DynamicArray() {
		data = new int[5];
		nextIndex = 0;
		capacity = 5;
	}

	DynamicArray(DynamicArray const &d) {
		//this -> data = d.data;		// Shallow copy
		
		// Deep copy
		this -> data = new int[d.capacity];
		for(int i = 0; i < d.nextIndex; i++) {
			this -> data[i] = d.data[i];
		}
		this -> nextIndex = d.nextIndex;
		this -> capacity = d.capacity;
	}

	void operator=(DynamicArray const &d) {
		this -> data = new int[d.capacity];
		for(int i = 0; i < d.nextIndex; i++) {
			this -> data[i] = d.data[i];
		}
		this -> nextIndex = d.nextIndex;
		this -> capacity = d.capacity;
	}


	void add(int element) {
		if(nextIndex == capacity) {
			int *newData = new int[2 * capacity];
			for(int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			delete [] data;
			data = newData;
			capacity *= 2;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	int get(int i) const {
		if(i < nextIndex) {
			return data[i];
		}
		else {
			return -1;
		}
	}

	void add(int i, int element) {
			if(i < nextIndex) {
				data[i] = element;
			}
			else if(i == nextIndex) {
				add(element);
			}
			else {
				return;
			}
	}

	void print() const {
		for(int i = 0; i < nextIndex; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
};


int main() {
	DynamicArray d1;

	d1.add(10);
	d1.add(20);
	d1.add(30);
	d1.add(40);
	d1.add(50);
	d1.add(60);

	d1.print();

	DynamicArray d2(d1);		// Copy constructor

	DynamicArray d3;

	d3 = d1;

	d1.add(0, 100);

	d2.print();
	d3.print();
}

```


### SOME Short quesiton:


#### Q-1.  What will be the output of the following code ?

What will be the output of the following code ?

```cpp
#include <iostream>
using namespace std;

class Student{
    public :
        char *name;
        int rollNo;

        void print(){
            cout << name << " "  <<  rollNo << " ";
        }
};

int main() {
    char name[] = "Misha";
    Student s1;
    s1.name = name;
    s1.rollNo = 101;

    name[0] = 'N';
    Student s2;
    s2.name = name;
    s2.rollNo = 102;

    s1.print();
    s2.print();
}

==> ANSWER: Nisha 101 Nisha 102 ==>> Because of the shallow copy.

```
#### Q-2.  What will be the output of the following code ?

What will be the output of the following code ?

```cpp
----------------------------------------------------------------
Student(int r, int a) : rollNumber(r), age(a) 
--------------------------------------------------------------
#include <iostream>
using namespace std;

class Student {
    public :

    const int rollNumber;
    int age;

    Student(int r, int a) : rollNumber(r), age(a) { ==>>use can value in const variable using that kind of system.
    }
};


int main() {
    Student s1(100, 23);
    cout << s1.rollNumber << " " << s1.age;
}

==> ANSWER: 100 23 ==> this quesiton is about how to send data in a const variable.

```
#### Q-3.  What will be the output of the following code ?

What will be the output of the following code ?

```cpp
class Student {
    public :

    int rollNumber;
    int age;

};


int main() {
    Student s1;

    Student const s2 = s1;

    s1.rollNumber = 101;
    s1.age = 20;

    cout << s2.rollNumber << " " << s2.age;
}

==> ANSWER: Garbage Garbage | ==>> Because S2 is initialize before passing data in S1. const doesn't matter.

```
#### Q-4 .  What will be the output of the following code ?

What will be the output of the following code ?

```cpp
class Student {
    int rollNumber;

    public :

    int age;

    Student(int r) {
        rollNumber = r;
    }

    int getRollNumber() {
        return rollNumber;
    }

};


int main() {
    Student s1(101);
    s1.age = 20;

    Student const s2 = s1;
    cout << s2.getRollNumber();
}

==> ANSWER: ERROR. WHY? ==>> if i want to access s2.getRollNumber(); then I have to make this function const. becuase
the S2 object is const.most of the time we can do print() or geting function const to make access for all kind objects.

```
#### Q-5 .  What will be the output of the following code ?

What will be the output of the following code ?

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Student {
    public :

    int rollNumber;
    static int totalStudents;
};

int Student::totalStudents = 20;

int main() {
    Student s;
    // Correct statement to access totalStudents
}

==> ANSWER: cout << Student :: totalStudents << endl;

```
#### Q-6 .  What will be the output of the following code ?

What will be the output of the following code ?

```cpp
class Student {
    public :

    int rollNumber;
    static int totalStudents;

    Student() {
        totalStudents++;
    }
};

int Student::totalStudents = 20;

int main() {
    Student s1, s2, s3, s4;
    cout << Student :: totalStudents;
}

==> ANSWER: 24

```

#### some basic:

What will be the output of the following code ?

```cpp
class Student {
       static int rollNumber;
    public :

    static int getRollNumber() {
        return rollNumber;
    }
};

int Student::rollNumber = 101;
int main() {
	// 1st way
    Student s;
    cout << s.getRollNumber() << endl;

	//2nd way
	cout << Student::getRollNumber() << endl;
}



==> Here we write,[ static int rollNumber] for static function, if we don't declare variable as a static then we can't
access if from static function.

```

### Code : Polynomial Class:

```

Implement a polynomial class, with the following properties and functions.
Properties :
1. An integer array (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as 
coefficient of ith degree.
2. An integer holding total size of array A.
Functions :
1. Default constructor
2. Copy constructor
3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity
 of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is within
  limits, then previous coefficient value is replaced by given coefficient value
4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more
 clarity, refer sample test cases


Input Format :
Line 1 : N, total number of terms in polynomial P1
Line 2 : N integers representing degree of P1 (separated by space)
Line 3 : N integers representing coefficients of P1 (separated by space)
Line 4 : M, total number of terms in polynomial P2
Line 5 : M integers representing degree of P2 (separated by space)
Line 6 : M integers representing coefficients of P2 (separated by space)
Line 7 : Integer C, choice representing the function to be called (See main for more details)

Sample Input 1 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
1


Sample Output 1 :
4x0 3x1 -3x2 3x3 -4x5
Sample Input 2 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
2


Sample Output 2 :
-4x0 -1x1 3x2 1x3 -4x5


Sample Input 3 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
3

Sample Output 3 :
4x1 2x2 5x3 5x4 -22x5 -6x6 12x7 -4x8

```

```cpp

/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial {
    
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    
    Polynomial(){
        this->degCoeff=new int[6];
        this->capacity=5;
    }
    //Making paramaterized constructor for defining with capacity
    Polynomial (int capacity){
        this->degCoeff=new int[capacity+1];
        this->capacity=capacity;
    }
    
    Polynomial (Polynomial const &p){
        int *newdeg=new int[p.capacity+1];
            
        for(int i=0;i<=p.capacity;i++)
            newdeg[i]=p.degCoeff[i];
            
        this->degCoeff=newdeg;
        
        this->capacity=p.capacity;
    }
    
    void setCoefficient(int deg,int coef){
        if(deg>capacity){
            int newcapacity=deg;
            int *newdeg=new int[newcapacity+1];
            //Copy the contents from original to new
            for(int i=0;i<=capacity;i++)
                newdeg[i]=degCoeff[i];
            
            this->degCoeff=newdeg;
            this->capacity=newcapacity;
            //Set the new coeff;
            degCoeff[deg]=coef;
        }
        else{
            degCoeff[deg]=coef;
        }
    }
    
    Polynomial operator+(Polynomial const &P2){
        
        int newcap=max(this->capacity,P2.capacity);
        
        Polynomial P3(newcap);
        
        for(int i=0;i<=newcap;i++){
            if(i<=capacity && i<=P2.capacity)
                P3.degCoeff[i]=this->degCoeff[i]+P2.degCoeff[i];
            else if(i<=capacity)
                P3.degCoeff[i]=this->degCoeff[i];
            else 
                P3.degCoeff[i]=P2.degCoeff[i];
        }
        return P3;
    }
    
    Polynomial operator-(Polynomial const &P2){
        
        int newcap=max(this->capacity,P2.capacity);
        Polynomial P3(newcap);
        
        for(int i=0;i<=newcap;i++){
            if(i<=capacity && i<=P2.capacity)
                P3.degCoeff[i]=this->degCoeff[i]-P2.degCoeff[i];
            else if(i<=capacity)
                P3.degCoeff[i]=this->degCoeff[i];
            else 
                P3.degCoeff[i]=-P2.degCoeff[i];
        }
        return P3;
    }
    
    Polynomial operator*(Polynomial const &P2){

        int newcap=this->capacity+P2.capacity;
        Polynomial P3(newcap);
        
        for(int i=0;i<=this->capacity;i++){
            
            for(int j=0;j<=P2.capacity;j++){
                P3.degCoeff[i+j]+=this->degCoeff[i]*P2.degCoeff[j];
            }
        }
        return P3;
    }
    
    void operator=(Polynomial const &p){
        int *newdeg=new int[p.capacity+1];
        //Copy the contents
        for(int i=0;i<p.capacity;i++)
            newdeg[i]=p.degCoeff[i];
            
        this->degCoeff=newdeg;
        this->capacity=p.capacity;
    }
    
    void print(){
        
        for(int i=0;i<=this->capacity;i++){
            if(degCoeff[i]!=0)
                cout<<degCoeff[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }        
};

//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }

    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }       
    }    
    return 0;
}

```
```
==>MCQ START
```
![image](https://user-images.githubusercontent.com/57065763/171999156-cf0b7661-fd39-4881-b951-7e99b36f75fd.png)
![image](https://user-images.githubusercontent.com/57065763/171999171-5d8d5cac-cc4f-45ae-8b39-b105e2b7aeb1.png)
![image](https://user-images.githubusercontent.com/57065763/171999184-8587cb07-ed7a-432e-82e4-d1f399e5aa0c.png)
![image](https://user-images.githubusercontent.com/57065763/171999199-5715254d-98f5-44eb-9961-127c282f5a10.png)
![image](https://user-images.githubusercontent.com/57065763/171999204-644cbdf5-01ff-4bd0-acfa-9a85ad77a47b.png)
![image](https://user-images.githubusercontent.com/57065763/171999223-d1e920a5-4823-4af2-baa8-980d42c0cac1.png)
![image](https://user-images.githubusercontent.com/57065763/171999226-505c942b-54de-4c05-b9f8-591284d8799d.png)
![image](https://user-images.githubusercontent.com/57065763/171999233-f3458e8c-03eb-4563-b3b6-6b63c27530d5.png)
![image](https://user-images.githubusercontent.com/57065763/171999248-fa08f4b8-ea6b-40fb-8165-3233c1ce5504.png)
![image](https://user-images.githubusercontent.com/57065763/171999253-809942c2-d7b8-4045-b8b3-4a25e13dbadc.png)
![image](https://user-images.githubusercontent.com/57065763/171999259-a19ed9c5-ae5e-4816-84cb-895efde7f034.png)

```
==>MCQ END
```

### OPPS-2 END HERE

```cpp

OPPS-2 END HERE

```
 -->
