#include <bits/stdc++.h>
#include <stdio.h>

#define pii pair<int, int>
#define ff first
#define ss second
#define allV(v) v.begin(), v.end()
#define ll long long
#define l long
#define INF 10e5+9
#define veci vector<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, m, t, current = 0, amount = 0;

bool isStart = 1;
bool isLeft = 1;

vector<pair<int, string>> input_timeline;
queue<pair<int, string>> boarding_people;

map<string, int> answer;

queue<int> left_q;
queue<int> right_q;

int main() {
    fastio;
    cin >> m >> t >> n;

    for (int i = 0; i < n; i++) {
        int arrival;
        string pos;
        cin >> arrival >> pos;
        input_timeline.push_back({ arrival, pos });
    }

    sort(allV(input_timeline));

    for (pair<int, string> p : input_timeline) {
        if (p.ss == "left") {
            left_q.push(p.ff);
        }
        else {
            right_q.push(p.ff);
        }
    }

    

    while (1) {
        if (!isStart) {
            current += t;
            //cout << "ferry moved at " << current << "\n";

            isLeft = !isLeft;
            amount = 0;
            while (!boarding_people.empty()) {
                pair<int, string> person = boarding_people.front();
                boarding_people.pop();

                string key = to_string(person.ff) + "_" + person.ss;

                answer[key] = current;
            }
        }
        isStart = 0;


        // 종료조건 : 두 땅에 아무도 올 사람이 없을 때
        if (left_q.empty() && right_q.empty()) {
            break;
        }

        if(isLeft) {
            //cout << "status - boarding_count : " << boarding_people.size() << "\tis left? : " << isLeft << "\n";
            // 앞으로 올 사람이 없으면 넘기기
            if (left_q.empty()) {
                continue;
            }
            // 현재 시간에 탈 사람이 있을 경우
            while (!left_q.empty()) {
                int arrival_time = left_q.front();

                if (arrival_time <= current) {
                    //cout << "left : " << arrival_time << " is on board\n";
                    boarding_people.push({ arrival_time, "left" });
                    left_q.pop();
                }
                else {
                    break;
                }
                if (boarding_people.size() == m) {
                    break;
                }
            }
            // 탈 사람이 없을 경우
            if (boarding_people.size() == 0) {
                if (right_q.front() < left_q.front()) {
                    // 만약 오른쪽에 사람이 먼저 오면 일단 이동
                    current = right_q.front();
                    continue;
                }
                // 왼쪽에 사람이 먼저 왔으면 그 시간에 온 모든 사람을 최대 수 까지 태움
                current = left_q.front();

                while (!left_q.empty()) {
                    int arrival_time = left_q.front();

                    if (arrival_time <= current) {
                        boarding_people.push({ arrival_time, "left" });
                        left_q.pop();
                    }
                    else {
                        break;
                    }
                    if (boarding_people.size() == m) {
                        break;
                    }
                }
            }
        }
        else {
            //cout << "status - boarding_count : " << boarding_people.size() << "\tis left? : " << isLeft << "\n";
            // 앞으로 올 사람이 없으면 넘기기
            if (right_q.empty()) {
                continue;
            }
            // 현재 시간에 탈 사람이 있을 경우
            while (!right_q.empty()) {
                int arrival_time = right_q.front();

                if (arrival_time <= current) {
                    //cout << "right : " << arrival_time << " is on board\n";
                    boarding_people.push({ arrival_time, "right" });
                    right_q.pop();
                }
                else {
                    break;
                }
                if (boarding_people.size() == m) {
                    break;
                }
            }
            // 탈 사람이 없을 경우
            if (boarding_people.size() == 0) {
                if (right_q.front() > left_q.front()) {
                    // 만약 왼쪽에 사람이 먼저 오면 일단 이동
                    current = left_q.front();
                    continue;
                }
                // 오른쪽에 사람이 먼저 왔으면 그 시간에 온 모든 사람을 최대 수 까지 태움
                current = right_q.front();

                while (!right_q.empty()) {
                    int arrival_time = right_q.front();

                    if (arrival_time <= current) {
                        boarding_people.push({ arrival_time, "right" });
                        right_q.pop();
                    }
                    else {
                        break;
                    }
                    if (boarding_people.size() == m) {
                        break;
                    }
                }
            }
        }
    }
    for (pair<int, string> person : input_timeline) {
        cout << answer[to_string(person.ff) + "_" + person.ss] << "\n";
    }

    return 0;
}