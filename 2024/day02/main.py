import sys

levels = sys.stdin.readlines()


def part_one():
    safe_count = 0
    for slevel in levels:
        level = list(map(int, slevel.split(" ")))
        increasing = len(level) == 0 or level[0] < level[1]
        isSafe = True
        for i in range(1, len(level)):
            diff = abs(level[i-1] - level[i])
            if increasing != (level[i-1] < level[i]) or diff < 1 or diff > 3:
                isSafe = False
        safe_count += isSafe
    return safe_count


def part_two():
    safe_count = 0
    for slevel in levels:
        level = list(map(int, slevel.split(" ")))
        oneSafe = False
        for de in range(0, len(level)):
            lev = level.copy()
            lev.pop(de)
            increasing = len(lev) == 0 or lev[0] < lev[1]
            isSafe = True
            for i in range(1, len(lev)):
                diff = abs(lev[i-1] - lev[i])
                if increasing != (lev[i-1] < lev[i]) or diff < 1 or diff > 3:
                    isSafe = False
            oneSafe |= isSafe
        safe_count += oneSafe
    return safe_count


if __name__ == "__main__":
    # print(part_one())
    print(part_two())
