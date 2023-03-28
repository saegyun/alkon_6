#include <stdio.h>
#include <bits/stdc++.h>

#define pii pair<int, int>
#define ff first
#define ss second
#define allV(v) v.begin(), v.end()
#define veci vector<int>
#define vecb vector<bool>
#define ll long long
#define l long
#define INF 2147483647
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int ub(veci v, int val) {
	int low = 0, high = v.size();
	int mid = 0;
	while (low < high) {
		mid = (high + low) / 2;;
		if (v[mid] < val) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}

	return low;
}

veci dp;

int main() {
	fastio;
	vector<pii> v;
	int n, maxValue = 0;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		int len = ub(dp, a);
		
		if (len < dp.size()) {
			if(dp[len] > a) dp[len] = a;
		}
		else if(len >= dp.size()){
			dp.push_back(a);
		}
		if (maxValue < len) {
			maxValue = len;
		}
	/*	cout << a << ": " << len << '\n';
		for (int k : dp) {
			cout << k << " ";
		}
		cout << "\n";*/

	}
	cout << maxValue + 1;
	return 0;
}