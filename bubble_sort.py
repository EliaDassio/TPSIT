ar = [2, 3, 7, 8, 4, 6, 9, 1, 5, 0]

for j in range(0, len(ar)):
    for i in range(0, len(ar) - 1):
        if ar[i] > ar[i +1]:
            so = ar[i]
            ar[i] = ar[i + 1]
            ar[i + 1] = so

print(ar)