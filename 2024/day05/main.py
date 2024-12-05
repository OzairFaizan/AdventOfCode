from collections import defaultdict
import sys


def part_one():
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

    ans = 0
    while True:
        if i >= len(table):
            break
        order = list(map(int, table[i].strip("\n").split(",")))
        correct = True
        for j in range(len(order)):
            for k in range(j+1, len(order)):
                if order[k] in g[order[j]]:
                    correct = False
                    break
            if not correct:
                break
        if correct:
            ans += order[len(order)//2]
        i += 1
    return ans


def part_two():
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

    ans = 0
    while True:
        if i >= len(table):
            break
        order = list(map(int, table[i].strip("\n").split(",")))
        correct = True
        for j in range(len(order)):
            for k in range(j+1, len(order)):
                if order[k] in g[order[j]]:
                    correct = False
                    break
            if not correct:
                break
        if correct:
            i += 1
            continue

        visited = set()
        topo_order = []
        for v in order:
            if v not in visited:
                toposort(g, v, visited, topo_order, order)
        ans += topo_order[len(topo_order)//2]
        i += 1
    return ans


if __name__ == "__main__":
    # print(part_one())
    print(part_two())
