#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long h[N], e[N], nx[N], idx;
long long k, T, t, n, m, ans, cnt;
long long a[N], b[N], vis[N];
priority_queue<long long, vector<long long>, greater<long long> > q;
bool cmp(long long x, long long y) { return a[x] < a[y]; }
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    vector<long long> res;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) vis[i] = 0, b[i] = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      vis[a[i]]++;
      if (vis[a[i]] <= k) res.push_back(i);
    }
    while (res.size() % k) res.pop_back();
    sort(res.begin(), res.end(), cmp);
    long long num = 1;
    for (auto it : res) {
      if (num > k) num = 1;
      b[it] = num;
      num++;
    }
    for (long long i = 1; i <= n; i++) cout << b[i] << ' ';
    cout << '\n';
  }
  return 0;
}
