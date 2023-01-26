#include <bits/stdc++.h>
const long long mod = 1e9 + 7, N = 5e5;
using namespace std;
long long t, n, k, p, c, a[N + 5];
string s, res;
string cnt(long long n) {
  string s = "";
  while (n > 0) {
    s = char(n % 10 + 48) + s;
    n /= 10;
  }
  return s;
}
void check(int a, int b) {
  bool bgr = 0, br = 0;
  string v = "";
  v += char(a + 48);
  string w[12][2];
  w[0][0] = "";
  w[0][1] = "";
  for (auto i = 1; i <= 10; i++) {
    w[i][0] = w[i - 1][0] + char(min(a, b) + 48);
    w[i][1] = w[i - 1][1] + char(max(a, b) + 48);
  }
  if (v[0] > s[0]) bgr = 1;
  long long e = s.size() - 1;
  long long p1 = min(a, b), p2 = max(a, b);
  if (bgr == 1) {
    v += w[e][0];
    res = min(res, v);
    return;
  }
  for (auto i = 1; i <= s.size() - 1; i++) {
    v += char(p2 + 48);
    e--;
    if (v[i] < s[i]) return;
    if (v[i] > s[i]) {
      string r = v + w[e][0];
      res = min(res, r);
      v[i] = char(p1 + 48);
      if (v[i] < s[i])
        return;
      else if (v[i] > s[i]) {
        r = v + w[e][0];
        res = min(res, r);
        return;
      }
    }
  }
  res = min(res, v);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    s = cnt(n);
    if (k == 1) {
      p = 1;
      for (auto i = 2; i <= s.size(); i++) p = p * 10 + 1;
      c = 0;
      while (c < n) {
        c += p;
        if (c % 10 == 0) c++;
      }
      cout << c << "\n";
    } else {
      res = "9999999999999999";
      for (auto i = 1; i <= 9; i++)
        for (auto j = 0; j <= 9; j++)
          if (i >= (s[0] - 48)) check(i, j);
      cout << res << "\n";
    }
  }
}
