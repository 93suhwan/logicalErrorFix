#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = 0;
  int sum = 0;
  while (c < '0' || c > '9') c = getchar();
  while ('0' <= c && c <= '9') sum = sum * 10 + c - '0', c = getchar();
  return sum;
}
struct node {
  int x, y, num;
  bool operator<(const node &a) const {
    if (x != a.x) return x < a.x;
    return y < a.y;
  }
};
node p[400000 + 1];
struct node2 {
  int x, y, num;
  bool operator<(const node2 &a) const {
    if (y != a.y) return y < a.y;
    return x < a.x;
  }
};
node2 p2[400000 + 1];
set<node> v;
set<node> s;
set<node2> s2;
int n, ans, dp[400000 + 1];
struct bit {
  int c[400000 + 1];
  int lowbit(int x) { return x & (-x); }
  void add(int x, int d) {
    for (; x <= 2 * n; x += lowbit(x)) c[x] = (c[x] + d) % 1000000007;
    return;
  }
  int Sum(int x) {
    int res = 0;
    for (; x >= 1; x -= lowbit(x)) res = (res + c[x]) % 1000000007;
    return res;
  }
};
bit T;
bool check(node x) {
  if ((*s.begin()).x < x.x) return 0;
  auto it = s2.end();
  it--;
  if ((*it).y > x.y) return 0;
  return 1;
}
int main() {
  int t, x;
  n = read();
  for (int i = 1; i <= n; ++i)
    p[i].x = p2[i].x = read(), p[i].y = p2[i].y = read(),
    p[i].num = p2[i].num = i, v.insert(p[i]);
  t = read();
  while (t--) x = read(), s.insert(p[x]), s2.insert(p2[x]);
  sort(p + 1, p + n + 1), sort(p2 + 1, p2 + n + 1);
  for (int i = n; i >= 1; --i)
    dp[p[i].num] = (1 + T.Sum(p[i].y)) % 1000000007,
    T.add(p[i].y, dp[p[i].num]);
  int ps = n;
  while (!s.empty()) {
    auto it = v.begin();
    if (s.find(*it) != s.end())
      ans += dp[(*it).num], s.erase(*it),
          s2.erase((node2){(*it).x, (*it).y, 0});
    else if (check(*it)) {
      while (ps >= 1 && p2[ps].y > (*it).y) {
        if (v.find((node){p2[ps].x, p2[ps].y, 0}) != v.end())
          v.erase((node){p2[ps].x, p2[ps].y, 0});
        ps--;
      }
    } else
      ans = (ans + dp[(*it).num]) % 1000000007;
    v.erase(it);
  }
  printf("%d\n", ans);
  return 0;
}
