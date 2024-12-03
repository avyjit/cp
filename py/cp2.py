n, k = map(int, input().split())
nums = [int(x) for x in input().split()]

matrix = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    for j in range(n):
        if bin(nums[i] ^ nums[j]).count('1') % 3 == 0:
            matrix[i][j] += 1

mod = 10**9 + 7

def matmul(m1, m2):
    res = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                res[i][j] += m1[i][k] * m2[k][j]
                res[i][j] %= mod

    return res

def matpow(m, p):
    if p == 0:
        return [[1 if i == j else 0 for j in range(n)] for i in range(n)]
    if p == 1:
        return m
    
    y = matpow(m, p // 2)
    res = matmul(y, y)

    if p % 2 == 1:
        res = matmul(res, m)
    
    return res

final = matpow(matrix, k+1)

for r in matrix:
    print(*r)

ans = 0
for i in range(n):
    for j in range(n):
        ans += final[i][j]
        ans %= mod

print(ans) 