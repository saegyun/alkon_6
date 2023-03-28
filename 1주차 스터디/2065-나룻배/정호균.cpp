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

vector<pair<pair<int, int>, string>> input_timeline;
vector<pair<pair<int, int>, string>> tmp_timeline;

queue<pair<pair<int, int>, string>> boarding_people;

map<string, int> answer;

queue<pair<int, int>> left_q;
queue<pair<int, int>> right_q;

int main() {
    fastio;
    cin >> m >> t >> n;

    for (int i = 0; i < n; i++) {
        int arrival;
        string pos;
        cin >> arrival >> pos;
        input_timeline.push_back({ { arrival, i }, pos });
    }

    tmp_timeline = input_timeline;
    sort(allV(tmp_timeline));

    for (pair<pair<int, int>, string> p : tmp_timeline) {
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

            isLeft = !isLeft;
            //cout << "ferry moved at " << current << " to " << (isLeft ? "Left" : "Right") << "\n";
            
            amount = 0;
            while (!boarding_people.empty()) {
                pair<pair<int, int>, string> person = boarding_people.front();
                //cout << person.ff << " from " << person.ss << " leave at " << current << "\n";
                boarding_people.pop();

                //cout << current << "\n";
                string key = to_string(person.ff.ff) + "_" + person.ss + "_" + to_string(person.ff.ss);

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
                if (!right_q.empty()) {
                    current = max(right_q.front().ff, current);
                    continue;
                }
                break;
            }
            // 현재 시간에 탈 사람이 있을 경우
            while (!left_q.empty()) {
                pair<int, int> arrival_time = left_q.front();

                if (arrival_time.ff <= current) {
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
                if (!right_q.empty()) {
                    if (right_q.front() < left_q.front()) {
                        // 만약 오른쪽에 사람이 먼저 오면 일단 이동
                        current = max(right_q.front().ff, current);
                        continue;
                    }
                }
                // 왼쪽에 사람이 먼저 왔으면 그 시간에 온 모든 사람을 최대 수 까지 태움
                current = left_q.front().ff;

                while (!left_q.empty()) {
                    pair<int, int> arrival_time = left_q.front();
                    //cout << "left : " << arrival_time << " is on board\n";

                    if (arrival_time.ff <= current) {
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

                if (!left_q.empty()) {
                    current = max(left_q.front().ff, current);
                    continue;
                }
                break;
            }
            // 현재 시간에 탈 사람이 있을 경우
            while (!right_q.empty()) {
                pair<int, int> arrival_time = right_q.front();

                if (arrival_time.ff <= current) {
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
                if (!left_q.empty()) {
                    if (right_q.front() > left_q.front()) {
                        // 만약 왼쪽에 사람이 먼저 오면 일단 이동
                        current = max(left_q.front().ff, current);
                        continue;
                    }

                }
                // 오른쪽에 사람이 먼저 왔으면 그 시간에 온 모든 사람을 최대 수 까지 태움
                current = right_q.front().ff;

                while (!right_q.empty()) {
                    pair<int, int> arrival_time = right_q.front();
                    //cout << "right : " << arrival_time << " is on board\n";

                    if (arrival_time.ff <= current) {
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
    for (pair<pair<int, int>, string> person : input_timeline) {
        cout << answer[to_string(person.ff.ff) + "_" + person.ss + "_" + to_string(person.ff.ss)] << "\n";
    }

    return 0;
}