inFile = open('input.txt', 'r')
outFile = open('output.txt', 'w')
inFile.readline()
numbers = list(map(int, inFile.readline().split()))
days = [numbers[0]]
for day in numbers[1:]:
    if day > days[-1]:
        days.append(day)
    elif day <= days[-1]:
        maxH = len(days) - 1
        minH = 0
        while minH + 1 < maxH:
            mid = (minH + maxH) // 2
            if days[mid] > day:
                maxH = mid
            elif days[mid] < day:
                minH = mid
            else:
                break
        else:
            while minH <= maxH:
                if days[minH] >= day:
                    days[minH] = day
                    break
                minH += 1
outFile.write(str(len(days)))
inFile.close()
outFile.close()