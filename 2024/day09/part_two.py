disk = input().strip("\n")


def checksum(idx, id, size, ans):
    for _ in range(size):
        ans += idx * id
        idx += 1
    return ans, idx


sizes = []
sizes_start = []
free = []
free_start = []
expanded_idx = 0
for i in range(len(disk)):
    c = ord(disk[i]) - ord('0')
    if i % 2 == 0:
        sizes.append(c)
        sizes_start.append(expanded_idx)
    else:
        free.append(c)
        free_start.append(expanded_idx)
    expanded_idx += c


ans = 0
for right in range(len(sizes)-1, -1, -1):
    moved = False
    for idx in range(len(free)):
        if free[idx] >= sizes[right] and free_start[idx] <= sizes_start[right]:
            free[idx] -= sizes[right]
            ans, free_start[idx] = checksum(
                free_start[idx], right, sizes[right], ans)
            moved = True
            break
    if not moved:
        ans, _ = checksum(sizes_start[right], right, sizes[right], ans)
    right -= 1

print(ans)
