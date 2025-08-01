def longest_palindrome_center(s:str) -> tuple[str, int]:
    """ searching for longest palindromic substring
     starting from its CENTRAL character
     return:
     - sub: str, substring
     - size: int, substring length
     """
    n = len(s)
    size = 0 if n == 0 else 1
    start = 0
    for i in range(n):
        # odd
        l = max(0, i-1)
        r = min(i+1, n-1)
        while l >= 0 and r < n and s[l] == s[r]:
            size_temp = r - l + 1
            if size < size_temp:
                size = size_temp
                start = l
            l -= 1
            r += 1
        # even
        l = max(0, i)
        r = min(i+1, n-1)
        while l >= 0 and r < n and s[l] == s[r]:
            size_temp = r - l + 1
            if size < size_temp:
                size = size_temp
                start = l
            l -= 1
            r += 1
    sub = s[start:start+size]
    return sub, size


def longest_palindrome_first(s:str) -> tuple[str, int]:
    """ searching for longest palindromic substring
     starting from its FIRST character
     return:
     - sub: str, substring
     - size: int, substring length
     """
    n = len(s)
    size = 0 if n == 0 else 1
    start = 0
    for i in range(n-1):
        for j in range(i+1, n):
            if s[i] == s[j]:  # first and last characters are equal
                pal = True
                for k in range(j-i):
                    if s[i+k] != s[j-k]:
                        pal = False
                if pal:
                    size_temp = i - j + 1
                    if size < size_temp:
                        size = size_temp
                        start = i
    sub = s[start:start+size]
    return sub, size


def ext_longest_palindrome(s:str):
    " Given a string s, find the longest palindromic substring in s.  "
    n = len(s)
    max_len = 0
    if n == 0: return ''

    dp = [[False for _ in range(n)] for _ in range(n)]

    for i in range(n): dp[i][i] = True

    for i in range(n-1):
        dp[i][i+1] = s[i] == s[i+1]

    for i in range(n-1, -1, -1):
        for j in range(i+2, n):
            dp[i][j] = dp[i+1][j-1] and s[i] == s[j]
    
    for i in range(n):
        for j in range(i, n):
            if (dp[i][j] and j - i + 1 > max_len):
                max_len = j - i + 1
                start = i
    
    return s[start:max_len]

def ext_longest_palindrome_center(s:str):
    " Given a string s, find the longest palindromic substring in s by expanding around the center. "
    n = len(s)
    start = 0
    max_len = 1 if n > 0 else 0
    for i in range(n):
        # even number of letters
        l, r = i - 1, i
        while l >= 0 and r < n and s[l] == s[r]:
            if (r - l + 1 > max_len):
                max_len = r - l + 1
                start = l
            l -= 1
            r += 1
        # odd number of letters
        l, r = i - 1, i + 1
        while l >= 0 and r < n and s[l] == s[r]:
            if (r - l + 1 > max_len):
                max_len = r - l + 1
                start = l
            l -= 1
            r += 1
    if max_len == 0:
        return ''
    return s[start:max_len]


if __name__ == "__main__":
    strings = ["babad", "akjsfdhoierbghbwivrhawewafhajksdfhgirvuqhiceu"]
    for s in strings:
        print(ext_longest_palindrome(s))
        print(ext_longest_palindrome_center(s))
        print(longest_palindrome_first(s))
        print(longest_palindrome_center(s))