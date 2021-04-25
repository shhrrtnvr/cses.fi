n = int(input())
sm = (n*n + n) // 2
if sm % 2 == 1:
    print("NO") 
    exit()
else:
    print('YES')

l = (list(), list())
sm //= 2
for i in range(n, 0, -1):
    if i > sm:
        l[0].append(i)
        continue
    l[1].append(i)
    sm -= i

for p in l:
    print(len(p))
    print(' '.join(map(str, p)))


