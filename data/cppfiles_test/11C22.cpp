#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
struct BIT {
  int n;
  vector<int> bit;
  BIT(int _n) {
    n = _n;
    bit = vector<int>(n, -n);
  }
  int mx(int k) {
    int s = -n;
    k++;
    while (k >= 1) {
      s = max(s, bit[k]);
      k -= k & -k;
    }
    return s;
  }
  void update(int p, int value) {
    p++;
    while (p <= n) {
      bit[p] = max(bit[p], value);
      p += p & -p;
    }
  }
};
vector<int> v[MAXN];
int main() {
  int n;
  cin >> n;
  BIT bit(MAXN);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    v[x].push_back(i);
  }
  bit.update(0, 0);
  int ans = 0;
  for (int i = 1; i < MAXN; i++) {
    reverse(v[i].begin(), v[i].end());
    for (auto x : v[i]) {
      if (x < i) continue;
      int res = bit.mx(x - i) + 1;
      ans = max(ans, res);
      bit.update(x - i, res);
    }
  }
  cout << ans << "\n";
  return 0;
}
