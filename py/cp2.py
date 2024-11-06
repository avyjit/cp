from bisect import bisect_left
from itertools import groupby
t = 1

for _ in range(t):
    n, m, k = map(int, input().split())

    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]

    ga = [len(list(g)) for k, g in groupby(a) if k == 1]
    gb = [len(list(g)) for k, g in groupby(b) if k == 1]

    def cmpute(xs, v):
        ans = 0
        for x in xs:
            if x >= v:
                ans += x - v + 1
        return ans

    print(ga, gb)

    seen = set()
    ans = 0

    for x in range(1, k+1):
        if k % x != 0:
            continue

        y = k // x

        if (x, y) in seen:
            continue

        seen.add((x, y))

        ans += cmpute(ga, x) * cmpute(gb, y)
    
    print(ans)



