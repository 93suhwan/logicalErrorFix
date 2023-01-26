#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 2e5 + 100;
string s[maxn];
long long J[maxn];
long long POW(long long base, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * base % mod;
    ;
    base = base * base % mod;
    p >>= 1;
  }
  return ans;
}
long long inv(long long num) { return POW(num, mod - 2); }
long long C(int n, int m) { return J[n] * inv(J[m] * J[n - m] % mod) % mod; }
int n;
long long solve() {
  map<char, int> mp;
  for (int i = 1; i <= n; ++i) {
    mp[s[i][0]]++;
    mp[s[i][1]]++;
  }
  if (mp['B'] > n || mp['W'] > n) {
    cout << "0\n";
    return 0;
  }
  long long cnt = C(mp['?'], n - mp['B']);
  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  J[0] = 1;
  for (int i = 1; i < maxn; ++i) J[i] = J[i - 1] * i % mod;
  int T = 1;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    long long cnt = solve();
    if (cnt == 0) {
      cout << cnt << endl;
      continue;
    }
    bool f = false;
    for (int i = 1; i <= n; ++i) {
      if (s[i][0] != '?' && s[i][1] != '?' && s[i][0] == s[i][1]) {
        f = true;
        break;
      }
      if (s[i][0] != '?' && s[i][1] != '?') continue;
      if (s[i][0] == '?' && s[i][0] == '?') continue;
      if (s[i][0] == 'B')
        s[i][1] = 'W';
      else if (s[i][0] == 'W')
        s[i][1] = 'B';
      else if (s[i][1] == 'B')
        s[i][0] = 'W';
      else if (s[i][1] == 'W')
        s[i][0] = 'B';
    }
    if (f) {
      cout << cnt << endl;
      continue;
    }
    map<char, int> mp;
    int f1 = 0, f2 = 0;
    for (int i = 1; i <= n; ++i) {
      mp[s[i][0]]++;
      mp[s[i][1]]++;
      if (s[i][0] == 'B' && s[i][1] == 'W')
        f1 = 1;
      else if (s[i][0] == 'W' && s[i][1] == 'B')
        f2 = 1;
    }
    if (mp['B'] != mp['W']) {
      cout << cnt << endl;
      continue;
    }
    int cnt0 = mp['?'] / 2;
    f1 ^= 1;
    f2 ^= 1;
    cnt = (cnt - POW(2, cnt0) + mod + f1 + f2) % mod;
    cout << cnt << endl;
  }
}
