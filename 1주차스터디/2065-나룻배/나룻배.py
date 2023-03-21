import sys
M, t, N = map(int, sys.stdin.readline().split())
# M: 배의 capa
# t: 배가 건너는데 걸리는 시간
# N: sample 수

tt_l = [] # 왼쪽 timetable
tt_r = [] # 오른쪽 timetable
tt = [i for i in range(N)]

for i in range(N):
    time, pos = sys.stdin.readline().split()
    if pos == "left":
        tt_l.append((int(time),i))
    else:
        tt_r.append((int(time),i))

boat_position =  True #왼쪽
current = 0
capa = 0
#a = sorted(tt_l, key = lambda x: x[1]) #오름차순이라고 가정

while tt_l or tt_r:
    capa = 0
    person = []
    if boat_position:
        while tt_l and current >= tt_l[0][0] and capa < M: # 현재 시간보다 빨리왔고, 최대 수용인원보다 적다면
            capa += 1
            _, idx = tt_l.pop(0)
            person.append(idx)
        if capa == 0: #아무도 못 태운 경우
            if not tt_l: a = 100000000
            else: a = tt_l[0][0]
            if not tt_r: b = 100000000
            else: b = tt_r[0][0]

            min_value = min(a, b)
            if a == min_value:
                current = tt_l[0][0]
            else:
                if current > b:
                    current = current + t
                else:
                    current = tt_r[0][0] + t
                boat_position = not boat_position
        else:
            current += t
            for k in person:
                tt[k] = current  # 옮기기
            boat_position = not boat_position


    else:
        while tt_r and current >= tt_r[0][0] and capa < M: # 현재 시간보다 빨리왔고, 최대 수용인원보다 적다면
            capa += 1
            _, idx = tt_r.pop(0)
            person.append(idx)
        if capa == 0:  # 아무도 못 태운 경우
            if not tt_l:
                a = 100000000
            else:
                a = tt_l[0][0]
            if not tt_r:
                b = 100000000
            else:
                b = tt_r[0][0]

            min_value = min(a, b)
            if b == min_value:
                current = tt_r[0][0]
            else:
                if current > a:
                    current = current + t
                else:
                    current = tt_l[0][0]+t
                boat_position = not boat_position


        else:
            current += t
            for k in person:
                tt[k] = current  # 옮기기
            boat_position = not boat_position


for p in tt:
    print(p)