### Basic input/output in c++

Header files in C++ for IO:
1. iostream - cin, cout, cerr
2. iomanip - setw, setprecision
3. fstream - handle data from files

### C++ preprocessors
1. Source code file -> Expanded source code file -> object code ->
exectuable file
2. 4 main types of preprocessor directives:
  1. Macros
    1. eg: #define LIMIT 5
    2. eg: #define AREA(l,b) (l*b)
  2. File inclusion
    1. #include <file_name>
    2. #include "file_name"
  3. Conditional compilation
    1. ifdef macro_name do this endif
  4. Other directives
    1. #undef LIMIT
    2. #pragma

### Operators in CPP
1. Arithmetic ops (+,-,*,/)
2. Relational ops
3. Logical ops
4. Bitwise ops - TODO bitlevel manipulation from CTCI
5. Asignment =, +=,-=,/=,*=
6. Others such as sizeof(), conditional: exp1 ? exp2 : exp3

Assigning values without using if else is by storing the values in
an array. if x = 0, take one value else take the other value.

### Arrays in CPP
1. Declaration:
int a[] = {1,2,3};
int a[6] = {1,2,3};

- Intializing with more elements that the asigned space- compiler error

- No bounds checking

### Arrays of strings
1. Using string keyword
string colored[4] = {"Blue", "Red", "Orange", "Grey"};
2. Using vectors of strings
- vector<string> color;
- color.push_back("blue");

### Multidimensional arrays in cpp
1. int x[3][4] = {{0,1,2,3},{0,1,2,3},{0,1,2,3}};

### Counts of distinct consecutive sub string of length two
```
#include <algorithm>
#include <string>
#include <map>
#include <utility>

void printDistinctSubstrings(string str)
{
  map<pair<char,char>, int> dPairs;

  for(int i=0; i<str.size()-1; ++i)
  {
    dPairs[make_pair(str[i],str[i+1])]++;
  }
  cout << "Distinct sub-strings with counts:\n";
  for (auto it=dPairs.begin(); it!=dPairs.end(); it++)
    cout << it->first.first << it->first.second
         << "-" << it->second << " ";
}
```

### Pair in CPP STL
1. Pair is used to combine together two values which may be different in type.
2. eg:
```
//CPP program to illustrate pair in STL
#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main()
{
    pair <string, int> g1;
    pair <string, int> g2("Quiz", 3);
    pair <string, int> g3(g2);
    pair <int, int> g4(5, 10);

    g1 = make_pair(string("Geeks"), 1);
    g2.first = ".com";
    g2.second = 2;

    cout << "This is pair g" << g1.second << " with "
        << "value " << g1.first << "." << endl << endl;

    cout << "This is pair g" << g3s.econd
        << " with value " << g3.first
        << "This pair was initialized as a copy of "
        << "pair g2" << endl << endl;

    cout << "This is pair g" << g2.second
        << " with value " << g2.first
        << "\nThe values of this pair were"
        << " changed after initialization."
        << endl << endl;

    cout << "This is pair g4 with values "
        << g4.first << " and " << g4.second
        << " made for showing addition. \nThe "
        << "sum of the values in this pair is "
        << g4.first+g4.second
        << "." << endl << endl;

    cout << "We can concatenate the values of"
        << " the pairs g1, g2 and g3 : "
        << g1.first + g3.first + g2.first << endl << endl;

    cout << "We can also swap pairs "
        << "(but type of pairs should be same) : " << endl;
    cout << "Before swapping, " << "g1 has " << g1.first
        << " and g2 has " << g2.first << endl;
    swap(g1, g2);
    cout << "After swapping, "
        << "g1 has " << g1.first << " and g2 has " << g2.first;

    return 0;
}
```
3. If not initialized, values are automatically initialized.
4. Member functions
make_pair(): Allows to create a value pair without writing the
types explicitly.
`pair_name = make_pair(v1, v2);`
5. operators (=,<,>,!=)
== checks for AND condition

### Vector in STL
1. begin() – Returns an iterator pointing to the first element
2. end() – Returns an iterator pointing to the theoretical element that follows last element
3. rbegin() – Returns a reverse iterator pointing to the last element
4. rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element
5. size() - returns the size
6. empty() - returns whether the container is empty or not
7.front() = first element
8. back() - last element
9. at(g) - returns element at position g

### Ways of copying a vector in CPP
1. Iterative method
2. Assignment operator
3. By passing vector as a constructor
4. copy(v1.begin(), v1.end(), back_inserter(v2))
5. v2.assign(v1.begin(), v1.end())


### Sort the first row
sort(v1[0].begin(), v1[0].end())


### Strings
1. A char array is simply an array terminated by null char. A string is a class which defines objects that are represented as stream
of chars. 
2. Memory allocated dynamically. 
3. input functions: 
    1. getline(cin, str) 
    2. push_back('<insert some char>')
    3. pop_back('<removes last char from the string>')
    4. str.capacity() - indicates the capacity allocated for the string
    5. str.resize()
    6. str.shrink_to_fit()
    7. begin(), end(), rbegin(), rend()
    8. copy("char array", len, pos) -> this function copies the substring in target char array mentioned in its args. 
    9. str1.swap(str2) - swaps one string with another. 