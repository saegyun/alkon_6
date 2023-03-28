import sys
q =int(sys.stdin.readline())

lt = 0
rt = int(2e32)
flag = False

while lt <= rt:  # lt가 rt보다 커지면 반복문 탈출
    mid = (lt + rt) // 2  # mid는 lt와 rt의 중간값
    r = int(mid*mid)
    if q == r:
        print(mid)
        flag = True
        break
    elif q > r:
        lt = mid + 1  # lt를 높임
    else:
        rt = mid - 1  # rt를 낮춤

if not flag:
    print(lt)