import sys


n = int(input())

sys.setrecursionlimit(1000000)

dp: list = [None] * 1_000_001


def f(num):
    if num == 1:
        return 0

    if dp[num] != None:
        return dp[num]

    result = 1000001

    if num % 3 == 0:
        result = min(result, f(num // 3) + 1)

    if num % 2 == 0:
        result = min(result, f(num // 2) + 1)

    result = min(result, f(num - 1) + 1)

    dp[num] = result

    return dp[num]


print(f(n))
