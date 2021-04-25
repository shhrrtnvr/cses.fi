n = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(1, len(A)):
    ans += max(0, A[i-1]-A[i])
    A[i] = max(A[i], A[i-1])
print(ans)