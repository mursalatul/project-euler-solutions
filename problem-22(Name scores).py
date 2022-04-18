def nvalue(s):
    n = 0
    for i in s:
        n += (ord(i) - 64)
    return n


f = open("/home/mursalatul/PallobsData/Programming_related/online contest submission/online judge code collection/project-euler-solution/problem-22_names.txt")

listOfWords = f.readlines()[0].split(',')
listOfWords = list(map(lambda i: i.replace('"', ''), listOfWords))
listOfWords.sort()

score = 0
print(listOfWords)
for i, item in enumerate(listOfWords):
    nv = nvalue(item)
    score += ((i+1) * nv)
    

print("\nfinal score: ",score)

f.close()