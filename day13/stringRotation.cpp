#include <iostream>
#include <string> 

using namespace std;

bool isRotation(string s1, string s2)
{
	size_t len1 = s1.length();
	size_t len2 = s2.length();

	if(len1 == 0 || len1 != len2)
		return false;

	string concat = s1 + s1;
	if(concat.find(s1) != string::npos)
		return true;
	else
		return false;
}

int main() {
	std::string s1, s2;
	std::cout << "Enter string 1 : ";
	std::cin >> s1;
	std::cout << "Enter string 2 : ";
	std::cin >> s2;
	if ( isRotation(s1, s2) ) {
		std::cout << "Yes! " << s2 << " is rotation of " << s1 << std::endl;
	} else {
		std::cout << "No! " << s2 << " is not a rotation of " << s1 << std::endl;
	}
	return 0;
}