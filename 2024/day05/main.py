from collections import defaultdict
import sys


def toposort(g, v, visited, topo_order, order):
    visited.add(v)
    for n in g[v]:
        if n in order and n not in visited:
            toposort(g, n, visited, topo_order, order)
    topo_order.append(v)


table = sys.stdin.readlines()
g = defaultdict(set)

i = 0
while True:
    if table[i] == "\n":
        i += 1
        break
    a, b = list(map(int, table[i].strip("\n").split("|")))
    g[b].add(a)
    i += 1

part_one = 0
part_two = 0
while True:
    if i >= len(table):
        break
    order = list(map(int, table[i].strip("\n").split(",")))
    visited = set()
    topo_order = []
    for v in order:
        if v not in visited:
            toposort(g, v, visited, topo_order, order)
    if topo_order == order:
        part_one += topo_order[len(topo_order)//2]
    else:
        part_two += topo_order[len(topo_order)//2]
    i += 1

print(part_one)
print(part_two)
