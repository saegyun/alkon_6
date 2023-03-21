#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> l;
queue<int> r;
bool ship = true;
int m, t, n, tmpNum, curTime = 0;
string tmpString;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> t >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmpNum;
		cin >> tmpString;
		if (tmpString == "left") l.push(tmpNum);
		else r.push(tmpNum);
	}

	while (!l.empty() || !r.empty()) {
		int countPerson = 0;
		if (ship) { //왼쪽
			if (l.empty()) { //현재 큐에 사람이 없다. 
				// 40 7 4750
				ship = (!ship);
				if (!r.empty()) {
					curTime = r.front();
					curTime += t;
				}
				
			}
			else if (l.front() <= curTime) { //태울 사람이 있어
				//태우고
				while ((l.front() <= curTime) && countPerson < m) {
					countPerson++;
					l.pop();
					if (l.empty()) {
						break;
					}
				}
				//이동하고
				curTime += t;
				//내린다
				for (int i = 0; i < countPerson; i++) {
					cout << curTime << "\n";
				}
				ship = (!ship);
			}
			else { // 태울 사람이 없다. > 시간이 안 맞아서
				if (r.empty()) {
					curTime = l.front();
					continue;
				}
				if (r.front() < l.front()) { // 반대쪽이 더 빠르다.
					ship = (!ship);
					curTime = r.front();
					curTime += t;
				}
				else { //현재 시간이 더 빠르다.
					curTime = l.front();
				}
			}
		}
		else {
			if (r.empty()) { //현재 큐에 사람이 없다. 
				ship = (!ship);
				curTime += t;
				if (!l.empty()) {
					curTime = l.front();
					curTime += t;
				}
			}
			else if (r.front() <= curTime) { //태울 사람이 있어
				//태우고
				while ((r.front() <= curTime) && countPerson < m) {
					countPerson++;
					r.pop();
					if (r.empty()) {
						break;
					}
				}
				//이동하고
				curTime += t;
				//내린다
				for (int i = 0; i < countPerson; i++) {
					cout << curTime << "\n";
				}
				ship = (!ship);
			}
			else { // 태울 사람이 없다. > 시간이 안 맞아서
				if (l.empty()) {
					curTime = r.front();
					continue;
				}
				if (l.front() < r.front()) { // 반대쪽이 더 빠르다.
					ship = (!ship);
					curTime += t;
				}
				else { //현재 시간이 더 빠르다.
					curTime = r.front();
				}
			}
		}
	}

	return 0;
}
