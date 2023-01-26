#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int modd = 998244353;
const int MAX = 3e5 + 5;
const int inf = 1e9;
long long bipow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * 1LL * a) % mod;
    a = (a * 1LL * a) % mod;
    b >>= 1;
  }
  return ans;
}
bool isPrime(int x) {
  if (x == 1)
    return 0;
  else if (x == 2 || x == 3)
    return 1;
  if (x % 2 == 0 || x % 3 == 0) return 0;
  for (int i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  }
  return 1;
}
inline long long add(long long x, long long y) {
  return (x % mod + y % mod) % mod;
}
inline long long sub(long long x, long long y) {
  if (x < 0) x += mod;
  if (y < 0) y += mod;
  return (x % mod - y % mod + mod) % mod;
}
inline long long mul(long long x, long long y) {
  return ((x % mod) * (y % mod)) % mod;
}
inline long long dvd(long long x, long long y) {
  return mul(x, bipow(y, mod - 2));
}
void solve(int test) {
  int n;
  cin >> n;
  vector<string> v(n);
  for (auto &s : v) cin >> s;
  int len = 0;
  vector<vector<int>> a(5, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    vector<int> tmp(5, 0);
    int len = (int)v[i].size();
    for (auto &c : v[i]) tmp[c - 'a']++;
    for (int j = 0; j < 5; j++) {
      a[j][i] = 2 * tmp[j] - len;
    }
  }
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    sort(a[i].begin(), a[i].end());
    reverse(a[i].begin(), a[i].end());
    int cur = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (cur + a[i][j] > 0)
        cnt++, cur += a[i][j];
      else
        break;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(15) << fixed;
  int tc = 1;
  cin >> tc;
  for (int ttc = 1; ttc <= tc; ttc++) {
    solve(ttc);
  }
  return 0;
}
