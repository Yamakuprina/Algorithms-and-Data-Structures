
heap = []

def siftUp(index):
	global heap
	if index > 0:
		mother = (index - 1) // 2
		if heap[index][1] < heap[mother][1]:
			heap[index], heap[mother] = heap[mother], heap[index]
			siftUp(mother)

def siftDown(index):
	global heap
	child1 = 2 * index + 1
	child2 = 2 * index + 2
	ch = 0
	if child1 < len(heap) and child2 < len(heap):
		if heap[child1][1] < heap[child2][1]:
			ch = child1
		else:
			ch = child2
	elif child1 < len(heap):
		ch = child1
	elif child2 < len(heap):
		ch = child2
	else:
		return

	if heap[index][1] > heap[ch][1]:
		heap[index], heap[ch] = heap[ch], heap[index]
		siftDown(ch)


def decreaseKey(x):
	global heap
	for i in range(len(heap)):
		if heap[i][0] == x[0]:
			heap[i] = x
			siftUp(i)
			break

def insert(x):
	global heap
	heap.append(x)
	siftUp(len(heap) - 1)

def extractMin():
	global heap
	output = 0
	if len(heap) == 0:
		return 1000000001
	output = heap[0][1]
	heap[0][1] = 1000000001
	siftDown(0)
	return output

fin = open("priorityqueue.in",  "r")
fout = open("priorityqueue.out", "w")

instruction = fin.read().splitlines()

for i in range(len(instruction)):

	if 'push' in instruction[i]:

		inst = instruction[i].split()
		inst.pop(0)

		pair = []
		pair.append(i+1)
		pair.append(int(inst[0]))

		insert(pair)

	elif 'extract-min' in instruction[i]:

		result = extractMin()

		if result == 1000000001:
			fout.write("*")
			fout.write('\n')
		else:
			fout.write(str(result))
			fout.write('\n')

	elif 'decrease-key' in instruction[i]:

		inst = instruction[i].split()
		inst.pop(0)

		for i in range(len(inst)):
			inst[i] = int(inst[i])

		decreaseKey(inst)
	print(heap)

input()
fin.close()
fout.close()