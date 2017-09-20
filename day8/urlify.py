import unittest

# First Solution
# Time Complexity: O(n)
# Space Complexity: O(n)
def urlify(s):
    listy = s.strip().split(' ')
    result = []
    for word in listy:
        if(word != listy[-1]):
            word = word + '%20'
        else :
            word = word
        result.append(word)
    result = ''.join(result)
    return result

class Test(unittest.TestCase):

    data = [(('Mr John Smith    '), ('Mr%20John%20Smith'))]

    def test_urlify(self):
        for [test_string, expected] in self.data:
            result = urlify(test_string)
            self.assertEqual(result, expected)

if __name__ == '__main__':
    unittest.main()
