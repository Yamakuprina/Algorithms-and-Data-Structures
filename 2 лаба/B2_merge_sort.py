def merge_sort(array, left_index, right_index):
    if left_index >= right_index:
        return

    middle = (left_index + right_index)//2
    merge_sort(array, left_index, middle)
    merge_sort(array, middle + 1, right_index)
    merge(array, left_index, right_index, middle)

def merge(array, left_index, right_index, middle):

    left_copy = array[left_index:middle + 1]
    right_copy = array[middle+1:right_index+1]

    left_copy_index = 0
    right_copy_index = 0
    sorted_index = left_index

    while left_copy_index < len(left_copy) and right_copy_index < len(right_copy):

        if left_copy[left_copy_index][0] <= right_copy[right_copy_index][0]:
            array[sorted_index] = left_copy[left_copy_index]
            left_copy_index = left_copy_index + 1
        else:
            array[sorted_index] = right_copy[right_copy_index]
            right_copy_index = right_copy_index + 1

        sorted_index = sorted_index + 1


    while left_copy_index < len(left_copy):
        array[sorted_index] = left_copy[left_copy_index]
        left_copy_index = left_copy_index + 1
        sorted_index = sorted_index + 1

    while right_copy_index < len(right_copy):
        array[sorted_index] = right_copy[right_copy_index]
        right_copy_index = right_copy_index + 1
        sorted_index = sorted_index + 1


fin = open("race.in",  "r")
fout = open("race.out", "w")

num = int(fin.readline())

A=[]
for i in range(num):
	A.append(fin.readline().split())

merge_sort(A, 0, len(A) - 1)

countrie = A[0][0]
fout.write("=== ")
fout.write(A[0][0])
fout.write(" ===\n")


for i in range(len(A)):

	if A[i][0] == countrie:
		fout.write(A[i][1])
		fout.write("\n")
	else:
		fout.write("=== ")
		fout.write(A[i][0])
		fout.write(" ===\n")
		fout.write(A[i][1])
		fout.write("\n")
		countrie = A[i][0]


fin.close()
fout.close()
