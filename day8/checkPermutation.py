from collections import Counter
import unittest

def checkPermutations(str1, str2):
	if(len(str1)!=len(str2)): return False

	if (len(list(Counter(str1) - Counter(str2)))) == 0:
		return True
	else:
		return False

class Test(unittest.TestCase):
    dataT = (
        ('abcd', 'bacd'),
        ('3563476', '7334566'),
        ('wef34f', 'wffe34'),
    )
    dataF = (
        ('abcd', 'd2cba'),
        ('2354', '1234'),
        ('dcw4f', 'dcw5f'),
    )

    def test_cp(self):
        # true check
        for test_strings in self.dataT:
            result = checkPermutations(*test_strings)
            self.assertTrue(result)
        # false check
        for test_strings in self.dataF:
            result = checkPermutations(*test_strings)
            self.assertFalse(result)


if __name__ == "__main__":
    unittest.main()
