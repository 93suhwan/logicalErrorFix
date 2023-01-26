#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
const int mod = 1e9 + 7;
const int INF = INT32_MAX;
const double Pi = acos(-1.0);
int t, n, m;
int a[N];
int dir[][2] = {{0, 0},  {0, 1},   {-1, 0}, {0, -1}, {1, 0},
                {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
inline int read() {
  int x = 0, f = 1;
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
inline int gcd(int x, int y) {
  if (!x) return y;
  return gcd(y % x, x);
}
inline int power(int x, int k, int p) {
  int res = 1;
  for (; k; k >>= 1, x = (long long)x * x % p)
    if (k & 1) res = (long long)res * x % p;
  return res;
}
int pre[N];
void solve() {
  n = read();
  m = read();
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '+')
      a[i + 1] = (i + 1) % 2 ? 1 : -1;
    else
      a[i + 1] = (i + 1) % 2 ? -1 : 1;
  }
  map<int, int> mp;
  vector<int> v[(n << 1) + 10];
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + a[i];
    if (!mp[pre[i]]) {
      mp[pre[i]] = ++cnt;
    }
    v[mp[pre[i]]].push_back(i);
  }
  while (m--) {
    int l = read(), r = read();
    if (pre[r] == pre[l - 1]) {
      puts("0");
      continue;
    }
    if ((pre[r] - pre[l]) % 2) {
      int mid = (pre[r - 1] + pre[l]) / 2;
      if ((pre[r - 1] + pre[l]) % 2 == 0) mid++;
      auto it = lower_bound(v[mp[mid]].begin(), v[mp[mid]].end(), l);
      printf("2\n%d %d\n", (*it), r);
    } else {
      int mid = (pre[r] + pre[l]) / 2;
      auto it = lower_bound(v[mp[mid]].begin(), v[mp[mid]].end(), l);
      printf("1\n%d\n", (*it));
    }
  }
  return;
}
int main() {
  t = read();
  while (t--) {
    solve();
  }
  return 0;
}
