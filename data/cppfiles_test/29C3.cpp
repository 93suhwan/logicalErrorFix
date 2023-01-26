#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct FenwickTree {
  vector<long long> bit;
  int n;
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  long long query(int r) {
    long long ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  long long query(int l, int r) { return query(r) - query(l - 1); }
  void rupd(int idx, long long delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};
void solve() {
  int n, x;
  long long res = 0;
  cin >> n;
  FenwickTree cnt(N), b(N), pre(N);
  for (int i = 0; i < n; i++) {
    cin >> x;
    res += 1ll * i * x - b.query(x);
    for (int j = 0; j < N; j += x) {
      int nxt = min(j + x - 1, N - 1);
      long long sum = pre.query(j, nxt), e = cnt.query(j, nxt);
      res += sum - e * j;
    }
    for (int j = x; j < N; j += x) b.rupd(j, x);
    cnt.rupd(x, 1);
    pre.rupd(x, x);
    cout << res << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
