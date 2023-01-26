#include <ctime>
#include <random>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

typedef long long ll;


struct Event {
	int val, id, ty;

	Event(int val, int id, int ty) {
		this->val = val;
		this->id = id;
		this->ty = ty;
	}

	bool operator <(Event other) {
		return val < other.val || val == other.val && ty < other.ty;
	}
};


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(30);

	int t;
	cin >> t;

	for (; t; t--) {
		int n, m;
		cin >> n >> m;

		vector < vector < int > > a(n, vector < int >(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		}


		vector < vector < int > > mnr(n, vector < int >(m)), mxr(n, vector < int >(m));
		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				if (j == m - 1) {
					mnr[i][j] = a[i][j];
					mxr[i][j] = a[i][j];
				}
				else {
					mnr[i][j] = min(a[i][j], mnr[i][j + 1]);
					mxr[i][j] = max(a[i][j], mxr[i][j + 1]);
				}
			}
		}

		bool res = false;
		vector < int > mnl(n, 1e6), mxl(n, 1);
		for (int j = 0; j < m - 1 && !res; j++) {
			vector < Event > q;
			set < pair < int, int > > red, blue;
			for (int i = 0; i < n; i++) {
				mnl[i] = min(mnl[i], a[i][j]);
				mxl[i] = max(mxl[i], a[i][j]);
				q.push_back(Event(mnl[i], i, 0));
				q.push_back(Event(mxl[i], i, 1));

				red.insert({ mxr[i][j + 1], i });
			}
			sort(q.begin(), q.end());

			int cnt = 0;
			vector < char > ty(n, 'R');
			for (Event cur : q) {
				if (cur.ty)
					cnt--;
				else {
					cnt++;
					ty[cur.id] = 'B';
					red.erase({ mxr[cur.id][j + 1], cur.id });
					blue.insert({ mnr[cur.id][j + 1], cur.id });
				}

				if (cnt == 0 && !red.empty() && !blue.empty() && *blue.begin() > *red.rbegin()) {
					res = true;
					cout << "YES\n";
					for (char el : ty)
						cout << el;
					cout << " " << j + 1 << "\n";
					break;
				}
			}
		}

		if (!res)
			cout << "NO\n";
	}

	return 0;
}