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
		if (ship) { //����
			if (l.empty()) { //���� ť�� ����� ����. 
				// 40 7 4750
				ship = (!ship);
				if (!r.empty()) {
					curTime = r.front();
					curTime += t;
				}
				
			}
			else if (l.front() <= curTime) { //�¿� ����� �־�
				//�¿��
				while ((l.front() <= curTime) && countPerson < m) {
					countPerson++;
					l.pop();
					if (l.empty()) {
						break;
					}
				}
				//�̵��ϰ�
				curTime += t;
				//������
				for (int i = 0; i < countPerson; i++) {
					cout << curTime << "\n";
				}
				ship = (!ship);
			}
			else { // �¿� ����� ����. > �ð��� �� �¾Ƽ�
				if (r.empty()) {
					curTime = l.front();
					continue;
				}
				if (r.front() < l.front()) { // �ݴ����� �� ������.
					ship = (!ship);
					curTime = r.front();
					curTime += t;
				}
				else { //���� �ð��� �� ������.
					curTime = l.front();
				}
			}
		}
		else {
			if (r.empty()) { //���� ť�� ����� ����. 
				ship = (!ship);
				curTime += t;
				if (!l.empty()) {
					curTime = l.front();
					curTime += t;
				}
			}
			else if (r.front() <= curTime) { //�¿� ����� �־�
				//�¿��
				while ((r.front() <= curTime) && countPerson < m) {
					countPerson++;
					r.pop();
					if (r.empty()) {
						break;
					}
				}
				//�̵��ϰ�
				curTime += t;
				//������
				for (int i = 0; i < countPerson; i++) {
					cout << curTime << "\n";
				}
				ship = (!ship);
			}
			else { // �¿� ����� ����. > �ð��� �� �¾Ƽ�
				if (l.empty()) {
					curTime = r.front();
					continue;
				}
				if (l.front() < r.front()) { // �ݴ����� �� ������.
					ship = (!ship);
					curTime += t;
				}
				else { //���� �ð��� �� ������.
					curTime = r.front();
				}
			}
		}
	}

	return 0;
}