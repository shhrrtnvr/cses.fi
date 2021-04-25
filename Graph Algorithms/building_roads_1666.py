import sys
input = sys.stdin.readline

def find(i):
    global p
    if p[i] == i:
        return i
    p[i] = find(p[i])
    return p[i]

def union(i, j):
    global p
    p[find(i)] = find(j)

n, m = map(int, input().split())
p = list(range(n))

for _ in range(m):
    union(*map(lambda x : int(x)-1, input().split()))

l = list()
for i, v in enumerate(p):
    if i==v:
        l.append(v)

print(len(l)-1)
for i in range(1, len(l)):
    print(l[i]+1, l[i-1]+1)
