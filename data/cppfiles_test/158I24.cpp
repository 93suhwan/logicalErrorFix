#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 5, mod = 998244353;
long long res[N], vt[N], a[N], n, m, rs, x[N];
bool cmp(long long b, long long c) { return (a[b] < a[c]); }
string s[11];
long long cal() {
  long long as = 0;
  for (long long i = 1; i <= n; i++) {
    long long cnt = 0;
    for (long long j = 1; j <= m; j++)
      if (s[i][j] == '1') cnt += x[j];
    as += abs(cnt - a[i]);
  }
  return as;
}
void check(long long mid) {
  for (long long i = 1; i <= m; i++) x[i] = 0;
  long long l = 0, r = m + 1;
  for (long long i = 1; i <= mid; i++) {
    long long v = vt[i];
    for (long long j = m; j >= 1; j--)
      if (s[v][j] == '1' && x[j] == 0) r--, x[j] = r;
  }
  for (long long i = n; i >= mid + 1; i--) {
    long long v = vt[i];
    for (long long j = 1; j <= m; j++)
      if (s[v][j] == '1' && x[j] == 0) l++, x[j] = l;
  }
  for (long long j = 1; j <= m; j++)
    if (x[j] == 0) l++, x[j] = l;
  if (cal() > rs) {
    rs = cal();
    for (long long i = 1; i <= m; i++) res[i] = x[i];
  }
}
void Pmaru() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) vt[i] = i;
  sort(vt + 1, vt + n + 1, cmp);
  for (long long i = 1; i <= n; i++) cin >> s[i], s[i] = "." + s[i];
  rs = 0;
  if (n == 1) {
    cout << 1;
    return;
  }
  for (long long i = 1; i <= n - 1; i++) check(i);
  for (long long i = 1; i <= m; i++) cout << res[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  cin >> tests;
  while (tests--) {
    Pmaru();
    cout << endl;
  }
  cerr << "\n" << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms";
}
