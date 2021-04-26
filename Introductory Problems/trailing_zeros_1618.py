n = int(input())
cnt = 0
while n != 0:
    cnt, n = cnt + n//5, n//5
print(cnt)