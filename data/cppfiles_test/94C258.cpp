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
string s;
int n;
long long ans;
map<vector<int>, bool> mp;
void fun(vector<int> a) {
  if (mp[a]) return;
  mp[a] = 1;
  long long tmp = 1;
  int flag = 2;
  for (auto& t : a) {
    tmp *= 10 - abs(t - 9);
    if (t >= 10) flag = 0;
  }
  ans += tmp - flag;
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      if (i + 2 < n && a[i + 2] < 10) {
        a[i]--;
        a[i + 2] += 10;
        fun(a);
        a[i]++;
        a[i + 2] -= 10;
      }
    }
  }
}
void solve() {
  mp.clear();
  cin >> s;
  n = s.size();
  vector<int> a;
  for (auto& t : s) {
    a.push_back(t - 48);
  }
  ans = 0;
  fun(a);
  cout << ans << endl;
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
