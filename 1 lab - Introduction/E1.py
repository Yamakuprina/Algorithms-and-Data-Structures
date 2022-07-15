
def insertion_sort(arr, arr2): 
    length = len(arr) 
    for i in range(1, length):
        key = arr[i]
        j = i
        while (j - 1 >= 0) and (arr[j - 1] > key):
            arr[j - 1], arr[j] = arr[j], arr[j - 1]
            arr2[j - 1], arr2[j] = arr2[j], arr2[j-1]
            j = j - 1
        arr[j] = key


fin = open("sortland.in",  "r")
fout = open("sortland.out", "w")

length = int(fin.readline())

A =list(map(float, fin.readline().split()))
B = [i+1 for i in range(length)]

insertion_sort(A, B)
 
fout.write(str(B[0]))
fout.write(" ")
fout.write(str(B[length//2]))
fout.write(" ")
fout.write(str(B[length-1]))
fout.write(" ")


fin.close()
fout.close()