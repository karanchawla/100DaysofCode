class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        string_list = s.split()
        result = ""
        for i, word in enumerate(string_list):
            word = word[::-1]
            if(i != len(string_list)-1):
                result = result + word + " "
            else:
                result = result + word

        return result

