#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int bas = 13333;
const double eps = 1e-7;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int a[maxn];
void INIT() {}
void init() {}
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int l, r, u, d;
  l = r = u = d = 0;
  int maxlr = 0, maxud = 0;
  int maxrl = 0, maxdu = 0;
  int flag1 = 0, flag2 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L') l++;
    if (s[i] == 'U') u++;
    if (s[i] == 'D') d++;
    if (s[i] == 'R') r++;
    maxlr = max(maxlr, l - r);
    maxud = max(maxud, u - d);
    maxrl = max(maxrl, r - l);
    maxdu = max(maxdu, d - u);
    if (maxlr + maxrl >= m) {
      if (s[i] == 'L')
        flag1 = 1;
      else
        flag1 = 2;
      break;
    }
    if (maxud + maxdu >= n) {
      if (s[i] == 'D')
        flag2 = 1;
      else
        flag2 = 2;
      break;
    }
  }
  int ansx = 0, ansy = 0;
  if (maxlr + maxrl >= m) {
    if (flag1 == 1) {
      ansy = maxlr;
    } else {
      ansy = 1 + maxlr;
    }
    ansx = 1 + maxud;
  } else {
    if (flag2 == 2) {
      ansx = maxud;
    } else {
      ansx = n - maxdu;
    }
    ansy = 1 + maxlr;
  }
  cout << ansx << " " << ansy << '\n';
  return;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  long long T;
  cin >> T;
  while (T--) INIT(), solve();
  return 0;
}
