
def insertion_sort(arr): 
    length = len(arr) 
    for i in range(1, length):
        key = arr[i]
        j = i
        while (j - 1 >= 0) and (arr[j - 1] > key):
            arr[j - 1], arr[j] = arr[j], arr[j - 1]
            j = j - 1
        arr[j] = key


fin = open("smallsort.in",  "r")
fout = open("smallsort.out", "w")

length = int(fin.readline())

A =list(map(int, fin.readline().split()))

insertion_sort(A)

for i in range(len(A)): 
	fout.write(str(A[i]))
	fout.write(" ")

fin.close()
fout.close()