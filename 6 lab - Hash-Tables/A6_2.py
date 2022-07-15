
dictionary = []

def hash(x):
	h = x % 32
	return h
"""
def insert(x):
	global dictionary
	if [hash(x), x] not in dictionary:
		dictionary.append([hash(x), x])

def exists(x):
	global dictionary
	if [hash(x), x] in dictionary:
		return "true"
	elif [hash(x), x] not in dictionary:
		return "false"

def delete(x):
	global dictionary
	if [hash(x), x] in dictionary:
		dictionary.remove([hash(x), x])
"""

fin = open("set.in",  "r")
fout = open("set.out", "w")

instruction = fin.read().splitlines()

for i in range(len(instruction)):

	if 'insert' in instruction[i]:

		inst = instruction[i].split()
		if [hash(int(inst[1])), int(inst[1])] not in dictionary:
			dictionary.append([hash(int(inst[1])), int(inst[1])])

	elif 'exists' in instruction[i]:

		inst = instruction[i].split()
		if [hash(int(inst[1])), int(inst[1])] in dictionary:
			 fout.write("true")
		elif [hash(int(inst[1])), int(inst[1])] not in dictionary:
			fout.write("false")
		fout.write("\n")

	elif 'delete' in instruction[i]:

		inst = instruction[i].split()
		if [hash(int(inst[1])), int(inst[1])] in dictionary:
			dictionary.remove([hash(int(inst[1])), int(inst[1])])

fin.close()
fout.close()