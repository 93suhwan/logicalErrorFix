#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e5 + 5;
int pref[N];
const int dx[] = {0, -1, 1, 0};
const int dy[] = {1, 0, 0, -1};
const long long inf = 1e18;
long long a[32], b[N];
bool f(long long x, long long n) {
  long long h = 0;
  for (long long i = 0; i < n; i++) {
    if (x - 1 - a[i] <= h && h <= b[i]) ++h;
  }
  return h >= x;
}
int getcount(int n, int k) {
  int res = (n >> (k + 1)) << k;
  if ((n >> k) & 1) res += n & ((1LL << k) - 1);
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, h, n, k, i, j, l, x, r, w, d, m, z, y, q;
  cin >> t;
  while (t--) {
    string s, g, gg;
    cin >> n;
    vector<long long> a(n);
    vector<pair<long long, long long>> p, pp;
    for (i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    for (i = 0; i < n; i++) {
      if (s[i] == '1')
        p.push_back({a[i], i});
      else
        pp.push_back({a[i], i});
    }
    sort(p.rbegin(), p.rend());
    sort(pp.rbegin(), pp.rend());
    k = n;
    for (i = 0; i < p.size(); i++) a[p[i].second] = k, k--;
    for (i = 0; i < pp.size(); i++) a[pp[i].second] = k, k--;
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
  }
}
