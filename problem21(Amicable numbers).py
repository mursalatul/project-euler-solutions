import itertools

def divisors(n):
    return list(itertools.filterfalse(lambda x: n % x, range(1, n)))

res = []
for i in range(220, 10001):
    d_i = sum(divisors(i))
    i_d = sum(divisors(d_i))
    if i == i_d and d_i not in res and i_d not in res and d_i != i_d:
        res.append(d_i)
        res.append(i_d)
print(sum(res))
