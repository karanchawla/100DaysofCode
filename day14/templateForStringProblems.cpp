// For most string problems, we are given a string and need to find a substring of it which satisies some conditions. A general way is to use a hashmap assisted with two pointers.
// A template is given below. 

int findSubstring(string s)
{
	vector<int> map(128,0);
	int counter = 0; // Check whether the substring is valid
	int begin = 0, end = 0; // two poiunters one point to tail and one to head
	int d; // the length of substring

	for() { /*intialize hashmap here */}

	while(end < s.size())
	{
		if(map[s[end++]]-- ? ){/* modify counter here*/}

		/* update d here if finding minimum */

		// increase begin to make it invalid/valid again

		if(map[s[begin++]]++ ? ){/* modify counter here */ }
	}

	// update d here if finding maximum

}