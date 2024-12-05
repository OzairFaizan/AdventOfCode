import sys

table = sys.stdin.readlines()
X = len(table)
Y = len(table[0])


def part_one():
    def search(x, y, dx, dy):
        term = "XMAS"
        for i in range(len(term)):
            cx, cy = x + i*dx, y + i*dy
            if not (0 <= cx < X and 0 <= cy < Y) or table[cx][cy] != term[i]:
                return False
        return True

    ans = 0
    for x in range(X):
        for y in range(Y):
            for dx in [-1, 0, 1]:
                for dy in [-1, 0, 1]:
                    ans += search(x, y, dx, dy)
    return ans


def part_two():
    def search(x, y, dx, dy):
        term = "MAS"
        for i in range(len(term)):
            cx, cy = x + (i-1)*dx, y + (i-1)*dy
            if not (0 <= cx < X and 0 <= cy < Y) or table[cx][cy] != term[i]:
                return False
        return True

    ans = 0
    for x in range(X):
        for y in range(Y):
            count = 0
            for dx in [-1, 1]:
                for dy in [-1, 1]:
                    count += search(x, y, dx, dy)
            ans += count > 1
    return ans


if __name__ == "__main__":
    # print(part_one())
    print(part_two())
