#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
struct SparseTable {
  int N, sz;
  vector<vector<long long>> table;
  SparseTable(vector<long long> v) {
    int sz = v.size();
    N = 0;
    while ((1 << N) <= sz) N++;
    table = vector<vector<long long>>(N, vector<long long>(sz));
    for (int i = 0; i < sz; i++) table[0][i] = v[i];
    for (int i = 1; i < N; i++) {
      for (int j = 0; j + (1 << i) - 1 < sz; j++) {
        table[i][j] = gcd(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  long long range_calc(int l, int r) {
    int h = floor(log2(r - l + 1));
    return gcd(table[h][l], table[h][r - (1 << h) + 1]);
  }
};
int n;
vector<long long> a, d;
void solve() {
  cin >> n;
  a = vector<long long>(n);
  d = vector<long long>(n - 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) d[i] = abs(a[i + 1] - a[i]);
  SparseTable spt(d);
  int ans = 1;
  for (int i = 0; i < n - 1; i++) {
    if (d[i] == 1) continue;
    int ok = i, ng = n - 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      if (spt.range_calc(i, mid) > 1)
        ok = mid;
      else
        ng = mid;
    }
    ans = max(ans, ok - i + 2);
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
