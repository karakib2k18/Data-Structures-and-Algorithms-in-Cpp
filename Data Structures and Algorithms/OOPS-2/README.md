# ##OOPS-2

---

### Shallow and Deep Copy

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

### Initialisation List | Passing value in the Const Data type.

```cpp

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

```cpp
------------------------------------------------------------------------------------------------

(i++)++ ==>> its not possible, because nesting increment are not allow in post-increment.

(i += j) += j; ===> This is possible. SO we can do nested post-increment using this formula.

(+=) ==>> need to create overloading function for it.

int j= i++; ==> for this we need to crate new object. then pass i value to the Objects of J. becuase first copy
then increment the data of i Object.

int j= ++i; ==> Here i will increment then send data to the  J. So, we can use refernce and get value j to i.

int j= ++(++i); || (f1 += f2) += f2; ==> it is possible, return type should be ClassName. store (++i) value in a 
New object and return the object. then increment the object again. 


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
int *data;
data = new int[5];
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

<!-- 
### OPPS-2 END HERE

```cpp

OPPS-2 END HERE

``` -->