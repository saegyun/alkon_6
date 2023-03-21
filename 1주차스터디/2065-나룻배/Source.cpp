//2065 나룻배

#include <iostream>
#include <queue>
using namespace std;
queue<int> l;
queue<int> r;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, t, n, tmpNum, curTime = 0;
	string tmpString;
	cin >> m >> t >> n;
	bool ship = true;
	for (int i = 0; i < n; i++) {
		cin >> tmpNum;
		cin >> tmpString;
		if (tmpString == "left") l.push(tmpNum);
		else r.push(tmpNum);
	}
	while ((!l.empty()) || (!r.empty())) {
		int countPerson = 0;	
		if (ship) {
			if (l.empty()) {
				ship = (!ship);
				curTime += t;
				continue;
			}
			else { //비어있지는 않아.
				if (l.front() <= curTime) {
					while (l.front() <= curTime) {
						countPerson++;
						l.pop();
					}
				}
				if (countPerson != 0 || l.front() > r.front()) {
					ship = (!ship);
					curTime += t;
					for (int k = 0; k < countPerson; k++) cout << curTime << "\n";
				}
				else {
					curTime = l.front();
				}
			}		
		}
		else {
			if (r.empty()) {
				ship = (!ship);
				curTime += t;
				continue;
			}
			
			//while (r.front() <= curTime) {
			//	countPerson++;
			//	r.pop();
			//}
			////이동
			//if (countPerson != 0 || (l.empty() || l.front() < r.front())) {
			//	ship = (!ship);
			//	curTime += t;
			//	for (int k = 0; k < countPerson; k++) cout << curTime << "\n";
			//}
			//else {
			//	curTime = r.front();
			//}
		}
		
	}






















}