from collections import Counter

def isUnique(s):
	s = s.lower()
	dicty = dict(Counter(s))
	for char in dicty.keys():
		if dicty[char] > 1:
			return False

	return True

def isUniqueBrute(s):
	s = s.lower()
	for i in range(len(s)):
		for j in range(i+1,len(s)):
			if(s[j] == s[i]):
				return False

	return True

def isUniqueOptim(s):
	s = s.lower()
	s = sorted(s)
	for i in range(len(s)-1):
		if(s[i]==s[i+1]):
			return False

	return True

s = "abcdefgh"

print(isUniqueOptim(s))