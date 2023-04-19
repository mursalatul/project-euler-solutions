s = 0
for i in range(1, 1001):
    p = pow(i, i)
    s += p

num = 0
i = 1
for _ in range(10):
    num += i * (s % 10)
    i *= 10
    s //= 10
print(num)