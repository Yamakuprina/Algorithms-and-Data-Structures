
def BinSearch_left(A, key, left, right):

	while right > left + 1:
		middle = (left + right) // 2
		if A[middle] < key:
			left = middle
		else:
			right = middle

	if A[right] == key:
		return right+1
	else:
		return -1

def BinSearch_right(A, key, left, right):

	while right > left + 1:
		middle = (left + right) // 2
		
		if A[middle] <= key:
			left = middle
		else:
			right = middle
		
	if A[right-1] == key:
		return right
	else:
		return -1


fin = open("binsearch.in",  "r")
fout = open("binsearch.out", "w")

instruction = fin.read().splitlines()

Array_len = int(instruction[0])
Array = list(map(int, instruction[1].split()))
Search_len = int(instruction[2])
Search = list(map(int, instruction[3].split()))

for i in range(Search_len):

	searched = BinSearch_left(Array, Search[i], -1, Array_len-1)
	fout.write(str(searched))
	fout.write(" ")
	
	searched = BinSearch_right(Array, Search[i], -1, Array_len)
	fout.write(str(searched))
	fout.write("\n")

fin.close()
fout.close()