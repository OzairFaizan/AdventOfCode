import re
import sys

corrupted = sys.stdin.readlines()[0]


def part_one():
    ans = 0
    for mul in re.findall(r"mul\(\d{1,3},\d{1,3}\)", corrupted):
        a, b = list(map(int, mul[4:-1].split(",")))
        ans += a * b
    return ans


def part_two():
    ans = 0
    enabled = True
    for op in re.findall(r"mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\)", corrupted):
        if op == "do()":
            enabled = True
        elif op == "don't()":
            enabled = False
        elif enabled:
            a, b = list(map(int, op[4:-1].split(",")))
            ans += a * b
    return ans


if __name__ == "__main__":
    # print(part_one())
    print(part_two())
