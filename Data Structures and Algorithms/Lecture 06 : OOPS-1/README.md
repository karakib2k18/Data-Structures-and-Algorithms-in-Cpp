```

Lecture 06 : OOPS-1  START HERE

```
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
![image](https://user-images.githubusercontent.com/57065763/185500141-9dd2f54f-aba2-418f-b20e-6bc3606f4819.png)

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

![image](https://user-images.githubusercontent.com/57065763/185591283-2f659b49-2a33-4302-a45b-fe9d6c500fef.png)

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
### QUIZ:
![image](https://user-images.githubusercontent.com/57065763/185595733-3e18cd56-4f20-4ce9-b07b-856ac55e2f3a.png)

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

```

Lecture 06 : OOPS-1  END HERE

```