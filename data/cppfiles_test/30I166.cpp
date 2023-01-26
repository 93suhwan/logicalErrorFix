#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long bigMod(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long res = bigMod(x, y / 2LL);
  res *= res;
  res %= MOD;
  if (y % 2) {
    res *= x;
    res %= MOD;
  }
  return res;
}
long long fac[1000005];
long long choose(long long x, long long y) {
  if (x == y) return 1;
  if (y > x) return 0;
  if (y == 0) return 1;
  long long up = fac[x];
  long long down = fac[y] * fac[x - y];
  down %= MOD;
  long long ret = up * bigMod(down, MOD - 2);
  ret %= MOD;
  return ret;
}
int t;
int n;
string s;
bool is_pal(char c) {
  int j = n - 1, i = 0;
  bool bla = 0;
  while (i < j) {
    while (s[i] == c) i++;
    while (s[j] == c) j--;
    if (j < i) break;
    if (s[i] != s[j]) return 0;
    i++;
    j--;
  }
  return 1;
}
set<int> v[30];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    for (int i = 0; i < 30; i++) v[i].clear();
    for (int i = 0; i < n; i++) {
      int x = s[i] - 'a';
      v[x].insert(i);
    }
    if (is_pal('1')) {
      cout << 0 << endl;
      continue;
    }
    bool bla = 0;
    int ans = n;
    for (char c = 'a'; c <= 'z'; c++) {
      bool tmp = is_pal(c);
      if (tmp) {
        int idx = c - 'a';
        int cur = v[idx].size();
        for (auto x : v[idx]) {
          if (x > n / 2 && n % 2 == 1) break;
          if (x >= n / 2 && n % 2 == 0) break;
          int need = n - 1 - x;
          if (v[idx].find(need) != v[idx].end()) {
            cur--;
            if (need != x) cur--;
          }
        }
        ans = min(ans, cur);
        bla = 1;
      }
    }
    if (!bla) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
