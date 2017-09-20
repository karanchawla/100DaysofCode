import unittest
from collections import Counter

def oneEditAway(str1, str2):
    if(len(str1) == len(str2) + 1 or len(str2) == len(str1) + 1):
        result = dict(Counter(str1) - Counter(str2))
        for x in result.values():
            if x==1:
                return True
            else:
                return False
    else:
        return False

class Test(unittest.TestCase):

    listOne = [('pale'),('pales')]
    listTwo = [('ple'),('pale')]

    def testOneEditAway(self):
        for test_case, solution in zip(self.listOne,self.listTwo):
            result = oneEditAway(test_case, solution)
            self.assertTrue(result)

if __name__ == "__main__":
    unittest.main()

