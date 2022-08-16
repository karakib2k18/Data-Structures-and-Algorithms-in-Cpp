```

Lecture 2: Dynamic Allocation START HERE

```

# ##Lecture 2: Dynamic Allocation 

---

//============>>>>>>>>>> Lecture 2: Dynamic Allocation Notes
[Lecture 2: Dynamic Allocation Notes.pdf](https://github.com/karakib2k18/Data-Structures-and-Algorithms-in-Cpp/files/9350328/Lecture.2.Dynamic.Allocation.Notes.pdf)

---

### Address Typecasting

```cpp
#include <iostream>
using namespace std;

int main() {
	int i = 65;
	char c = i;
	cout << c << endl;

	int * p = &i;
	char * pc = (char*)p;

	cout << p << endl;
	cout << pc << endl;

	cout << *p << endl;
	cout << *pc << endl;
	cout << *(pc + 1) << endl;
	cout << *(pc + 2) << endl;
	cout << *(pc + 3) << endl;
}
```
```
//output
A
0x7fff5d63d384
A
65
A
�
�
�
```

###   Reference and Pass By Reference 
```cpp
#include <iostream>
using namespace std;

void increment(int& i) {
	i++;
}

// bad practice
int& f(int n) {
	int a = n;
	return a;
}

// bad practice
int* f2() {
	int i = 10;
	return &i;
}

int main() {
	int* p = f2();

	int i;
	i = 10;

	int& k1 = f(i);


	increment(i);
	cout << i << endl;

	int& j = i;

	i++;
	cout << j << endl;
	j++;
	cout << i << endl;

	int k = 100;
	j = k;
	cout << i << endl;
}
```
```
//output
11
12
13
100
```

###Dynamic Memory Allocation

```cpp
#include <iostream>
using namespace std;

int main() {

	int *p = new int;
	delete p;

	p = new int;
	delete p;

	p = new int[100];
	delete [] p;

	/*
	while (true) {
		int *p = new int;
	}
	
	while (true) {
		int i = 10;
	}
*/

}
```

```cpp
#include <iostream>
using namespace std;

int main() {
	int * p = new int;
	*p = 10;
	cout << *p << endl;

	double *pd = new double;

	char* c = new char;

	int* pa = new int[50];
	int n;
	cout << "Enter num of elements" << endl; 
	cin >> n;

	int* pa2 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> pa2[i];
	}

	int max = -1;
	for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	cout << max << endl;
}

```
### Dynamic Allocation of 2D Arrays 

```cpp
#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	int** p = new int*[m];
	for (int i = 0; i < m; i++) {
		p[i] = new int[i + 1];
		for (int j = 0;j <n; j++) {
			cin >> p[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		delete [] p[i];
	}
	delete [] p;
}
```
### Macros and Global Variables 

```cpp
/*---------------Macros-----------*/
#include <iostream>
using namespace std;

int a;

void g() {
	a++;
	cout << a << endl;
}

void f() {
	cout << a << endl;
	a++;
	g();
}

int main() {
	a = 10;
	f();
	f();
	cout << a << endl;
}

/*-------------------define------------*/
#include <iostream>
using namespace std;
#define PI 3.14

int main() {

	int r;
	cin >> r;

	cout << PI * r * r << endl;

}

```

### Inline and Default Arguments

```cpp
/*-----------------default_arguments.cpp-----*/
#include <iostream>
using namespace std;

int sum(int a[], int size, int si = 0) {
	int ans = 0;
	for (int i = si; i < size; i++) {
		ans += a[i];
	}
	return ans;
}

int sum2(int a, int b = 0, int c = 0, int d = 0) {
	return a + b + c + d;
}

int main() {
	 int a[20];
	 // input code for a

	 cout << sum(a, 20) << endl;
}

/*---------inline.cpp-----------*/
#include <iostream>
using namespace std;

inline int max(int a, int b) {
	return (a > b)?  a : b;
}

int main() {
	int a, b;
	cin >> a >> b;

	int c = max(a, b);

	int x,y;
	x = 12;
	y = 34;

	int z = max(x, y);
}
```

### Constant Variables

```cpp
/*-------------CONST POINTER------------*/
#include <iostream>
using namespace std;

int main() {
	int i = 10;
	int j = 21;
	int const * p = &i;

	p = &j;

	int * const p2 = &i;
	(*p2)++;
	//p2 = &j;

	int const * const p3 = &i;
	p3 = &j;
	(*p3)++;
}


/*-------------CONST POINTER------------*/
#include <iostream>
using namespace std;

void g(int const & a) {
	a++;
}

void f(const int * p) {
}

int main() {
	int const i = 10;
	int const * p = &i;

	int j = 12;
	int* p3 = &j;
	f(p3);
	g(j);

	int const * p2 = &j;
	cout << *p2 << endl;
	j++;
	cout << *p2 << endl;
}

/*-------------CONST REFFERENCE------------*/
#include <iostream>
using namespace std;

int main() {
	// constant int
	const int i = 10;
	int const i2 = 10;
	
	// constant reference from a non const int
	int j = 12;
	const int & k = j;
	j++;

	cout << k << endl;

	// constant reference from a const int
	int const j2 = 12;
	int const &k2 = j2;

	// reference from a const int
	int const j3 = 123;
	int & k3 = j3;
	k3++;
}
```

### QUIZZZ
![image](https://user-images.githubusercontent.com/57065763/184858902-702f3727-6762-4f2b-aa92-eed8e0c6e862.png)
![image](https://user-images.githubusercontent.com/57065763/184859976-c3914ffa-7e14-4e4f-93f4-94206ba6216b.png)

```

Lecture 2: Dynamic Allocation END HERE

```
