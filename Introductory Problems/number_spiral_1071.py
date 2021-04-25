for _ in range(int(input())):
    x, y = map(int, input().split())
    b = max(x, y)
    if b % 2 == 1:
        x, y = y, x
    ans = (b-1)**2
    if b == x:
        ans += (b-y)
    print(ans+x)