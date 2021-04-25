n = int(input())
if n > 1 and n < 4:
    print('NO SOLUTION')
    exit()
ans = list()
for a, b in zip(range(n//2), range(n//2, n)):
    ans.append(b+1)
    ans.append(a+1)
if len(ans) != n:
    ans.append(n)
print(' '.join(map(str, ans)))