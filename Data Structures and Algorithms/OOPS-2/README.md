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



<!-- 
### OPPS-2 END HERE

```cpp

OPPS-2 END HERE

``` -->