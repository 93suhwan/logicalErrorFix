#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
const long long mod = 1000000007;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const long long N = 300100;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long p1[N], p2[N];
long long sz1[N], sz2[N];
long long find1(long long x) {
  if (p1[x] == x) return x;
  return p1[x] = find1(p1[x]);
}
long long find2(long long x) {
  if (p2[x] == x) return x;
  return p2[x] = find2(p2[x]);
}
void join1(long long a, long long b) {
  if ((a = find1(a)) == (b = find1(b))) return;
  if (sz1[a] < sz1[b]) swap(a, b);
  p1[b] = a;
  sz1[a] += sz1[b];
}
void join2(long long a, long long b) {
  if ((a = find2(a)) == (b = find2(b))) return;
  if (sz2[a] < sz2[b]) swap(a, b);
  p2[b] = a;
  sz2[a] += sz2[b];
}
bool join(long long a, long long b) {
  long long c = find1(a), d = find1(b);
  long long e = find2(a), f = find2(b);
  if (c == d || e == f) return false;
  join1(c, d);
  join2(e, f);
  return true;
}
void solve() {
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  for (long long i = 1; i <= n; i++) p1[i] = p2[i] = i, sz1[i] = sz2[i] = 1;
  for (long long i = 0; i < m1; i++) {
    long long a, b;
    cin >> a >> b;
    join1(a, b);
  }
  for (long long i = 0; i < m2; i++) {
    long long a, b;
    cin >> a >> b;
    join2(a, b);
  }
  vector<pair<long long, long long> > ans;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      if (join(i, j)) {
        ans.push_back({i, j});
      }
    }
  }
  cout << (long long)ans.size() << "\n";
  for (auto p : ans) {
    cout << p.first << " " << p.second << "\n";
  }
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  ;
  long long t_ = 1;
  while (t_--) solve();
  return 0;
}
