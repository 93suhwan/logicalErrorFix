#include <bits/stdc++.h>
using namespace std;
long long count(long long n, long long k) {
  long long res = (n >> (k + 1)) << k;
  if ((n >> k) & 1) res += n & ((1ll << k) - 1);
  return res;
}
void solve() {
  long long l, r;
  cin >> l >> r;
  vector<int> v(21, 0);
  vector<int> u(21, 0);
  vector<int> w(21, 0);
  l--;
  for (int j = 0; j < 21; j++) {
    v[j] = count(r + 1, j);
    u[j] = count(l + 1, j);
    w[j] = v[j] - u[j];
  }
  int n = r - l;
  sort(w.begin(), w.end());
  cout << n - w[20];
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
    cout << "\n";
  }
  return 0;
}
