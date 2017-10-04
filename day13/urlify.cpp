#include <iostream>
#include <string> 

using namespace std;

void urlify(string &str, int len)
{
	int numOfSpaces = 0;
	int i =0, j= 0;

	for(i = 0; i< len; ++i)
	{
		if(str[i] == ' ')
		{
			++numOfSpaces;
		}
	}

	int extendedLen = len + 2*numOfSpaces;
	i = extendedLen - 1;
	for( j = len - 1; j >= 0; --j ) 
	{
        if ( str[j] != ' ' ) 
        {
           str[i--] = str[j];
        } else 
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }

}

int main()
{
    string phrase = "Mr John Smith    ";                       //String with extended length ( true length + 2* spaces)
    std::cout << "Actual string   : " << phrase << std::endl;
    urlify(phrase, 13);                                        //Length of "Mr John Smith" = 13
    std::cout << "URLified string : " << phrase << std::endl;
    return 0;
}