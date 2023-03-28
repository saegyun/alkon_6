#include <bits/stdc++.h>
#include <stdio.h>

#define pii pair<int, int>
#define ff first
#define ss second
#define allV(v) v.begin(), v.end()
#define ll unsigned long long
#define l long
#define INF 9223372036854775807
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define veci vector<int>

using namespace std;

ll n, st = 0, ed, ans;

int main(void) {
	fastio;
	
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	ed = INF;
	ans = n;

	while (st <= ed) {
		ll mid = (ed + st) / 2;
		//cout << st << "\t" << mid << "\t" << ed << "\n";

		if (mid * mid >= n) {
			ed = mid - 1;

			ans = min(ans, mid);
		}
		else {
			st = mid + 1;
		}
	}
	cout << ans;
	
	return 0;
}