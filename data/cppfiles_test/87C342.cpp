#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1000;
template <typename T>
T qpow(T a, T x) {
  T ans = 1;
  while (x) {
    if (x & 1) ans *= a;
    x >>= 1;
    a *= a;
  }
  return ans;
}
const int mod = 998244353;
int a[300 + 5], b[300 + 5];
int lowbit(int x) { return x & -x; }
void add(int x) {
  while (x <= 305) {
    a[x]++;
    x = x + lowbit(x);
  }
}
int getsum(int x) {
  int ans = 0;
  while (x >= 1) {
    ans = ans + a[x];
    x = x - lowbit(x);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    memset(a, 0, sizeof(a));
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<int> p;
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
      p.push_back(b[i]);
    }
    sort(p.begin(), p.end());
    for (int i = 1; i <= m; i++) {
      b[i] = lower_bound(p.begin(), p.end(), b[i]) - p.begin() + 1;
    }
    for (int i = 1; i <= m; i++) {
      add(b[i]);
      ans += getsum(b[i] - 1);
    }
    cout << ans << "\n";
  }
  return 0;
}
