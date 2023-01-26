#include <bits/stdc++.h>
using namespace std;
long long s[80], p[80];
long long st[10005 * 60][7];
vector<long long> v[70];
long long qpow(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int k, n;
  cin >> k >> n;
  p[0] = s[0] = 1;
  for (int i = 1; i <= 62; i++) {
    s[i] = s[i - 1] * 2;
    p[i] = p[i - 1] + s[i];
  }
  unordered_map<long long, int> hs;
  for (int i = 1; i <= n; i++) {
    long long v;
    string s;
    cin >> v >> s;
    hs[v] = i;
    int id = lower_bound(p, p + 63, v) - p;
    int c;
    if (s[0] == 'o')
      c = 5;
    else if (s[0] == 'r')
      c = 4;
    else if (s[0] == 'b')
      c = 3;
    else if (s[0] == 'g')
      c = 2;
    else if (s[0] == 'w')
      c = 1;
    else
      c = 0;
    ::v[id].push_back(v);
    for (int j = 0; j < 6; j++) st[i][j] = 0;
    long long sz;
    if (id != k) sz = (1LL << (k - id)) - 2;
    st[i][c] = qpow(4, sz);
  }
  int cnt = n;
  for (int i = k - 1; i >= 0; i--) {
    for (auto x : v[i]) {
      long long fa = x / 2;
      long long sz = (1LL << (k - i + 1)) - 2;
      long long bs = qpow(4, sz);
      long long d = qpow(qpow(4, sz / 2), 1000000007 - 2);
      if (!hs[fa]) {
        hs[fa] = ++cnt;
        for (int j = 0; j < 6; j++) st[hs[fa]][j] = bs;
        if (i) v[i - 1].push_back(fa);
      }
      int id = hs[fa];
      for (int j = 0; j < 6; j++) {
        long long c = 0;
        for (int k = 0; k < 6; k++) {
          if (j == k || (j ^ 1) == k) continue;
          (c += st[hs[x]][k]) %= 1000000007;
        }
        (st[id][j] *= c * d % 1000000007) %= 1000000007;
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < 6; i++) {
    res = (res + st[hs[1]][i]) % 1000000007;
  }
  cout << res;
  return 0;
}
