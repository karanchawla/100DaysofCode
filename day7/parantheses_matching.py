def is_matched(expression):
    pairs_dict = {'}': '{', ']': '[', ')': '('}
    stack = []
    for char in expression:
        if char in pairs_dict.values():
            stack.append(char)
        elif char in pairs_dict:
            if not stack or pairs_dict[char] != stack.pop():
                return False
    return not stack