
fin = open("search4.in",  "r")
fout = open("search4.out", "w")

patterns = []
patterns_found = []

class AhoNode:

	def __init__(self):
		self.goto = {}
		self.out = []
		self.fail = None


	def aho_create_forest(patterns):

		root = AhoNode()

		for p in patterns:
			node = root
			for symbol in p:
				node = node.goto.setdefault(symbol, AhoNode())
			node.out.append(p)
		return root

	def aho_create_automat(patterns):

		root = AhoNode.aho_create_forest(patterns)
		queue = []
		for node in root.goto.values():
			queue.append(node)
			node.fail = root

		while len(queue) > 0:
			rnode = queue.pop(0)

			for key, unode in rnode.goto.items():
				queue.append(unode)
				fnode = rnode.fail
				while fnode is not None and key not in fnode.goto:
					fnode = fnode.fail
				unode.fail = fnode.goto[key] if fnode else root
				unode.out += unode.fail.out

		return root

	def aho_find_all(s, root):

		node = root

		for i in range(len(s)):
			while node is not None and s[i] not in node.goto:
				node = node.fail
			if node is None:
				node = root
				continue
			node = node.goto[s[i]]
			for pattern in node.out:
				patterns_found.append(pattern)


N = int(fin.readline())
for i in range(N):
	x = fin.readline()
	patterns.append(x[:-1])

string = fin.readline()

root = AhoNode.aho_create_automat(patterns)
AhoNode.aho_find_all(string, root)

for p in patterns:
	if p in patterns_found:
		fout.write("YES")
		fout.write("\n")
	else:
		fout.write("NO")
		fout.write("\n")
		