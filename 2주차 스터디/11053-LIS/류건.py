import sys
from bisect import bisect_left # 이진탐색 라이브러리
n=map(int,sys.stdin.readline())
a_i = list(map(int,sys.stdin.readline().split()))

dp = [0]
p_i = [0]

for a in a_i:
    idx = bisect_left(p_i, a)
    # 가장 큰 수가 들어왔다
    if idx == len(p_i):
        p_i.append(a)
    else:
        p_i[idx] = a
    dp.append(idx)

print(max(dp))
print(p_i)
print(dp)