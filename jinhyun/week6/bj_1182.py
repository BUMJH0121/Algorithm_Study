import sys

NAS = sys.stdin.readline().split()
N = int(NAS[0])
S = int(NAS[1])
P = list(map(int, sys.stdin.readline().split()))
global answer
global temp
answer = 0
temp = 0
visit = [0 for i in range(N)]

def dfs(depth, last_index):
    global answer
    global temp
    if depth == N:
        return
    else:
        for j in range(last_index, N):
            if visit[j] == 0:
                visit[j] = 1
                temp = temp + P[j]
                if temp == S:
                    answer = answer + 1
                dfs(depth+1, j)
                visit[j] = 0
                temp = temp - P[j]

for k in range(N):
    if S == P[k]:
        answer = answer+1
    temp = P[k]
    visit[k] = 1
    dfs(1, k)
    visit[k] = 0
    temp = temp - P[k]

print(answer)