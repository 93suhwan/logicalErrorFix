#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return a % b ? gcd(b, a % b) : b; }
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f;
long long qpow(long long a, long long b) {
  long long t = 1;
  while (b != 0) {
    if (b & 1) t = (t * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return t;
}
template <typename T>
void re(T& a) {
  for (auto& t : a) cin >> t;
}
template <typename T>
void pr(T& a) {
  for (auto& t : a) cout << t << " ";
  cout << endl;
}
string a = "14689";
string b = "2357";
int n;
string s;
bool flag;
bool p(int n) {
  if (n < 2) return 0;
  int q = sqrt(n + 0.5) + 1;
  for (int i = 2; i < q; ++i) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void dfs(int x, int ans, int cnt) {
  if (flag) return;
  if (x == n) {
    if (ans != 0 && !p(ans)) {
      flag = 1;
      cout << cnt << endl;
      cout << ans << endl;
    }
    return;
  }
  dfs(x + 1, ans, cnt);
  dfs(x + 1, ans * 10 + s[x] - '0', cnt + 1);
}
void solve() {
  cin >> n;
  cin >> s;
  for (auto& t : s) {
    for (auto& tt : a) {
      if (t == tt) {
        cout << 1 << endl;
        cout << tt << endl;
        return;
      }
    }
  }
  int num[12] = {};
  for (auto& t : a) {
    num[t - '0']++;
  }
  for (auto& t : b) {
    if (num[t - '0'] > 1) {
      cout << 2 << endl;
      cout << t << t << endl;
      return;
    }
  }
  flag = 0;
  dfs(0, 0, 0);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
