import unittest
from collections import Counter

#O(n)
def stringCompression(str1):
    dicty = dict(Counter(str1))
    result = []
    for x in sorted(dicty.keys()):
        temp = x + str(dicty[x])
        result.append(temp)
    result = ''.join(result)
    if(len(result)>len(str1)):
        return str1
    return result

class Test(unittest.TestCase):

    data = [('aabbccddd', 'a2b2c2d3'),('abc','abc')]

    def test_stringCompression(self):
        for test,solution in self.data:
            result = stringCompression(test)
            self.assertEqual(result,solution)

if __name__ == "__main__":
    unittest.main()
