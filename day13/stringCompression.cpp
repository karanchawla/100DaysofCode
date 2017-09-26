#include <iostream>
#include <string> 

using namespace std;

string compress(string &str)
{
	size_t len = str.length();
	if(len<2)
		return str;

	string out("");
	int count = 1;
	for(size_t i = 1; i<len; ++i)
	{
		if(str[i-1] == str[i])
		{
			++count;
		}
		else
		{
			out += str[i-1];
			out += to_string(count);
			count = 1;
		}

		if(out.length() > len)
			return str;
	}

	out += str[len -1];
	out += to_string(count);
	if(out.length() > len)
		return str;

	return out;
}

int main()
{
	std::string str, out;
	std::cout << "Enter a string:\n";
	std::cin >> str;
	out = compress(str);
	if (str.compare(out)) 
	{
		std::cout << str << " can be compressed to " << out << std::endl;
	} else {
		std::cout << str << " can not be compressed\n";
	}
	return 0;
}