from collections import defaultdict
class Graph:

	def __init__(self, vertices):
		self.V = vertices 
		self.graph = []


	def addEdge(self, u, v, w):
		self.graph.append([u, v, w])


	def find(self, parent, i):
		if parent[i] == i:
			return i
		return self.find(parent, parent[i])


	def union(self, parent, rank, x, y):
		xroot = self.find(parent, x)
		yroot = self.find(parent, y)

		if rank[xroot] < rank[yroot]:
			parent[xroot] = yroot
		elif rank[xroot] > rank[yroot]:
			parent[yroot] = xroot

		else:
			parent[yroot] = xroot
			rank[xroot] += 1


	def KruskalMST(self):

		result = [] 
		i = 0
		e = 0
		self.graph = sorted(self.graph,key=lambda item: item[2])
		parent = []
		rank = []


		for node in range(self.V):
			parent.append(node)
			rank.append(0)


		while e < self.V - 1:


			u, v, w = self.graph[i]
			i = i + 1
			x = self.find(parent, u)
			y = self.find(parent, v)


			if x != y:
				e = e + 1
				result.append([u, v, w])
				self.union(parent, rank, x, y)


		minimumCost = 0
		print ("Edges in the constructed MST")
		for u, v, weight in result:
			minimumCost += weight
			if u == 0:
				u = 'a'
			if v == 0:
				v = 'a'
			if u == 1:
				u = 'b'
			if v == 1:
				v = 'b'
			if u == 2:
				u = 'c'
			if v == 2:
				v = 'c'
			if u == 3:
				u = 'd'
			if v == 3:
				v = 'd'
			print("%s -- %s == %d" % (u, v, weight))
		print("Minimum Spanning Tree" , minimumCost)


g1 = Graph(4)
g1.addEdge(0, 1, 6)
g1.addEdge(0, 2, 6)
g1.addEdge(0, 3, 6)
g1.addEdge(1, 3, 2)
g1.addEdge(2, 3, 2)

print("For Graph - 1")
g1.KruskalMST()
print("\n");
print("For Graph - 2")
g2 = Graph(4)
g2.addEdge(0, 1, 3)
g2.addEdge(0, 2, 3)
g2.addEdge(0, 3, 3)
g2.addEdge(1, 3, 1)
g2.addEdge(2, 3, 1)
g2.KruskalMST()