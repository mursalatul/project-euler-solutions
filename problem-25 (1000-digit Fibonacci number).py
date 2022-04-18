f1, f2 = 1, 1
indexOfLastFibo = 2
while True:
    f3 = f1 + f2
    indexOfLastFibo += 1
    if len(str(f3)) == 1000:
        break
    else:
        f1 = f2
        f2 = f3
print(indexOfLastFibo)