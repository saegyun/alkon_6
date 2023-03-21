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

int n, m, t, p1 = 0, p2 = 0, current = 0;
bool isStart = 0;

bool isLeft = 1;

ll total = 0;

veci la;
veci ra;

map<string, int> mp;
vector<string> ip;

int main() {
    fastio;
    cin >> m >> t >> n;

    for (int i = 0; i < n; i++) {
        int arrival;
        string pos;
        cin >> arrival >> pos;
        if (pos == "left") {
            la.push_back(arrival);
        }
        if (pos == "right") {
            ra.push_back(arrival);
        }
        ip.push_back(to_string(arrival) + pos);
    }
    sort(allV(la));
    sort(allV(ra));

    la.push_back(INF);
    ra.push_back(INF);

    vector<string> v;

    while (1) {
        //cout << "status - r: " << ra[p2] << " at " << p2 << "\tl: " << la[p1] << " at " << p1 << "\tisLeft" << isLeft << "\n";

        if (isStart != 0) {
            //cout << "at " << total << " across!\n";
            total += t;
            for (string str : v) {
                mp[str] = total;
            }
            isLeft = !isLeft;

            current = 0;
        }
        isStart = 1;
    
        v.resize(0);

        if (la[p1] == INF && ra[p2] == INF) {
            break;
        }

        if (isLeft) {
            while (total >= la[p1]) {
                //cout << "method 1 " << la[p1] << "-board\n";
                v.push_back(to_string(la[p1]) + (isLeft ? "left" : "right"));
                current++;
                p1++;
                if (current == m) {
                    break;
                }
            }
            if (current == m) {
                continue;
            }
            if (current == 0) {

                if (ra[p2] > la[p1]) {
                    //cout << "method 2 "  << la[p1] << "-board\n";
                    v.push_back(to_string(la[p1]) + (isLeft ? "left" : "right"));

                    total = la[p1];

                    current++;
                    p1++;

                    continue;
                }
                if (ra[p2] != INF) {
                    total = ra[p2];
                }
            }

        }
        else {
            while (total >= ra[p2]) {
                //cout << "method 1 " << ra[p2] << "-board\n";
                v.push_back(to_string(ra[p2]) + (isLeft ? "left" : "right"));

                current++;
                p2++;
                if (current == m) {
                    break;
                }
            }
            if (current == m) {
                continue;
            }
            if (current == 0) {
                if (ra[p2] < la[p1]) {
                    //cout << "method 2 " << ra[p2] << "-board\n";
                    v.push_back(to_string(ra[p2]) + (isLeft ? "left" : "right"));

                    total = ra[p2];

                    current++;
                    p2++;
                    continue;
                }
                if (la[p1] != INF) {
                    total = la[p1];
                }
            }

        }
    }

    for (string str : ip) {
        cout << mp[str] << "\n";
    }

    return 0;
}