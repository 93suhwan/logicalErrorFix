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
long long n, m, k;
char s[105][105];
int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    int h = k;
    int v = (n * m) / 2 - h;
    int needH = (n % 2) * m / 2;
    if (needH > h) {
      cout << "NO" << endl;
      continue;
    }
    int needV = (m % 2) * n / 2;
    if (needV > v) {
      cout << "NO" << endl;
      continue;
    }
    h -= needH;
    v -= needV;
    if (v % 2 || h % 2) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) s[i][j] = '.';
    if (needH) {
      for (int j = 0; j < m; j += 2) {
        s[0][j] = s[0][j + 1] = char(('a') + j / 2);
      }
    }
    if (needV) {
      for (int i = 0; i < n; i += 2) {
        s[i][0] = s[i + 1][0] = char(('a') + i / 2);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        set<char> se;
        for (char c = 'a'; c <= 'h'; c++) se.insert(c);
        if (s[i][j] == '.' && s[i][j + 1] == '.' && s[i + 1][j] == '.' &&
            s[i + 1][j + 1] == '.') {
          if (i > 0) {
            if (se.find(s[i - 1][j]) != se.end())
              se.erase(se.find(s[i - 1][j]));
            if (se.find(s[i - 1][j + 1]) != se.end())
              se.erase(se.find(s[i - 1][j + 1]));
          }
          if (j > 0) {
            if (se.find(s[i][j - 1]) != se.end())
              se.erase(se.find(s[i][j - 1]));
            if (se.find(s[i + 1][j - 1]) != se.end())
              se.erase(se.find(s[i + 1][j - 1]));
          }
          if (h >= 2) {
            s[i][j] = s[i][j + 1] = *se.begin();
            se.erase(se.begin());
            s[i + 1][j] = s[i + 1][j + 1] = *se.begin();
            h -= 2;
          } else {
            s[i][j] = s[i + 1][j] = *se.begin();
            se.erase(se.begin());
            s[i][j + 1] = s[i + 1][j + 1] = *se.begin();
            v -= 2;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << s[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
