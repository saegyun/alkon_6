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

string s;

stack<bool> pipe;
int arr[50000] = { 0, };
ll cnt = 0;

int main() {
    fastio;
    
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' && s[min((int)s.size() - 1, i + 1)] != ')') {
            pipe.push(1);
            continue;
        }
        else if (s[i] == '(' && s[min((int)s.size() - 1, i + 1)] == ')') {
            for (int j = 0; j < pipe.size(); j++) {
                arr[j] += 1;
            }
            i += 1;
        }
        else if (s[i] == ')') {
            cnt += arr[pipe.size() - 1] + 1;
            arr[pipe.size() - 1] = 0;
            //cout << i << "th " << s[i] << cnt << "\n";
            if(!pipe.empty()) pipe.pop();
            
        }
    }
    cout << cnt;

    return 0;
}