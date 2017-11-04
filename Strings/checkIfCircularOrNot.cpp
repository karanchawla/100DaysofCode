#include <string> 
#include <iostream>
#include <vector>

using namespace std; 

bool isCircular(string &str)
{
	char dir = 'N';
	int x = 0;
	int y = 0;

	for(int i = 0; i < str.length(); i++)
	{
		switch(str[i])
		{
			case 'M':
				if(dir=='N')
					y++;
				else if(dir=='W')
					x--;
				else if(dir=='E')
					x++;
				else
					y--;
				break;
			case 'L':
				if(dir=='N')
					dir = 'W';
				else if(dir=='W')
					dir = 'S';
				else if(dir=='S')
					dir = 'E';
				else
					dir = 'N';
				break;
			case 'R':
				if(dir=='N')
					dir = 'E';
				else if(dir=='W')
					dir = 'N';
				else if(dir=='S')
					dir = 'W';
				else
					dir = 'S';
				break;
		}
	}

	return (!x && !y);
}

int main()
{
	string str = "MMRMMRMMRMM";

	cout << isCircular(str);


}