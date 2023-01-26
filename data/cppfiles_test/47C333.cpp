#include <bits/stdc++.h>
using namespace std;
long long f(vector<int> x, int k) {
  long long ret = 0;
  sort(x.begin(), x.end());
  for (int i = x.size() - 1; i >= 0; i -= k) {
    ret += x[i] * 2;
  }
  return ret;
}
void solve() {
  int n, k, mx = 0;
  cin >> n >> k;
  vector<int> x(n), a, b;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    mx = max(mx, abs(x[i]));
    if (x[i] < 0)
      a.push_back(-x[i]);
    else
      b.push_back(x[i]);
  }
  cout << f(a, k) + f(b, k) - mx << endl;
}
int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
}
