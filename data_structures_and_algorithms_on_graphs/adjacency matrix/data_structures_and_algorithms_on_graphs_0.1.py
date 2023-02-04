inFile = open('input.txt', 'r')
outFile = open('output.txt', 'w')
lines = inFile.readlines()
inFile.close()
n_m = list(map(int, (lines[0]).split()))
a = []

for i in range(n_m[0]):
    b = []
    for j in range(n_m[0]):
        x = 0
        b.append(x)
    a.append(b)
    
for edge in lines[1:]:
    edge = list(map(int, edge.split()))
    a[edge[0] - 1][edge[1] - 1] = 1
    a[edge[1] - 1][edge[0] - 1] = 1
    print(a)

for i in range(n_m[0]):
    for j in range(n_m[0]):
        print(a[i][j], file=outFile, end=' ')
    print('\n', file=outFile, end='')
outFile.close()