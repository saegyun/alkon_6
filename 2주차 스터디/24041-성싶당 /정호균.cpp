#include <bits/stdc++.h>
#include <stdio.h>

#define pii pair<int, int>
#define ff first
#define ss second
#define allV(v) v.begin(), v.end()
#define ll unsigned long long
#define l long
#define INF 10e9 + 5
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define veci vector<int>

using namespace std;

struct Tri {
	int S;
	int L;
	bool O;
};

vector<Tri> v;
int n, g, k;

// x일차에 밀키트에 존재할 수 있는 "최소 세균 수"를 구한 후, 먹을 수 있는지 없는지를 반환하는 함수
bool chk(l x) {
	priority_queue<ll> pq;
	ll sm = 0;

	for (Tri k : v) {
		ll d = k.S * max((l)1, x - k.L);
		if (k.O) {
			pq.push(d);
		}
		sm += d;
	}
	for (int i = 0; i < k; i++) {
		if (!pq.empty()) {
			sm -= pq.top();
			pq.pop();
		}
	}

	if (sm > g) {
		return false;
	}
	return true;
}

// 매개변수 탐색으로 가능한 요일을 찾자!
int main(void) {
	fastio;
	cin >> n >> g >> k;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].S >> v[i].L >> v[i].O;
	}
	

	l st = 0, ed = INF, ans = 0;
	while (st <= ed) {
		l mid = (ed + st) / 2;

		if (chk(mid)) {
			st = mid + 1;
			ans = max(ans, mid);
		}
		else {
			ed = mid - 1;
		}
	}
	cout << ans;


	return 0;
}