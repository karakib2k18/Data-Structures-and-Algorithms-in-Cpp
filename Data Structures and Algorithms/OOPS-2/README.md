# ##OOPS-2

---

### Shallow and Deep Copy

```cpp
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

// using Initialisation List we can pass value to the const variable or to the reference variable.
// here age(age), didn't write this->age(age) because it automatically indicating the variable.
//but here x(this -> age), if don't write (this->) then value will pass here but we want to indicate the age variable.
// x is referencing to the age variable.
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

### Constant Functions | Const Obj can call only const Functions, they can't call the normal functions.

```
==> what is const function? ANSWER: which function does not change any property of current object. And we can make 
getvalue and print functions const. becuase we don't need to change them. And normal & const property also can access
const function. but we can't write const on setvalue or other calculation function where main variable's value of 
private class will be change. We should make every geting and printing function const becuase it's best way and we 
don't need to do any inside of geting and printing function;
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

=>(::)=> this is called scop resolution operator.

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

// code outside of the Class or Main function
int Student :: totalStudents = 0;	// initialze static data members

// main function is accessing the static value from class 
cout << Student :: getTotalStudent() << endl;

```

```cpp
#include <iostream>
using namespace std;

class Student {
	static int totalStudents;		// total number of students present

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



<!-- 
### OPPS-2 END HERE

```cpp

OPPS-2 END HERE

``` -->