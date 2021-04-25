mx, rn, last = 0, 0, None
for c in input():
    if c != last:
        mx, rn, last = max(mx, rn), 0, c
    rn += 1
print(max(mx, rn))