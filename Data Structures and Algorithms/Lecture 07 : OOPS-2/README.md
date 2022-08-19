```

Lecture 07 : OOPS-2 START HERE

```

# ##OOPS-2

---
//============>>>>>>>>>> Lecture 07 : OOPS-2
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
![image](https://user-images.githubusercontent.com/57065763/185598745-154942a5-2f85-4478-a9b9-07155892fe9c.png)

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
![image](https://user-images.githubusercontent.com/57065763/185601237-b643620e-80c9-4d2c-baea-4d563125bfc5.png)

```
==>MCQ END
```

```

Lecture 07 : OOPS-2 END HERE

```