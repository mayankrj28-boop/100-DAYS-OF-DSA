//Implement a Min Heap using an array where the smallest element is always at the root.

import heapq

n = int(input())
heap = []

for _ in range(n):
    op = input().split()
    
    if op[0] == "insert":
        heapq.heappush(heap, int(op[1]))
    
    elif op[0] == "extractMin":
        if len(heap) == 0:
            print(-1)
        else:
            print(heapq.heappop(heap))
    
    elif op[0] == "peek":
        if len(heap) == 0:
            print(-1)
        else:
            print(heap[0])
