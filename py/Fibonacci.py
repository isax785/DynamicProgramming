def fib_brute(n:int) -> int:
    if n <= 2: return 1
    return fib_brute(n-1) + fib_brute(n-2)

def fib_memo(n:int, memo:dict={}):
    if n in memo: return memo[n]
    if n <= 2: return 1
    memo[n] = fib_memo(n-1, memo=memo) + fib_memo(n-2, memo=memo)
    return memo[n]

def fib_tab(n:int):
    table = [0 for _ in range(n+2)]
    table[1] = 1
    for i in range(n):
        table[i+1] += table[i]
        table[i+2] += table[i]
        # print(i, table) # DEBUG  
    return table[n]

if __name__ == "__main__":
    print(fib_brute(10))
    print(fib_brute(20))
    print(fib_tab(10))
    print(fib_memo(1000))
