disk = input().strip("\n")


def checksum(idx, id, size, ans):
    for _ in range(size):
        ans += idx * id
        idx += 1
    return ans, idx


sizes = []
free = []
for i in range(len(disk)):
    c = ord(disk[i]) - ord('0')
    if i % 2 == 0:
        sizes.append(c)
    else:
        free.append(c)

left, right = 0, len(sizes)-1
free_idx = 0
expanded_idx = 0
ans = 0


while left < right:
    ans, expanded_idx = checksum(expanded_idx, left, sizes[left], ans)

    while free[free_idx] > 0:
        if free[free_idx] >= sizes[right]:
            free[free_idx] -= sizes[right]
            ans, expanded_idx = checksum(
                expanded_idx, right, sizes[right], ans)
            right -= 1
        else:
            sizes[right] -= free[free_idx]
            ans, expanded_idx = checksum(
                expanded_idx, right, free[free_idx], ans)
            free[free_idx] = 0

    free_idx += 1
    left += 1

ans, expanded_idx = checksum(expanded_idx, left, sizes[left], ans)
print(ans)
