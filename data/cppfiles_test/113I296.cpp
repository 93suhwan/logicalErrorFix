#include <bits/stdc++.h>
using namespace std;
void solve();
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}
long long int n;
cin >> n;
vector<long long int> v(n);
for (long long int i = 0; i < n; i++) cin >> v[i];
sort(v.begin(), v.end());
long long int sm = 0;
for (long long int i : v) sm += i;
long long int m;
cin >> m;
vector<vector<long long int>> dr(m, vector<long long int>(2));
for (long long int i = 0; i < m; i++) cin >> dr[i][0] >> dr[i][1];
for (long long int i = 0; i < m; i++) {
  long long int it = lower_bound(v.begin(), v.end(), dr[i][0]) - v.begin();
  bool isc = 0, isp = 0;
  if (it > 0) isp = 1;
  if (it < n) isc = 1;
  long long int re;
  long long int rsm = 0;
  long long int ans1 = 1e18, ans2 = 1e18;
  if (isp) {
    re = dr[i][0] - v[it - 1];
    rsm = sm - v[it - 1];
    ans1 = re;
    if (dr[i][1] > rsm) ans1 += dr[i][1] - rsm;
  }
  if (isc) {
    rsm = sm - v[it];
    ans2 = 0;
    if (dr[i][1] > rsm) ans2 += dr[i][1] - rsm;
  }
  cout << min(ans1, ans2) << endl;
}
}
