t = int(input())


for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]

    s = set(a)

    if len(s) != len(a):
        print("YES")
        continue 

    flag = False

    for x in a:
        for y in a:
            if x - y in s or y - x in s:
                flag = True
                break
    
    if flag:
        print("YES")
    else:
        print("NO")
