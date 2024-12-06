import sys

table = sys.stdin.readlines()
table = [line.strip("\n") for line in table]
n = len(table)
m = len(table[0])

dr = [(-1, 0), (0, 1), (1, 0), (0, -1)]


def start():
    for i in range(n):
        for j in range(m):
            if table[i][j] == '^':
                return i, j
    return -1, -1


def part_one():
    di = 0
    x, y = start()
    visited = [[-1 for _ in range(m)] for _ in range(n)]
    while True:
        if visited[x][y] == di:
            break
        visited[x][y] = di

        nx, ny = x + dr[di][0], y + dr[di][1]
        while (0 <= nx < n and 0 <= ny < m) and table[nx][ny] == '#':
            di = (di + 1) % 4
            nx, ny = x + dr[di][0], y + dr[di][1]
        if not (0 <= nx < n and 0 <= ny < m):
            break

        x, y = nx, ny

    ans = 0
    for l in visited:
        for i in l:
            ans += i >= 0
    return ans


def part_two():
    ans = 0
    sx, sy = start()
    for ox in range(n):
        for oy in range(m):
            di = 0
            x, y = sx, sy
            if table[ox][oy] != '.':
                continue
            visited = [[-1 for _ in range(m)] for _ in range(n)]
            while True:
                if visited[x][y] == di:
                    ans += 1
                    break
                visited[x][y] = di

                nx, ny = x + dr[di][0], y + dr[di][1]
                while (0 <= nx < n and 0 <= ny < m) and (table[nx][ny] == '#' or (nx, ny) == (ox, oy)):
                    di = (di + 1) % 4
                    nx, ny = x + dr[di][0], y + dr[di][1]
                if not (0 <= nx < n and 0 <= ny < m):
                    break

                x, y = nx, ny
    return ans


if __name__ == "__main__":
    # print(part_one())
    print(part_two())
