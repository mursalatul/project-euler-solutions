st = set([])
for i in range(2, 101):
    for j in range(2, 101):
        st.add(i ** j)
print(len(st))