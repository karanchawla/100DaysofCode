#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

bool judgeSquareSum(int c) 
{
    int a = 0;
    int b = sqrt(c);
    
    while(a <= b){
        
        if(a*a + b*b == c)return true;
        else if(a*a + b*b > c)b--;
        else a++;
    }
    return false;
}   

int main()
{
	cout << judgeSquareSum(3);
}