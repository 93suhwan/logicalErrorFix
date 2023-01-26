#include <bits/stdc++.h>
using namespace std;
struct Q {
  vector<int> c;
  vector<int> buf;
  Q(int n) {
    c = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
      c[i] = lowbit(i);
    }
  }
  int lowbit(int x) { return x & -x; }
  void update(int p) {
    for (int i = p; i < c.size(); i += lowbit(i)) {
      c[i]--;
      buf.push_back(i);
    }
  }
  void rollback() {
    for (auto &p : buf) {
      c[p]++;
    }
    buf.clear();
  }
  int find(int sum) {
    int temp = 0;
    int p = 0;
    for (int i = 20; i >= 0; i--) {
      if (p + (1 << i) < c.size() && temp + c[p + (1 << i)] < sum) {
        p += 1 << i;
        temp += c[p];
      }
    }
    return p + 1;
  }
} q(2e5);
vector<int64_t> fac(4e5 + 1), ifac(4e5 + 1);
const int mod = 998244353;
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
int comb(int n, int m) { return fac[n] * ifac[n - m] % mod * ifac[m] % mod; }
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ins(m);
  for (auto &[x, y] : ins) {
    cin >> x >> y;
  }
  unordered_set<int> flag;
  int c = 0;
  for (int i = m - 1; i >= 0; i--) {
    auto [x, y] = ins[i];
    int p = q.find(y);
    q.update(p);
    c += !flag.count(p + 1);
    flag.insert(p);
  }
  q.rollback();
  cout << comb(n + (n - 1 - c), n) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < fac.size(); i++) {
    fac[i] = fac[i - 1] * i % mod;
    ifac[i] = powermod(fac[i], mod - 2, mod) % mod;
  }
  while (t--) {
    solve();
  }
  return 0;
}
