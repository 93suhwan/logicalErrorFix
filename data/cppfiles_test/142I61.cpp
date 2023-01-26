#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int t; cin >> t;
	while (t--) {
		int m, n; cin >> m >> n;
		vector b(n, vector(m, int()));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cin >> b[j][i];
		}
		if (n > m) {
			int mi = INF;
			for (int i = 0; i < n; i++) {
				int ma = -1;
				for (int j = 0; j < m; j++) ma = max(ma, b[i][j]);
				mi = min(mi, ma);
			}
			cout << mi << endl;
			continue;
		}
		int l = 0, r = 1e9+10;
		while (l < r) {
			int mid = (l+r+1)/2;
			vector<int> tem(m);
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
				if (b[i][j] >= mid) tem[j]++;
			bool show = false;
			for (int j = 0; j < m; j++) if (tem[j] > 1) show = true;
			if (show) l = mid;
			else r = mid-1;
		}
		cout << l << endl;
	}
	exit(0);
}
