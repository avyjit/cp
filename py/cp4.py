t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    nums = [1 if x == '+' else -1 for x in s]

    print(abs(sum(nums)))
