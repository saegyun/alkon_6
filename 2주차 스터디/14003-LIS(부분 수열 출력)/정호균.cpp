#include <bits/stdc++.h>
#include <stdio.h>

#define pii pair<int, int>
#define ff first
#define ss second
#define allV(v) v.begin(), v.end()
#define ll unsigned long long
#define l long
#define INF 10e9
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define veci vector<int>

using namespace std;

int n;
pii res = { -1, -1 };
veci v;
veci ddp;

vector<pii> dp;

int getlen(int x) {
	int st = 0, ed = dp.size() - 1, ans = 0;
	while (st <= ed) {
		int mid = (st + ed) / 2;
		if (dp[mid].ff < x) {
			st = mid + 1;
			ans = max(ans, mid);
		}
		else {
			ed = mid - 1;
		}
	}

	return ans;
}

int main(void) {
	fastio;
	dp.push_back({ -INF, -1});

	cin >> n;

	v.resize(n);
	ddp.resize(n, -1);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		int idx = getlen(v[i]);
		
		ddp[i] = dp[idx].ss;

		if (idx + 1 < dp.size()) {
			dp[idx + 1] = { v[i], i };
		}
		else {
			dp.push_back({ v[i], i });
		}
		if (res.ff <= idx + 1) {
			res = { idx + 1, i };
		}
	}

	cout << res.ff << "\n";

	int k = res.ss;
	stack<int> st;

	st.push(v[k]);

	while (ddp[k] != -1) {
		st.push(v[ddp[k]]);
		k = ddp[k];
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}