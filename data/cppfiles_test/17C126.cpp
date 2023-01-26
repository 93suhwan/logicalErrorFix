#include <bits/stdc++.h>
using namespace std;
inline void io() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
long long I() {
  long long a;
  cin >> a;
  return a;
}
void PV(vector<long long> v) {
  for (long long i = 0; i < (long long)v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
void PA(long long v[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cout << v[i] << " ";
  cout << endl;
}
void IA(long long a[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cin >> a[i];
}
const long long N = (2e5) + 7, N1 = 1e8 + 7, MOD = 998244353, INF = (1e17 + 7);
long long n;
vector<long long> bit(N);
long long smaller(long long i) {
  long long sm = 0;
  for (; i > 0; i -= (i & -i)) sm += bit[i];
  return sm;
}
void update(long long i) {
  for (; i <= n; i += (i & -i)) bit[i] += 1;
}
void solve() {
  cin >> n;
  long long a[n], b[n];
  IA(a, n);
  for (long long i = 0; i < n + 1; i++) bit[i] = 0;
  for (long long i = 0; i < n; i++) b[i] = a[i];
  sort(b, b + n);
  map<long long, long long> m, m1;
  for (long long i = 0; i < n; i++)
    if (m[b[i]] == 0) m[b[i]] = i + 1;
  long long noi = 0;
  for (long long i = 0; i < n; i++) {
    noi += min(i - m1[a[i]] - smaller(m[a[i]] - 1), smaller(m[a[i]] - 1));
    long long x = upper_bound(b, b + n, a[i]) - b;
    if (x < n) update(x);
    m1[a[i]]++;
  }
  cout << noi << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t1 = 1, x0 = 1;
  cin >> t1;
  while (t1--) {
    solve();
  }
}
