t = int(input())

def solve(a):
    maxval = 0
    seen = set()
    def ways(arr, val):
        nonlocal maxval
        if tuple(arr) in seen:
            return
        seen.add(tuple(arr))

        if len(arr) == 1:
            val += arr[0]
            maxval = max(maxval, val)
            return
        
        for i in range(len(arr)):
            nval = a[i]*a[i+1] if i < len(arr)-1 else a[i]
            old = arr.pop(i)
            ways(arr, val+nval)
            arr.insert(i, old)
    
    ways(a, 0)
    return maxval

for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    
    ans = solve(a)
    print(ans)


#print(*range(1, 201))
