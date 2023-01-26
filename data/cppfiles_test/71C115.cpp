#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 2 * 1e5 + 10;
const long long inf = 1e18;
const long long ninf = -1e18;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long modPower(long long a, long long b, long long M = mod) {
  if (a == 0) return 0;
  b %= (M - 1);
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res;
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long p = power(x, y / 2);
  p = (p * p);
  return (y % 2 == 0) ? p : (x * p);
}
long long modInverse(long long a, long long m) {
  return ((modPower(a, m - 2, m) + mod) % mod);
}
long long modDivide(long long a, long long b, long long m) {
  a = a % m;
  long long inv = modInverse(b, m);
  if (inv == -1)
    return 0;
  else
    return (inv * a) % m;
}
struct comparepq {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
  }
};
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
vector<long long> v;
int max(int a, int b) { return (a > b) ? a : b; }
int lcs(string X, string Y, int m, int n) {
  int L[m + 1][n + 1];
  int i, j;
  for (i = 0; i <= m; i++) {
    for (j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (X[i - 1] == Y[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;
      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }
  return L[m][n];
}
void pre() {
  long long ptr = 0, num = power(2, ptr);
  while (num <= 1e18) {
    v.push_back(num);
    ptr++;
    num = power(2, ptr);
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  string s = to_string(n), ans = "999999999999999";
  int sz = s.length();
  if (k == 1) {
    string t;
    for (int i = (1); i < (10); i++) {
      for (int k = (0); k < (sz); k++) t += char('0' + i);
      if (t >= s) ans = min(ans, t);
      t = "";
    }
  } else {
    string t;
    for (int i = (1); i < (10); i++) {
      for (int j = (0); j < (10); j++) {
        if (i == j) continue;
        int id = 0, last = -1;
        char a = '0' + i, b = '0' + j;
        for (int k = (0); k < (sz); k++) {
          if (id > 0) {
            t += min(a, b);
            continue;
          } else if (id < 0)
            break;
          else {
            if (s[k] > a && s[k] > b && last == -1)
              id = -1;
            else if (s[k] > a && s[k] > b && last != -1) {
              t = t.substr(0, last + 1);
              t[last] = max(a, b);
              for (int l = (0); l < (sz - last - 1); l++) t += min(a, b);
              break;
            } else if (s[k] < max(a, b)) {
              last = k;
              if (s[k] <= min(a, b)) {
                if (s[k] < min(a, b)) id = 1;
                t += min(a, b);
              } else {
                t += max(a, b);
                id = 1;
              }
            } else if (s[k] == max(a, b)) {
              t += max(a, b);
            }
          }
          if (id < 0) break;
        }
        if (id >= 0) {
          ans = min(ans, t);
        }
        t = "";
      }
    }
  }
  int sz1 = ans.length();
  assert(sz1 == sz);
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  pre();
  for (int i = (0); i < (t); i++) {
    solve();
  }
  return 0;
}
