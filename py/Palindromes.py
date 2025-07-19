def longest_palindrome(s:str):
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

def longest_palindrome_center(s:str):
    # FIXME: it does not work!!!
    " Given a string s, find the longest palindromic substring in s by expanding around the center. "
    n = len(s)
    start = 0
    max_len = 1 if n > 0 else 0
    for i in range(n):
        l = i - 1
        r = i
        while all([l >=0,
                   r < n,
                   s[l] == s[r]]):
            if (r - l + 1 > max_len):
                max_len = r - l + 1
                start = l
            l -= 1
            r += 1
        l = i - 1
        r = i + 1
        while all([l >= 0,
                   r < n,
                   s[l] == s[r]]):
            if (r - l + 1 > max_len):
                max_len = r - l + 1
                start = l
            l -= 1
            r += 1
    if max_len == 0:
        return ''
    return s[start:max_len]


if __name__ == "__main__":
    print(longest_palindrome("babad"))
    print(longest_palindrome_center("babad"))