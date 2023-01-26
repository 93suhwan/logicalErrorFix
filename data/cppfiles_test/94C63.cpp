#include <bits/stdc++.h>
using namespace std;
long long calc(int i, vector<long long> x) {
  if (i == x.size()) return 1;
  long long p1 = 0, p2 = 0;
  p1 = min(x[i] + 1, 19 - x[i]) * calc(i + 1, x);
  if (x[i] > 0 && i + 2 < x.size()) {
    --x[i];
    x[i + 2] += 10;
    p2 = min(x[i] + 1, 19 - x[i]) * calc(i + 1, x);
  }
  return p1 + p2;
}
void solve() {
  int n, m, i, p;
  cin >> n;
  vector<long long> x;
  m = n;
  while (m) {
    x.push_back(m % 10);
    m /= 10;
  }
  reverse(x.begin(), x.end());
  cout << calc(0, x) - 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
