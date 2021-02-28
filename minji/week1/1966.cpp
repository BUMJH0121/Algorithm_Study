/*
	[BOJ] 1966 ������ ť
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	
	while (T--) {
		queue<pair<int,int>> q;		//����, ��°
		priority_queue<int> pq;
		int N, M,cnt=0;
		cin >> N >> M;
		for (int i = 0; i < N; ++i) {
			int num;
			cin >> num;
			q.push(make_pair(num,i));
			pq.push(num);
		}

		while (!q.empty()) {
			int fnum = q.front().first;
			int tnum = q.front().second;
			q.pop();

			if (pq.top() == fnum) {
				pq.pop();
				cnt++;
				if (tnum == M) {
					break;
				}
			}
			else {
				q.push(make_pair(fnum, tnum));
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}