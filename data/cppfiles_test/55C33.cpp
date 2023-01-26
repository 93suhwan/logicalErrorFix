#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10, pi = 3.1415926535898;
const int mod = 1e9 + 7, maxn = 3e5 + 10;
int T, n, m, k, x, y, a[maxn], dp[maxn];
struct P {
  int x, y, i;
  bool operator<(const P& a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  }
} p[2 * maxn];
vector<int> v[maxn], v1[maxn];
int main(int argc, char const* argv[]) {
  int ans = 0, cnt = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    dp[i] = 1;
  }
  set<int> s;
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &k, &x, &y);
    p[2 * i - 1].x = x;
    p[2 * i - 1].y = 0;
    p[2 * i - 1].i = k;
    p[2 * i].x = y;
    p[2 * i].y = 1;
    p[2 * i].i = k;
  }
  sort(p + 1, p + 2 * m + 1);
  for (int i = 1; i <= 2 * m; ++i) {
    if (p[i].y == 0) {
      ++a[p[i].i];
      if (a[p[i].i] == 1) {
        set<int>::iterator it = s.lower_bound(p[i].i);
        if (it != s.end()) {
          v[p[i].i].push_back(*it);
          v1[*it].push_back(p[i].i);
        }
        if (!s.empty() and it != s.begin()) {
          --it;
          v[*it].push_back(p[i].i);
          v1[p[i].i].push_back(*it);
        }
        s.insert(p[i].i);
      }
    } else {
      --a[p[i].i];
      if (a[p[i].i] == 0) {
        s.erase(p[i].i);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j : v[i]) {
      dp[j] = max(dp[j], dp[i] + 1);
      if (dp[j] > ans) {
        ans = dp[j];
        cnt = j;
      }
    }
  }
  a[cnt] = mod;
  while (dp[cnt] > 1) {
    for (int i : v1[cnt]) {
      if (dp[i] == dp[cnt] - 1) {
        a[i] = mod;
        cnt = i;
        break;
      }
    }
  }
  printf("%d\n", n - ans);
  for (int i = 1; i <= n; ++i) {
    if (a[i] != mod) printf("%d ", i);
  }
  printf("\n");
  return 0;
}
