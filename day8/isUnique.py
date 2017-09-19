from collections import Counter
import unittest

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

class Test(unittest.TestCase):

	dataT = [('abcd'), ('s4fad'), ('')]
	dataF = [('23ds2'), ('hb 627jh=j ()')]

	def test_unique(self):
		# true check
		for test_string in self.dataT:
			actual = isUnique(test_string)
			self.assertTrue(actual)
        # false check
		for test_string in self.dataF:
			actual = isUnique(test_string)
			self.assertFalse(actual)

if __name__ == "__main__":
    unittest.main()