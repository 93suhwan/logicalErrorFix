#include <bits/stdc++.h>
using namespace std;
struct Q {
  vector<int> c;
  Q(int n) {
    c = vector<int>(n + 1);
    iota(c.begin(), c.end(), 0);
  }
  int lowbit(int x) { return x & -x; }
  void update(int p) {
    for (int i = p; i < c.size(); i += lowbit(i)) {
      c[i]--;
    }
  }
  int find(int sum) {
    int temp = 0;
    int p = 0;
    for (int i = 20; i >= 0; i--) {
      if (p + (1 << i) < c.size() && temp + c[p + (1 << i)] < sum) {
        p += 1 << i;
        temp += c[p + (1 << i)];
      }
    }
    return p + 1;
  }
};
int powermod(int64_t a, int n, int mod) {
  int64_t ans = 1;
  while (n) {
    if (n & 1) {
      ans = ans * a % mod;
    }
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
int comb(int n, int m, int mod = 998244353) {
  int64_t ans = 1;
  for (int i = n; i >= n - m + 1; i--) {
    ans = ans * i % mod;
  }
  int64_t temp = 1;
  for (int i = 1; i <= m; i++) {
    temp = temp * i % mod;
  }
  ans = ans * powermod(temp, mod - 2, mod) % mod;
  return ans;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ins(m);
  for (auto &[x, y] : ins) {
    cin >> x >> y;
  }
  vector<int> a(n + 1);
  vector<int> flag(n + 1);
  Q q(n);
  for (int i = m - 1; i >= 0; i--) {
    auto [x, y] = ins[i];
    int p = q.find(y);
    a[p] = x;
    q.update(p);
    flag[x] = 1;
  }
  int j = 1;
  for (int i = 1; i <= n; i++) {
    if (!a[i]) {
      while (flag[j]) {
        j++;
      }
      a[i] = j;
      flag[j] = 1;
    }
  }
  int c = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i + 1]) {
      c++;
    }
  }
  cout << comb(n + (n - 1 - c), n) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
