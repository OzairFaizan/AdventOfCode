import sys

table = sys.stdin.readlines()
table = [line.strip("\n") for line in table]

part_two = True

ans = 0
for line in table:
    target, values = line.split(": ")
    target = int(target)
    values = list(map(int, values.split(" ")))
    values.reverse()

    targets = [target]
    for i in range(len(values)-1):
        ntargets = []
        for t in targets:
            if part_two and t != values[i] and str(t).endswith(str(values[i])):
                ntargets.append(int(str(t)[:-len(str(values[i]))]))
            if t % values[i] == 0:
                ntargets.append(t // values[i])
            if t - values[i] >= 0:
                ntargets.append(t - values[i])
        targets = ntargets

    if values[-1] in targets:
        ans += target

print(ans)
