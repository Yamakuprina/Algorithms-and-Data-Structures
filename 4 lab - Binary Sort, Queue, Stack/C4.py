
top = -1
stack = []

for i in range(100):
	stack.append('0')

def insert(x):
	global stack
	global top
	top+=1
	stack[top] = x

def extract():
	global top
	top-=1

fin = open("brackets.in",  "r")
fout = open("brackets.out", "w")

instruction = fin.read().splitlines()

for i in range(len(instruction)):

	check=1
	top = -1
	
	for j in instruction[i]:

		if j=='(' or j=='[':
			insert(j)
		else:

			if (j==')' and stack[top]=='(') or (j==']' and stack[top]=='['):
				extract()
			else:
				check=0
				break

	if check==1 and top==-1:
		fout.write("YES")
		fout.write("\n")
	else:
		fout.write("NO")
		fout.write("\n")

fin.close()
fout.close()