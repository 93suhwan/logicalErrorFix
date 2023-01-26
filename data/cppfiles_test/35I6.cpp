#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const double eps = (double)1e-9;
const double pi = acos(-1.0);
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
const int N = 1000500;
long long ans;
char s[N];
vector<pair<int, int> > pr[N];
int n, cnt, lp[N], f[N];
inline void add(int i) {
  for (auto x : pr[i]) {
    int was = f[x.first];
    f[x.first] += x.second;
    int now = f[x.first];
    if (was >= 0 && now < 0) cnt++;
    if (was < 0 && now >= 0) cnt--;
  }
}
inline void del(int i) {
  for (auto x : pr[i]) {
    int was = f[x.first];
    f[x.first] -= x.second;
    int now = f[x.first];
    if (was >= 0 && now < 0) cnt++;
    if (was < 0 && now >= 0) cnt--;
  }
}
int main() {
  for (int i = 2; i * i < N; i++) {
    if (!lp[i]) {
      for (int j = i * i; j < N; j += i)
        if (!lp[j]) lp[j] = i;
    }
  }
  for (int i = 2; i < N; i++)
    if (!lp[i]) lp[i] = i;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    while (x > 1) {
      int p = lp[x], pw = 0;
      while (x % p == 0) {
        pw++;
        x /= p;
      }
      pr[i].push_back({p, pw});
    }
  }
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] != '/') continue;
    for (auto &j : pr[i]) j.second = -j.second;
  }
  for (int i = 1, ptr = 1; i <= n; i++) {
    ptr = max(ptr, i);
    while (ptr <= n) {
      add(ptr);
      if (cnt > 0) {
        del(ptr);
        break;
      }
      ptr++;
    }
    ans += ptr - i;
    if (i < ptr) del(i);
  }
  printf("%lld", ans);
  return 0;
}
