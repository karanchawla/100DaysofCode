#include <stack>
#include <iostream> 
#include <vector> 

using namespace std; 

int getMaxArea(vector<int> hist)
{
	int max_area = 0;
	int area_with_top = 0;
	int tp;
	stack<int> s;

	int i = 0;
	while(i < hist.size())
	{
		if(s.empty() || hist[s.top()] <= hist[i])
		{
			s.push(i++);
		}
		else
		{
			tp = s.top();
			s.pop();

			area_with_top = hist[s.top()]*(s.empty() ? i : i - s.top() - 1);

			if(max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	return max_area;
}

int main()
{
	std::vector<int> v = {6,2,5,4,5,1,6};
	cout << getMaxArea(v);
}